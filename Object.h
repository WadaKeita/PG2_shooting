#pragma once
#include "Vector2d.h"

class Object
{

protected:
	Vector2 pos_;
	Vector2 velocity_;
	Vector2 acceleration_;
	Vector2 speed_;
	float radius_;
	bool isAlive_;

public:
	virtual void Move();
	virtual void Draw();
	
	Vector2 GetPos() { return pos_; }
	void SetPos(Vector2 vec2);

	bool GetIsAlive() { return isAlive_; }
	void SetIsAlive(bool isAlive);

	Vector2 GetSpeed() { return speed_; }
	void SetSpeed(Vector2 speed);

	float GetRadius() { return radius_; }
	void SetRadius(float radius);

	Vector2 GetVelocity() { return velocity_; }
	void SetVelocity(Vector2 velocity);
};

