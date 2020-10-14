#pragma once

class MatrixBuffer : public ConstBuffer
{
private:
	struct Data
	{
		Matrix matrix;
	}data;

public:
	MatrixBuffer() : ConstBuffer(&data, sizeof(Data))
	{
		data.matrix = XMMatrixIdentity();
	}

	void Set(Matrix value)
	{
		data.matrix = XMMatrixTranspose(value);
	}
};

class LightBuffer : public ConstBuffer
{
public:
	struct Data
	{
		Float3 direction;

		float padding;
	}data;

	LightBuffer() : ConstBuffer(&data, sizeof(Data))
	{
		data.direction = { 0, -1, 0 };
	}
};