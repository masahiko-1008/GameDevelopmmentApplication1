﻿#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

// プレイヤー状態
enum eEnemyState
{
	ENEMY_IJIKE,		// 逃亡状態
	ENEMY_MOVE,		// 追跡状態
	ENEMY_HOME,		// 帰宅状態
};

/// <summary>
/// プレイヤークラス（パックマン）
/// </summary>
class EnemyBase : public GameObject
{
private:
	// 進行方向状態
	enum eDirectionState : unsigned char
	{
		ENEMY_UP,
		ENEMY_RIGHT,
		ENEMY_DOWN,
		ENEMY_LEFT,
	};

private:
	// 各敵の行動の種類を表す状態
	enum eEnemyMoveState : unsigned char
	{
		PURSUE,
		AMBUSH,
		REFLECTION,
		RANDAM,
		TERRITORY,
		WAIT,
	};

protected:
	std::vector<int> move_animation;		// 移動のアニメーション画像
	std::vector<int> eyes_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// プレイヤー状態
	eDirectionState now_direction_state;	// 現在進行方向状態
	eDirectionState next_direction_state;	// 次回進行方向状態
	//int food_count;							// 餌を食べた数
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	ePanelID old_panel;						// 前回パネル情報
	//bool is_power_up;						// パワー餌を食べたか？
	//bool is_destroy;						// 死んだ状態になったか？
	bool is_ijike;						// パワー餌を食べられたか？
	int eye_image;						//目の画像
	bool powerdown;						//プレイヤーの情報
	float ijike_time;						//いじけの時間

protected:
	// 移動アニメーションの順番
	const int animation_red[2] = { 0, 1 };
	const int animation_blue[2] = { 4, 5 };
	const int animation_pink[2] = { 2, 3 };
	const int animation_yellow[2] = { 6, 7 };
	const int ijike_animation_num[2] = { 16 ,17 };

public:
	EnemyBase();
	virtual ~EnemyBase();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;
	virtual void Finalize() override;

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	/// <summary>
	/// 餌を食べた数取得
	/// </summary>
	/// <returns>餌を食べた数</returns>
	//int GetFoodCount() const;

	/// <summary>
	/// プレイヤーの状態を取得する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	eEnemyState GetEnemyState() const;

	/// <summary>
	/// プレイヤーがパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	//bool GetPowerUp() const;

	/// <summary>
	/// プレイヤーの状態を取得する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	void SetEnemyState();

	/// <summary>
	/// パワーダウンさせる
	/// </summary>
	bool SetPowerDown();

	/// <summary>
	/// プレイヤーがパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	//bool GetDestroy() const;


protected:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void Movement(float delta_second);
	/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void AnimationControl(float delta_second);
};