#include "Framework.h"

Camera::Camera()
	: speed(200), offset(CENTER_X, CENTER_Y, 0), zoomSpeed(1)
{
	SetWorldBuffer(1);
	projectionBuffer = new MatrixBuffer();
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (target == nullptr)
		FreeMode();
	else
		FollowMode();

	UpdateWorld();
	SetWorldBuffer(1);
	//worldBuffer
}

void Camera::PostRender()
{
}

void Camera::SetViewport(UINT width, UINT height)
{
}

void Camera::SetOrthographic(UINT width, UINT height)
{
}

Vector3 Camera::GetMouseWorldPos()
{
	return Vector3();
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
		{
			position.y -= speed;
		}
		if (KEY_PRESS('S'))
		{
			position.y += speed;
		}
		if (KEY_PRESS('A'))
		{
			position.x += speed;
		}
		if (KEY_PRESS('D'))
		{
			position.x -= speed;
		}
	}

	if (mouseWheel != 0)
	{
		scale += mouseWheel * zoomSpeed;

		if (scale.x < 0.1f || scale.y < 0.1f || scale.z < 0.1f)
			scale = Vector3(0.1f, 0.1f, 0.1f);
	}
}

void Camera::FollowMode()
{
	Vector3 targetPos = target->position - offset;

	if (targetPos.x < leftBottom.x)
		targetPos.x = leftBottom.x;

	if (targetPos.x > rightTop.x - WIN_WIDTH)
		targetPos.x = rightTop.x - WIN_WIDTH;

	if (targetPos.y < leftBottom.y)
		targetPos.y = leftBottom.y;

	if (targetPos.y > rightTop.y - WIN_HEIGHT)
		targetPos.y = rightTop.y - WIN_HEIGHT;

	position = LERP(position, targetPos * -1, speed);
		
}
