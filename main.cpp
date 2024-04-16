#include "Windows.h"
#include <iostream>
#include "DeltaTime.hpp"
#include "Terminal3D.hpp"
#include "DrawingFunctions.hpp"



int main()
{

	Terminal3D::Init(100,80);
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
	Terminal3D::Add_Texture('h', texture1, 8, 9);

	//Terminal3D::Add_Texture('e', texture_e, 20, 20);


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


	


	while (true)
	{
		DeltaTime::HandleTime();
		DeltaTime::ShowFPS();


		mat3 Rot =
		{
			cos(time),-sin(time),0,
			sin(time), cos(time),0,
			0,0,1
		};

		vec3 qua[] =
		{
			vec3(-1,-1,0),
			vec3(1,-1,0),
			vec3(1,1,0),
			vec3(-1,1,0)
		};


		if (GetAsyncKeyState('D') & 0x8000)
			time += 3*DeltaTime::GetFrameTime();
		
		for (int i = 0; i < 4; i++)
		{
			qua[i] = Rot * qua[i];
			qua[i] *= 0.5;
			//qua[i] += vec3(Terminal3D::GetScreenWidth() / 2, Terminal3D::GetScreenHeight() / 2, 0);
		}

		//Draw::Circle(vec2(0, 0),10, 'g');
		Draw::Quad_uv(qua, 'h');


		Terminal3D::Render();
		//std::cout << "\x1B[H";
		Terminal3D::ClearBuffer();
	}
	Terminal3D::Terminate();
}

