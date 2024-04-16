#include "Windows.h"
#include <iostream>
#include "DeltaTime.hpp"
#include "Terminal3D.hpp"
#include "Draw3D.hpp"



int main()
{

	Terminal3D::Init(200,180, '0');
	Terminal3D::Render();

	//DeltaTime::SetTargetFPS(60);

	float x = 40;
	float y = 0;
	
	float time = 0;

	char Tex_h[] =
	{
		'o','o','o','o','o','o',
		'o','.','o','o','.','o',
		'o','.','o','o','.','o',
		'o','.','o','o','.','o',
		'o','.','.','.','.','o',
		'o','.','o','o','.','o',
		'o','.','o','o','.','o',
		'o','.','o','o','.','o',
		'o','o','o','o','o','o',
	};

	char Tex_e[] =
	{
		'o','o','o','o','o',
		'o','.','.','.','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','.','.','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','.','.','o',
		'o','o','o','o','o'
	};

	char Tex_l[] =
	{
		'o','o','o','o','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','o','o','o',
		'o','.','.','.','o',
		'o','o','o','o','o'
	};

	char Tex_o[] =
	{
		'o','o','o','o','o',
		'o','.','.','.','o',
		'o','.','o','.','o',
		'o','.','o','.','o',
		'o','.','o','.','o',
		'o','.','o','.','o',
		'o','.','o','.','o',
		'o','.','.','.','o',
		'o','o','o','o','o'
	};
	Terminal3D::Add_Texture('o', Tex_o, 5, 9);
	Terminal3D::Add_Texture('l', Tex_l, 5, 9);
	Terminal3D::Add_Texture('e', Tex_e, 5, 9);
	Terminal3D::Add_Texture('h', Tex_h, 6, 9);

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

		vec3 H[] =
		{
			vec3(-1,-2,0),
			vec3(1,-2,0),
			vec3(1,2,0),
			vec3(-1,2,0)
		};

		vec3 E[4];
		vec3 L[4];
		vec3 L2[4];
		vec3 O[4];


		if (GetAsyncKeyState('F') & 0x8000)
			time += 3*DeltaTime::GetFrameTime();

		camera.Update();
		
		for (int i = 0; i < 4; i++)
		{
			H[i] *= 2;
			H[i] = Rot * H[i];
			E[i] = H[i] + vec3(-2, 0, 1)* 2;
			L[i] = H[i] + vec3(0, 0, 2)	* 2;
			L2[i] = H[i] + vec3(2, 0, 1)* 2;
			O[i] = H[i] + vec3(4, 0, 2)	* 2;
			H[i] += vec3(-4, 1, 4)		* 2;
		}

		//Draw::Circle(vec2(0, 0),10, 'g');
		//Draw::Quad_uv(qua, 'h');
		Draw3D::Plain_uv(H, 'h', camera);
		Draw3D::Plain_uv(E, 'e', camera);
		Draw3D::Plain_uv(L, 'l', camera);
		Draw3D::Plain_uv(L2, 'l', camera);
		Draw3D::Plain_uv(O, 'o', camera);


		Terminal3D::Render();
		//std::cout << "\x1B[H";
		Terminal3D::ClearBuffer();
	}
	Terminal3D::Terminate();
}

