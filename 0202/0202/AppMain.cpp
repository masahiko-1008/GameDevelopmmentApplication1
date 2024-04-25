#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLone, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[�I��
		return -1;
	}

	//�������[�擾
	SetDrawScreen(DX_SCREEN_BACK);

	GameObject* object1 = new GameObject();
	Player* object2 = new Player();

	object1->Initialize();
	object2->Initialize();

	//�Q�[�����[�v
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE)==
false)
	{
		//�X�V����
		InputControl::Update();

		object1->Update();
		object2->Update();

		//��ʂ̏�����
		ClearDrawScreen();

		//�`�揈��
		object1->Draw();
		object2->Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}

	//�������[�̉��
	delete object1;
	delete object2;

	//DX���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}