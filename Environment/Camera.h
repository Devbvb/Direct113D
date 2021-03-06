#pragma once

struct Ray
{
	Vector3 position;
	Vector3 direction;	
};

class Camera : public Transform
{
private:
	class ViewBuffer : public ConstBuffer
	{
	private:
		struct Data
		{
			Matrix matrix;
			Matrix invMatrix; //역행렬
		}data;

	public:
		ViewBuffer() : ConstBuffer(&data, sizeof(Data))
		{
			data.matrix = XMMatrixIdentity();
			data.invMatrix = XMMatrixIdentity();
		}

		void Set(Matrix value)
		{
			data.matrix = XMMatrixTranspose(value);
			Matrix temp = XMMatrixInverse(nullptr, value);  //역행렬
			data.invMatrix = XMMatrixTranspose(temp);
		}
	};

	float moveSpeed;
	float rotSpeed;

	ViewBuffer* viewBuffer;
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

	Ray ScreenPointToRay(Vector3 pos);
};