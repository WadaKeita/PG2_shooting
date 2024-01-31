#pragma once
#include "myBaseScene.h"
class TitleScene :public BaseScene
{
public:
	TitleScene();
	~TitleScene();	
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

private:


};

