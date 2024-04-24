#pragma once
class Vector2D
{
public:
	//•Ï”éŒ¾
	float x;
	float y;

public:
	//ŠÖ”éŒ¾
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	~Vector2D();

public:
	Vector2D& operator=(const Vector2D& location);

	//‰ÁZˆ—
	const Vector2D operator +(const Vector2D& location)const;
	Vector2D& operator+=(const Vector2D& location);

	//Œ¸Zˆ—
	const Vector2D operator-(const Vector2D& location)const;
	Vector2D& operator-=(const Vector2D& location);

	//æZˆ—
	const Vector2D operator*(const float& scalar)const;
	const Vector2D operator*(const Vector2D& location)const;
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);

	//œZˆ—
	const Vector2D operator/(const float& scalar)const;
	const Vector2D operator/(const Vector2D& location)const;
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);

	void ToInt(int* x, int* y)const;
};

