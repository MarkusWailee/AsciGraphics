#include "Draw.hpp"
#include "Camera3D.hpp"


class Draw3D : Draw
{
public:
	static void Plain_uv(vec3* vertices4, char tex_code, Camera3D camera);
};

inline void Draw3D::Plain_uv(vec3* vertices4, char tex_code, Camera3D camera)
{
	vec3 quad_vertices[4];
	for (int i = 0; i < 4; i++)
	{
		vec3 vertice = vertices4[i];
		vertice -= camera.position;
		vertice = camera.RotXAxis() * camera.RotYAxis() * vertice;
		vertice = vec3(vertice.x / vertice.z, vertice.y / vertice.z, vertice.z);
		quad_vertices[i] = vertice;
	}
	Quad_uv(quad_vertices, tex_code);
}


