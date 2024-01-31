#pragma once
#include "Vector2d.h"

class EnemySpawn
{
public:
	EnemySpawn();
	~EnemySpawn();

	void Move();
	void Draw();

	Vector2 GetPos() { return pos_; }
	void SetPos(Vector2 pos);

	bool GetIsSpawn() { return isSpawn_; }
	void SetIsSpawn(bool isSpawn);

	void SetSpawnTime(int spawnTime);

	bool GetIsAlive() { return isAlive_; }
	void SetIsAlive(bool isAlive);

	float GetRadius() { return radius_; }

	int GetHP() { return HP_; }
	void SetHP(int HP);


public:
	Vector2 pos_;
	float radius_;
	int HP_;
	int MAX_HP_;
	int spawnTime_;
	int spawnTimer_;
	bool isSpawn_;
	bool isAlive_;
};