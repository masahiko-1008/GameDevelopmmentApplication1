#pragma once

#define D_KEYCODE_MAX (256)  //�L�[���͍ő�l

//���͐���N���X(�����o�͐ÓI�ŏ��L����)
class InputControl
{
	//��{�I�Ƀ����o�ϐ��̓v���C�x�[�g
private:
	static char now_key[D_KEYCODE_MAX];   //���݂̓��͒l
	static char old_key[D_KEYCODE_MAX];   //�O��̓��͒l

	//�֐��̓p�u���b�N
public:
	static void Update();           //�X�V����

	//�L�[���͎擾�n
	static bool GetKey(int key_code);      //���������Ă��邩?
	static bool GetKeyDown(int key_code);  //�������u�Ԃ�?
	static bool GetKeyUp(int key_code);    //�������u�Ԃ�?

	//�O�����J�̕K�v����������΁A�v���C�x�[�g
private:
	static bool CheckKeyCodeRange(int key_code);   //�L�[�R�[�h�͈̓`�F�b�N
};

