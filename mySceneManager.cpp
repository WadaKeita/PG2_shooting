#include "mySceneManager.h"
#include "myTitleScene.h"
#include "myGameScene.h"
#include "myResultScene.h"
#include "stdio.h"
#include "Novice.h"

BaseScene* SceneManager::currentScene = NULL;

SceneManager::SceneManager() {
	currentScene = new TitleScene;
	nowScene = kTITLE;
	nextScene = kTITLE;
}

SceneManager::~SceneManager() {

}

void SceneManager::ChangeScene(SCENE scene) {

	if (currentScene != NULL) {
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


	nextScene = SCENE(currentScene->SwitchScene());
	if (nowScene != nextScene) {
		ChangeScene(nextScene);
		nowScene = nextScene;
	}


	if (keys[DIK_1] && preKeys[DIK_1] == false) {
		ChangeScene(kTITLE);
		nowScene = kTITLE;
	}
	else if (keys[DIK_2] && preKeys[DIK_2] == false) {
		ChangeScene(kGAME);
		nowScene = kGAME;
	}
	else if (keys[DIK_3] && preKeys[DIK_3] == false) {
		ChangeScene(kRESULT);
		nowScene = kRESULT;
	}

	if (currentScene != NULL) {
		currentScene->Update(keys,preKeys);
	}
}

void SceneManager::Render() {

	if (currentScene != NULL) {
		currentScene->Draw();
	}
}