#pragma once

#include "Triangle.h"

class Tetrahedron : virtual public Polygon {
public:
	Tetrahedron(glm::dvec3 _v0, glm::dvec3 _v1, glm::dvec3 _v2, glm::dvec3 _v3) {
		Triangle t0(_v0, _v1, _v2);
		Triangle t1(_v0, _v3, _v1);
		Triangle t2(_v1, _v3, _v2);
		Triangle t3(_v2, _v3, _v0);
		triangles[0] = t0;
		triangles[1] = t1;
		triangles[2] = t2;
		triangles[3] = t3;
	};

	bool rayIntersection(Ray* ray) override;

private:
	Triangle triangles[4];

};
