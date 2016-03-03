#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "Sphere.h"
#include "Camera.h"
#include "File.h"
#include <assert.h>


extern GLShaderManager		   shaderManager;
extern GLGeometryTransform	   transformPipeline;

extern Sphere                 *pShere;
extern Camera				  *pCamera;

bool LoadTGATextureSphere(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);

Sphere::Sphere()
{
	radius = 0.5f;

	center = Vect(0.0f, 0.0f, 0.0f);
}

void Sphere::loadTexture( void )
{
    glGenTextures(1, &this -> textureID);

	glBindTexture(GL_TEXTURE_2D, this -> textureID);
	
	LoadTGATextureSphere("moon.tga", GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE);
    
}

void Sphere::createSphere( sphereVertexStride sVerts[], int size, float radius, int slices, int stacks )
{	
	assert(size == (slices * stacks * 2 * 3));

	float drho = (float)(3.141592653589) / (float) stacks;
    float dtheta = 2.0f * (float)(3.141592653589) / (float) slices;
	float ds = 1.0f / (float) slices;
	float dt = 1.0f / (float) stacks;
	float t = 1.0f;	
	float s = 0.0f;
    int i, j;     // Looping variables
    
	for (i = 0; i < stacks; i++) 
		{
		float rho = (float)i * drho;
		float srho = (float)(sin(rho));
		float crho = (float)(cos(rho));
		float srhodrho = (float)(sin(rho + drho));
		float crhodrho = (float)(cos(rho + drho));
		
        // Many sources of OpenGL sphere drawing code uses a triangle fan
        // for the caps of the sphere. This however introduces texturing 
        // artifacts at the poles on some OpenGL implementations
        s = 0.0f;
		Vect vVertex[4];
		Vect vNormal[4];
		Vect vTexture[4];

		for ( j = 0; j < slices; j++) 
			{
			float theta = (j == slices) ? 0.0f : j * dtheta;
			float stheta = (float)(-sin(theta));
			float ctheta = (float)(cos(theta));
			
			float x = stheta * srho;
			float y = ctheta * srho;
			float z = crho;
        
			vTexture[0][X] = s;
			vTexture[0][Y] = t;
			vNormal[0][X] = x;
			vNormal[0][Y] = y;
			vNormal[0][Z] = z;
			vVertex[0][X] = x * radius;
			vVertex[0][Y] = y * radius;
			vVertex[0][Z] = z * radius;
			
            x = stheta * srhodrho;
			y = ctheta * srhodrho;
			z = crhodrho;

 			vTexture[1][X] = s;
			vTexture[1][Y] = t - dt;
			vNormal[1][X] = x;
			vNormal[1][Y] = y;
			vNormal[1][Z] = z;
			vVertex[1][X] = x * radius;
			vVertex[1][Y] = y * radius;
			vVertex[1][Z] = z * radius;
			

			theta = ((j+1) == slices) ? 0.0f : (j+1) * dtheta;
			stheta = (float)(-sin(theta));
			ctheta = (float)(cos(theta));
			
			x = stheta * srho;
			y = ctheta * srho;
			z = crho;
        
            s += ds;
			vTexture[2][X] = s;
			vTexture[2][Y] = t;
			vNormal[2][X] = x;
			vNormal[2][Y] = y;
			vNormal[2][Z] = z;
			vVertex[2][X] = x * radius;
			vVertex[2][Y] = y * radius;
			vVertex[2][Z] = z * radius;
			
            x = stheta * srhodrho;
			y = ctheta * srhodrho;
			z = crhodrho;

 			vTexture[3][X] = s;
			vTexture[3][Y] = t - dt;
			vNormal[3][X] = x;
			vNormal[3][Y] = y;
			vNormal[3][Z] = z;
			vVertex[3][X] = x * radius;
			vVertex[3][Y] = y * radius;
			vVertex[3][Z] = z * radius;

			//Load three vertices
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].x  = vVertex[0][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].y  = vVertex[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].z  = vVertex[0][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].s  = vTexture[0][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].t  = vTexture[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].nx = vNormal[0][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].ny = vNormal[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 0].nz = vNormal[0][Z];
			
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].x  = vVertex[1][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].y  = vVertex[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].z  = vVertex[1][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].s  = vTexture[1][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].t  = vTexture[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].nx = vNormal[1][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].ny = vNormal[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 1].nz = vNormal[1][Z];
			
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].x  = vVertex[2][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].y  = vVertex[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].z  = vVertex[2][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].s  = vTexture[2][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].t  = vTexture[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].nx = vNormal[2][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].ny = vNormal[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 2].nz = vNormal[2][Z];
			
			// Rearrange for next triangle
			vVertex[0] = vVertex[1];
			vNormal[0] = vNormal[1];
			vTexture[0] = vTexture[1];
			
			vVertex[1] = vVertex[3];
			vNormal[1] = vNormal[3];
			vTexture[1] = vTexture[3];

			//Load next three vertices
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].x  = vVertex[0][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].y  = vVertex[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].z  = vVertex[0][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].s  = vTexture[0][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].t  = vTexture[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].nx = vNormal[0][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].ny = vNormal[0][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 3].nz = vNormal[0][Z];
			
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].x  = vVertex[1][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].y  = vVertex[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].z  = vVertex[1][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].s  = vTexture[1][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].t  = vTexture[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].nx = vNormal[1][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].ny = vNormal[1][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 4].nz = vNormal[1][Z];

			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].x  = vVertex[2][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].y  = vVertex[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].z  = vVertex[2][Z];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].s  = vTexture[2][X];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].t  = vTexture[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].nx = vNormal[2][X]; 
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].ny = vNormal[2][Y];
			sVerts[i + (i * (slices * 6 - 1)) + j + (j * 5) + 5].nz = vNormal[2][Z];

			}
        t -= dt;
        }
}

