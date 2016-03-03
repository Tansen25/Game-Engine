#include "OpenGLWrapper.h"
#include "RenderScene.h"
#include "pyramid.h"
#include "Camera.h"
#include "GraphicsManager.h"
#include "GraphicsObject.h"

extern Pyramid *pPyramid;
extern Camera  *pCamera;

///////////////////////////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{    
    // Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Our new camera, make sure everything is consistent
	pCamera->updateCamera();

	// get the graphic object manager (singleton)
	GraphicsObjectManager *gom = GraphicsObjectManager::getInstance();
	
	if (pPyramid->getTest1())
	{
		// Draw them
		gom->drawObjectsList();
	}
	else
	{
		// Draw them
		gom->drawObjectsTree();
	}

	// Flush drawing commands
	glutSwapBuffers();

	glutPostRedisplay();
}