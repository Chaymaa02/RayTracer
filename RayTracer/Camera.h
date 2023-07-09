#pragma once

#include <fstream>
#include <glm/glm.hpp>
#include "Pixel.h"
#include "Scene.h"
#include <vector>

const int SIZE = 800;

class Camera
{
public:
	Camera();
	~Camera() {};

	void render(Scene scene);

	void createImage();


private:
	std::vector<std::vector<glm::dvec3>> image;
	glm::dvec3 eye1 = glm::dvec3(-1, 0, 0);
	double iMax = 0;    // The highest color value in the image
	
};
