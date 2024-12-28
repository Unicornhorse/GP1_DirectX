#include "Camera.h"

Camera::Camera(const Vector3& origin, float fovAngle):
	m_Origin(origin), 
	m_FovAngle(fovAngle), 
	m_Fov(tanf((fovAngle* TO_RADIANS) / 2.f))
{
}

Camera::~Camera()
{
}

void Camera::Update(float elapsedSec)
{

}

Matrix Camera::GetViewMatrix()
{
	m_Right = Vector3::Cross(Vector3(0, 1, 0), m_Forward).Normalized();
	m_Up = Vector3::Cross(m_Forward, m_Right).Normalized();


	m_InvViewMatrix = {
		m_Right,
		m_Up,
		m_Forward,
		m_Origin
	};

	viewMatrix = m_InvViewMatrix.Inverse();
	return viewMatrix;
}

Matrix Camera::GetProjectionMatrix(float aspectRatio) const
{
	const float nearPlane = 1.f;
	const float farPlane = 1000.f;

	const float A = farPlane / (farPlane - nearPlane);
	const float B = (-farPlane * nearPlane) / (farPlane - nearPlane);

	return Matrix{ 
		{ 1 / (aspectRatio * m_Fov), 0, 0, 0 },
		{ 0, 1 / m_Fov, 0, 0 },
		{ 0, 0, A, 1 },
		{ 0, 0, B, 0 } };
}
