#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"

//�v���O�����J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLone, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[�I��
		return -1;
	}

	//�������[�擾
	Player* player = new Player();

	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//�X�V����
		InputControl::Update();

		player->Update();

		//�ʒu���W�擾
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

		//��ʂ̏�����
		ClearDrawScreen();

		//�`�揈��
		player->Draw();

		//����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//�������[�̉��
	delete player;

	//DX���C�u�����g�p�̏I������
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}