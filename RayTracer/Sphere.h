#pragma once

#include <glm/glm.hpp>
#include "Ray.h"
#include "Polygon.h"
#include <iostream>

class Sphere : virtual public Polygon {
public:
	Sphere(double _radius, glm::dvec3 _center):radius(_radius), center(_center){}


	bool rayIntersection(Ray* ray) override;

	/*glm::dvec3 getColor() {
		return color;
	}*/

	void setRaduis(float _radius) {
		radius = _radius;
	}

	void setCenter(glm::vec4 _center) {
		center = _center;
	}


private:
	double radius;
	glm::dvec3 center;
};