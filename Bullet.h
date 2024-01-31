#pragma once
#include "Vector2d.h"
#include "Object.h"

class Bullet : public Object
{
public:
	Bullet();
	~Bullet();
	void Move()override;
	void Draw()override;

private:
	bool isShot_;
};

