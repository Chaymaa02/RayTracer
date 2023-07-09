#include "Scene.h"
#include <iostream>
#include <random>
#include <corecrt_math_defines.h>

Scene::Scene()
{
}

void Scene::createScene() {
	//Floor
	Rectangle floorRect(glm::dvec3(0, 6, -5), glm::dvec3(0, -6, -5), glm::dvec3(10, -6, -5), glm::dvec3(10, 6, -5));
	Triangle floorTr1(glm::dvec3(10, 6, -5), glm::dvec3(10, -6, -5), glm::dvec3(13, 0, -5));
	Triangle floorTr2(glm::dvec3(0, 6, -5), glm::dvec3(-3, 0, -5), glm::dvec3(0, -6, -5));

	floorRect.setColor(glm::dvec3(1, 0.5, 0.7));
	floorTr1.setColor(glm::dvec3(1, 0.5, 0.7));
	floorTr2.setColor(glm::dvec3(1, 0.5, 0.7));

	//Roof
	Rectangle roofRect(glm::dvec3(0, 6, 5), glm::dvec3(10, 6, 5), glm::dvec3(10, -6, 5), glm::dvec3(0, -6, 5));
	Triangle roofTr1(glm::dvec3(10, 6, 5), glm::dvec3(13, 0, 5), glm::dvec3(10, -6, 5));
	Triangle roofTr2(glm::dvec3(0, 6, 5), glm::dvec3(0, -6, 5), glm::dvec3(-3, 0, 5));

	roofRect.setColor(glm::dvec3(0.4, 0.3, 0.6));
	roofTr1.setColor(glm::dvec3(0.4, 0.3, 0.6));
	roofTr2.setColor(glm::dvec3(0.4, 0.3, 0.6));

	//Left Wall
	Rectangle leftWall1(glm::dvec3(-3, 0, 5), glm::dvec3(-3, 0, -5), glm::dvec3(0, 6, -5), glm::dvec3(0, 6, 5));
	Rectangle leftWall2(glm::dvec3(0, 6, 5), glm::dvec3(0, 6, -5), glm::dvec3(10, 6, -5), glm::dvec3(10, 6, 5));
	Rectangle leftWall3(glm::dvec3(10, 6, 5), glm::dvec3(10, 6, -5), glm::dvec3(13, 0, -5), glm::dvec3(13, 0, 5));

	leftWall1.setColor(glm::dvec3(0.1, 0.7, 0.7));
	leftWall2.setColor(glm::dvec3(0.3, 0.7, 0.2));
	leftWall3.setColor(glm::dvec3(0.1, 0.0, 0.9));

	//Right Wall
	Rectangle rightWall1(glm::dvec3(-3, 0, 5), glm::dvec3(0, -6, 5), glm::dvec3(0, -6, -5), glm::dvec3(-3, 0, -5));
	Rectangle rightWall2(glm::dvec3(0, -6, 5), glm::dvec3(10, -6, 5), glm::dvec3(0, -6, -5), glm::dvec3(10, -6, -5));
	Rectangle rightWall3(glm::dvec3(10, -6, 5), glm::dvec3(13, 0, 5), glm::dvec3(13, 0, -5), glm::dvec3(10, -6, -5));

	rightWall1.setColor(glm::dvec3(0.7, 0.7, 0.1));
	rightWall2.setColor(glm::dvec3(0.2, 0.3, 0.6));
	rightWall3.setColor(glm::dvec3(0.1, 0.6, 0.3));

	//rightWall3.setMaterial(Mirror);
	//rightWall3.setMaterial(Lambertian, 0.8);
	//roofRect.setMaterial(Lambertian, 0.8);
	//floorTr1.setMaterial(Lambertian, 0.8);

	//Sphere
	Sphere sphere1(1.2, glm::dvec3(6.0, -3.5, -2.0));
	sphere1.setColor(glm::dvec3(1.0, 1.0, 1.0));
	sphere1.setMaterial(Mirror, 0.95);

	Sphere sphere2(2.0, glm::dvec3(10.0, -1.0, -1.0));
	sphere2.setColor(glm::dvec3(1.0, 1.0, 1.0));
	sphere2.setMaterial(Transparent);
	//z, x, y
	Sphere sphere3(1.0, glm::dvec3(6.0, 3, -3.0));
	sphere3.setColor(glm::dvec3(0.92, 0.71, 0.07));
	sphere3.setMaterial(Lambertian, 0.6);

	//Tetrahedron
	Tetrahedron tetrahedron(glm::dvec3(8.0, 2.0, 1.0), glm::dvec3(7.0, 2.0, -2.0), glm::dvec3(8.0, 1.0, -2.0), glm::dvec3(8.0, 3.0, -2.0));
	tetrahedron.setColor(glm::dvec3(0.8, 0.2, 0.6));

	Tetrahedron tetrahedron2(glm::dvec3(7.0, -4.0, -4.0), glm::dvec3(5.0, -2.0, -5.0), glm::dvec3(7.0, 0.0, -5.0), glm::dvec3(6.0, -2.0, -5.0));
	tetrahedron2.setColor(glm::dvec3(0.3, 0.2, 0.8));

	//Add light
	Rectangle lightSource{ glm::dvec3(4.0, -1.0, 5.0), glm::dvec3(4.0, 1.0, 5.0), glm::dvec3(6.0, 1.0, 5.0), glm::dvec3(6.0, -1.0, 5.0) };
	lightSource.setColor(glm::dvec3(1, 1, 1));
	lightSource.setMaterial(Light);

	lights.push_back(new Rectangle(lightSource));

	//ADDING ALL THE OBJECTS TO THE LIST
	objects.push_back(new Tetrahedron(tetrahedron));
	objects.push_back(new Sphere(sphere2));
	objects.push_back(new Sphere(sphere1));
	objects.push_back(new Tetrahedron(tetrahedron2));
	objects.push_back(new Sphere(sphere3));

	//Walls
	polygons.push_back(new Rectangle(floorRect));
	polygons.push_back(new Triangle(floorTr1));
	polygons.push_back(new Triangle(floorTr2));
	polygons.push_back(new Rectangle(roofRect));
	polygons.push_back(new Triangle(roofTr1));
	polygons.push_back(new Triangle(roofTr2));
	polygons.push_back(new Rectangle(leftWall1));
	polygons.push_back(new Rectangle(leftWall2));
	polygons.push_back(new Rectangle(leftWall3));
	polygons.push_back(new Rectangle(rightWall1));
	polygons.push_back(new Rectangle(rightWall2));
	polygons.push_back(new Rectangle(rightWall3));

}
Scene::~Scene()
{
}

