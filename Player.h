#pragma once
#include "Bullet.h"

const int bulletMax_ = 8;

class Player : public Object
{
public:
	Player();
	~Player();

	void Move(char* keys, char* preKeys);
	void Draw() override;

	Vector2 GetDirection() { return direction_; }
	void SetDirection(Vector2 direction);

	Bullet* bullet_[bulletMax_];

private:
	Vector2 direction_;
	Vector2 tmpDirection_;
};

