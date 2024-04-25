#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

//プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_
	int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラー終了
		return -1;
	}

	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject();
	objects[1] = new Player();

	for (int i = 0; i < 0; i++)
	{
		objects[i]->Initialize();
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		InputControl::Update();

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}

		//画面の初期化
		ClearDrawScreen();

		//裏画面の内容を表画面に反映
		ScreenFlip();

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];
	}

	//DXライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}