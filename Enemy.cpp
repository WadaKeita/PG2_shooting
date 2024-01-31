#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy() {

	pos_ = { 0,0 };
	radius_ = 16;
	speed_ = { 0,0 };
	isAlive_ = false;
};

Enemy::~Enemy() {

}

void Enemy::Move() {

	if (isAlive_ == true) {
		velocity_ = speed_;

		pos_ += velocity_;

		if (pos_.x_ <= radius_) {
			speed_.x_ = -speed_.x_;
			pos_.x_ = radius_;
		}
		if (pos_.y_ <= radius_) {
			speed_.y_ = -speed_.y_;
			pos_.y_ = radius_;
		}
		if (pos_.x_ >= 720 - radius_) {
			speed_.x_ = -speed_.x_;
			pos_.x_ = 720 - radius_;
		}
		if (pos_.y_ >= 720 - radius_) {
			speed_.y_ = -speed_.y_;
			pos_.y_ = 720 - radius_;
		}

	}
}

void Enemy::Draw() {

	if (isAlive_ == true) {

		Novice::DrawEllipse(int(pos_.x_), int(pos_.y_), int(radius_), int(radius_), 0, 0xFFFFFFFF, kFillModeSolid);

	}
}