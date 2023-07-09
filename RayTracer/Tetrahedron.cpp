#include "Tetrahedron.h"

bool Tetrahedron::rayIntersection(Ray* ray) {
	for (int i = 0; i < 4; ++i) {
		if (glm::dot(ray->getDirection(), triangles[i].getNormal()) < 0 && triangles[i].rayIntersection(ray)) {
			normal = triangles[i].getNormal();
			return true;
		}
	}
	return false;
}
