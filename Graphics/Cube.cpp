#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "Cube.h"
#include "Camera.h"
#include "File.h"
#include <assert.h>

extern GLShaderManager		   shaderManager;
extern GLGeometryTransform	   transformPipeline;

extern Cube                   *pCube;
extern Camera				  *pCamera;

Cube::Cube()
{
	nearTopLeft.set(-1.0f, 1.0f, 1.0f);

	nearTopRight.set(1.0, 1.0, 1.0);

	nearBottomLeft.set(-1.0f, -1.0f, 1.0f);

	nearBottomRight.set(1.0f, -1.0f, 1.0f);

	farTopLeft.set(-1.0f, 1.0f, -1.0f);

	farTopRight.set(1.0f, 1.0f, -1.0f);

	farBottomLeft.set(-1.0f, -1.0f, -1.0f);

	farBottomRight.set(1.0f, -1.0f, -1.0f);

	topNormal.set(0.0f, 1.0f, 0.0f);

	bottomNormal.set(0.0f, -1.0f, 0.0f);

	rightNormal.set(1.0f, 0.0f, 0.0f);

	leftNormal.set(-1.0f, 0.0f, 0.0f);

	frontNormal.set(0.0f, 0.0f, 1.0f);

	backNormal.set(0.0f, 0.0f, -1.0f);
}

