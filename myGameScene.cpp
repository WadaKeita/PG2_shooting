#include "myGameScene.h"
#include "Novice.h"
#include "random.h"
#include "math.h"

myGameScene::myGameScene() {

	nextScene_ = 1;

	enemyCount_ = 0;

	player = new Player();

	// -------------------------------------------------- Enemy -------------------------------------------------- //
	for (int i = 0; i < enemyMAX; i++) {
		enemy[i] = new Enemy();
	}

	for (int i = 0; i < 8; i++) {
		enemy[i]->SetIsAlive(true);
		enemyCount_++;

		enemy[i]->SetPos({ float(GetRand() % 720),float(GetRand() % (720)) });

		for (int j = 0; j < 100; j++) {


			if (enemy[i]->GetPos().x_ >= 720 / 2.0f - 50 && enemy[i]->GetPos().x_ <= 720 / 2.0f + 50 &&
				enemy[i]->GetPos().y_ >= 720 / 2.0f - 50 && enemy[i]->GetPos().y_ <= 720 / 2.0f + 50) {

				enemy[i]->SetPos({ float(GetRand() % 720),float(GetRand() % 720) });
			}
			else {
				break;
			}
		}

		for (int j = 0; j < 100; j++) {


			if (enemy[i]->GetVelocity().x_ == 0 || enemy[i]->GetVelocity().y_ == 0) {
				enemy[i]->distance_.x_ = enemy[i]->GetPos().x_ + float(GetRand() % 32 - 16);
				enemy[i]->distance_.y_ = enemy[i]->GetPos().y_ + float(GetRand() % 32 - 16);

				enemy[i]->distance_.x_ = enemy[i]->distance_.x_ - enemy[i]->GetPos().x_;
				enemy[i]->distance_.y_ = enemy[i]->distance_.y_ - enemy[i]->GetPos().y_;
				enemy[i]->length_ = sqrtf(enemy[i]->distance_.x_ * enemy[i]->distance_.x_ + enemy[i]->distance_.y_ * enemy[i]->distance_.y_);

				if (enemy[i]->length_ != 0.0f) {
					enemy[i]->distance_.x_ = enemy[i]->distance_.x_ / enemy[i]->length_ * enemy[i]->GetSpeed().x_;
					enemy[i]->distance_.y_ = enemy[i]->distance_.y_ / enemy[i]->length_ * enemy[i]->GetSpeed().y_;
				}
				enemy[i]->SetVelocity({enemy[i]->distance_.x_, enemy[i]->distance_.y_});
			}
			else {
				break;
			}
		}
	}
	// -------------------------------------------------- EnemySpawn -------------------------------------------------- //

	for (int i = 0; i < spawnMAX; i++) {
		enemySpawn[i] = new EnemySpawn();
		enemySpawn[i]->SetSpawnTime((GetRand() % 120 + 300));

		enemyCount_++;
	}

	enemySpawn[0]->SetPos({ 720 / 5.0f, 720 / 5.0f });
	enemySpawn[1]->SetPos({ 720 / 5.0f * 4, 720 / 5.0f });
	enemySpawn[2]->SetPos({ 720 / 5.0f, 720 / 5.0f * 4 });
	enemySpawn[3]->SetPos({ 720 / 5.0f * 4, 720 / 5.0f * 4 });

	// --------------------------------------------------------------------------------------------------------- //

}

myGameScene::~myGameScene() {
	delete player;
	for (int i = 0; i < enemyMAX; i++) {
		delete enemy[i];
	}
	for (int i = 0; i < spawnMAX; i++) {
		delete enemySpawn[i];
	}
}

