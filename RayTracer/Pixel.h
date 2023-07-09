#pragma once

#include "Ray.h"

class Pixel
{
public:

	glm::dvec3 color() {
		return _color;
	}
	
	void setColor(double _red, double _green, double _blue) {
		_color = glm::dvec3(_red, _green, _blue);
	}
private:
	glm::dvec3 _color;
	Ray ray;
};
