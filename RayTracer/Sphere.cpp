#include "Sphere.h"

bool Sphere::rayIntersection(Ray* ray)
{
	glm::dvec3 S = ray->getStartVertex();
	glm::dvec3 D = ray->getDirection();

	double c1 = glm::dot(D, D); // c1 = D^2
   // std::cout << c1 << std::endl;
	double c2 = 2 * glm::dot(D, S-center); // c2 = 2D(S-C)
	double c3 = glm::dot(S-center, S-center) - pow(radius, 2); // (S - C)^2 - r^2

	double arg = pow(c2, 2) - 4.0 * c1 * c3;
    // No solutions
    if (arg < 0) {
        return false;
    }
    //One solution
    else if (arg < DBL_EPSILON) {
        double t = -c2 / 2.0;
        glm::dvec3 xr = S + glm::dvec3(D.x*t, D.y*t, D.z*t); // xr=S+D*t
        normal = glm::normalize((xr - center));
        ray->setEndVertex(xr);
        return true;
    }
    //Two solutions
    else {
        double t1 = (-c2 + sqrt(arg)) / (2.0 * c1);
        double t2 = (-c2 - sqrt(arg)) / (2.0 * c1);

        if (t1 > 0.0f && t2 > 0.0f) {
            double t = glm::min(t1, t2);
            glm::dvec3 xr = S + glm::dvec3(D.x * t, D.y * t, D.z * t); // xr=S+D*t
            ray->setEndVertex(xr);
            normal = glm::normalize((xr - center));
            return true;
        }
        else if(t1 < 0.0f && t2 < 0.0f){
            return false;
        }
        else {
            double t = glm::max(t1, t2);
            glm::dvec3 xr = S + glm::dvec3(D.x * t, D.y * t, D.z * t); // xr=S+D*t
            ray->setEndVertex(xr);
            normal = glm::normalize((xr - center));
            return true;
        }
    }

	return false;
}
