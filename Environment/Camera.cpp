#include "Framework.h"

Camera::Camera()
	: moveSpeed(20.0f), rotSpeed(5.0f)
{
	viewBuffer = new ViewBuffer(); //인스턴싱 (viewBuffer 는 인스턴스)
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
	ImGui::Text("CameraInfo");
	ImGui::Text("CamPos : %.1f, %.1f, %.1f", position.x, position.y, position.z);
	ImGui::Text("CamRot : %.1f, %.1f, %.1f", rotation.x, rotation.y, rotation.z);
	ImGui::Spacing(); // 한줄 띄우기
}

void Camera::SetVS(UINT slot)
{
	viewBuffer->SetVSBuffer(slot);
}

Ray Camera::ScreenPointToRay(Vector3 pos)
{
	Float2 screenSize(WIN_WIDTH, WIN_HEIGHT);

	Float2 point;
	point.x = ((2 * pos.x) / screenSize.x) - 1.0f;
	point.y = (((2 * pos.y) / screenSize.y) - 1.0f) * -1.0f;

	Matrix projection = Environment::Get()->GetProjection();

	Float4x4 temp;
	XMStoreFloat4x4(&temp, projection);

	point.x /= temp._11;
	point.y /= temp._22;

	Ray ray;
	ray.position = position;

	Matrix invView = XMMatrixInverse(nullptr, view);

	Vector3 tempPos(point.x, point.y, 1.0f);

	ray.direction = XMVector3TransformNormal(tempPos.data, invView);
	ray.direction.Normal();

	return ray;
}
