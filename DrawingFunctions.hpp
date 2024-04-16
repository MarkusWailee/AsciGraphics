#pragma once
#include "Terminal3D.hpp"





class Draw : Terminal3D //friend
{
public:
	static void Triangle(vec3 p1, vec3 p2, vec3 p3, char c);
	static void Triangle_uv(vec3* p, vec2* uv, char tex_code);
	static void Circle(vec2 position, float r, char character);
};


inline void Draw::Triangle_uv(vec3* p, vec2* uv, char tex_code)
{
	ASCI_Texture& tex = Get().textures[tex_code];
	if (tex.data == NULL)return;

	int min_x = min(min(p[0].x, p[1].x), p[2].x);
	int min_y = min(min(p[0].y, p[1].y), p[2].y);
	int max_x = max(max(p[0].x, p[1].x), p[2].x);
	int max_y = max(max(p[0].y, p[1].y), p[2].y);
	//prevent rendering off screen
	if (min_x < 0) min_x = 0;
	if (min_y < 0) min_y = 0;
	if (max_x > Terminal3D::GetScreenWidth()) max_x = Terminal3D::GetScreenWidth();
	if (max_y > Terminal3D::GetScreenHeight()) max_y = Terminal3D::GetScreenHeight();
	for (int posY = min_y; posY < max_y; posY++)
	{
		for (int posX = min_x; posX < max_x; posX++)
		{
			float w1, w2, w3;
			w2 = ((posY - p[0].y) * (p[2].x - p[0].x) - (posX - p[0].x) * (p[2].y - p[0].y)) /
				((p[1].y - p[0].y) * (p[2].x - p[0].x) - (p[1].x - p[0].x) * (p[2].y - p[0].y));
			w3 = ((posY - p[1].y) * (p[0].x - p[1].x) - (posX - p[1].x) * (p[0].y - p[1].y)) /
				((p[2].y - p[1].y) * (p[0].x - p[1].x) - (p[2].x - p[1].x) * (p[0].y - p[1].y));
			w1 = 1 - w2 - w3;
			vec3 pixel_position = vec3(posX, posY, p[0].z * w1 + p[1].z * w2 + p[2].z * w3);
			vec2 uv_cord = uv[0] * w1 + uv[1] * w2 + uv[2] * w3;
			int uv_x = uv_cord.x * tex.width;
			int uv_y = uv_cord.y * tex.height;
			if (!(w1 >= 0 && w1 <= 1 && w2 >= -0 && w2 <= 1 && w3 >= -0 && w3 <= 1))continue;
			Get().SetPixel(pixel_position, tex.data[uv_x + uv_y * tex.width]);
		}
	}
}

inline void Draw::Triangle(vec3 p1, vec3 p2, vec3 p3, char c) //RASTERIZER using barycentric coordinates
{
	int min_x = min(min(p1.x, p2.x), p3.x);
	int min_y = min(min(p1.y, p2.y), p3.y);
	int max_x = max(max(p1.x, p2.x), p3.x);
	int max_y = max(max(p1.y, p2.y), p3.y);
	//prevent rendering off screen
	if (min_x < 0) min_x = 0;
	if (min_y < 0) min_y = 0;
	if (max_x > Terminal3D::GetScreenWidth()) max_x = Terminal3D::GetScreenWidth();
	if (max_y > Terminal3D::GetScreenHeight()) max_y = Terminal3D::GetScreenHeight();
	for (int posY = min_y; posY < max_y; posY++)
	{
		for (int posX = min_x; posX < max_x; posX++)
		{
			float w1, w2, w3;
			w2 = ((posY - p1.y) * (p3.x - p1.x) - (posX - p1.x) * (p3.y - p1.y)) /
				((p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y));
			w3 = ((posY - p2.y) * (p1.x - p2.x) - (posX - p2.x) * (p1.y - p2.y)) /
				((p3.y - p2.y) * (p1.x - p2.x) - (p3.x - p2.x) * (p1.y - p2.y));
			w1 = 1 - w2 - w3;
			vec3 pixel_position = vec3(posX, posY, p1.z * w1 + p2.z * w2 + p3.z * w3);
			if (!(w1 >= -0 && w1 <= 1 && w2 >= 0 && w2 <= 1 && w3 >= 0 && w3 <= 1))continue;
			Get().SetPixel(pixel_position, c);
		}
	}
}


inline void Draw::Circle(vec2 position, float r, char character)
{
	int min_x = position.x - r;
	int min_y = position.y - r;
	int max_x = position.x + r;
	int max_y = position.y + r;
	for (int y = min_y; y <= max_y; y++)
		for (int x = min_x; x <= max_x; x++)
			if ((vec2(x, y) - position).mag() <= r)
				Terminal3D::SetPixel(vec3(x, y, 0), character);
}

