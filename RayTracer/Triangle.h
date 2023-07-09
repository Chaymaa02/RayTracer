#pragma once

#include <glm/glm.hpp>
#include "Ray.h"
#include "Polygon.h"
#include <iostream>

class Triangle : virtual public Polygon{
public:

	Triangle() = default;

	Triangle(glm::dvec3 _v0, glm::dvec3 _v1, glm::dvec3 _v2) : v0{ _v0 }, v1{ _v1 }, v2{_v2} {
		//Default values for the color and normals will be set later by hand for now
		color = glm::dvec3(1, 1, 1);
		glm::dvec3 edge1 = (_v1 - _v0);
		glm::dvec3 edge2 = (_v2 - _v0);

		normal = glm::normalize(glm::cross(edge1, edge2));
	}


	bool rayIntersection(Ray* ray) override;

	/*glm::dvec3 getColor() {
		return color;
	}*/

	void setVertices(glm::dvec3 _v0, glm::dvec3 _v1, glm::dvec3 _v2) {
		v0 = _v0;
		v1 = _v1;
		v2 = _v2;
	}


	friend std::ostream& operator<<(std::ostream& os, const Triangle& rec)
	{
		os << "(" << rec.v0.x << ", " << rec.v0.y << ", " << rec.v0.z << ")" << "  " << "(" << rec.v1.x << ", " << rec.v1.y << ", " << rec.v1.z << ")" << "  " << "(" << rec.v2.x << ", " << rec.v2.y << ", " << rec.v2.z << ")" << std::endl;
		return os;
	}

private:
	glm::dvec3 v0, v1, v2;
};