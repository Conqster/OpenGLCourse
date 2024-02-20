#pragma once
#include<iostream>
#include<iomanip>

const int MAX_POINT_LIGHTS = 3;
const int MAX_SPOT_LIGHTS = 3;


#define SCREEN_WIDTH 2560
#define SCREEN_HEIGHT 1440

//#define SCREEN_WIDTH 1920
//#define SCREEN_HEIGHT 1080




struct Vec2
{
	float x;
	float y;

	Vec2() = default;

	Vec2(float x, float y) : x(x), y(y){}

	static Vec2 One() { return Vec2(1.0f, 1.0f); }
	static Vec2 Zero() { return Vec2(0.0f, 0.0f); }

	Vec2 Up() { return Vec2(0.0f, 1.0f); }
	Vec2 Right() { return Vec2(1.0f, 0.0f); }

	friend std::ostream& operator<<(std::ostream& os, const Vec2& vec2)
	{
		return os << "Vector2(" << std::fixed << std::setprecision(2) << vec2.x << "f, " << vec2.y << "f).";
	}
};



struct Vec3
{
	float x;
	float y;
	float z;

	Vec3() = default;

	Vec3(float x, float y, float z) : x(x), y(y), z(z){}

	static Vec3 One() { return Vec3(1.0f, 1.0f, 1.0f); }

	static Vec3 Zero() { return Vec3(0.0f, 0.0f, 0.0f); }

	static Vec3 Up() { return Vec3(0.0f, 1.0f, 0.0f); }

	static Vec3 Forward() { return Vec3(0.0f, 0.0f, 1.0f); }

	static Vec3 Right() { return Vec3(1.0f, 0.0f, 0.0f); }

	friend std::ostream& operator <<(std::ostream& os, const Vec3& vec3)
	{
		return os << "Vector(" << std::fixed << std::setprecision(2)<< /*static_cast<double>*/(vec3.x) << "f, " << /*static_cast<double>*/(vec3.y) << "f, " << /*static_cast<double>*/(vec3.z) << "f).";
	}


	inline Vec3 operator *(const float& rhs) const
	{
		Vec3 temp;
		temp.x = x * rhs;
		temp.y = y * rhs;
		temp.z = z * rhs;
		return temp;
	}

	inline Vec3 operator +=(const Vec3& rhs) const
	{
		Vec3 temp;
		temp.x += rhs.x;
		temp.y += rhs.y;
		temp.z += rhs.z;
		return temp;
	}



	/*
private:
	static Vec3 zeroVector;
	static Vec3 one = One();



public: 
	static myVector zero;*/
	

public:

};


