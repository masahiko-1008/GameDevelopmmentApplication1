#include "GameObject.h"
#include "DxLib.h"

GameObject::GameObject() : color(0x0),location(0.0f),box_size(0.0f)
{

}

GameObject::~GameObject()
{

}

void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.0f);

	location = box_size;
}

void GameObject::Update()
{
	location.x += 1.0f;

	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}

void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color,
TRUE);
}

void GameObject::Finalize()
{

}

void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

Vector2D GameObject::GetLocation() const
{
	return this->location;
}

Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}
