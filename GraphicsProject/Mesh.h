#pragma once
#include "Entity.h"
#include "gl_core_4_4.h"
#include "glm\vec4.hpp"
#include "glm\mat4x4.hpp"

class Mesh : public Entity
{
public:
	struct Vertex {
		glm::vec4 position = glm::vec4(0.0f);
		glm::vec4 color = glm::vec4(1.0f);
	};

public:
	Mesh();
	~Mesh();

	void onStart() override;
	void onDraw() override;

private:
	virtual Vertex* generateVertices(unsigned int& vertexCount, unsigned int& triCount) = 0;

private:
	unsigned int m_triCount;
	unsigned int m_vertexArrayObject, m_vertexBufferObject, m_indexBufferObject;
};
