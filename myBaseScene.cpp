#include "myBaseScene.h"

BaseScene::BaseScene() {
	nextScene_ = 0;
	result_ = kERROR;
}

BaseScene::~BaseScene() {

}

void BaseScene::Update(char* keys, char* preKeys) {
	keys = 0;
	preKeys = 0;
};

void BaseScene::Draw() {
	
};

void BaseScene::SetResult(int result) {

	result_ = RESULT(result);
}