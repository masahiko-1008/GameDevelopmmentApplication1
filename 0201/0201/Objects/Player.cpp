#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Player::Player() : location(), direction(0.0f), radius(15.0f)
{
}

//コンストラクタ
Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{
}

//コンストラクタ
Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}

//デストラクタ
Player::~Player()
{
}

//更新処理
void Player::Update()
{
	Movement();
}

//描画処理
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255),
		TRUE);
}

//位置座標情報変更処理
void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

//位置座標情報取得
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

//位置座標取得
Vector2D Player::GetLocation() const
{
	return location;
}

//半径情報取得
float Player::GetRadius()
{
	return 0.0f;
}

//移動処理
void Player::Movement()
{
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = -1.0f;
	}
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.y = -1.0f;
	}
	location += direction;
}
