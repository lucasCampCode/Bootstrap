#pragma once
#include "World.h"
#include "PlayerCamera.h"
#include "Light.h"
#include "Cube.h"
#include "OBJMesh.h"
class DragonWorld :
	public World
{
public:
	void onStart() override;
	void onEnd() override;

private:
	PlayerCamera* m_camera = nullptr;
	Light* m_light1 = nullptr;
	Light* m_light2 = nullptr;
	OBJMesh* m_dragon = nullptr;
	Cube* m_cube = nullptr;
};

