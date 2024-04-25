#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_
	int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[�I��
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

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		InputControl::Update();

		for (int i = 0; i < 2; i++)
		{
			objects[i]->Update();
		}

		//��ʂ̏�����
		ClearDrawScreen();

		//����ʂ̓��e��\��ʂɔ��f
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

	//DX���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}