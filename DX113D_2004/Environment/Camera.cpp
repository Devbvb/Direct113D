#include "Framework.h"

Camera::Camera()
	: moveSpeed(20.0f), rotSpeed(5.0f)
{
	viewBuffer = new MatrixBuffer();
	oldPos = MOUSEPOS;
}

Camera::~Camera()
{
	delete viewBuffer;
}

void Camera::Update()
{
	Move();
	Rotation();

	View();
}

void Camera::Move()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
			position += Forward() * moveSpeed * DELTA;
		if (KEY_PRESS('S'))
			position -= Forward() * moveSpeed * DELTA;
		if (KEY_PRESS('A'))
			position -= Right() * moveSpeed * DELTA;
		if (KEY_PRESS('D'))
			position += Right() * moveSpeed * DELTA;
		if (KEY_PRESS('Q'))
			position -= Up() * moveSpeed * DELTA;
		if (KEY_PRESS('E'))
			position += Up() * moveSpeed * DELTA;
	}

	position += Forward() * Control::Get()->GetWheel() * moveSpeed * DELTA;
}

void Camera::Rotation()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		Vector3 value = MOUSEPOS - oldPos;

		rotation.x += value.y * rotSpeed * DELTA;
		rotation.y += value.x * rotSpeed * DELTA;		
	}	

	oldPos = MOUSEPOS;
}

void Camera::View()
{
	UpdateWorld();

	Vector3 focus = position + Forward();
	view = XMMatrixLookAtLH(position.data, focus.data, Up().data);

	viewBuffer->Set(view);
}

void Camera::PostRender()
{
}

void Camera::SetVS(UINT slot)
{
	viewBuffer->SetVSBuffer(slot);
}
