#ifndef TORUS_H
#define TORUS_H


#include "MathEngine.h"

class Vect;
class Torus
{
public:
   Torus();

   void loadTexture( void );
   void createTriangleBatch( void );

   void setCenter(const Vect &inV);

   void updateTorus(const float &Scale, const Matrix &Trans);

   //Accessors
   float getMajorRadius();

   float getMinorRadius();

   Vect getCenter();

   GLTriangleBatch		torusBatch;
   GLuint				textureID;

private:
	void defaultTorus();

	float majorRadius;
	float minorRadius;

	Vect center;
};


#endif