Polygon* Scene::getIntersectedPolygon(Ray* ray) {
	glm::dvec3 startVertex = ray->getStartVertex();

	double minDist = 100000000000.0;
	Polygon* intersectedObject = nullptr;
	//check if the ray intersected any object in the scene
	for (auto polygon : objects) {
		if (polygon->rayIntersection(ray) ) {
			//std::cout << "found polygon " << polygon->getColor().x << ", " << polygon->getColor().y << ", " << polygon->getColor().z << "\n";
			//std::cout << "found polygon " << polygon->getNormal().x << ", " << polygon->getNormal().y << ", " << polygon->getNormal().z << std::endl;
			
			// Compute distance between the intersection point and the starting point of the ray
			double dist = glm::length(ray->getEndVertex() - startVertex);

			// Check the closest intersected polygon 
			if (dist < minDist) {
				minDist = dist;
				intersectedObject = polygon;
			}
		}
	}
	//check if the ray intersected the walls of the room in the scene
	if (intersectedObject == nullptr) {
		for (auto polygon : lights) {
			if (polygon->rayIntersection(ray)) {
				// Compute distance between the intersection point and the starting point of the ray
				double dist = glm::length(ray->getEndVertex() - startVertex);

				// Check the closest intersected polygon 
				if (dist < minDist) {
					minDist = dist;
					intersectedObject = polygon;
				}
			}
		}
		for (auto polygon : polygons) {
			if (polygon->rayIntersection(ray)) {
				// Compute distance between the intersection point and the starting point of the ray
				double dist = glm::length(ray->getEndVertex() - startVertex);

				// Check the closest intersected polygon 
				if (dist < minDist) {
					minDist = dist;
					intersectedObject = polygon;
					break;
				}
			}
		}
	}
	return intersectedObject;
}

