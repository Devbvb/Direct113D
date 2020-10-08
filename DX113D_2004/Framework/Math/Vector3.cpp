#include "Framework.h"

Vector3::Vector3()
{
	data = XMVectorZero(); // 0을 벡터에 넣어주는 함수
}

Vector3::Vector3(Float3 value)
{
	data = XMLoadFloat3(&value); //변환해주는 함수 (주소값 넣야함)
}

Vector3::Vector3(float x, float y, float z)
{
	data = XMVectorSet(x, y, z, 0);
}

Vector3::Vector3(Vector4 value)
	: data(value)
{
}

Vector3::operator Float3()
{
	Float3 result;
	XMStoreFloat3(&result, data);

	return result;
}

void Vector3::SetX(float value)
{
	data = XMVectorSetX(data, value);
}

void Vector3::SetY(float value)
{
	data = XMVectorSetY(data, value);
}

void Vector3::SetZ(float value)
{
	data = XMVectorSetZ(data, value);
}

void Vector3::SetW(float value)
{
	data = XMVectorSetW(data, value);
}

float Vector3::GetX()
{
	return XMVectorGetX(data);
}

float Vector3::GetY()
{
	return XMVectorGetY(data);
}

float Vector3::GetZ()
{
	return XMVectorGetZ(data);
}

float Vector3::GetW()
{
	return XMVectorGetW(data);
}
