#include "GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() : color(0x0),location(),box_size()
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
    location = Vector2D(32.0f, 24.0f);

    box_size = Vector2D(32.0f, 24.0f);

    color = GetColor(0, 255, 0);
}

//�X�V����
void GameObject::Update()
{
    location += 1.0f;
}

//�`�揈��
void GameObject::Draw() const
{
    Vector2D tl = this->location - (this->box_size / 2.0f);
    Vector2D br = this->location + (this->box_size / 2.0f);

    DrawBoxAA(tl.x, tl.y, br.x, br.y, color, TRUE);
}

//�I�����Ɏg������
void GameObject::Finalize()
{

}

//�ʒu�ݒu
void GameObject::SetLocation(Vector2D location)
{
    this->location = location;
}

//�ʒu�̏���n������
Vector2D GameObject::GetLocation() const
{
    return this->location;
}

//�I�u�W�F�N�g�̃T�C�Y�̑傫����n��
Vector2D GameObject::GetBoxSize() const
{
    return this->box_size;
}
