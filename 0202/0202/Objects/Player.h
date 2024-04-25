#pragma once

#include "GameObject.h"

//PlayerƒNƒ‰ƒX‚ÌéŒ¾
class Player : public GameObject
{
	//•Ï”éŒ¾
private:

	//ŠÖ”éŒ¾
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

