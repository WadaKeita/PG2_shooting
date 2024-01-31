#pragma once
#include "myBaseScene.h"
class SceneManager
{
public:
	enum SCENE {
		kTITLE,
		kGAME,
		kRESULT,
	};

	SceneManager();
	~SceneManager();
	
	void ChangeScene(SCENE scene);
	void Update(char*keys,char*preKeys);
	void Render();

private:
	static BaseScene* currentScene;

	int changeTime;
	int changeTimer;

	SCENE nextScene;
	SCENE nowScene;
};

