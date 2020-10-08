#pragma once

class Transform
{
public:
	string tag;

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

protected:	
	Vector3 globalPosition;
	Vector3 globalRotation;
	Vector3 globalScale;

	Vector3 pivot;

	Matrix world;
	Matrix* parent;

	MatrixBuffer* worldBuffer;

public:
	Transform(string tag = "Untagged");
	virtual ~Transform();

	void UpdateWorld();

	void SetWorldBuffer(UINT slot = 0);

	//////////
	void SetParent(Matrix* matrix) { parent = matrix; }
	Matrix* GetMatrix() { return &world; }
};
