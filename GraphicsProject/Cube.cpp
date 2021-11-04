#include "Cube.h"
#include "gl_core_4_4.h"

void Cube::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}
	int specularPower = glGetUniformLocation(program, "kSpecularPower");
	if (specularPower >= 0) {
		glUniform1f(specularPower, 30);
	}
	Mesh::onDraw();
}

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 8;
	vertices = new Vertex[vertexCount];

	vertices[0].position = { -1.0f,1.0f,-1.0f,1.0f };//a
	vertices[1].position = { -1.0f,1.0f,1.0f,1.0f };//b
	vertices[2].position = { 1.0f,1.0f,-1.0f,1.0f };//c
	vertices[3].position = { 1.0f,1.0f,1.0f,1.0f };//d

	vertices[4].position = { 1.0f,-1.0f,1.0f,1.0f };//e
	vertices[5].position = { 1.0f,-1.0f,-1.0f,1.0f };//f
	vertices[6].position = { -1.0f,-1.0f,1.0f,1.0f };//g
	vertices[7].position = { -1.0f,-1.0f,-1.0f,1.0f };//h

	vertices[0].normal = { -1.0f,1.0f,-1.0f,0.0f };//a
	vertices[1].normal = { -1.0f,1.0f,1.0f,0.0f };//b
	vertices[2].normal = { 1.0f,1.0f,-1.0f,0.0f };//c
	vertices[3].normal = { 1.0f,1.0f,1.0f,0.0f };//d
	vertices[4].normal = { 1.0f,-1.0f,1.0f,0.0f };//e
	vertices[5].normal = { 1.0f,-1.0f,-1.0f,0.0f };//f
	vertices[6].normal = { -1.0f,-1.0f,1.0f,0.0f };//g
	vertices[7].normal = { -1.0f,-1.0f,-1.0f,0.0f };//h

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].color = m_color;
	}
	return vertices;
}

unsigned int* Cube::generateIndices(unsigned int& indexCount)
{
	//Set the number of indices
	indexCount = 36;

	unsigned int* indices = new unsigned int[indexCount] {
		0, 1, 2,
		3, 1, 2,

		0, 1, 7,
		6, 1, 7,

		0, 2, 5,
		0, 7, 5,

		2, 3, 4,
		2, 4, 5,

		4, 5, 7,
		4, 7, 6,

		3, 1, 6,
		3, 6, 4
	};

	return indices;
}
