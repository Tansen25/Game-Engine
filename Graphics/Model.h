#ifndef MODEL_H
#define MODEL_H

#include "MathEngine.h"

#define FILE_NAME_SIZE 20
#define TEXTURE_NAME_SIZE 20

struct modelStride
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

struct modelTriangleList
{
	unsigned short v1;
	unsigned short v2;
	unsigned short v3;
};

struct modelHeader
{
	char fileName[FILE_NAME_SIZE];
	char textureName[TEXTURE_NAME_SIZE];
	int vertCount;
	int uvCount;
	int normCount;
	int triangleCount;
	int textureSize;
	bool duplicates;
};

class Vect;
class Model
{
public:
   Model();

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

	bool duplicates;

	modelHeader header;

	modelStride *modelData;
	modelTriangleList *triangleList;
};


#endif