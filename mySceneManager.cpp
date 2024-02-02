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
	color_ = 0x00000000;
}

SceneManager::~SceneManager() {

}

void SceneManager::ChangeScene(SCENE scene) {

	result_ = currentScene->GetResult();

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
		currentScene->SetResult(result_);
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

	Draw();
}

void SceneManager::SceneTransition() {

	nextScene = SCENE(currentScene->GetNextScene());
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
			color_ = 0x00000000;
		}
		else {
			if (transitionTimer > transitionTime / 2) {
				color_ -= 0x000000FF / (transitionTime / 2);
			}
			else {
				color_ += 0x000000FF / (transitionTime / 2);
			}
		}
	}
}