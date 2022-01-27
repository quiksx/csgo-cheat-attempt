#include "include.h"

struct Vec2
{
	float x, y;
};
struct Vec3
{
	float x, y, z;

	Vec3 operator+(Vec3 D)
	{
		return { x + D.x, y + D.y, z + D.z };
	}
	Vec3 operator-(Vec3 D)
	{
		return { x - D.x, y - D.y, z - D.z };
	}
	Vec3 operator*(float D)
	{
		return { x * D, y * D, z * D };
	}
	Vec3 operator/(float D)
	{
		return { x / D, y / D, z / D };
	}

	void Normalize()
	{
		while (y < -180)
			y = 179.99;
		while (y > 180)
			y = -179.99;
		while (x < -89)
			x = -89;
		while (x > 89)
			x = 89;
		z = 0;
	}
};
struct Vec4
{
	float x, y, z, w;
};