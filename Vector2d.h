#pragma once
class Vector2
{
public:
	float x_;
	float y_;

public:
	// コンストラクタ/デストラクタ
	Vector2(float x = 0, float y = 0);
	~Vector2();

	// コピーコンストラクタ
	Vector2(const Vector2& obj);

	// 演算子オーバーロード
	const Vector2& operator=(const Vector2& obj);
	const Vector2 operator+(const Vector2& obj)const;
	const Vector2 operator-(const Vector2& obj)const;
	const Vector2 operator*(const Vector2& obj)const;
	const Vector2 operator/(const Vector2& obj)const;
	const void operator+=(const Vector2& obj);
	const void operator-=(const Vector2& obj);
	const void operator*=(const Vector2& obj);
	const void operator/=(const Vector2& obj);
	bool operator==(const Vector2& obj);
	bool operator!=(const Vector2& obj);

};