void Cube::createVAO(void)
{
	struct cubeVertexStride
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

	cubeVertexStride cVerts[8];

	triangleList	 cList[12];

	#if 1
		FileHandle fh2;
		FileError ferror;

		ferror = File::open(fh2, "cube.vbo", FILE_READ);
		assert(ferror == FILE_SUCCESS);

		ferror = File::read(fh2, &cVerts, 8 * sizeof(cubeVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::read(fh2, &cList, 12 * sizeof(triangleList));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh2);
		assert(ferror == FILE_SUCCESS);

	#else

		//nearTopLeft
		cVerts[0].x  = -1.0f;
		cVerts[0].y  =  1.0f;
		cVerts[0].z  =  1.0f;
		cVerts[0].s  =  0.0f;
		cVerts[0].t  =  1.0f;
		cVerts[0].nx = -1.0f;
		cVerts[0].ny =  1.0f;
		cVerts[0].nz =  1.0f;

		//nearTopRight
		cVerts[1].x  =  1.0f;
		cVerts[1].y  =  1.0f;
		cVerts[1].z  =  1.0f;
		cVerts[1].s  =  1.0f;
		cVerts[1].t  =  1.0f;
		cVerts[1].nx =  1.0f;
		cVerts[1].ny =  1.0f;
		cVerts[1].nz =  1.0f;

		//farTopRight
		cVerts[2].x  =  1.0f;
		cVerts[2].y  =  1.0f;
		cVerts[2].z  = -1.0f;
		cVerts[2].s  =  1.0f;
		cVerts[2].t  =  1.0f;
		cVerts[2].nx =  1.0f;
		cVerts[2].ny =  1.0f;
		cVerts[2].nz = -1.0f;

		//farTopLeft
		cVerts[3].x  = -1.0f;
		cVerts[3].y  =  1.0f;
		cVerts[3].z  = -1.0f;
		cVerts[3].s  =  0.0f;
		cVerts[3].t  =  1.0f;
		cVerts[3].nx = -1.0f;
		cVerts[3].ny =  1.0f;
		cVerts[3].nz = -1.0f;

		//nearBottomLeft
		cVerts[4].x  = -1.0f;
		cVerts[4].y  = -1.0f;
		cVerts[4].z  =  1.0f;
		cVerts[4].s  =  0.0f;
		cVerts[4].t  =  0.0f;
		cVerts[4].nx = -1.0f;
		cVerts[4].ny = -1.0f;
		cVerts[4].nz =  1.0f;

		//nearBottomRight
		cVerts[5].x  =  1.0f;
		cVerts[5].y  = -1.0f;
		cVerts[5].z  =  1.0f;
		cVerts[5].s  =  1.0f;
		cVerts[5].t  =  0.0f;
		cVerts[5].nx =  1.0f;
		cVerts[5].ny = -1.0f;
		cVerts[5].nz =  1.0f;

		//farBottomRight
		cVerts[6].x  =  1.0f;
		cVerts[6].y  = -1.0f;
		cVerts[6].z  = -1.0f;
		cVerts[6].s  =  1.0f;
		cVerts[6].t  =  0.0f;
		cVerts[6].nx =  1.0f;
		cVerts[6].ny = -1.0f;
		cVerts[6].nz = -1.0f;

		//farBottomLeft
		cVerts[7].x  = -1.0f;
		cVerts[7].y  = -1.0f;
		cVerts[7].z  = -1.0f;
		cVerts[7].s  =  0.0f;
		cVerts[7].t  =  0.0f;
		cVerts[7].nx = -1.0f;
		cVerts[7].ny = -1.0f;
		cVerts[7].nz = -1.0f;

		//Front 1
		cList[0].v1  = 0;
		cList[0].v2  = 4;
		cList[0].v3  = 5;
				 
		//Front 2	 
		cList[1].v1  = 0;
		cList[1].v2  = 5;
		cList[1].v3  = 1;
				 
		//Left 1	 
		cList[2].v1  = 3;
		cList[2].v2  = 7;
		cList[2].v3  = 4;
				 
		//Left 2	 
		cList[3].v1  = 3;
		cList[3].v2  = 4;
		cList[3].v3  = 0;
				 
		//Back 1	 
		cList[4].v1  = 2;
		cList[4].v2  = 6;
		cList[4].v3  = 7;
				 
		//Back 2	 
		cList[5].v1  = 2;
		cList[5].v2  = 7;
		cList[5].v3  = 3;
				 
		//Right 1	 
		cList[6].v1  = 1;
		cList[6].v2  = 5;
		cList[6].v3  = 6;
				 
		//Right 2	 
		cList[7].v1  = 1;
		cList[7].v2  = 6;
		cList[7].v3  = 2;
				 
		//Top 1		 
		cList[8].v1  = 3;
		cList[8].v2  = 0;
		cList[8].v3  = 1;
				 
		//Top 2		 
		cList[9].v1  = 3;
		cList[9].v2  = 1;
		cList[9].v3  = 2;

		//Bottom 1
		cList[10].v1 = 4;
		cList[10].v2 = 7;
		cList[10].v3 = 6;

		//Bottom 2
		cList[11].v1 = 4;
		cList[11].v2 = 6;
		cList[11].v3 = 5;

		//Write the data to a file ---------------------

		FileHandle fh;
		FileError ferror;

		//-----------WRITE--------------------------------

		ferror = File::open(fh, "cube.vbo", FILE_WRITE);
		assert(ferror == FILE_SUCCESS);

		//Write the data
		ferror = File::write(fh, &cVerts, 8 * sizeof(cubeVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::write(fh, &cList, 12 * sizeof(triangleList));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh);
		assert(ferror == FILE_SUCCESS);

	#endif

	/* Allocate and assign a Vertex Array Object to our handle */
    glGenVertexArrays(1, &this->vao);
 
    /* Bind our Vertex Array Object as the current used object */
    glBindVertexArray(this->vao);

    //GLuint vbo;
    GLuint vbo[2];

    /* Allocate and assign two Vertex Buffer Objects to our handle */
    glGenBuffers(2, vbo);

	// Load the combined data: ---------------------------------------------------------

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
 
	/* Copy the vertex data to our buffer */
    // glBufferData(type, size in bytes, data, usage) 
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertexStride) * 8, &cVerts, GL_STATIC_DRAW);

	// VERTEX data: ---------------------------------------------------------

	// Set Attribute to 0
    // WHY - 0? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_VERTEX = 0

	// Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(0);  

	//Compute offset
	void *offsetVert = (void *)((unsigned int)&cVerts[0].x - (unsigned int)&cVerts);

	/* Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(0, 3, GL_FLOAT,  GL_FALSE, sizeof(cubeVertexStride), offsetVert);

	// Texture data: ---------------------------------------------------------
     
	// Set Attribute to 3
    // WHY - 3? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_TEXTURE0 = 3

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(3);  

	//Compute offset
	void *offsetTex = (void *)((unsigned int)&cVerts[0].s - (unsigned int)&cVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(3, 2, GL_FLOAT,  GL_FALSE, sizeof(cubeVertexStride), offsetTex);

	// Normal data: ---------------------------------------------------------
		
	// Set Attribute to 2
    // WHY - 2? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    // GLT_ATTRIBUTE_NORMAL = 2

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(2);  

	//Compute offset
	void *offsetNorm = (void *)((unsigned int)&cVerts[0].nx - (unsigned int)&cVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(2, 3, GL_FLOAT,  GL_FALSE, sizeof(cubeVertexStride), offsetNorm);

	// Load the index data: ---------------------------------------------------------

    /* Bind our 2nd VBO as being the active buffer and storing index ) */
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);

	/* Copy the index data to our buffer */
    // glBufferData(type, size in bytes, data, usage) 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleList)*12, cList, GL_STATIC_DRAW);

}

