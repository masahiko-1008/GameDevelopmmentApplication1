#pragma once

#include "GameObject.h"

//Player�N���X�̐錾
class Player : public GameObject
{
	//�ϐ��錾
private:

	//�֐��錾
public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	void Movement();
};

