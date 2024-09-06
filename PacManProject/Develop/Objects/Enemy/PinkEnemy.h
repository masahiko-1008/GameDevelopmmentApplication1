#pragma once

#include "EnemyBase.h"

class PinkEnemy : public  EnemyBase
{
public:

	const int animation_pink[2] = { 2, 3 };
public:
	PinkEnemy();
	virtual ~PinkEnemy();

	void Initialize() override;
	void Update(float delta_second) override;
	void Draw(const Vector2D& screen_offset) const override;
	void Finalize() override;

	void Movement(float delta_second);
	void Animation(float delta_second);
};