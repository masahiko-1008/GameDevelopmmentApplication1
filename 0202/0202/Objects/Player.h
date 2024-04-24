#pragma once

#include "GameObject.h"

class Player : public GameObject
{
private:

public:
	Player();
	~Player();

	void Initialize();
	void Update();
	void Draw() const;
	void Finlize();

private:
	void Movement();
};

