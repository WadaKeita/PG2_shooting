#include "EnemySpawn.h"

#include "Random.h"
#include "Novice.h"

EnemySpawn::EnemySpawn() {
	pos_ = { 0, 0 };
	MAX_HP_ = 20;
	HP_ = 20;
	radius_ = 32;
	spawnTime_ = 0;
	spawnTimer_ = 0;
	isSpawn_ = false;
	isAlive_ = true;

}

EnemySpawn::~EnemySpawn() {

}

void EnemySpawn::Move() {

	if (isAlive_ == true) {
		if (spawnTimer_ < spawnTime_) {
			spawnTimer_++;
		}
		else if (spawnTimer_ >= spawnTime_) {

			spawnTimer_ = 0;
			spawnTime_ = (GetRand() % 120 + 300);

			isSpawn_ = true;
		}
	}
}

void EnemySpawn::Draw() {

	if (isAlive_ == true) {
		Novice::DrawEllipse(int(pos_.x_), int(pos_.y_), int(radius_), int(radius_), 0, 0x606060FF, kFillModeSolid);

		if (pos_.y_ < 720 / 2) {
			Novice::DrawBox(int(pos_.x_ - 50), int(pos_.y_ - 50 - 6), 100, 12, 0, 0x606060FF, kFillModeSolid);
			Novice::DrawBox(int(pos_.x_ - 50), int(pos_.y_ - 50 - 6), int(100 * (float(HP_) / float(MAX_HP_))), 12, 0, 0x00CD32FF, kFillModeSolid);
		}
		else {
			Novice::DrawBox(int(pos_.x_ - 50), int(pos_.y_ + 50 - 6), 100, 12, 0, 0x606060FF, kFillModeSolid);
			Novice::DrawBox(int(pos_.x_ - 50), int(pos_.y_ + 50 - 6), int(100 * (float(HP_) / float(MAX_HP_))), 12, 0, 0x00CD32FF, kFillModeSolid);
		}
	}
}

void EnemySpawn::SetPos(Vector2 pos) {
	pos_ = pos;
}

void EnemySpawn::SetIsSpawn(bool isSpawn) {
	isSpawn_ = isSpawn;
}

void EnemySpawn::SetSpawnTime(int spawnTime) {
	spawnTime_ = spawnTime;
}

void EnemySpawn::SetIsAlive(bool isAlive) {
	isAlive_ = isAlive;
}

void EnemySpawn::SetHP(int HP) {
	HP_ = HP;
}