#include "InputControl.h"
#include "DxLib.h"

//現在のキー情報
char InputControl::now_key[D_KEYCODE_MAX] = {};

//前回のキー情報
char InputControl::old_key[D_KEYCODE_MAX] = {};

//更新処理
void InputControl::Update()
{
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	GetHitKeyStateAll(now_key);
}

//キー取得処理(押した瞬間)
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}

//キー取得処理(押し続ける)
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}

//キー取得処理(離した瞬間)
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}

//入力値の処理
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}