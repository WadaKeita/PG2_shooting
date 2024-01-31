#include "Object.h"

void Object::Move() {

}

void Object::Draw() {

}

void Object::SetPos(Vector2 vec2) {
	pos_ = vec2;
}

void Object::SetIsAlive(bool isAlive) {
	isAlive_ = isAlive;
}

void Object::SetSpeed(Vector2 speed) {
	speed_ = speed;
}

void Object::SetRadius(float radius) {
	radius_ = radius;
}

void Object::SetVelocity(Vector2 velocity) {
	velocity_ = velocity;
}
