#pragma once
#include "Light.h"

class Vec3;     //forward declare

class PointLight : public Light
{

public:
	PointLight();

	/// <summary>
	/// cons is the constant,
	/// lin is the linear different of light brightness,
	/// expo is the exponent.
	/// </summary>
	/// <param name="red"></param>
	/// <param name="green"></param>
	/// <param name="blue"></param>
	/// <param name="aIntensity"></param>
	/// <param name="dIntensity"></param>
	/// <param name="xPos"></param>
	/// <param name="yPos"></param>
	/// <param name="zPos"></param>
	/// <param name="cons"></param>
	/// <param name="lin"></param>
	/// <param name="expo"></param>
	PointLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity, GLfloat dIntensity,
				GLfloat xPos, GLfloat yPos, GLfloat zPos,
				GLfloat cons, GLfloat lin, GLfloat expo);

	void UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
		GLuint diffuseIntensityLocation, GLuint positionLocation,
		GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation);

	void AddVelocity(glm::vec3 rate);

	~PointLight();

protected:
	glm::vec3 position;

	GLfloat constant, linear, exponent;
};