void Sphere::createVAO(void)
{
	#if 1
		FileHandle fh2;
		FileError ferror;

		ferror = File::open(fh2, "sphere.vbo", FILE_READ);
		assert(ferror == FILE_SUCCESS);

		ferror = File::read(fh2, &sVerts, 2028 * sizeof(sphereVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh2);
		assert(ferror == FILE_SUCCESS);

	#else	
	
		createSphere( sVerts, 2028, 0.5, 26, 13 );

		//Write the data to a file ---------------------

		FileHandle fh;
		FileError ferror;

		//-----------WRITE--------------------------------

		ferror = File::open(fh, "sphere.vbo", FILE_WRITE);
		assert(ferror == FILE_SUCCESS);

		//Write the data
		ferror = File::write(fh, &sVerts, 2028 * sizeof(sphereVertexStride));
		assert(ferror == FILE_SUCCESS);

		ferror = File::close(fh);
		assert(ferror == FILE_SUCCESS);

	#endif

	/* Allocate and assign a Vertex Array Object to our handle */
    glGenVertexArrays(1, &this->vao);
 
    /* Bind our Vertex Array Object as the current used object */
    glBindVertexArray(this->vao);

    GLuint vbo;

    /* Allocate and assign two Vertex Buffer Objects to our handle */
    glGenBuffers(1, &vbo);

	// Load the combined data: ---------------------------------------------------------

	/* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
 
	/* Copy the vertex data to our buffer */
	// glBufferData(type, size in bytes, data, usage) 
	glBufferData(GL_ARRAY_BUFFER, sizeof(sphereVertexStride) * 2028, &sVerts, GL_STATIC_DRAW);

	// VERTEX data: ---------------------------------------------------------

	// Set Attribute to 0
    //           WHY - 0? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    //           GLT_ATTRIBUTE_VERTEX = 0

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(0);  

	//Calculate offset
	void *offsetVert = (void *)((unsigned int)&sVerts[0].x - (unsigned int)&sVerts);

	/* Specify that our coordinate data is going into attribute index 0, and contains 3 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(0, 3, GL_FLOAT,  GL_FALSE, sizeof(sphereVertexStride), offsetVert);

	// Texture data: ---------------------------------------------------------
     
	// Set Attribute to 3
    //           WHY - 3? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
    //           GLT_ATTRIBUTE_TEXTURE0 = 3

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(3);  

	//Calculate offset
	void *offsetTex = (void *)((unsigned int)&sVerts[0].s - (unsigned int)&sVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
	glVertexAttribPointer(3, 2, GL_FLOAT,  GL_FALSE, sizeof(sphereVertexStride), offsetTex);

	// Normal data: ---------------------------------------------------------
		
	// Set Attribute to 2
    //           WHY - 2? and not 1,2,3 (this is tied to the shader attribute, it is defined in GLShaderManager.h)
	//           GLT_ATTRIBUTE_NORMAL = 2

    // Specifies the index of the generic vertex attribute to be enabled
	glEnableVertexAttribArray(2);  

	//Calculate offset
	void *offsetNorm = (void *)((unsigned int)&sVerts[0].nx - (unsigned int)&sVerts);

	/* Specify that our coordinate data is going into attribute index 3, and contains 2 floats per vertex */
    // ( GLuint index,  GLint size,  GLenum type,  GLboolean normalized,  GLsizei stride,  const GLvoid * pointer);
            
	glVertexAttribPointer(2, 3, GL_FLOAT,  GL_FALSE, sizeof(sphereVertexStride), offsetNorm);

}

void Sphere::setCenter(const Vect &inV)
{
	center = inV;
}

void Sphere::updateSphere(const float &Scale, const Matrix &Trans)
{
	//Set sphere defaults
	defaultSphere();

	//Update radius
	radius *= Scale;
	
	//Update center
	center *= Trans;
}

float Sphere::getRadius()
{
	return radius;
}

Vect Sphere::getCenter()
{
	return center;
}

void Sphere::defaultSphere()
{
	radius = 0.5f;
	
	center = Vect(0, 0, 0);
}

// Load a TGA as a 2D Texture. Completely initialize the state
bool LoadTGATextureSphere(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
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