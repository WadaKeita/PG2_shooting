#include "Vector2d.h"


Vector2::Vector2(float x, float y) {
	x_ = x;
	y_ = y;
}

Vector2::~Vector2() {

}

Vector2::Vector2(const Vector2& obj) {
	x_ = obj.x_;
	y_ = obj.y_;
}

const Vector2 &Vector2::operator=(const Vector2& obj){
	x_ = obj.x_;
	y_ = obj.y_;

	return *this;
}

const Vector2 Vector2::operator+(const Vector2& obj)const {
	Vector2 vec2{ 0,0 };

	vec2.x_ = x_ + obj.x_;
	vec2.y_ = y_ + obj.y_;

	return vec2;
}

const Vector2 Vector2::operator-(const Vector2& obj)const {
	Vector2 vec2{ 0,0 };

	vec2.x_ = x_ - obj.x_;
	vec2.y_ = y_ - obj.y_;

	return vec2;
}

const Vector2 Vector2::operator*(const Vector2& obj)const {
	Vector2 vec2{ 0,0 };

	vec2.x_ = x_ * obj.x_;
	vec2.y_ = y_ * obj.y_;

	return vec2;
}

const Vector2 Vector2::operator/(const Vector2& obj)const {
	Vector2 vec2{ 0,0 };

	vec2.x_ = x_ / obj.x_;
	vec2.y_ = y_ / obj.y_;

	return vec2;
}

const void Vector2::operator+=(const Vector2& obj) {

	x_ += obj.x_;
	y_ += obj.y_;
}

const void Vector2::operator-=(const Vector2& obj) {

	x_ -= obj.x_;
	y_ -= obj.y_;
}

const void Vector2::operator*=(const Vector2& obj) {

	x_ *= obj.x_;
	y_ *= obj.y_;
}

const void Vector2::operator/=(const Vector2& obj) {

	x_ /= obj.x_;
	y_ /= obj.y_;
}

bool Vector2::operator==(const Vector2& obj) {
	return x_ == obj.x_ && y_ == obj.y_;
}

bool Vector2::operator!=(const Vector2& obj) {
	return x_ != obj.x_ || y_ != obj.y_;
}