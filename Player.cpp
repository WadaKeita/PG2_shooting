#include "Player.h"
#include "Novice.h"
#include "math.h"

Player::Player() {

	for (int i = 0; i < bulletMax_; i++) {
		bullet_[i] = new Bullet();
	}

	pos_.x_ = 720 / 2.0f;
	pos_.y_ = 720 / 2.0f;
	radius_ = 16;
	speed_ = { 2,2 };
	isAlive_ = true;
	direction_ = { 0,-1 };
	tmpDirection_ = { 0,-1 };
};

Player::~Player() {

	for (int i = 0; i < bulletMax_; i++) {
		delete bullet_[i];
	}

};

void Player::Move(char* keys, char* preKeys) {

	if (isAlive_ == true) {


		tmpDirection_ = { 0,0 };
		if (keys[DIK_W]) {

			tmpDirection_ += { 0, -1 };
		}
		if (keys[DIK_A]) {

			tmpDirection_ += { -1, 0 };
		}
		if (keys[DIK_S]) {

			tmpDirection_ += { 0, 1 };
		}
		if (keys[DIK_D]) {

			tmpDirection_ += { 1, 0 };
		}


		length_ = sqrtf(tmpDirection_.x_ * tmpDirection_.x_ + tmpDirection_.y_ * tmpDirection_.y_);
		if (length_ != 0.0f) {
			tmpDirection_.x_ = (tmpDirection_.x_ / length_);
			tmpDirection_.y_ = (tmpDirection_.y_ / length_);
		}

		if (tmpDirection_ != (0.0f, 0.0f)) {
			direction_ = tmpDirection_;
		}

		velocity_ = tmpDirection_ * speed_;

		pos_ += velocity_;

		if (pos_.x_ <= radius_) {
			pos_.x_ = radius_;
		}
		if (pos_.y_ <= radius_) {
			pos_.y_ = radius_;
		}
		if (pos_.x_ >= 720 - radius_) {
			pos_.x_ = 720 - radius_;
		}
		if (pos_.y_ >= 720 - radius_) {
			pos_.y_ = 720 - radius_;
		}

		Attack(keys, preKeys);

		for (int i = 0; i < bulletMax_; i++) {

			bullet_[i]->Move();

		}
	}
}

void Player::Attack(char* keys, char* preKeys) {

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

		for (int i = 0; i < bulletMax_; i++) {

			if (bullet_[i]->GetIsAlive() == false) {

				bullet_[i]->SetVelocity(direction_ * bullet_[i]->GetSpeed());

				bullet_[i]->SetIsAlive(true);
				bullet_[i]->SetPos(pos_);

				break;
			}
		}
	}
}

void Player::Draw() {

	for (int i = 0; i < bulletMax_; i++) {

		bullet_[i]->Draw();

	}

	if (isAlive_ == true) {
		Novice::DrawEllipse(int(pos_.x_), int(pos_.y_), int(radius_), int(radius_), 0, BLUE, kFillModeSolid);
	}
}

void Player::SetDirection(Vector2 direction) {
	direction_ = direction;
}