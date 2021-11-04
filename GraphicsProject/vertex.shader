#version 410

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec4 vNormal;
layout(location = 2) in vec2 vTexCoord;
layout(location = 3) in vec4 vTangent;
layout(location = 4) in vec4 vColor;

uniform mat4 projectionViewMatrix;
uniform mat4 modelMatrix;

out vec4 fPosition;
out vec4 fNormal;
out vec4 fColor;
out vec2 fTexCoord;

void main() {
	fPosition = vPosition;
	fNormal = modelMatrix * vNormal;
	fColor = vColor;
	fTexCoord = vTexCoord;
	gl_Position = projectionViewMatrix * modelMatrix * vPosition;
}
