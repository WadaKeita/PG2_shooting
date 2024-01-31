#pragma once
class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	virtual void Update(char* keys, char* preKeys);
	virtual void Draw();

	int SwitchScene() { return nextScene_; }

	int nextScene_;
};

