#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "Torus.h"
#include "Camera.h"

extern GLShaderManager		   shaderManager;
extern GLGeometryTransform	   transformPipeline;

extern Torus                  *pTorus;
extern Camera				  *pCamera;

bool LoadTGATextureTorus(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

void MakeTorus(GLTriangleBatch& torusBatch);

Torus::Torus()
{
	majorRadius = 0.4f;

	minorRadius = 0.15f;

	center = Vect(0.0f, 0.0f, 0.0f);
}

void Torus::loadTexture( void )
{
    glGenTextures(1, &this -> textureID);

	glBindTexture(GL_TEXTURE_2D, this -> textureID);
	
	LoadTGATextureTorus("marble.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
    
}

void Torus::createTriangleBatch( void )
{	
	MakeTorus(this -> torusBatch);
}

void Torus::setCenter(const Vect &inV)
{
	center = inV;
}

void Torus::updateTorus(const float &Scale, const Matrix &Trans)
{
	//Set sphere defaults
	defaultTorus();

	//Update majorRadius
	majorRadius *= Scale;

	//Update minorRadius
	minorRadius *= Scale;
	
	//Update center
	center *= Trans;
}

float Torus::getMajorRadius()
{
	return majorRadius;
}

float Torus::getMinorRadius()
{
	return minorRadius;
}

Vect Torus::getCenter()
{
	return center;
}

void Torus::defaultTorus()
{
	majorRadius = 0.4f;

	minorRadius = 0.15f;
	
	center = Vect(0, 0, 0);
}

void MakeTorus(GLTriangleBatch& TorusBatch)
{
	gltMakeTorus(TorusBatch, 0.4f, 0.15f, 40, 20);
}

// Load a TGA as a 2D Texture. Completely initialize the state
bool LoadTGATextureTorus(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
	GLbyte *pBits;
	int nWidth, nHeight, nComponents;
	GLenum eFormat;
	
	// Read the texture bits
	pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
	if(pBits == NULL) 
		return false;
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGB, nWidth, nHeight, 0,
				 eFormat, GL_UNSIGNED_BYTE, pBits);
	
    free(pBits);
    
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);
    
	return true;
}