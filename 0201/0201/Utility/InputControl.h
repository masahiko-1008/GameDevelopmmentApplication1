#pragma once

#define D_KEYCODE_MAX (256)

//InputControlƒNƒ‰ƒX‚ÌéŒ¾
class InputControl
{
//•Ï”éŒ¾
private:
	static char now_key[D_KEYCODE_MAX];
	static char old_key[D_KEYCODE_MAX];

//ŠÖ”éŒ¾
public:
	static void Update();

	static bool GetKey(int key_code);
	static bool GetKeyDown(int key_code);
	static bool GetKeyUp(int key_code);

private:
	static bool CheckKeyCodeRange(int key_code);
};

