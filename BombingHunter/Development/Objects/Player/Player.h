#pragma once

#include "../GameObject.h"

class Player : public GameObject
{
private:
	int animation[6];          //アニメーション画像
	int animation_count;       //アニメーション時間
	int flip_flag;             //反転フラグ

public:
	Player();
	~Player();

	//初期化処理
	virtual void Initialize() override;
	//更新処理
	virtual void Update() override;
	//描画処理
	virtual void Draw() const override;
	//終了時処理
	virtual void Finalize() override;

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();
};

