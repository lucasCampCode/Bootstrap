#include "Engine.h"
#include "DragonWorld.h"

int main() {
	Engine* engine = new Engine(1280, 720, "Graphics");

	DragonWorld* dragonWorld = new DragonWorld();

	engine->setActiveWorld(dragonWorld);

	int exitCode = engine->run();

	delete dragonWorld;
	delete engine;

	return exitCode;
}