glm::dvec3 Scene::castRays(Ray& ray, int rayDepth){
	if (rayDepth > maxRayDepth) {
		ray.setColor(glm::dvec3(0.0, 0.0, 0.0));
		return ray.getColor();
	}
	auto object = getIntersectedPolygon(&ray);
	if (object == nullptr) {
		ray.setColor(glm::dvec3(0.0, 0.0, 0.0));
		return ray.getColor();
	}

	glm::dvec3 intersectionVertex = ray.getEndVertex() + object->getNormal() * 1e-7;
	glm::dvec3 normal = object->getNormal();
	glm::dvec3 direction = ray.getDirection();

	//--------------------------------------------------------------------
	if (object->getMaterial().type == Light) {
		ray.setColor(glm::dvec3(1, 1, 1));
	}
	//--------------------------------------------------------------------
	else if (object->getMaterial().type == Mirror) {
		//create new ray
		double kr = object->getMaterial().rho; //amount of reflected light
		glm::dvec3 newDirection = glm::normalize(glm::reflect(direction, normal));
		Ray reflected(intersectionVertex, newDirection, ray.getColor() * kr);
		//cast the new ray to the scene
		reflected.setColor(castRays(reflected, rayDepth + 1));
		//set final color to the ray
		ray.setColor(reflected.getColor());
	}
	//--------------------------------------------------------------------
	else if (object->getMaterial().type == Lambertian) {
		// Create uniformly distributed numbers between 0 and 1
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dist(0.0, 1.0);
		// The random number
		double y = dist(gen);

		double Rho = object->getMaterial().rho;

		// Calculate azimuth angle (theta)
		double theta = 2.0 * M_PI * y / Rho;

		// Calculate inclination angle (phi)
		double phi = acos(sqrt(1.0 - y));
		if (theta <= 2.0 * M_PI) {
			// Convert spherical coordinates to Cartesian coordinates
			double xu = sin(phi) * cos(theta);
			double yu = sin(phi) * sin(theta);
			double zu = cos(phi);

			// Define a local coordinate system
			glm::dvec3 zdirection = normal;
			glm::dvec3 xdirection = glm::normalize(-1.0 * direction + glm::dot(normal, direction) * normal);
			glm::dvec3 ydirection = glm::cross(zdirection, xdirection);

			// Projecting the random point on the unit hemisphere into the true hemisphere
			double x = xu * xdirection.x + yu * xdirection.y + zu * xdirection.z;
			double y = xu * ydirection.x + yu * ydirection.y + zu * ydirection.z;
			double z = xu * zdirection.x + yu * zdirection.y + zu * zdirection.z;
			glm::dvec3 newendpoint = glm::dvec3(x, y, z);

			// Creating the new ray emitted in the random direction we have sampled
			glm::dvec3 newstartpoint = ray.getEndVertex();
			//create a new ray
			Ray emitted(newstartpoint, glm::normalize(newendpoint - newstartpoint), ray.getColor() * Rho);
			//cast the new ray to the scene
			emitted.setColor(castRays(emitted, rayDepth + 1));
			//set final color to the ray
			glm::dvec3 totalDirectLight = compute_total_direct_light(intersectionVertex, object);
			ray.setColor(Rho/M_PI * object->getColor() * emitted.getColor() + totalDirectLight);
		}
		else {
			//Compute the total direct light
			glm::dvec3 totalDirectLight = compute_total_direct_light(intersectionVertex, object);
			ray.setColor(totalDirectLight);
		}

	}
	//--------------------------------------------------------------------
	else if (object->getMaterial().type == Transparent) {
		// Create uniformly distributed numbers between 0 and 1
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dist(0.0, 1.0);
		// The random number
		double y = dist(gen);

		// Declare variables
		double n1 = 1.0; // air
		double n2 = 1.5; // glass

		if (ray.getType() == Inside) {
			normal = -normal;
			// Schlick’s law gave us the reflection coefficient  R and the transmission coefficient T
			double cosOmega = glm::dot(-direction, normal);
			double R0 = pow(((n2 - n1) / (n1 + n2)), 2);
			double R = R0 + (1.0 - R0) * pow((1.0 - cosOmega), 5);
			double T = 1.0 - R;

			if (sin(acos(cosOmega)) * n2 / n1 > 1) {//cast reflected ray only no refraction
				R = 1.0;
				Ray reflected(intersectionVertex, glm::normalize(glm::reflect(direction, normal)), R * ray.getColor());
				reflected.setType(Inside);
				//cast the new ray to the scene
				reflected.setColor(castRays(reflected, rayDepth + 1));
				//set final color to the ray
				ray.setColor(R * reflected.getColor());
			}
			else {
				if (y < R) {
					//cast reflected ray
					Ray reflected(intersectionVertex, glm::normalize(glm::reflect(direction, normal)), ray.getColor());
					reflected.setType(Inside);
					reflected.setColor(castRays(reflected, rayDepth + 1));
					ray.setColor(R *  reflected.getColor());
				}
				else {
					//cast refracted ray
					glm::dvec3 dir = glm::normalize((n2 / n1) * direction + normal * (-(n2 / n1) * glm::dot(normal, direction) - sqrt(1.0 - pow((n2 / n1), 2.0) * (1.0 - pow(glm::dot(normal, direction), 2.0)))));
					Ray refracted(ray.getEndVertex() - normal * 1e-7, dir, ray.getColor());
					refracted.setType(Outside);
					refracted.setColor(castRays(refracted, rayDepth + 1));
					ray.setColor(T * refracted.getColor());
				}
				//ray.setColor(reflected.getColor() * R + refracted.getColor() * T);

			}
		}
		else {
			// Schlick’s law gave us the reflection coefficient  R and the transmission coefficient T
			double cosOmega = glm::dot(-direction, normal);
			double R0 = pow(((n1 - n2) / (n1 + n2)), 2);
			double R = R0 + (1.0 - R0) * pow((1.0 - cosOmega), 5);
			double T = 1.0 - R;

			if (y < R) {
				//cast reflected ray
				Ray reflected(intersectionVertex, glm::normalize(glm::reflect(direction, normal)), ray.getColor());
				reflected.setType(Outside);
				reflected.setColor(castRays(reflected, rayDepth + 1));
				ray.setColor(R * reflected.getColor());
			}
			else {
				//cast refracted ray
				glm::dvec3 dir = glm::normalize((n1 / n2) * direction + normal * (-(n1 / n2) * glm::dot(normal, direction) - sqrt(1.0 - pow((n1 / n2), 2.0) * (1.0 - pow(glm::dot(normal, direction), 2.0)))));
				Ray refracted(ray.getEndVertex() - normal * 1e-7, dir, ray.getColor());
				refracted.setType(Inside);
				refracted.setColor(castRays(refracted, rayDepth + 1));
				ray.setColor(T * refracted.getColor());
			}
			//ray.setColor(reflected.getColor() * R + refracted.getColor() * T);

		}
	}

	else {
		ray.setColor(object->getColor());
	}

	return ray.getColor();
}