void myGameScene::Update(char* keys, char* preKeys) {

	if (enemyCount_ > 0) {
		player->Move(keys, preKeys);


		for (int i = 0; i < spawnMAX; i++) {
			enemySpawn[i]->Move();

			if (enemySpawn[i]->GetIsSpawn() == true) {
				enemySpawn[i]->SetIsSpawn(false);

				for (int j = 0; j < enemyMAX; j++) {

					if (enemy[j]->GetIsAlive() == false) {

						enemyCount_++;

						enemy[j]->SetIsAlive(true);

						enemy[j]->SetPos(enemySpawn[i]->GetPos());

						for (int k = 0; k < 100; k++) {

							if (enemy[j]->GetVelocity().x_ == 0 || enemy[j]->GetVelocity().y_ == 0) {
								enemy[j]->distance_.x_ = enemy[j]->GetPos().x_ + float(GetRand() % 32 - 16);
								enemy[j]->distance_.y_ = enemy[j]->GetPos().y_ + float(GetRand() % 32 - 16);

								enemy[j]->distance_.x_ = enemy[j]->distance_.x_ - enemy[j]->GetPos().x_;
								enemy[j]->distance_.y_ = enemy[j]->distance_.y_ - enemy[j]->GetPos().y_;
								enemy[j]->length_ = sqrtf(enemy[j]->distance_.x_ * enemy[j]->distance_.x_ + enemy[j]->distance_.y_ * enemy[j]->distance_.y_);

								if (enemy[j]->length_ != 0.0f) {
									enemy[j]->distance_.x_ = enemy[j]->distance_.x_ / enemy[j]->length_ * enemy[j]->GetSpeed().x_;
									enemy[j]->distance_.y_ = enemy[j]->distance_.y_ / enemy[j]->length_ * enemy[j]->GetSpeed().y_;
								}
								enemy[j]->SetVelocity({ enemy[j]->distance_.x_, enemy[j]->distance_.y_ });
							}
							else {
								break;
							}
						}

						break;
					}
				}
			}
		}



		for (int i = 0; i < enemyMAX; i++) {
			enemy[i]->Move();
		}

		// 当たり判定
		for (int i = 0; i < enemyMAX; i++) {

			if (enemy[i]->GetIsAlive() == true) {

				for (int j = 0; j < bulletMax_; j++) {

					if (player->bullet_[j]->GetIsAlive() == true) {

						Vector2 distance = enemy[i]->GetPos() - player->bullet_[j]->GetPos();
						float distance_c = sqrtf(distance.x_ * distance.x_ + distance.y_ * distance.y_);

						if (distance_c <= enemy[i]->GetRadius() + player->bullet_[j]->GetRadius()) {
							enemy[i]->SetIsAlive(false);
							enemyCount_--;
							player->bullet_[j]->SetIsAlive(false);
						}
					}
				}
			}
		}

		for (int i = 0; i < spawnMAX; i++){
			
			if (enemySpawn[i]->GetIsAlive() == true) {

				for (int j = 0; j < bulletMax_; j++) {

					if (player->bullet_[j]->GetIsAlive() == true) {

						player->bullet_[j]->distance_ = enemySpawn[i]->GetPos() - player->bullet_[j]->GetPos();
						player->bullet_[j]->length_ = sqrtf(player->bullet_[j]->distance_.x_ * player->bullet_[j]->distance_.x_ + player->bullet_[j]->distance_.y_ * player->bullet_[j]->distance_.y_);

						if (player->bullet_[j]->length_ < enemySpawn[i]->GetRadius() + player->bullet_[j]->GetRadius()) {
							player->bullet_[j]->SetIsAlive(false);

							if (enemySpawn[i]->GetHP() > 0) {
								enemySpawn[i]->SetHP(enemySpawn[i]->GetHP() - 1);
							}
							if (enemySpawn[i]->GetHP() <= 0) {
								enemySpawn[i]->SetIsAlive(false);
								enemyCount_--;
							}
						}
					}
				}
			}
		}

	}
	else if (enemyCount_ <= 0) {

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nextScene_ = 2;
		}
	}


}

void myGameScene::Draw() {

	for (int i = 0; i < spawnMAX; i++) {
		enemySpawn[i]->Draw();
	}

	for (int i = 0; i < enemyMAX; i++) {
		enemy[i]->Draw();
	}
	player->Draw();

	if (enemyCount_ <= 0) {

		Novice::ScreenPrintf(0, 20, "Clear");
	}


	Novice::ScreenPrintf(0, 0, "Game");
}