#ifndef PYRAMID_H
#define PYRAMID_H

#include "MathEngine.h"

class Vect;
class Pyramid
{
public:
   Pyramid();

   void loadTexture( void );
   
   void createVAO(void);

   void setPyramid(const Vect &inV);

   Vect getCenter(void);

   float getRadius(void);

   void updatePyramid(const float &Scale, const Matrix &Trans);

   void setTest(bool testValue);
   void setTest1(bool testValue);

   bool getTest1();

   GLuint		vao;
   GLuint		textureID;
private:
	void defaultPyramid();

	Vect center;
	float radius;

	bool test;
	bool test1;
};


#endif