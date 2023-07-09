#pragma once

#include <cmath>
#include <vector>

#include "Triangle.h"
#include "Rectangle.h"
#include "Ray.h"
#include "Sphere.h"
#include "Tetrahedron.h"



class Scene
{
public:
	Scene();
	~Scene();

	Polygon* getIntersectedPolygon(Ray* ray);
	void createScene();
	glm::dvec3 castRays(Ray& ray, int rayDepth);
	glm::dvec3 compute_total_direct_light(glm::dvec3 intersectionVertex, Polygon* object);
	void setParams(int _numberRays, int _numberShadowRays, int _maxRayDepth) {
		numberRays = _numberRays;
		numberShadowRays = _numberShadowRays;
		maxRayDepth = _maxRayDepth;
	}
	int getNumberRays() {
		return numberRays;
	}
private:
	std::vector<Polygon*> polygons; //Walls of the room
	std::vector<Polygon*> objects;  //objects added to the scene (sphere, tetrahedron,..)
	std::vector<Rectangle*> lights; //light sources contained in the scene

	int numberRays = 5;  //number of rays we cast per pixel
	int numberShadowRays = 10; //number of shadow rays we cast per intersection
	int maxRayDepth = 10; //maximum ray depth : The depth of the ray implies how many times the ray has bounced
};