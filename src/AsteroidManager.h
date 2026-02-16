#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"

class AsteroidManager
{
    public:
        std::vector<Asteroid> asteroids;

        AsteroidManager();

        void Update();
        void PlayerToAsteroidCollision(Player player);
};