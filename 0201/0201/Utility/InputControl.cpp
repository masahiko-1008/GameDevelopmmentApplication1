#include "InputControl.h"
#include "DxLib.h"

//���݂̃L�[���
char InputControl::now_key[D_KEYCODE_MAX] = {};

//�O��̃L�[���
char InputControl::old_key[D_KEYCODE_MAX] = {};

//�X�V����
void InputControl::Update()
{
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	GetHitKeyStateAll(now_key);
}

//�L�[�擾����(�������u��)
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}

//�L�[�擾����(����������)
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}

//�L�[�擾����(�������u��)
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}

//���͒l�̏���
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}