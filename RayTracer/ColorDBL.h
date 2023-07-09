#pragma once
#include <glm/glm.hpp>

class ColorDBL
{
public:
	
	void SetColor(glm::vec3 _color) {
		color = _color;
	}

	glm::vec3 getColor() {
		return color;
	}

private:
	glm::vec3 color;
};