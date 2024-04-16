#pragma once
#include "Math/mat.h"




struct Camera3D
{
	vec3 position;
	vec2 view;

	mat3 RotXAxis();
	mat3 RotYAxis();
};

inline mat3 Camera3D::RotXAxis()
{
	return mat3
	{
		1,0,0,
		0,cosf(view.y), -sinf(view.y),
		0,sinf(view.y), cosf(view.y)
	};
}
inline mat3 Camera3D::RotYAxis()
{
	return mat3
	{
		cosf(view.x), 0, sinf(view.x),
		0,1,0,
		-sinf(view.x), 0 ,cosf(view.x)
	};
}