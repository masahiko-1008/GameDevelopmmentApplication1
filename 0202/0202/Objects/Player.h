#pragma once

#include "GameObject.h"

//Playerクラスの宣言
class Player : public GameObject
{
	//変数宣言
private:

	//関数宣言
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

