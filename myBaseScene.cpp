#include "myBaseScene.h"

BaseScene::BaseScene() {
	nextScene_ = 0;
}

BaseScene::~BaseScene() {

}

void BaseScene::Update(char* keys, char* preKeys) {
	keys = 0;
	preKeys = 0;
};

void BaseScene::Draw() {
	
};

