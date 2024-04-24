#include "GameObject.h"
#include "DxLib.h"

GameObject::GameObject() : color(0x0),location(),box_size()
{

}

GameObject::~GameObject()
{

}

void GameObject::Initialize()
{
    location = Vector2D(32.0f, 24.0f);

    box_size = Vector2D(32.0f, 24.0f);

    color = GetColor(0, 255, 0);
}

void GameObject::Update()
{
    location += 1.0f;
}

void GameObject::Draw() const
{
    Vector2D tl = this->location - (this->box_size / 2.0f);
    Vector2D br = this->location + (this->box_size / 2.0f);

    DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);
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
