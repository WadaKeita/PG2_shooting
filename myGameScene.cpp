#include "myGameScene.h"
#include "Novice.h"
#include "random.h"
#include "math.h"

myGameScene::myGameScene() {

	nextScene_ = 1;

	enemyCount_ = 0;

	player = new Player();
	for (int i = 0; i < enemyMAX; i++) {
		enemy[i] = new Enemy();
	}

	for (int i = 0; i < enemyMAX; i++) {
		enemy[i]->SetIsAlive(true);
		enemyCount_++;

		enemy[i]->SetPos({ float(GetRand() % 720),float(GetRand() % (720)) });

		for (int j = 0; j < 100; j++) {

			if (enemy[i]->GetPos().x_ >= 720 / 2.0f - 50 && enemy[i]->GetPos().x_ <= 720 / 2.0f + 50 &&
				enemy[i]->GetPos().y_ >= 720 / 2.0f - 50 && enemy[i]->GetPos().y_ <= 720 / 2.0f + 50) {

				enemy[i]->SetPos({ float(GetRand() % 720),float(GetRand() % (720)) });
			}
			else {
				break;
			}
		}

		for (int j = 0; j < 100; j++) {

			if (enemy[i]->GetSpeed().x_ == 0 || enemy[i]->GetSpeed().y_ == 0) {
				enemy[i]->SetSpeed({ float(GetRand() % 3 - 1),float(GetRand() % 3 - 1) });
			}
			else {
				break;
			}
		}
	}


}

myGameScene::~myGameScene() {
	delete player;
	for (int i = 0; i < enemyMAX; i++) {
		delete enemy[i];
	}
}

void myGameScene::Update(char* keys, char* preKeys) {

	if (enemyCount_ > 0) {
		player->Move(keys, preKeys);

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
	}else if (enemyCount_ <= 0) {

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nextScene_ = 2;
		}
	}


}

void myGameScene::Draw() {

	for (int i = 0; i < enemyMAX; i++) {
		enemy[i]->Draw();
	}
	player->Draw();

	if (enemyCount_ <= 0) {

		Novice::ScreenPrintf(0, 20, "Clear");
	}


	Novice::ScreenPrintf(0, 0, "Game");
}