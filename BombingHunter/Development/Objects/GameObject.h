#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER   //座標の原点を画像の中心にする

//ゲームオブジェクト基底クラス
class GameObject
{
protected:
	Vector2D location;  //位置情報
	Vector2D box_size;  //矩形の大きさ
	double radian;      //向き
	int image;          //画像
	int sound;          //音源

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void Draw() const;
	virtual void Finalize();

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object);

	//位置情報取得処理
	Vector2D GetLocation() const;

	//位置情報変更処理
	void SetLocation(const Vector2D& location);

	//当たり判定の大きさを取得する
	Vector2D GetBoxSize() const;
};

