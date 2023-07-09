#pragma once

#include <glm/glm.hpp>
#include "Defintions.h"

class Ray {
public:
	Ray(glm::dvec3 _startVertex, glm::dvec3 _endVertex) : startVertex{ _startVertex }, endVertex{_endVertex} {
		direction = glm::normalize(_endVertex - _startVertex);
		color = glm::dvec3(1, 1, 1);
	}

	Ray(glm::dvec3 _startVertex, glm::dvec3 _direction, glm::dvec3 _color) : startVertex{ _startVertex }, direction{ _direction }, color{_color} {
		//direction = glm::normalize(_endVertex - _startVertex);
	}
	
	glm::dvec3 getStartVertex() {
		return startVertex;
	}

	glm::dvec3 getEndVertex() {
		return endVertex;
	}

	void setEndVertex(glm::dvec3 vertex) {
		endVertex = vertex;
	}

	glm::dvec3 getDirection() {
		return direction;
	}

	glm::dvec3 getColor() {
		return color;
	}

	void setColor(glm::dvec3 _color) {
		color = _color;
	}

	RayType getType() {
		return type;
	}

	void setType(RayType _type) {
		type = _type;
	}

private:
	glm::dvec3 startVertex;
	glm::dvec3 endVertex;
	glm::dvec3 direction;
	glm::dvec3 color;
	RayType type = Outside;
};