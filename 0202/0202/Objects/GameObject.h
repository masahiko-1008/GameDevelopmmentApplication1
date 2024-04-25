#pragma once

#include "../Utility/Vector2D.h"

//GameObjectƒNƒ‰ƒX‚ÌéŒ¾
class GameObject
{
	//•Ï”éŒ¾
protected:
	unsigned int color;
	Vector2D location;
	Vector2D box_size;

	//ŠÖ”éŒ¾
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

