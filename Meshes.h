#pragma once
#include "Math/mat.h"


namespace Cube
{
	const vec3 FRONT_FACE[4] =
	{
		vec3(-0.5, -0.5, -0.5),	//Bottom Left
		vec3(0.5, -0.5, -0.5),	//Bottom Right
		vec3(0.5, 0.5, -0.5),	//Top Right
		vec3(-0.5, 0.5, -0.5)	//Top Left
	};
	const vec3 RIGHT_FACE[4] =
	{
		vec3(0.5,-0.5,-0.5),
		vec3(0.5,-0.5,0.5),
		vec3(0.5,0.5,0.5),
		vec3(0.5,0.5,-0.5)
	};
	const vec3 BACK_FACE[4] =
	{
		vec3(0.5,-0.5,0.5),
		vec3(-0.5,-0.5,0.5),
		vec3(-0.5,0.5,0.5),
		vec3(0.5,0.5,0.5)
	};
	const vec3 LEFT_FACE[4] =
	{
		vec3(-0.5, -0.5, 0.5),
		vec3(-0.5, -0.5, -0.5),
		vec3(-0.5, 0.5, -0.5),
		vec3(-0.5,0.5,0.5)
	};
	const vec3 BOTTOM_FACE[4] =
	{
		vec3(-0.5, -0.5, 0.5),
		vec3(0.5, -0.5, 0.5),
		vec3(0.5, -0.5, -0.5),
		vec3(-0.5, -0.5, -0.5)
	};
	const vec3 TOP_FACE[4] =
	{
		vec3(-0.5, 0.5, -0.5),
		vec3(0.5, 0.5, -0.5),
		vec3(0.5, 0.5, 0.5),
		vec3(-0.5, 0.5, 0.5)
	};
}
