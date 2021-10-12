#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
#pragma region normals
	glm::vec4 forwardNormal = { 0.0f,0.0f,1.0f,0.0f };
	glm::vec4 rightNormal = { 1.0f,0.0f,0.0f,0.0f };
	glm::vec4 upNormal = { 0.0f, 1.0f, 0.0f, 0.0f };
#pragma endregion
#pragma region positions
	glm::vec4 cornerA = { -1.0f,1.0f,-1.0f,1.0f };
	glm::vec4 cornerB = { 1.0f,1.0f,1.0f,1.0f };
	glm::vec4 cornerC = { 1.0f,-1.0f,-1.0f,1.0f };
	glm::vec4 cornerD = { -1.0f,-1.0f,1.0f,1.0f };
	glm::vec4 cornerE = { 1.0f,1.0f,-1.0f,1.0f };
	glm::vec4 cornerF = { -1.0f,1.0f,1.0f,1.0f };
	glm::vec4 cornerG = { -1.0f,-1.0f,-1.0f,1.0f };
	glm::vec4 cornerH = { 1.0f,-1.0f,1.0f,1.0f };
#pragma endregion

	Vertex* verticies = nullptr;
	triCount = 12;
	vertexCount = 36;
	verticies = new Vertex[vertexCount];

	#pragma region backFace
	verticies[0].position = cornerA;
	verticies[0].normal = -forwardNormal;
	verticies[1].position = cornerE;
	verticies[1].normal = -forwardNormal;
	verticies[2].position = cornerC;
	verticies[2].normal = -forwardNormal;

	verticies[3].position = cornerA;
	verticies[3].normal = -forwardNormal;
	verticies[4].position = cornerG;
	verticies[4].normal = -forwardNormal;
	verticies[5].position = cornerC;
	verticies[5].normal = -forwardNormal;
	#pragma endregion
	#pragma region topFace
	verticies[6].position = cornerA;
	verticies[6].normal = upNormal;
	verticies[7].position = cornerE;
	verticies[7].normal = upNormal;
	verticies[8].position = cornerB;
	verticies[8].normal = upNormal;

	verticies[9].position = cornerA;
	verticies[9].normal = upNormal;
	verticies[10].position = cornerF;
	verticies[10].normal = upNormal;
	verticies[11].position = cornerB;
	verticies[11].normal = upNormal;
	#pragma endregion
	#pragma region leftFace
	verticies[12].position = cornerA;
	verticies[12].normal = -rightNormal;
	verticies[13].position = cornerF;
	verticies[13].normal = -rightNormal;
	verticies[14].position = cornerG;
	verticies[14].normal = -rightNormal;

	verticies[15].position = cornerG;
	verticies[15].normal = -rightNormal;
	verticies[16].position = cornerF;
	verticies[16].normal = -rightNormal;
	verticies[17].position = cornerD;
	verticies[17].normal = -rightNormal;
	#pragma endregion
	#pragma region frontFace
	verticies[18].position = cornerF;
	verticies[18].normal = forwardNormal;
	verticies[19].position = cornerB;
	verticies[19].normal = forwardNormal;
	verticies[20].position = cornerD;
	verticies[20].normal = forwardNormal;

	verticies[21].position = cornerH;
	verticies[21].normal = forwardNormal;
	verticies[22].position = cornerB;
	verticies[22].normal = forwardNormal;
	verticies[23].position = cornerD;
	verticies[23].normal = forwardNormal;
	#pragma endregion
	#pragma region rightFace
	verticies[24].position = cornerE;
	verticies[24].normal = rightNormal;
	verticies[25].position = cornerC;
	verticies[25].normal = rightNormal;
	verticies[26].position = cornerH;
	verticies[26].normal = rightNormal;

	verticies[27].position = cornerE;
	verticies[27].normal = rightNormal;
	verticies[28].position = cornerB;
	verticies[28].normal = rightNormal;
	verticies[29].position = cornerH;
	verticies[29].normal = rightNormal;
	#pragma endregion
	#pragma region bottomFace
	verticies[30].position = cornerG;
	verticies[30].normal = -upNormal;
	verticies[31].position = cornerC;
	verticies[31].normal = -upNormal;
	verticies[32].position = cornerD;
	verticies[32].normal = -upNormal;

	verticies[33].position = cornerH;
	verticies[33].normal = -upNormal;
	verticies[34].position = cornerC;
	verticies[34].normal = -upNormal;
	verticies[35].position = cornerD;
	verticies[35].normal = -upNormal;
	#pragma endregion

	for (int i = 0; i < vertexCount; i += 8) {
		verticies[i].color = m_color;
	}

	//setVertexPosition(verticies, vertexCount, 0, { -1.0f,1.0f,-1.0f });//A
	//setVertexPosition(verticies, vertexCount, 1, { 1.0f,1.0f,1.0f });//B
	//setVertexPosition(verticies, vertexCount, 2, { 1.0f,-1.0f,-1.0f });//C
	//setVertexPosition(verticies, vertexCount, 3, { -1.0f,-1.0f,1.0f });//D
	//setVertexPosition(verticies, vertexCount, 4, { 1.0f,1.0f,-1.0f });//E
	//setVertexPosition(verticies, vertexCount, 5, { -1.0f,1.0f,1.0f });//F
	//setVertexPosition(verticies, vertexCount, 6, { -1.0f,-1.0f,-1.0f });//G
	//setVertexPosition(verticies, vertexCount, 7, { 1.0f,-1.0f,1.0f });//H

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
