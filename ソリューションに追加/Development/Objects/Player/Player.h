#pragma once

#include "../GameObject.h"

class Player : public GameObject
{
private:
	int animation[2];        //�A�j���[�V�����摜
	int animation_count;     //�A�j���[�V��������
	int flip_flag;           //���]�t���O

public:
	Player();
	~Player();

	//����������
	virtual void Initialize() override;

	//�X�V����
	virtual void Update() override;

	//�`�揈��
	virtual void Draw() const override;

	//�I��������
	virtual void Finalize() override;

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();
};

