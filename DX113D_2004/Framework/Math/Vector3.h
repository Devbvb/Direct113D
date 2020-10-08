#pragma once

class Vector3
{
public:
	Vector4 data;

	Vector3();
	Vector3(Float3 value);
	Vector3(float x, float y, float z);
	Vector3(Vector4 value);

	operator Float3();

	void SetX(float value);
	void SetY(float value);
	void SetZ(float value);
	void SetW(float value);

	float GetX();
	float GetY();
	float GetZ();
	float GetW();

	// lamda? �Լ�
	_declspec(property(get = GetX, put = SetX)) float x;
	_declspec(property(get = GetY, put = SetY)) float y;
	_declspec(property(get = GetZ, put = SetZ)) float z;
	_declspec(property(get = GetW, put = SetW)) float w;
};
