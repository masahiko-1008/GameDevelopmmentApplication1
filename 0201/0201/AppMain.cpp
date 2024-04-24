#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

//プログラム開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLone, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラー終了
		return -1;
	}

	//メモリー取得
	Player* player = new Player();

	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//更新処理
		InputControl::Update();

		player->Update();

		//位置座標取得
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;
			}
			else
			{
				tmp.x = 0.0f;
			}
			player->SetLocation(tmp);
		}

		if (tmp.y < 0.0f || 480.0 < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;
			}
			else
			{
				tmp.y = 0.0f;
			}
		}

		player->SetLocation(tmp);

		//画面の初期化
		ClearDrawScreen();

		//描画処理
		player->Draw();

		//裏画面の内容を表画面に反映
		ScreenFlip();

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//メモリーの解放
	delete player;

	//DXライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}