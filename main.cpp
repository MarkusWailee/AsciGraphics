#include "Windows.h"
#include <iostream>
#include "DeltaTime.hpp"
#include "Terminal3D.hpp"
#include "DrawingFunctions.hpp"



int main()
{

	Terminal3D::Init(300,200);
	Terminal3D::Render();

	//DeltaTime::SetTargetFPS(60);

	float x = 40;
	float y = 0;
	
	float time = 0;

	char texture1[] =
	{
		'o','o','o','o','o','o','o','o',
		'o','.','o','o','o','o','.','o',
		'o','.','o','o','o','o','.','o',
		'o','.','o','o','o','o','.','o',
		'o','.','.','.','.','.','.','o',
		'o','.','o','o','o','o','.','o',
		'o','.','o','o','o','o','.','o',
		'o','.','o','o','o','o','.','o',
		'o','o','o','o','o','o','o','o',
	};
	vec2 uv[] =
	{
		vec2(0,0),
		vec2(1,0),
		vec2(1,1),
	};
	vec2 uv2[] =
	{
		vec2(1,1),
		vec2(0,1),
		vec2(0,0),
	};
	Terminal3D::Add_Texture('h', texture1, 8, 9);




	while (true)
	{
		DeltaTime::HandleTime();
		DeltaTime::ShowFPS();


		vec3 p[3] =
		{
			vec3(-1,-1,1),
			vec3(1,-1,1),
			vec3(1,1,1)
		};
		vec3 p2[3] =
		{
			vec3(1,1,1),
			vec3(-1,1,1),
			vec3(-1,-1,1)
		};
		mat3 Rot =
		{
			cos(time),-sin(time),0,
			sin(time), cos(time),0,
			0,0,1
		};



		for (int i = 0; i < 3; i++)
		{
			p[i] = Rot * p[i];
			p[i] *= 50;
			p[i] += vec3(Terminal3D::GetScreenWidth() / 2, Terminal3D::GetScreenHeight() / 2,0);

			p2[i] = Rot * p2[i];
			p2[i] *= 50;
			p2[i] += vec3(Terminal3D::GetScreenWidth() / 2, Terminal3D::GetScreenHeight() / 2, 0);
		}

		if (GetAsyncKeyState('D') & 0x8000)
			time += 3*DeltaTime::GetFrameTime();
		
		//raw::Triangle(p[0], p[1], p[2], '-');
		//Draw::Triangle(p2[0], p2[1], p2[2], 'P');

		Draw::Triangle_uv(p, uv, 'h');
		Draw::Triangle_uv(p2, uv2, 'h');


		Terminal3D::Render();
		//std::cout << "\x1B[H";
		Terminal3D::ClearBuffer();
	}
	Terminal3D::Terminate();
}

