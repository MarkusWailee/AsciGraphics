
#include <iostream>
#include "DeltaTime.hpp"
#include "Terminal3D.hpp"
#include "Draw3D.hpp"

//these includes were only used for the demo
#include "Meshes.h"
#include "Font.h"





// HOLDS CTR + Down_scroll



/*3D Graphics in ASCI
* This Demo is a spinnig asci "HELLOWORLD".
* 
* This Library allows for graphics to be drawn in the terminal.
* I have provided many functions like Draw::Triangle or Draw3D::plain for 3D objects
* 
* functions like Draw::Quad_uv or Plain_uv are used to Render specific textures.
* tex_codes are the keys givin to access the texture
*/


/* For Windows users, go into the camera header and uncomment the camera controls
* controls: w, a, s, d, space(fly up), c(fly down), and arrow keys for looking around
*/




int main()
{
	//window initialization
	Terminal3D::Init(150,100, '.');

	//DeltaTime::SetTargetFPS(60);

	float x = 40;
	float y = 0;


	
	Terminal3D::Add_Texture('H', Font::tex_HELLO_WORLD, 70, 7);
	Terminal3D::Add_Texture('W', Font::tex_W, 7, 7);
	Terminal3D::Add_Texture(0, Font::tex_error, 6, 6);
	Terminal3D::Add_Texture(1, Font::tex_HAPPY, 9, 8);


	Camera3D camera;

	using namespace Cube;

	camera.view = vec2(0, -0.5);
	camera.position = vec3(0, 1.5, 0);
	float time = 0;
	while (true)
	{
		DeltaTime::HandleTime();
		DeltaTime::ShowFPS();

		time += DeltaTime::GetFrameTime();
		camera.Update();

		//Demo
		mat3 RotX
		{
			cosf(time), 0, sinf(time),
			0,1,0,
			-sinf(time), 0 ,cosf(time)
		};

		vec3 h_world_f[4] =
		{
			vec3(-2, -0.5, -0.5),	//Bottom Left
			vec3(2, -0.5, -0.5),	//Bottom Right
			vec3(2, 0.5, -0.5),	//Top Right
			vec3(-2, 0.5, -0.5)	//Top Left
		};
		vec3 h_world_b[4] =
		{
			vec3(2, -0.5,	0.5),	//Bottom Left
			vec3(-2, -0.5,	0.5),	//Bottom Right
			vec3(-2, 0.5,	0.5),	//Top Right
			vec3(2, 0.5,	0.5)	//Top Left
		};
		vec3 h_world_r[4] =
		{
			vec3(2,-0.5,-0.5),
			vec3(2,-0.5,0.5),
			vec3(2,0.5,0.5),
			vec3(2,0.5,-0.5)
		};
		vec3 h_world_l[4] =
		{
			vec3(-2, -0.5, 0.5),
			vec3(-2, -0.5, -0.5),
			vec3(-2, 0.5, -0.5),
			vec3(-2,0.5,0.5)
		};
		vec3 h_world_t[4] =
		{
			vec3(-2, 0.5, -0.5),
			vec3(2, 0.5, -0.5),
			vec3(2, 0.5, 0.5),
			vec3(-2, 0.5, 0.5)
		};

		for (int i = 0; i < 4; i++)
		{
			h_world_f[i] = RotX * h_world_f[i];
			h_world_b[i] = RotX * h_world_b[i];
			h_world_r[i] = RotX * h_world_r[i];
			h_world_l[i] = RotX * h_world_l[i];
			h_world_t[i] = RotX * h_world_t[i];
		}
		
		//rendering to the string
		Draw3D::Plain_uv(vec3(0, 0,3), h_world_f, 'H', camera);
		Draw3D::Plain_uv(vec3(0, 0, 3), h_world_b, 'H', camera);
		Draw3D::Plain_uv(vec3(0, 0, 3), h_world_r, 0, camera);
		Draw3D::Plain_uv(vec3(0, 0, 3), h_world_l, 1, camera);
		Draw3D::Plain(vec3(0, 0, 3), h_world_t, '[', camera);


		Terminal3D::Render();// <- couts the string
		Terminal3D::ClearBuffer();
	}
	Terminal3D::Terminate();
}

