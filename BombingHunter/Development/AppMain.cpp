#include "DxLib.h"

//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_
	int ii)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[�I��
		return -1;
	}

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//��ʂ̏�����
		ClearDrawScreen();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}
	//DX���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}