#include "DxLib.h"

//プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_
	int ii)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラー終了
		return -1;
	}

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//画面の初期化
		ClearDrawScreen();

		//裏画面の内容を表画面に反映
		ScreenFlip();
	}
	//DXライブラリ使用の終了処理
	DxLib_End();

	//ソフトの終了
	return 0;
}