#pragma once

const int MAX_POINT_LIGHTS = 3;

struct myVector
{
	float X;
	float Y;
	float Z;


	myVector(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}



	static myVector ZeroVector()
	{
		return myVector(0.0f, 0.0f, 0.0f);
	}

	static myVector VectorOne()
	{
		return myVector(1.0f, 1.0f, 1.0f);
	}

	static myVector VectorUp()
	{
		return myVector(0.0f, 1.0f, 0.0f);
	}

	static myVector VectorForward()
	{
		return myVector(0.0f, 0.0f, 1.0f);
	}

	static myVector VectorRight()
	{
		return myVector(1.0f, 0.0f, 0.0f);
	}

	
private:
	static myVector zeroVector;
	static myVector one;


public: 
	static myVector zero;

	

};


