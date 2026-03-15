#ifndef POLYGONCOLLISION_H
#define POLYGONCOLLISION_H

#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>
#include <cfloat>

inline void ProjectPolygon(const std::vector<Vector2>& verts, Vector2 axis, float& outMin, float& outMax)
{
    outMin = outMax = Vector2DotProduct(verts[0], axis);
    for (size_t i = 1; i < verts.size(); i++)
    {
        float proj = Vector2DotProduct(verts[i], axis);
        if (proj < outMin) outMin = proj;
        if (proj > outMax) outMax = proj;
    }
}

inline bool CheckPolygonCollision(const std::vector<Vector2>& polyA, const std::vector<Vector2>& polyB)
{
    if (polyA.size() < 2 || polyB.size() < 2) return false;

    auto testEdges = [&](const std::vector<Vector2>& poly) -> bool
    {
        size_t n = poly.size();
        for (size_t i = 0; i < n; i++)
        {
            Vector2 edge = Vector2Subtract(poly[(i + 1) % n], poly[i]);
            Vector2 axis = Vector2Normalize({ -edge.y, edge.x });

            float minA, maxA, minB, maxB;
            ProjectPolygon(polyA, axis, minA, maxA);
            ProjectPolygon(polyB, axis, minB, maxB);

            if (maxA < minB || maxB < minA)
                return false;
        }
        return true;
    };

    if (!testEdges(polyA)) return false;
    if (!testEdges(polyB)) return false;
    return true;
}

inline std::vector<Vector2> BuildRegularPolygon(Vector2 center, float radius, int sides, float angleDeg = 0.0f)
{
    std::vector<Vector2> verts;
    verts.reserve(sides);
    float step = 360.0f / sides;
    for (int i = 0; i < sides; i++)
    {
        float rad = (angleDeg + step * i) * DEG2RAD;
        verts.push_back({ center.x + cosf(rad) * radius, center.y + sinf(rad) * radius });
    }
    return verts;
}

inline std::vector<Vector2> TransformVertices(const std::vector<Vector2>& local, Vector2 center, float angleDeg)
{
    std::vector<Vector2> world;
    world.reserve(local.size());
    float rad = angleDeg * DEG2RAD;
    float c = cosf(rad), s = sinf(rad);
    for (auto& v : local)
    {
        world.push_back({
            center.x + v.x * c - v.y * s,
            center.y + v.x * s + v.y * c
        });
    }
    return world;
}

#endif