void Cube::updateVertices(Matrix &inMatrix)
{
	//Reset defaults
	defaultCoords();
	
	nearTopLeft *= inMatrix;

	nearTopRight *= inMatrix;

	nearBottomLeft *= inMatrix;

	nearBottomRight *= inMatrix;

	farTopLeft *= inMatrix;

	farTopRight *= inMatrix;

	farBottomLeft *= inMatrix;

	farBottomRight *= inMatrix;

	//Update normals
	updateNormals();
}

Vect Cube::getNearTopRight()
{
	return nearTopRight;
}

Vect Cube::getFarBottomLeft()
{
	return farBottomLeft;
}

Vect Cube::getTopNormal()
{
	return topNormal;
}

Vect Cube::getBottomNormal()
{
	return bottomNormal;
}

Vect Cube::getRightNormal()
{
	return rightNormal;
}

Vect Cube::getLeftNormal()
{
	return leftNormal;
}

Vect Cube::getFrontNormal()
{
	return frontNormal;
}

Vect Cube::getBackNormal()
{
	return backNormal;
}

void Cube::updateNormals()
{
	//Calculate vectors for normal calculations
	Vect topFront = nearTopLeft - nearTopRight;

	Vect topRight = farTopRight - nearTopRight;

	Vect frontRight = nearBottomRight - nearTopRight;

	Vect bottomLeft = nearBottomLeft - farBottomLeft;

	Vect bottomBack = farBottomRight - farBottomLeft;

	Vect backLeft = farTopLeft - farBottomLeft;
	
	//Calculate normals
	topNormal = topRight.cross(topFront);

	topNormal.norm();

	bottomNormal = bottomLeft.cross(bottomBack);

	bottomNormal.norm();

	rightNormal = topRight.cross(frontRight);

	rightNormal.norm();

	leftNormal = bottomLeft.cross(backLeft);

	leftNormal.norm();

	frontNormal = frontRight.cross(topFront);

	frontNormal.norm();

	backNormal = backLeft.cross(bottomBack);

	backNormal.norm();
}

void Cube::defaultCoords()
{
	nearTopLeft.set(-1.0f, 1.0f, 1.0f);

	nearTopRight.set(1.0, 1.0, 1.0);

	nearBottomLeft.set(-1.0f, -1.0f, 1.0f);

	nearBottomRight.set(1.0f, -1.0f, 1.0f);

	farTopLeft.set(-1.0f, 1.0f, -1.0f);

	farTopRight.set(1.0f, 1.0f, -1.0f);

	farBottomLeft.set(-1.0f, -1.0f, -1.0f);

	farBottomRight.set(1.0f, -1.0f, -1.0f);
}