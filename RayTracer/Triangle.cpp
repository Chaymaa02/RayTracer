#include "Triangle.h"

bool Triangle::rayIntersection(Ray* ray) {

	glm::dvec3 rayStart = ray->getStartVertex();
	glm::dvec3 direction = ray->getDirection();


	glm::dvec3 rayToVertex = rayStart - glm::dvec3(v0);

	glm::dvec3 edge01 = glm::dvec3(v1) - glm::dvec3(v0);
	glm::dvec3 edge02 = glm::dvec3(v2) - glm::dvec3(v0);

	glm::normalize(direction);
	glm::dvec3 P = glm::cross(direction, edge02);
	glm::dvec3 Q = glm::cross(rayToVertex, edge01);

	float det = glm::dot(edge01, P);
	if (det < 0.00000001f) return false;

	float invDet = 1.0f / det;
	float u = glm::dot(P, rayToVertex)*invDet;

	if (u < 0.0f || u > 1.0f) return false;

	float v = glm::dot(Q, direction) * invDet;

	if (v < 0.0f || u + v > 1.0f) return false;

	double t = glm::dot(Q, edge02) * invDet;
	if (t < 0.0f) return false;

	if (t > DBL_EPSILON && t < DBL_MAX) {
		ray->setEndVertex(rayStart + direction * t);
		return true;
	} 

	return false;
}