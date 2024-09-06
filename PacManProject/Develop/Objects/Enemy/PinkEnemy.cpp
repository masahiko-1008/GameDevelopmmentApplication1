#include "PinkEnemy.h"
#include "../../Utility/ResourceManager.h"


PinkEnemy::PinkEnemy()
{
}

PinkEnemy::~PinkEnemy()
{
}

void PinkEnemy::Initialize()
{
	__super::Initialize();
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);
	pink_image = move_animation[0];
}

void PinkEnemy::Update(float delta_second)
{
	__super::Update(delta_second);
	pink_image = animation_pink[ijike_animation_num[animation_count]];

}

void PinkEnemy::Draw(const Vector2D& screen_offset) const
{
	__super::Draw(screen_offset);
}

void PinkEnemy::Finalize()
{
}

void PinkEnemy::Movement(float delta_second)
{
	__super::Movement(delta_second);
}

void PinkEnemy::Animation(float delta_second)
{
	__super::AnimationControl(delta_second);

	// �ړ����̃A�j���[�V����
	/*animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		image = move_animation[animation_num[animation_count]];



	}*/

}