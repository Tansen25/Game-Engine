#ifndef SPHERE_H
#define SPHERE_H


#include "MathEngine.h"

struct sphereVertexStride
{
		float x;
		float y;
		float z;
		float s;
		float t;
		float nx;
		float ny;
		float nz;
};

class Vect;
class Sphere
{
public:
   Sphere();

   void loadTexture( void );
   
   void createVAO(void);

   void setCenter(const Vect &inV);

   void updateSphere(const float &Scale, const Matrix &Trans);

   //Accessors
   float getRadius();

   Vect getCenter();

   GLuint				vao;
   GLuint				textureID;

private:
	void defaultSphere();
	void createSphere( sphereVertexStride sVerts[], int size, float radius, int slices, int stacks );

	sphereVertexStride sVerts[2028];
	
	float radius;

	Vect center;
};


#endif