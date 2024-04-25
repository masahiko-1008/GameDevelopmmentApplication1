#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

//プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLone, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラー終了
		return -1;
	}

	//メモリー取得
	SetDrawScreen(DX_SCREEN_BACK);

	GameObject* object1 = new GameObject();
	Player* object2 = new Player();

	object1->Initialize();
	object2->Initialize();

	//ゲームループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE)==
false)
	{
		//更新処理
		InputControl::Update();

		object1->Update();
		object2->Update();

		//画面の初期化
		ClearDrawScreen();

		//描画処理
		object1->Draw();
		object2->Draw();

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}

	//メモリーの解放
	delete object1;
	delete object2;

	//DXライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}