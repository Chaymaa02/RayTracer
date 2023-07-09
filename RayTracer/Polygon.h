#pragma once
#include <glm/glm.hpp>
#include "Ray.h"
#include "ColorDBL.h"
#include "Defintions.h"
#include <iostream>

class Polygon {
public:
	glm::dvec3 getNormal() {
		return normal;
	}

	virtual bool rayIntersection(Ray* ray) = 0;

	glm::dvec3 getColor() {
		return color;
	}

	void setColor(glm::dvec3 _color) {
		color = _color;
	}

	void setNormal(glm::dvec3 _normal) {
		normal = _normal;
	}

	Material getMaterial() {
		return material;
	}

	void setMaterial(MaterialType type, double rho) {
		material.type = type;
		material.rho = rho;
	}

	void setMaterial(MaterialType type) {
		material.type = type;
	}

	friend std::ostream& operator<<(std::ostream& os, const Polygon& rec)
	{
		os << "hej";
		return os;
	}

protected:
	glm::dvec3 normal;
	glm::dvec3 color;
	Material material;
};