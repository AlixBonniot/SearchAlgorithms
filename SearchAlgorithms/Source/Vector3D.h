#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

namespace Config
{
	static constexpr float epsilon{ 0.00001f };
}

class Vector3D
{
public:
	Vector3D();
	Vector3D(const float in_x, const float in_y, const float in_z);

	float LengthSquared() const;
	float Length() const;

	static float Dot(const Vector3D& lhs, const Vector3D& rhs);
	static Vector3D Cross(const Vector3D& lhs, const Vector3D& rhs);

	Vector3D& Normalize();
	Vector3D GetNormalized() const;

	Vector3D operator-() const;

	Vector3D operator+(const Vector3D& rhs) const;
	Vector3D& operator+=(const Vector3D& rhs);
	Vector3D operator-(const Vector3D& rhs) const;
	Vector3D& operator-=(const Vector3D& rhs);
	Vector3D& operator*=(const float scalar);
	Vector3D operator/(const float scalar) const;
	Vector3D& operator/=(const float scalar);

	bool operator==(const Vector3D& rhs) const;
	bool operator!=(const Vector3D& rhs) const;

public:
	float x;
	float y;
	float z;
};

Vector3D operator*(const Vector3D& vector, const float scalar);
Vector3D operator*(const float scalar, const Vector3D& vector);

std::ostream& operator<<(std::ostream& out, const Vector3D& vector);

#endif