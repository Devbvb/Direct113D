#pragma once

class Camera : public Singleton <Camera>, Transform
{
private:
	float speed;
	float zoomSpeed;

	Transform* target;
	Vector3 offset;

	Vector3 leftBottom;
	Vector3 rightTop;

	Vector3 originPos;

	MatrixBuffer* projectionBuffer;

public:
	Camera();
	~Camera();

	void Update();
	void PostRender();

	void SetViewport(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);
	void SetOrthographic(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

	void SetTarget(Transform* value) { target = value; }
	void SetLeftBottom(Vector3 value) { leftBottom = value; }
	void SetRightTop(Vector3 value) { rightTop = value; }

	Vector3 GetMouseWorldPos();

private:
	void FreeMode();
	void FollowMode();
};
