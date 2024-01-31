#pragma once
#include "myBaseScene.h"
#include "Player.h"
#include "Enemy.h"

const int enemyMAX = 8;

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

	int enemyCount_;
};

