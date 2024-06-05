#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//���C���֐�(�v���O�����͂�������n�܂�܂��B)
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y(��:640px,�c:480px)��ݒ�
	SetGraphMode(920, 580, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}
	//�`���𗠉�ʂ���n�߂�悤�Ɏw�肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//���[�J���ϐ���`
	Scene* scene = new Scene();   //�V�[�����
	int result = 0;               //�I����ԏ��

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v(�X�V�ƕ`����s��)
		//ESC�L�[�������ꂽ��A���[�v���I������
		while (ProcessMessage() != -1 &&
			InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
		{
			//���͋@�\�̍X�V
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//�摜�̏�����
			ClearDrawScreen();

			//�V�[���̕`�揈��
			scene->Draw();

			//����ʂ̓��e��\��ʂɔ��f
			ScreenFlip();
		}
	}
	//�G���[�`�F�b�N
	catch (const char* error_log)
	{
		//�G���[����Log.txt�ɏo�͂���
		OutputDebugString(error_log);
		//�ُ��ԂɕύX����
		result = -1;
	}

	//�V�[����񂪑��݂��ē���΁A�폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	//DX���C�u�����̏I��������
	DxLib_End();

	//�I����Ԃ�ʒm
	return result;
}