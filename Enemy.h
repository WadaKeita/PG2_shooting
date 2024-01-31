#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();
	~Enemy();
	void Move()override;
	void Draw()override;

private:


};

