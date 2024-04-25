#pragma once

#include "../Utility/Vector2D.h"

//GameObject�N���X�̐錾
class GameObject
{
	//�ϐ��錾
protected:
	unsigned int color;
	Vector2D location;
	Vector2D box_size;

	//�֐��錾
public:
	GameObject();
	virtual ~GameObject();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;
};

