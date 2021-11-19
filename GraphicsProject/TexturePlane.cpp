#include "TexturePlane.h"
#include <gl_core_4_4.h>
#include "GLFW/glfw3.h"


void TexturePlane::onStart()
{
	Quad::onStart();
	//load texture
	if (!m_texture.load(m_fileName)) {
		printf("Failed to load texture");
	}
}

void TexturePlane::onDraw()
{
	//select current shader program
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	//not found return warning
	if (program == -1)
		printf("no shader bound.\n");

	//gets uniform location in shader
	int diffuseTextureUniform = glGetUniformLocation(program, "diffuseTexture");

	//get the attribute from uniform
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);

	//set the uniform to take a texture
	glActiveTexture(GL_TEXTURE0);

	//bind texture to uniform
	glBindTexture(GL_TEXTURE_2D, m_texture.getHandle());
	Quad::onDraw();
}
