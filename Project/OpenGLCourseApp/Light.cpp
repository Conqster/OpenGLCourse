#include "Light.h"
#include <iostream>


Light::Light()
{
	colour = glm::vec3(1.0f, 1.0f, 1.0f);
	ambientIntensity = 1.0f;
	diffuseIntensity = 0.0f;

	std::cout << "Light construct is been called" << std::endl;
}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity)
{
	colour = glm::vec3(red, green, blue);
	ambientIntensity = aIntensity;

	diffuseIntensity = dIntensity;
}




Light::~Light()
{

}
