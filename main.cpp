#include "Windows.h"
#include <iostream>
#include "DeltaTime.hpp"
#include "Terminal3D.hpp"
#include "Draw3D.hpp"



int main()
{

	Terminal3D::Init(80,60, '.');
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

	char tex2[] =
	{
		'#',' ','#',
		' ','#',' ',
		'#',' ','#'
	};
	Terminal3D::Add_Texture('p', tex2, 3, 3);
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


	Camera3D camera;




	while (true)
	{
		DeltaTime::HandleTime();
		DeltaTime::ShowFPS();


		mat3 Rot =
		{
			cosf(time), 0, sinf(time),
			0,1,0,
			-sinf(time), 0 ,cosf(time)
		};

		vec3 qua[] =
		{
			vec3(-1,-1,0),
			vec3(1,-1,0),
			vec3(1,1,0),
			vec3(-1,1,0)
		};


		if (GetAsyncKeyState('F') & 0x8000)
			time += 3*DeltaTime::GetFrameTime();

		if (GetAsyncKeyState('D') & 0x8000)
			camera.position.x += 5 * DeltaTime::GetFrameTime();
		if (GetAsyncKeyState('A') & 0x8000)
			camera.position.x -= 5 * DeltaTime::GetFrameTime();
		if (GetAsyncKeyState('W') & 0x8000)
			camera.position.z += 5 * DeltaTime::GetFrameTime();
		if (GetAsyncKeyState('S') & 0x8000)
			camera.position.z -= 5 * DeltaTime::GetFrameTime();
		
		for (int i = 0; i < 4; i++)
		{
			qua[i] = Rot * qua[i];
			qua[i] += vec3(0, 0, 2);
		}

		//Draw::Circle(vec2(0, 0),10, 'g');
		//Draw::Quad_uv(qua, 'h');
		Draw3D::Plain_uv(qua, 'h', camera);


		Terminal3D::Render();
		//std::cout << "\x1B[H";
		Terminal3D::ClearBuffer();
	}
	Terminal3D::Terminate();
}

