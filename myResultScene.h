#pragma once
#include "myBaseScene.h"
class ResultScene :
    public BaseScene
{
public:

	ResultScene();
	~ResultScene();
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:

};

