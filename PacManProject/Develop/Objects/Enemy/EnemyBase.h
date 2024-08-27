#pragma once

#include "../GameObject.h"

enum eDirectionState
{
	MOVE,
	IJIKE,
	HOME
};

class EnemyBase : public GameObject
{
	enum EnemyState
	{
		PURSUE,
		AMBUSH,
		REFLECTION,
		RANDAM,
		TERRITORY,
		WAIT
	};

private:
	std::vector<int> move_animation;
	std::vector<int> dying_animation;
	Vector2D old_location;
	Vector2D veloctity;
	eEnemyState : eEnemyState

protected:

public:
	EnemyBase();
	virtual ~EnemyBase();
};