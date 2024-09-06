#include "EnemyBase.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"
#include "../Food/Food.h"
#include "../Player/Player.h"

#define D_PLAYER_SPEED	(50.0f)

EnemyBase::EnemyBase() :
	move_animation(),
	eyes_animation(),
	velocity(0.0f),
	enemy_state(eEnemyState::ENEMY_MOVE),
	now_direction_state(eDirectionState::ENEMY_LEFT),
	next_direction_state(eDirectionState::ENEMY_LEFT),
	//food_count(0),
	animation_time(0.0f),
	ijike_time(0.0f),
	animation_count(0),
	old_panel(ePanelID::NONE),
	eye_image(NULL),
	is_ijike(false),
	//is_power_up(false),
	powerdown(false)
	//is_destroy(false)
{

}

EnemyBase::~EnemyBase()
{

}

void EnemyBase::Initialize()
{
	// �A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	eyes_animation = rm->GetImages("Resource/Images/eyes.png", 4, 4, 1, 32, 32);
	eye_image = eyes_animation[1];

	// �����蔻��̐ݒ�
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);

	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	// ���C���[�̐ݒ�
	z_layer = 5;

	// �����̐ݒ�
	mobility = eMobilityType::Movable;

	velocity = Vector2D(2.0f, 0.0f);

	//�������鎞��
	ijike_time = 8.0f;
}

void EnemyBase::Update(float delta_second)
{
	// �v���C���[��Ԃɂ���āA�����ς���
	switch (enemy_state)
	{
	case eEnemyState::ENEMY_IJIKE:
		Movement(delta_second);
		// �ړ����̃A�j���[�V����
		animation_time += delta_second;
		if (animation_time >= (1.0f / 16.0f))
		{
			animation_time = 0.0f;
			animation_count++;
			if (animation_count >= 2)
			{
				animation_count = 0;
			}

		}
		break;

	case eEnemyState::ENEMY_MOVE:
		// �ړ�����
		Movement(delta_second);
		// �A�j���[�V��������
		AnimationControl(delta_second);
		break;

	case eEnemyState::ENEMY_HOME:
		Movement(delta_second);
		AnimationControl(delta_second);
		break;
	default:
		break;
	}

	if (is_ijike == true)
	{
		enemy_state = eEnemyState::ENEMY_IJIKE;
		ijike_time -= delta_second;
		if (ijike_time <= 0)
		{
			enemy_state = eEnemyState::ENEMY_MOVE;
			is_ijike = false;
			powerdown = true;
		}
	}
	else
	{
		powerdown = false;
		ijike_time = 8.0f;
	}


}

void EnemyBase::Draw(const Vector2D& screen_offset) const
{
	//// �e�N���X�̕`�揈�����Ăяo��
	//__super::Draw(screen_offset);
	Vector2D graph_location = this->location + screen_offset;
	// �I�t�Z�b�g�l����ɉ摜�̕`����s��
	if (enemy_state == eEnemyState::ENEMY_MOVE || enemy_state == eEnemyState::ENEMY_IJIKE)
	{
		// �I�t�Z�b�g�l����ɉ摜�̕`����s��
		DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, red_image, TRUE);
		DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, blue_image, TRUE);
		DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, yellow_image, TRUE);
		DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, pink_image, TRUE);
	}

	if (enemy_state == eEnemyState::ENEMY_MOVE || enemy_state == eEnemyState::ENEMY_HOME)
	{
		DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, eye_image, TRUE);
	}




}

void EnemyBase::Finalize()
{
	// ���I�z��̉��
	move_animation.clear();
	eyes_animation.clear();
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// ���������A�I�u�W�F�N�g���ǂ�������
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// �����蔻������擾���āA�J�v�Z��������ʒu�����߂�
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// �ŋߖT�_�����߂�
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Player����near_point�ւ̕����x�N�g�����擾
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// �߂荞�񂾍���
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diff�̕������߂�
		location += dv.Normalize() * diff;

		//
		velocity *= -1;
	}

	//// ���������A�I�u�W�F�N�g���ʏ�a��������
	if (hit_object->GetCollision().object_type == eObjectType::player && enemy_state == eEnemyState::ENEMY_IJIKE)
	{
		is_ijike = false;
		enemy_state = eEnemyState::ENEMY_HOME;
	}


}

