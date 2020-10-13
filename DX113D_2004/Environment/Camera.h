#pragma once

class Camera : public Transform
{
private:
	float moveSpeed;
	float rotSpeed;

	MatrixBuffer* viewBuffer;
	Matrix view;

	Vector3 oldPos;
public:
	Camera();
	~Camera();

	void Update();

	void Move();
	void Rotation();
	void View();

	void PostRender();

	void SetVS(UINT slot = 1);
};