#include <Novice.h>
#include "mySceneManager.h"
#include <stdio.h>
#include <time.h>

const char kWindowTitle[] = "PG2_shooting_LC1A_28_ワダ_ケイタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	const int window_width = 720;
	const int window_height = 720;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, window_width, window_height);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	
	//randをリセット
	unsigned int currentTime = (unsigned)time(NULL);
	srand(currentTime);

	SceneManager* sceneManager = new SceneManager();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		sceneManager->Update(keys, preKeys);

		//player->pos_ += b;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		sceneManager->Render();


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
