#include "myResultScene.h"
#include "Novice.h"

ResultScene::ResultScene() {

	nextScene_ = 2;
}

ResultScene::~ResultScene() {

}

void ResultScene::Update(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		nextScene_ = 0;
	}
}

void ResultScene::Draw() {

	Novice::ScreenPrintf(0, 0, "Result");
}