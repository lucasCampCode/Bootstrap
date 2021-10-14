#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount)
{
#pragma region normals
	glm::vec4 forwardNormal = { 0.0f,0.0f,1.0f,0.0f };
	glm::vec4 rightNormal = { 1.0f,0.0f,0.0f,0.0f };
	glm::vec4 upNormal = { 0.0f, 1.0f, 0.0f, 0.0f };
#pragma endregion

	Vertex* verticies = nullptr;
	vertexCount = 8;
	verticies = new Vertex[vertexCount];

	verticies[0].position = { -1.0f,1.0f,-1.0f,1.0f };//a
	verticies[1].position = { -1.0f,1.0f,1.0f,1.0f };//b
	verticies[2].position = { 1.0f,1.0f,-1.0f,1.0f };//c
	verticies[3].position = { 1.0f,1.0f,1.0f,1.0f };//d
	verticies[4].position = { 1.0f,-1.0f,1.0f,1.0f };//e
	verticies[5].position = { 1.0f,-1.0f,-1.0f,1.0f };//f
	verticies[6].position = { -1.0f,-1.0f,1.0f,1.0f };//g
	verticies[7].position = { -1.0f,-1.0f,-1.0f,1.0f };//h

	verticies[0].normal = { -1.0f,1.0f,-1.0f,0.0f };//a
	verticies[1].normal = { -1.0f,1.0f,1.0f,0.0f };//b
	verticies[2].normal = { 1.0f,1.0f,-1.0f,0.0f };//c
	verticies[3].normal = { 1.0f,1.0f,1.0f,0.0f };//d
	verticies[4].normal = { 1.0f,-1.0f,1.0f,0.0f };//e
	verticies[5].normal = { 1.0f,-1.0f,-1.0f,0.0f };//f
	verticies[6].normal = { -1.0f,-1.0f,1.0f,0.0f };//g
	verticies[7].normal = { -1.0f,-1.0f,-1.0f,0.0f };//h

	for (int i = 0; i < vertexCount; i++) {
		verticies[i].color = m_color;
	}
	return verticies;
}

void Cube::setVertexPosition(Vertex* verticies, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i += 8) {
		verticies[i].position = glm::vec4(position * 0.5f,1.0f);
		verticies[i].normal = glm::vec4(position, 0.0f);
		verticies[i].color = m_color;
	}
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
