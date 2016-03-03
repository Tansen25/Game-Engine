#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "pyramid.h"
#include "Camera.h"
#include "File.h"
#include <assert.h>

extern GLShaderManager		   shaderManager;
extern GLGeometryTransform	   transformPipeline;

extern Pyramid                *pPyramid;
extern Camera				  *pCamera;

bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

Pyramid::Pyramid()
{
	center = Vect(0.0f, 0.0f, 0.0f);

	radius = 1.3f;

	test = false;
	test1 = true;
}

void Pyramid::loadTexture( void )
{
    glGenTextures(1, &this -> textureID);

	glBindTexture(GL_TEXTURE_2D, this -> textureID);
	
	LoadTGATexture("stone.tga", GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
    
}

void Pyramid::createVAO(void)
{

	struct pyramidVertexStride
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

	struct triangleList
	{
		unsigned short v1;
		unsigned short v2;
		unsigned short v3;
	};

	pyramidVertexStride pVerts[5];

	triangleList		pList[6];

	#if 1
		FileHandle fh2;
		FileError ferror;

		ferror = File::open(fh2, "pyramid.vbo", FILE_READ);
		assert(ferror == FILE_SUCCESS);

		ferror = File::read(fh2, &pVerts, 5 * sizeof(pyramidVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::read(fh2, &pList, 6 * sizeof(triangleList));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh2);
		assert(ferror == FILE_SUCCESS);

	#else

		// apex
		pVerts[0].x = 0.0f;
		pVerts[0].y = 1.0f;
		pVerts[0].z = 0.0f;
		pVerts[0].s = 0.5f;
		pVerts[0].t = 0.5f;
		pVerts[0].nx = 0.0f;
		pVerts[0].ny = 2.0f;
		pVerts[0].nz = 0.0f;

		// left front
		pVerts[1].x = -1.0f;
		pVerts[1].y = -1.0f;
		pVerts[1].z = 1.0f;//-1.0f;
		pVerts[1].s = 0.0f;
		pVerts[1].t = 0.0f;

		pVerts[1].nx = -3.0f;
		pVerts[1].ny = -5.0f;
		pVerts[1].nz = -3.0f;

		// right front
		pVerts[2].x = 1.0f;
		pVerts[2].y = -1.0f;
		pVerts[2].z = 1.0f;
		pVerts[2].s = 1.0f;
		pVerts[2].t = 0.0f;

		pVerts[2].nx = 3.0f;
		pVerts[2].ny = -5.0f;
		pVerts[2].nz = -3.0f;

		// left back
		pVerts[3].x = -1.0f;
		pVerts[3].y = -1.0f;
		pVerts[3].z = -1.0f;
		pVerts[3].s = 0.0f;
		pVerts[3].t = 1.0f;

		pVerts[3].nx = -3.0f;
		pVerts[3].ny = -5.0f;
		pVerts[3].nz = 3.0f;

		// right back
		pVerts[4].x = 1.0f;
		pVerts[4].y = -1.0f;
		pVerts[4].z = -1.0f;
		pVerts[4].s = 1.0f;
		pVerts[4].t = 1.0f;

		pVerts[4].nx = 3.0f;
		pVerts[4].ny = -5.0f;
		pVerts[4].nz = 3.0f;

		// front
		pList[0].v1 = 0;
		pList[0].v2 = 1;
		pList[0].v3 = 2;

		// left
		pList[1].v1 = 0;
		pList[1].v2 = 3;
		pList[1].v3 = 1;

		// right
		pList[2].v1 = 0;
		pList[2].v2 = 2;
		pList[2].v3 = 4;

		// back
		pList[3].v1 = 0;
		pList[3].v2 = 4;
		pList[3].v3 = 3;

		// bottom 1
		pList[4].v1 = 2;
		pList[4].v2 = 1;
		pList[4].v3 = 3;

		// bottom 2
		pList[5].v1 = 4;
		pList[5].v2 = 2;
		pList[5].v3 = 3;

		//Write the data to a file ---------------------

		FileHandle fh;
		FileError ferror;

		//-----------WRITE--------------------------------

		ferror = File::open(fh, "pyramid.vbo", FILE_WRITE);
		assert(ferror == FILE_SUCCESS);

		//Write the data
		ferror = File::write(fh, &pVerts, 5 * sizeof(pyramidVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::write(fh, &pList, 6 * sizeof(triangleList));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh);
		assert(ferror == FILE_SUCCESS);

	#endif

	if (test)
	{
		for( int i = 0; i<5; i++)
		{
			Matrix Trans(TRANS, 0.0f, 1.0f, 0.0f);
			//Matrix Scale(SCALE, 1.0f, 0.5f, 1.0f);
			Matrix Scale(SCALE, 0.3f, 0.1f, 0.3f);
			Matrix Rot( ROT_X, 90.0f * MATH_PI_180);

			Matrix M = Trans * Scale * Rot;
     

			Matrix Scale2( SCALE, 13.0f, 13.0f, 109.43f);

			Matrix Rot2; 
			Rot2.set(ROT_ORIENT, Vect(1.0f,0.0f,0.0f), Vect( 0.0f, 1.0f, 0.0f) );

			M =  M * Scale2 * Rot2;
      
			//M =  M * Scale2 ;

			Vect vert( pVerts[i].x, pVerts[i].y, pVerts[i].z);
			Vect vertNorm( pVerts[i].nx, pVerts[i].ny, pVerts[i].nz);

			Vect vout;
			Vect voutNorm;

			vout = vert * M;
			voutNorm = vertNorm * M;

			pVerts[i].x  = vout[x] ;
			pVerts[i].y  = vout[y] ;
			pVerts[i].z  = vout[z] ;
			pVerts[i].nx = voutNorm[x];
			pVerts[i].ny = voutNorm[y];
			pVerts[i].nz = voutNorm[z];

			printf(" vert[%d]  %f  %f  %f\n",i, vout[x], vout[y], vout[z]);

		}
	}

	/* Allocate and assign a Vertex Array Object to our handle */
    glGenVertexArrays(1, &this->vao);
 
    /* Bind our Vertex Array Object as the current used object */
    glBindVertexArray(this->vao);

	//Create two buffers
	GLuint vbo[2];

    /* Allocate and assign two Vertex Buffer Objects to our handle */
    glGenBuffers(2, vbo);

	// Load the combined data: ---------------------------------------------------------

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
 
	/* Copy the vertex data to our buffer */
    // glBufferData(type, size in bytes, data, usage) 
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidVertexStride) * 5, &pVerts, GL_STATIC_DRAW);

	// VERTEX data: ---------------------------------------------------------
		
	// Set Attribute to 0
    // WHY - 0? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_VERTEX = 0

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(0);  

	//Compute offset
	void *offsetVert = (void *)((unsigned int)&pVerts[0].x - (unsigned int)&pVerts);

	/* Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(0, 3, GL_FLOAT,  GL_FALSE, sizeof(pyramidVertexStride), offsetVert);

	// Texture data: ---------------------------------------------------------
		
	// Set Attribute to 3
    // WHY - 3? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_TEXTURE0 = 3

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(3);  

	//Compute offset
	void *offsetTex = (void *)((unsigned int)&pVerts[0].s - (unsigned int)&pVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(3, 2, GL_FLOAT,  GL_FALSE, sizeof(pyramidVertexStride), offsetTex);

	// Normal data: ---------------------------------------------------------
		
	// Set Attribute to 2
    // WHY - 2? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_NORMAL = 2

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(2);  

	//Compute offset
	void *offsetNorm = (void *)((unsigned int)&pVerts[0].nx - (unsigned int)&pVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(2, 3, GL_FLOAT,  GL_FALSE, sizeof(pyramidVertexStride), offsetNorm);

	// Load the index data: ---------------------------------------------------------
	
    /* Bind our 2nd VBO as being the active buffer and storing index ) */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);

	/* Copy the index data to our buffer */
    // glBufferData(type, size in bytes, data, usage) 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleList)*6, pList, GL_STATIC_DRAW);

}

void Pyramid::setPyramid(const Vect &inV)
{
	center = inV;
}

Vect Pyramid::getCenter(void)
{
	return center;
}

float Pyramid::getRadius(void)
{
	return radius;
}

void Pyramid::updatePyramid(const float &Scale, const Matrix &Trans)
{
	//Set pyramid defaults
	defaultPyramid();

	//Update radius
	radius *= Scale;
	
	//Update center
	center *= Trans;
}

void Pyramid::defaultPyramid()
{	
	center = Vect(0, 0, 0);

	radius = 1.3f;
}

void Pyramid::setTest(bool testValue)
{
	test = testValue;
}

void Pyramid::setTest1(bool testValue)
{
	test1 = testValue;
}

bool Pyramid::getTest1()
{
	return test1;
}

// Load a TGA as a 2D Texture. Completely initialize the state
bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
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
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
				 eFormat, GL_UNSIGNED_BYTE, pBits);
	
    free(pBits);
    
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);
    
	return true;
}