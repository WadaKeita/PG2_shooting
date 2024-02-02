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
	void Draw();
	void Render();
	void SceneTransition();

private:
	static BaseScene* currentScene;

	int transitionTime;
	int transitionTimer;
	bool isTransition;

	unsigned int color_;

	SCENE nextScene;
	SCENE nowScene;
};

