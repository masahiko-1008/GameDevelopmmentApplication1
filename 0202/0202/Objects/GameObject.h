#pragma once

#include "../Utility/Vector2D.h"

//GameObjectクラスの宣言
class GameObject
{
	//変数宣言
protected:
	unsigned int color;
	Vector2D location;
	Vector2D box_size;

	//関数宣言
public:
	GameObject();
	virtual ~GameObject();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

public:
	void SetLocation(Vector2D location);
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;
};

