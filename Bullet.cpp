#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {

	pos_ = { 0,0 };
	velocity_ = { 0,0 };
	acceleration_ = { 0,0 };
	speed_ = { 5,5 };
	radius_ = 8;
	isAlive_ = false;

};

Bullet::~Bullet() {
};

void Bullet::Move() {

	if (isAlive_ == true) {
		pos_ += velocity_;
	}

	if (pos_.x_ >= 720 + radius_) {
		isAlive_ = false;
	}
	if (pos_.y_ >= 720 + radius_) {
		isAlive_ = false;
	}
	if (pos_.x_ <= -radius_) {
		isAlive_ = false;
	}
	if (pos_.y_ <= -radius_) {
		isAlive_ = false;
	}
};

void Bullet::Draw() {

	if (isAlive_ == true) {

		Novice::DrawEllipse(int(pos_.x_), int(pos_.y_), int(radius_), int(radius_), 0, 0xFF0000FF, kFillModeSolid);

	}

};
