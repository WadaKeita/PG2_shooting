#include "mySceneManager.h"
#include "myTitleScene.h"
#include "myGameScene.h"
#include "myResultScene.h"
#include "Novice.h"

BaseScene* SceneManager::currentScene = nullptr;

SceneManager::SceneManager() {
	currentScene = new TitleScene;
	nowScene = kTITLE;
	nextScene = kTITLE;
	transitionTime = 100;
	transitionTimer = 0;
	isTransition = false;
}

SceneManager::~SceneManager() {

}

void SceneManager::ChangeScene(SCENE scene) {

	if (currentScene != nullptr) {
		delete currentScene;
	}

	switch (scene) {
	case kTITLE:
		currentScene = new TitleScene();
		break;

	case kGAME:
		currentScene = new myGameScene();
		break;

	case kRESULT:
		currentScene = new ResultScene();
		break;

	default:
		break;
	}

}

void SceneManager::Update(char* keys, char* preKeys) {

	SceneTransition();	

	if (currentScene != nullptr) {

		if (isTransition == false) {
			currentScene->Update(keys, preKeys);
		}

	}
}

void SceneManager::Draw() {

	Novice::DrawBox(0, 0, 720, 720, 0, color_, kFillModeSolid);

}

void SceneManager::Render() {

	if (currentScene != nullptr) {
		currentScene->Draw();
	}
}

void SceneManager::SceneTransition() {

	nextScene = SCENE(currentScene->SwitchScene());
	if (nowScene != nextScene) {

		isTransition = true;
		transitionTimer++;
		if (transitionTimer == transitionTime / 2) {

			ChangeScene(nextScene);

		}


		if (transitionTimer >= transitionTime) {

			transitionTimer = 0;
			nowScene = nextScene;
			isTransition = false;
		}
		else {
			color_ -= 
		}
	}
}