#include "Camera.h"
#include <time.h>


int main() {
	Scene scene;
	Camera camera;

	clock_t startTime = clock();

	int numberRays = 10;
	int numberShadowRays = 10;
	int maxRayDepth = 10;
	scene.setParams(numberRays, numberShadowRays, maxRayDepth);
	scene.createScene();

	camera.render(scene);
	camera.createImage();

	std::cout  << "time elapsed: " << (double)(clock() - startTime) / CLOCKS_PER_SEC << std::endl;

}