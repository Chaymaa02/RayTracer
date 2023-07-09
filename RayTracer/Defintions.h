#pragma once

enum MaterialType{Mirror, Transparent, Lambertian, Light};

enum RayType{Inside, Outside};

struct Material {
	MaterialType type = Lambertian;
	double rho = 0.8;
};