//eEnemyState EnemyBase::GetEnemyState() const
//{
//	return eEnemyState();
//}




void EnemyBase::SetEnemyState()
{
	this->is_ijike = true;

}

bool EnemyBase::SetPowerDown()
{
	return powerdown;
}

/// <summary>
/// �ړ�����
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::Movement(float delta_second)
{
	//// �ړ��ʂ���ړ��������X�V
	//if (Vector2D::Distance(old_location, location) == 0.0f)
	//{
	//	// �ړ����Ȃ���� direction_state ��ύX����
	//	velocity = 0.0f;
	//	now_direction_state = next_direction_state;
	//	next_direction_state = eDirectionState::ENEMY_RIGHT;
	//}
	//else
	//{
	//	// �ړ������Ɉړ����Ă��Ȃ���� direction_state ��ύX����
	//	switch (now_direction_state)
	//	{
	//	case eDirectionState::ENEMY_UP:
	//	case eDirectionState::ENEMY_DOWN:
	//	{
	//		float diff = location.y - old_location.y;
	//		if (((now_direction_state == eDirectionState::ENEMY_UP) && (diff < 0.0f)) ||
	//			((now_direction_state == eDirectionState::ENEMY_DOWN) && (0.0f < diff)))
	//		{
	//			// �ړ������Ɉړ����Ă�̂� break
	//			break;
	//		}

	//		velocity.y = 0.0f;
	//		now_direction_state = next_direction_state;
	//		//next_direction_state = eDirectionState::NONE;
	//	}
	//	break;

	//	case eDirectionState::ENEMY_LEFT:
	//	case eDirectionState::ENEMY_RIGHT:
	//	{

	//		float diff = location.x - old_location.x;
	//		if (((now_direction_state == eDirectionState::ENEMY_LEFT) && (diff < 0.0f)) ||
	//			((now_direction_state == eDirectionState::ENEMY_RIGHT) && (0.0f < diff)))
	//		{
	//			// �ړ������Ɉړ����Ă�̂� break
	//			break;
	//		}

	//		velocity.x = 0.0f;
	//		now_direction_state = next_direction_state;
	//		//next_direction_state = eDirectionState::NONE;
	//	}
	//	break;

	//	default:// �������Ȃ�
	//		break;
	//	}
	//}

	//// ���͏�Ԃ̎擾
	//InputManager* input = InputManager::GetInstance();

	//// ���݃p�l���̏�Ԃ��m�F
	//ePanelID panel = StageData::GetPanelData(location);

	// //���͂���ړ�������ݒ�
	///*if (input->GetKeyDown(KEY_INPUT_UP) || input->GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	//{
	//	switch (now_direction_state)
	//	{
	//	case eDirectionState::UP:
	//		old_panel = ePanelID::NONE;
	//	case eDirectionState::DOWN:
	//	case eDirectionState::NONE:
	//		now_direction_state = eDirectionState::UP;
	//		break;

	//	default:
	//		next_direction_state = eDirectionState::UP;
	//	}
	//}
	//else if (input->GetKeyDown(KEY_INPUT_DOWN) || input->GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	//{
	//	switch (now_direction_state)
	//	{
	//	case eDirectionState::DOWN:
	//		old_panel = ePanelID::NONE;
	//	case eDirectionState::UP:
	//	case eDirectionState::NONE:
	//		now_direction_state = eDirectionState::DOWN;
	//		break;

	//	default:
	//		next_direction_state = eDirectionState::DOWN;
	//	}
	//}
	//else if (input->GetKeyDown(KEY_INPUT_LEFT) || input->GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
	//{
	//	switch (now_direction_state)
	//	{
	//	case eDirectionState::LEFT:
	//		old_panel = ePanelID::NONE;
	//	case eDirectionState::RIGHT:
	//	case eDirectionState::NONE:
	//		now_direction_state = eDirectionState::LEFT;
	//		break;

	//	default:
	//		next_direction_state = eDirectionState::LEFT;
	//	}
	//}
	//else if (input->GetKeyDown(KEY_INPUT_RIGHT) || input->GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
	//{
	//	switch (now_direction_state)
	//	{
	//	case eDirectionState::RIGHT:
	//		old_panel = ePanelID::NONE;
	//	case eDirectionState::LEFT:
	//	case eDirectionState::NONE:
	//		now_direction_state = eDirectionState::RIGHT;
	//		break;

	//	default:
	//		next_direction_state = eDirectionState::RIGHT;
	//	}
	//}*/

	// //�i�s�����̈ړ��ʂ�ǉ�
	//switch (now_direction_state)
	//{
	//case EnemyBase::ENEMY_UP:
	//	velocity.y = -2.0f;
	//	break;
	//case EnemyBase::ENEMY_DOWN:
	//	velocity.y = 2.0f;
	//	break;
	//case EnemyBase::ENEMY_LEFT:
	//	velocity.x = -2.0f;
	//	break;
	//case EnemyBase::ENEMY_RIGHT:
	//	velocity.x = 2.0f;
	//	break;
	//default:
	//	velocity = 0.0f;
	//	now_direction_state = next_direction_state;
	//	//next_direction_state = Enemy::NONE;
	//	break;
	//}

	//// ��s���͂̈ړ��ʂ�ǉ�
	//if ((panel != ePanelID::NONE)
	//	&& (old_panel != panel))
	//{
	//	switch (next_direction_state)
	//	{
	//	case EnemyBase::ENEMY_UP:
	//		velocity.y = -2.0f;
	//		break;
	//	case EnemyBase::ENEMY_RIGHT:
	//		velocity.x = 2.0f;
	//		break;
	//	case EnemyBase::ENEMY_DOWN:
	//		velocity.y = 2.0f;
	//		break;
	//	case EnemyBase::ENEMY_LEFT:
	//		velocity.x = -2.0f;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	// //�O����W�̍X�V
	//old_location = location;

	//// �O��p�l���̍X�V
	//old_panel = panel;

	 //�ړ��� * ���� * ���� �ňړ�������肷��
	location += velocity * D_PLAYER_SPEED * delta_second;

	// //��ʊO�ɍs������A���Α��Ƀ��[�v������
	//if (location.x < 0.0f)
	//{
	//	old_location.x = 672.0f;
	//	location.x = 672.0f - collision.radius;
	//	velocity.y = 0.0f;
	//}
	//if (672.0f < location.x)
	//{
	//	old_location.x = 0.0f;
	//	location.x = collision.radius;
	//	velocity.y = 0.0f;
	//}
}

/// <summary>
/// �A�j���[�V��������
/// </summary>
/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::AnimationControl(float delta_second)
{
	if (enemy_state == eEnemyState::ENEMY_MOVE)
	{
		// �ړ����̃A�j���[�V����
		animation_time += delta_second;
		if (animation_time >= (1.0f / 16.0f))
		{
			animation_time = 0.0f;
			animation_count++;
			if (animation_count >= 2)
			{
				animation_count = 0;
			}
			red_image = move_animation[animation_red[animation_count]];
			blue_image = move_animation[animation_blue[animation_count]];
			yellow_image = move_animation[animation_yellow[animation_count]];
			pink_image = move_animation[animation_pink[animation_count]];
		}
	}

	if (velocity.x > 0)
	{
		eye_image = eyes_animation[1];
	}
	else if (velocity.x < 0)
	{
		eye_image = eyes_animation[3];
	}
	else if (velocity.y > 0)
	{
		eye_image = eyes_animation[2];
	}
	else if (velocity.y < 0)
	{
		eye_image = eyes_animation[0];
	}
}