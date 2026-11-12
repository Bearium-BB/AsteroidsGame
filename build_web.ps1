# Builds the game for the browser from PowerShell. Output: build_web\index.html
$emsdk   = if ($env:EMSDK) { $env:EMSDK } else { "C:\emsdk" }
$raylib  = if ($env:RAYLIB) { $env:RAYLIB } else { "C:\raylib\raylib\src" }
$emcc    = Join-Path $emsdk "upstream\emscripten\emcc.bat"
if (-not (Test-Path $emcc)) { Write-Error "emcc not found at $emcc (set `$env:EMSDK)"; exit 1 }
$env:PATH = "$emsdk;$emsdk\upstream\emscripten;$emsdk\node\22.16.0_64bit\bin;$env:PATH"

New-Item -ItemType Directory -Force build_web | Out-Null
& $emcc (Get-ChildItem src\*.cpp).FullName -o build_web\index.html -std=c++14 -Os -Wall `
  "-I$raylib" "$raylib\libraylib.web.a" -DPLATFORM_WEB -s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 `
  -s TOTAL_MEMORY=67108864 --preload-file MP3 --shell-file web\shell.html
if ($LASTEXITCODE -eq 0) { Write-Host "Done. Serve with: python -m http.server -d build_web 8080" }
