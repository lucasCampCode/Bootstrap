#include "DragonWorld.h"

void DragonWorld::onStart()
{
	//camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	
	setCamera(m_camera);
	add(m_camera);

	//light
	m_light1 = new Light(
		0,
		{ 1.0f, 0.0f, 1.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 0.25f, 0.25f, 0.75f, 1.0f },
		{ 0.2f, 1.0f, 0.5f, 1.0f }
	);
	m_light1->setDirection({ -1.0f,-0.5f,-1.0f });
	add(m_light1);

	m_light2 = new Light(
		1,
		{ 0.0f, -0.5f, 0.5f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f }
	);
	m_light2->setDirection({ -1.0f,-0.5f,-1.0f });
	add(m_light2);

	//dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({5.0f,0.0f,0.0f});
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	m_cube = new Cube();
	m_cube->setColor({0.5f,0.5f,0.5f,1.0f});
	m_cube->getTransform()->setPosition({0.0f,0.0f,5.0f});
	add(m_cube);

	m_map = new TexturePlane("earth_diffuse.jpg", { 0.25f,0.25f,0.25f,1.0f });
	add(m_map);
}

void DragonWorld::onUpdate(float deltaTime)
{
	float rotationSpeed = 60.0f;
	rotationSpeed *= deltaTime;

	m_light2->getTransform()->rotate({ 0.0f,rotationSpeed,0.0f });
	
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light1);
	destroy(m_light2);
	destroy(m_dragon);
	destroy(m_cube);
}
