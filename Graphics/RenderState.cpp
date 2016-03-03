#include "OpenGLWrapper.h"
#include "RenderState.h"
#include "pyramid.h"
#include "Cube.h"
#include "Sphere.h"
#include "SpaceFrigate.h"
#include "WarBear.h"
#include "AstroBoy.h"


extern GLShaderManager		   shaderManager;

extern Pyramid                 *pPyramid;

extern Cube					   *pCube;

extern Sphere				   *pSphere;

extern SpaceFrigate			   *pSpaceFrigate;

extern WarBear				   *pWarBear;

extern AstroBoy				   *pAstroBoy;

///////////////////////////////////////////////////////////////////////////////
// This function does any needed initialization on the rendering context. 
// This is the first opportunity to do any OpenGL related tasks.
void SetupRC()
{
    // Black background
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f );

	shaderManager.InitializeStockShaders();

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
    
}

///////////////////////////////////////////////////////////////////////////////
// Cleanup... such as deleting texture objects
void ShutdownRC(void)
{
    //Delete textures
	//glDeleteTextures(1, &pPyramid -> textureID);

	glDeleteTextures(1, &pSphere -> textureID);

}