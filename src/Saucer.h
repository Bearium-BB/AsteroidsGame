#ifndef SAUCER_H
#define SAUCER_H

#include <vector>
#include "raylib.h"
#include "Actor.h"
#include "Asteroid.h"
#include "Player.h"
#include "PolygonCollision.h"

class Saucer : public Actor
{
public:
    float dt;
    float size;
    float timeToShoot = 3.0f;

    float minSize = 10.0f;
    float maxSize = 100.0f;

    float minSpread = 1.0f;
    float maxSpread = 15.0f;

    bool smallSaucerImproveAim = false;

    Player*        player;
    BulletManager* bulletManager;

    Saucer();
    Saucer(Player* currentPlayer, BulletManager* bulletManagerTest);
    Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim);
    Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim, float sizeSaucer);

    void Update();
    void Draw();
    void Wrapping();

    // Returns a hexagon polygon in world space
    std::vector<Vector2> GetWorldVertices() const override;
};

#endif
