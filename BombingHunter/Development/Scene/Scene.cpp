#include "Scene.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Enemy/BoxEnemy.h"
#include "../Objects/Enemy/WingEnemy.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Objects/Enemy/GoldEnemy.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#define D_PIVOT_CENTER

//�R���X�g���N�^
Scene::Scene() : objects(),BackGround_image(NULL), GetRandMax(0), freamcount(0)
{

}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(450.0f, 60.0f));

	//�w�i�摜
	BackGround_image = LoadGraph("Resource/Images/BackGround.png");

	//�G���[�`�F�b�N
	if (BackGround_image == -1)
	{
		throw("�w�i�̉摜������܂���\n");
	}
}

//�X�V����
void Scene::Update()
{
	//�I�u�W�F�N�g���X�g���̃I�u�W�F�N�g���X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//�����蔻��`�F�b�N����
			HitCheckObject(objects[i], objects[j]);
		}
	}

	//�t���[���J�E���g�����Z����
	freamcount++;

	//60�t���[���ڂɓ��B������
	if (freamcount >= 60)
	{
		//�J�E���g�̃��Z�b�g
		freamcount = 0;

		//�����_���ɓG�B���o������
		GetRandMax = GetRand(10);
		{
			//�n�R�e�L
			if (GetRandMax <= 2)
			{
				CreateObject<BoxEnemy>(Vector2D(90.0f, 610.0f));
			}

			//�n�l�e�L
			if (GetRandMax > 2  && GetRandMax <= 5)
			{
				CreateObject<WingEnemy>(Vector2D(90.0f, 270.0f));
			}

			//�n�[�s�[
			if (GetRandMax > 5 && GetRandMax <= 8)
			{
				CreateObject<Harpy>(Vector2D(90.0f, 400.0f));
			}

			//���e�L
			if (GetRandMax > 8  && GetRandMax <= 10)
			{
				CreateObject<GoldEnemy>(Vector2D(90.0f, 610.0f));
			}
		}
	}

}

//�`�揈��
void Scene::Draw() const
{   
	//�w�i�摜
	DrawGraph(0, 0, BackGround_image, TRUE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//�I��������
void Scene::Finalize()
{
	//���I�z�u����Ȃ珈�����������I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//���I�z�u�̉��
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N����(��`�̒��S�Ŕ�������)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else

//�����蔻��`�F�b�N����(���㒸�_�̍��W���瓖���蔻��v�Z���s��)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�㒸�_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->Getlocation().x) &&
		(a_lower_right.y > b->Getlocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollsion(b);
		b->OnHitCollsion(a);
	}
}

#endif // D_PIVOT_CNETER