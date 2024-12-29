#pragma once
#include "pch.h"
#include "Matrix.h"

using namespace dae;

class Camera {
public:
	Camera() = default;
	Camera(const Vector3& origin, float fovAngle);
	~Camera();

	void Update(float elapsedSec);
	Matrix GetViewMatrix();
	Matrix GetProjectionMatrix(float aspectRatio) const;

private:
	Vector3 m_Origin;
	float m_FovAngle; // in radians
	float m_Fov; // in degrees

	Vector3 m_Forward;
	Vector3 m_Up;
	Vector3 m_Right;

	Matrix m_InvViewMatrix{};
	Matrix viewMatrix{};

	// FOV variables
	const float maxFov{ 150.f };
	const float minFov{ 20.f };
	const float angle{ 5.f };
};
