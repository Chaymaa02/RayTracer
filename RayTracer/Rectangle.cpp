#include "Rectangle.h"

bool Rectangle::rayIntersection(Ray* ray) {

	glm::dvec3 rayStart = ray->getStartVertex();
	glm::dvec3 direction = ray->getDirection();

	glm::dvec3 startToVertex =  glm::dvec3(v0) - rayStart; // (v - s)

	/*

	
	   v3 *-----------* v2
		  |           |
		  |           |
		  |           |
	edge2 |           |
		  |           |
		  |           |
	   v0 *-----------* v1
			 edge 1
	*/


	glm::dvec3 edge1 = glm::dvec3(v1) - glm::dvec3(v0);
	glm::dvec3 edge2 = glm::dvec3(v3) - glm::dvec3(v0);

	// t = ((v - s) * N) / (d * N)

	float t = glm::dot(startToVertex, normal) / glm::dot(direction, normal);

	if (t < 0.0f) return false;

	//Intersection point
	glm::dvec3 xi = rayStart + glm::dvec3(direction.x*t, direction.y*t, direction.z*t);

	double a = glm::dot((glm::dvec3(xi) - glm::dvec3(v0)), edge1) / (glm::dot(edge1, edge1));
	double b = glm::dot((glm::dvec3(xi) - glm::dvec3(v0)), edge2) / (glm::dot(edge2, edge2));

	if ((a >= 0 && a <= 1) && (b >= 0 && b <= 1)) {
		ray->setEndVertex(xi);
		return true;
	}

	return false;
}