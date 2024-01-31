#pragma once
class BaseScene
{
public:
	virtual void Update(char* keys, char* preKeys);
	virtual void Draw();

	int SwitchScene() { return nextScene_; }

	int nextScene_;
};

