#include "Camera.h"
#include <random>
#include <iostream>

void Camera::createImage() {

	FILE* fp = fopen("render.ppm", "wb");
	fprintf(fp, "P6\n%d %d\n255\n", SIZE, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			static unsigned char color[3];
			color[0] = image[i][j].x * (255.0 / iMax);
			color[1] = image[i][j].y * (255.0 / iMax);
			color[2] = image[i][j].z * (255.0 / iMax);
			fwrite(color, 1, 3, fp);
		}
	}
	fclose(fp);	
}

void Camera::render(Scene scene) {
	std::vector<glm::dvec3> row; //used to add colors to the image
	int depth = 0;
	int numberRays = scene.getNumberRays(); //number of rays we shoot

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			glm::dvec3 pixelColorDp(0, 0, 0);
			for (int k = 0; k < numberRays; ++k) {
				//Get the position of the current pixel on the camera plan
				glm::dvec3 currentPixel = glm::dvec3(0.0, -j * 0.0025 + 0.99875, -i * 0.0025 + 0.99875);

				//Create new ray
				Ray ray = Ray(eye1, currentPixel);
				pixelColorDp += scene.castRays(ray, 0);
			}
			glm::dvec3 pixelColor = glm::dvec3( sqrt(pixelColorDp.x / numberRays) * 255.0, sqrt(pixelColorDp.y / numberRays) * 255.0, sqrt(pixelColorDp.z / numberRays) * 255.0 );
			//glm::dvec3 pixelColor = glm::dvec3((int)(pixelColorDp.x * 255 / numberRays), (int)(pixelColorDp.y * 255 / numberRays), (int)(pixelColorDp.z * 255 / numberRays));
			row.push_back(pixelColor);

			double newiMax = glm::max(glm::max(pixelColor.x, pixelColor.y), pixelColor.z);

			if (newiMax > iMax) {
				iMax = newiMax;
			}
		}
		image.push_back(row);
		row.clear();
	}
	std::cout << "The highest color value in the image: " << iMax << std::endl;

}

Camera::Camera() {

}