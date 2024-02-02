#include "myTitleScene.h"
#include "Novice.h"
#include "mySceneManager.h"

TitleScene::TitleScene() {
	nextScene_ = 0;
}

TitleScene::~TitleScene() {

}

void TitleScene::Update(char* keys, char* preKeys) {
	
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		nextScene_ = 1;
	}

}

void TitleScene::Draw() {

	Novice::ScreenPrintf(0, 0, "TitleScene");

	Novice::ScreenPrintf(720 / 2 - 10 * 10 + 5, 720 / 2 - 10, "   start to SPACE    ");
}