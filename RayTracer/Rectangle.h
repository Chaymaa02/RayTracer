#pragma once

#include <glm/glm.hpp>
#include "Ray.h"
#include "Polygon.h"
#include <iostream>

class Rectangle : virtual public Polygon{
public:
	
	Rectangle(glm::dvec3 _v0, glm::dvec3 _v1, glm::dvec3 _v2, glm::dvec3 _v3) : v0{ _v0 }, v1{ _v1 }, v2{ _v2 }, v3{_v3} {
		//Default values for the color and normal, will be set later by hand for now
		color = glm::dvec3(1, 1, 1);
		//normal = glm::dvec3(0, 0, 0);

		glm::dvec3 c1 = (glm::dvec3(v1) - glm::dvec3(v0));
		glm::dvec3 c2 = (glm::dvec3(v3) - glm::dvec3(v0));
		normal = glm::normalize(glm::cross(c1, c2));
	}

	bool rayIntersection(Ray* ray) override;

	/*glm::dvec3 getColor() {
		return color;
	}*/

	void setVertices(glm::dvec3 _v0, glm::dvec3 _v1, glm::dvec3 _v2, glm::dvec3 _v3) {
		v0 = _v0;
		v1 = _v1;
		v2 = _v2;
		v3 = _v3;
	}

	glm::dvec3 getV0() {
		return v0;
	}
	glm::dvec3 getV1() {
		return v1;
	}
	glm::dvec3 getV2() {
		return v2;
	}
	glm::dvec3 getV3() {
		return v3;
	}


	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
	{
		os << "(" << rec.v0.x << ", " << rec.v0.y << ", "<< rec.v0.z << ")" << "  " << "(" << rec.v1.x << ", " << rec.v1.y << ", " << rec.v1.z << ")" << "  " << "(" << rec.v2.x << ", " << rec.v2.y << ", " << rec.v2.z << ")" << "  " << "(" << rec.v3.x << ", " << rec.v3.y << ", " << rec.v3.z << ")" << std::endl;
		return os;
	}

private:
	glm::dvec3 v0, v1, v2, v3;
};