#pragma once
#include "myBaseScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawn.h"

const int enemyMAX = 20;
const int spawnMAX = 4;

class myGameScene : public BaseScene
{
public:
	myGameScene();
	~myGameScene();
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:
	Player* player;
	Enemy* enemy[enemyMAX];
	EnemySpawn* enemySpawn[spawnMAX];

	int enemyCount_;
};

