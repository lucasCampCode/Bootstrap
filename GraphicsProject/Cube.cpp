#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* verticies = nullptr;
	triCount = 12;
	vertexCount = 36;
	verticies = new Vertex[vertexCount];
	
	
	setVertexPosition(verticies, vertexCount, 0, { -1.0f,1.0f,-1.0f });//A
	setVertexPosition(verticies, vertexCount, 0, { 1.0f,1.0f,1.0f });//B
	setVertexPosition(verticies, vertexCount, 0, { 1.0f,-1.0f,-1.0f });//C
	setVertexPosition(verticies, vertexCount, 0, { -1.0f,-1.0f,1.0f });//D
	setVertexPosition(verticies, vertexCount, 0, { 1.0f,1.0f,-1.0f });//E
	setVertexPosition(verticies, vertexCount, 0, { -1.0f,1.0f,1.0f });//F
	setVertexPosition(verticies, vertexCount, 0, { -1.0f,-1.0f,-1.0f });//G
	setVertexPosition(verticies, vertexCount, 0, { 1.0f,-1.0f,1.0f });//H

	return verticies;
}

void Cube::setVertexPosition(Vertex* verticies, int vertexCount, int index, glm::vec3 position)
{
	for (int i = index; i < vertexCount; i += 8) {
		verticies[i].position = glm::vec4(position,1.0f);
	}
}
