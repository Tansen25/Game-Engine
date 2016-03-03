#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "WarBear.h"
#include "Camera.h"
#include "File.h"
#include <assert.h>

extern GLShaderManager		   shaderManager;
extern GLGeometryTransform	   transformPipeline;

extern WarBear				  *pWarBear;
extern Camera				  *pCamera;

WarBear::WarBear()
{
	//center = Vect(0.0f, 0.0f, 0.0f);

	//radius = 1.3f;
}

void WarBear::loadTexture( void )
{
    glGenTextures(1, &this -> textureID);

	glBindTexture(GL_TEXTURE_2D, this -> textureID);
	
	LoadTGATextureModel(header.textureName, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
    
}

void WarBear::createVAO(void)
{
	if (header.duplicates == false)
	{
		/* Allocate and assign a Vertex Array Object to our handle */
		glGenVertexArrays(1, &this->vao);
 
		/* Bind our Vertex Array Object as the current used object */
		glBindVertexArray(this->vao);

		//Create two buffers
		GLuint vbo[2];

		/* Allocate and assign two Vertex Buffer Objects to our handle */
		glGenBuffers(2, vbo);

		// Load the combined data: ---------------------------------------------------------

		/* Bind our first VBO as being the active buffer and storing vertice data (coordinates) */
		glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
 
		/* Copy the vertex data to our buffer */
		// glBufferData(type, size in bytes, data, usage) 
		glBufferData(GL_ARRAY_BUFFER, sizeof(modelStride) * header.vertCount, modelData, GL_STATIC_DRAW);

		// VERTEX data: ---------------------------------------------------------
		
		// Set Attribute to 0
		// WHY - 0? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
		// GLT_ATTRIBUTE_VERTEX = 0

		// Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(0);  

		//Compute offset
		void *offsetVert = (void *)((unsigned int)&modelData[0].x - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex */
		// ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(0, 3, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetVert);

		// Texture data: ---------------------------------------------------------
		
		// Set Attribute to 3
		// WHY - 3? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
		// GLT_ATTRIBUTE_TEXTURE0 = 3

		// Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(3);  

		//Compute offset
		void *offsetTex = (void *)((unsigned int)&modelData[0].s - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
		// ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(3, 2, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetTex);

		// Normal data: ---------------------------------------------------------
		
		// Set Attribute to 2
		// WHY - 2? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
		// GLT_ATTRIBUTE_NORMAL = 2

		// Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(2);  

		//Compute offset
		void *offsetNorm = (void *)((unsigned int)&modelData[0].nx - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
		// ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(2, 3, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetNorm);

		// Load the index data: ---------------------------------------------------------
	
		/* Bind our second VBO as being the active buffer and storing index ) */
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);

		/* Copy the index data to our buffer */
		// glBufferData(type, size in bytes, data, usage) 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(modelTriangleList) * header.triangleCount, triangleList, GL_STATIC_DRAW);
	}

	else
	{
		/* Allocate and assign a Vertex Array Object to our handle */
		glGenVertexArrays(1, &this->vao);
 
		/* Bind our Vertex Array Object as the current used object */
		glBindVertexArray(this->vao);

		//Create a buffers
		GLuint vbo;

		/* Allocate and assign one Vertex Buffer Objects to our handle */
		glGenBuffers(1, &vbo);
 
		// Load the combined data: ---------------------------------------------------------

		/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
 
		/* Copy the vertex data to our buffer */
        // glBufferData(type, size in bytes, data, usage) 
		glBufferData(GL_ARRAY_BUFFER, sizeof(modelStride) * header.vertCount, modelData, GL_STATIC_DRAW);
		
		// VERTEX data: ---------------------------------------------------------

		// Set Attribute to 0
        // WHY - 0? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
        // GLT_ATTRIBUTE_VERTEX = 0

        // Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(0);  

		//Compute offset
		void *offsetVert = (void *)((unsigned int)&modelData[0].x - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex */
        // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(0, 3, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetVert);
		 
		// Texture data: ---------------------------------------------------------
     
		// Set Attribute to 3
        // WHY - 3? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
        // GLT_ATTRIBUTE_TEXTURE0 = 3

        // Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(3);  

		//Compute offset
		void *offsetTex = (void *)((unsigned int)&modelData[0].s - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
        // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(3, 2, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetTex);

		// Normal data: ---------------------------------------------------------
		
		// Set Attribute to 2
        // WHY - 2? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
        // GLT_ATTRIBUTE_NORMAL = 2

        // Specifies the index of the generic vertex attribute to be enabled
		glEnableVertexAttribArray(2);  

		//Compute offset
		void *offsetNorm = (void *)((unsigned int)&modelData[0].nx - (unsigned int)modelData);

		/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
        // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
		glVertexAttribPointer(2, 3, GL_FLOAT,  GL_FALSE, sizeof(modelStride), offsetNorm);
	}

	//Delete Dynamic Arrays
	delete modelData;
	delete triangleList;

}

void WarBear::loadData(const char * const inFile)
{
	//Get ready to model data from file
	FileHandle fh, fh1, fh2;
	FileError  ferror;

	//Open model file to be read
	ferror = File::open(fh, inFile, FILE_READ);
	assert(ferror == FILE_SUCCESS);

	//Grab model header
	ferror = File::read(fh, &header, sizeof(modelHeader));
	assert(ferror == FILE_SUCCESS);

	duplicates = header.duplicates;

	//Create Dynamic Arrays
	modelData = new modelStride[header.vertCount];
	triangleList = new modelTriangleList[header.triangleCount];
	char * textureBuffer = new char[header.textureSize];

	//Read model data into array
	ferror = File::read(fh, modelData, sizeof(modelStride) * header.vertCount);
	assert(ferror == FILE_SUCCESS);

	triangleCount = header.triangleCount;

	if (header.duplicates == false)
	{
		//Read triangle data into array
		ferror = File::read(fh, triangleList, sizeof(modelTriangleList) * header.triangleCount);
		assert(ferror == FILE_SUCCESS);
	}

	//Check if texture exists
	ferror = File::open(fh1, header.textureName, FILE_READ);

	if (ferror != FILE_SUCCESS)
	{
		//Read texture data
		ferror = File::read(fh, textureBuffer, header.textureSize);
		assert(ferror == FILE_SUCCESS);
		
		//Create tga
		ferror = File::open(fh2, header.textureName, FILE_WRITE);
		assert(ferror == FILE_SUCCESS);

		//Load tga with data
		ferror = File::write(fh2, textureBuffer, header.textureSize);
		assert(ferror == FILE_SUCCESS);

		//Close file
		ferror = File::close(fh2);
		assert(ferror == FILE_SUCCESS);
	}

	else
	{
		//Close file
		ferror = File::close(fh1);
		assert(ferror == FILE_SUCCESS);
	}

	//Close files
	ferror = File::close(fh);
	assert(ferror == FILE_SUCCESS);
}

//void Pyramid::setPyramid(const Vect &inV)
//{
//	center = inV;
//}

//Vect Pyramid::getCenter(void)
//{
//	return center;
//}

//float Pyramid::getRadius(void)
//{
//	return radius;
//}

//void Pyramid::updatePyramid(const float &Scale, const Matrix &Trans)
//{
	//Set pyramid defaults
//	defaultPyramid();

	//Update radius
//	radius *= Scale;
	
	//Update center
//	center *= Trans;
//}

int WarBear::getNumVerts(void)
{
	return header.vertCount;
}

bool WarBear::getDuplicates(void)
{
	return duplicates;
}

//void Pyramid::defaultPyramid()
//{	
//	center = Vect(0, 0, 0);

//	radius = 1.3f;
//}

// Load a TGA as a 2D Texture. Completely initialize the state
bool WarBear::LoadTGATextureModel(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
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