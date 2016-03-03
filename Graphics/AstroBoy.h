#ifndef ASTRO_BOY_H
#define ASTRO_BOY_H

#include "MathEngine.h"
#include "SharedDataWrapper.h"

class Vect;
class AstroBoy
{
public:
   AstroBoy();

   void loadTexture( void );
   
   void createVAO(void);

   void loadData(const char * const inFile);

   //void setPyramid(const Vect &inV);

   //Vect getCenter(void);

   //float getRadius(void);

   //void updatePyramid(const float &Scale, const Matrix &Trans);

   int getNumVerts(void);

   bool getDuplicates(void);

   GLuint		vao;
   GLuint		textureID;
   int			triangleCount;
private:
	//void defaultPyramid();

	//Vect center;
	//float radius;

	bool LoadTGATextureModel(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

	bool duplicates;

	modelHeader header;

	modelStride *modelData;
	modelTriangleList *triangleList;
};


#endif