glm::dvec3 Scene::compute_total_direct_light(glm::dvec3 intersectionVertex, Polygon* object) {
	glm::dvec3 normal = object->getNormal();

	glm::dvec3 totalDirectLight = glm::dvec3(0.0, 0.0, 0.0);
	// Create a random number generator engine
	std::random_device rd;
	std::mt19937 gen(rd());

	// Create a uniform distribution
	std::uniform_real_distribution<double> dis(0.0, 1.0);

	int n = lights.size();
	double V;
	for (int i = 0; i < n; ++i) {
		glm::dvec3 accumelatedColor(0, 0, 0);

		Rectangle* lamp = lights[i];
		glm::dvec3 e1 = lamp->getV1() - lamp->getV0();
		glm::dvec3 e2 = lamp->getV2() - lamp->getV0();
		double surface = glm::length(e1) * glm::length(e2);
		int c = 0;
		while (c < numberShadowRays) {
			V = 1.0;
			// Generate random numbers between 0 and 1 to generate a random point on the lamp's surface 
			double s = dis(gen);
			double t = dis(gen);
			glm::dvec3 d = lamp->getV0() + s * e1 + t * e2;

			glm::dvec3 directionShadowRay = d - intersectionVertex;
			Ray shadowRay(intersectionVertex, d);

			if (glm::dot(normal, directionShadowRay) < 0) {
				c++;
				continue;
			}

			for (int i = 0; i < objects.size(); i++) {
				if (objects[i] != object && objects[i]->rayIntersection(&shadowRay)) {
					V = 0.0;
					break;
				}
			}
			double norm = glm::length(directionShadowRay);
			double cosx = glm::dot(normal, directionShadowRay) / norm; //verify names
			double cosy = - glm::dot(lamp->getNormal(), directionShadowRay) / norm;

			accumelatedColor += V * cosy * cosx / (norm * norm);
			c++;
		}
		//adding the factor 30.0 give better result, if we remove it the image looks darker, almost we can't see anything
		glm::dvec3 w = surface * glm::dvec3(1, 1, 1) * 30.0;
		accumelatedColor *= object->getMaterial().rho/M_PI * object->getColor() * w / (double)numberShadowRays;

		totalDirectLight += accumelatedColor;
	}
	return totalDirectLight;
}