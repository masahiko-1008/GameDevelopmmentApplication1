#pragma once

#include"../Objects/GameObject.h"
#include <vector>

class Scene
{
private:
	std::vector<GameObject*>objects;   //�I�u�W�F�N�g���X�g

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	//�����蔻��`�F�b�N����
	void HitCheckObject(GameObject* a, GameObject* b);

	//�I�u�W�F�N�g��������
	template <class T>

	T* CreateObject(const Vector2D& location)
	{
		//�w�肵���N���X�̃I�u�W�F�N�g�𐶐�����
		T* new_instance = new T();

		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("GameObject�������ł��܂���ł����B\n");
		}

		//����������
		new_object->Initialize();

		//�ʒu���̐ݒ�
		new_object->SetLocation(location);

		//�V�[���ɑ��݂���I�u�W�F�N�g���X�g�ɒǉ�
		objects.push_back(new_object);

		//���������I�u�W�F�N�g�̃|�C���^��ԋp
		return new_instance;
	}
};
