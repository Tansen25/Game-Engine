#include "OpenGLWrapper.h"
#include "UserInterface.h"
#include "MathEngine.h"
#include "Camera.h"
#include "CameraManager.h"
#include "GlobalState.h"


extern Camera *pCamera;

static int sphereCollisionTestCount;
static int pyramidCollisionTestCount;
static int torusCollisionTestCount;
static int cameraCount;
static int test;

// Respond to arrow keys by moving the camera frame of reference
void SpecialKeys(int key, int inX, int inY)
{
	static float zoom = 0.0f;
	static float offset = 0.0f;

	Vect vUp(0.0f, 1.0f, 0.0f);
	pCamera -> getUp(vUp);
	Vect vTar(0.0f, 0.0f, 0.0f);
	Vect vPos(0.0f, 0.0f, 0.0f);
	pCamera -> getPos(vPos);


	if(key == GLUT_KEY_UP)
	{
		zoom += 0.05f;

		Vect vDir = vTar - vPos;
		vDir.norm();

		vPos = vPos + vDir * zoom; 

		pCamera->setOrientAndPosition(vUp, vTar, vPos );
	}
    
	if(key == GLUT_KEY_DOWN)
	{
		zoom -= 0.05f;

		Vect vDir = vTar - vPos;
		vDir.norm();

		vPos = vPos - vDir * zoom; 

		pCamera->setOrientAndPosition(vUp, vTar, vPos );
	}
	
	if(key == GLUT_KEY_LEFT)
	{
		offset = 0.08f;

		if (vUp.isEqual(Vect(0.0f, 1.0f, 0.0f), MATH_TOLERANCE))
		{
			Matrix R(ROT_Y, offset);

			vPos = vPos * R;
		}

		if (vUp.isEqual(Vect(0.0f, 0.0f, 1.0f), MATH_TOLERANCE))
		{
			Matrix R(ROT_Z, offset);

			vPos = vPos * R;
		}

		pCamera->setOrientAndPosition(vUp, vTar, vPos );
	}
    
	if(key == GLUT_KEY_RIGHT)
	{
		offset = -0.08f;

		if (vUp.isEqual(Vect(0.0f, 1.0f, 0.0f), MATH_TOLERANCE))
		{
			Matrix R(ROT_Y, offset);

			vPos = vPos * R;
		}

		if (vUp.isEqual(Vect(0.0f, 0.0f, 1.0f), MATH_TOLERANCE))
		{
			Matrix R(ROT_Z, offset);

			vPos = vPos * R;
		}

		pCamera->setOrientAndPosition(vUp, vTar, vPos );
	}

	//Setup pyramid scene
	if (key == GLUT_KEY_F1)
	{
		frameworkStartup();
	}

	//Setup sphere collision test scene
	if (key == GLUT_KEY_F2)
	{
		if (sphereCollisionTestCount == 0)
		{
			frameworkStartup1();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}
		
		else if (sphereCollisionTestCount == 1)
		{
			frameworkStartup2();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}

		else if (sphereCollisionTestCount == 2)
		{
			frameworkStartup3();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}

		else if (sphereCollisionTestCount == 3)
		{
			frameworkStartup4();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}

		else if (sphereCollisionTestCount == 4)
		{
			frameworkStartup5();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}

		else if (sphereCollisionTestCount == 5)
		{
			frameworkStartup6();

			cameraCount = 1;

			sphereCollisionTestCount++;
		}

		if (sphereCollisionTestCount > 5)
		{
			sphereCollisionTestCount = 0;
		}
	}

	//Pyramid collision test scene
	if (key == GLUT_KEY_F3)
	{
		if (pyramidCollisionTestCount == 0)
		{
			frameworkStartup14();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		else if (pyramidCollisionTestCount == 1)
		{
			frameworkStartup15();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		else if (pyramidCollisionTestCount == 2)
		{
			frameworkStartup16();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		else if (pyramidCollisionTestCount == 3)
		{
			frameworkStartup17();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		else if (pyramidCollisionTestCount == 4)
		{
			frameworkStartup18();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		else if (pyramidCollisionTestCount == 5)
		{
			frameworkStartup19();

			cameraCount = 1;

			pyramidCollisionTestCount++;
		}

		if (pyramidCollisionTestCount > 5)
		{
			pyramidCollisionTestCount = 0;
		}
		
		
	}

	//Setup cube scene
	if (key == GLUT_KEY_F4)
	{	
		frameworkStartup13();

		cameraCount = 0;
	}

	if (key == GLUT_KEY_F5)
	{
		frameworkStartup20();

		cameraCount = 0;
	}

	//Set up model scene
	if (key == GLUT_KEY_F6)
	{
		frameworkStartup21();

		cameraCount = 6;
	}

	if(key == GLUT_KEY_F7)
	{
		frameworkStartup22();

		cameraCount = 7;
	}

	if (key == GLUT_KEY_F8)
	{
		frameworkStartup23();

		cameraCount = 7;
	}

	//Switch between cameras
	if (key == GLUT_KEY_F9)
	{
		CameraManager *goCam = CameraManager::getInstance();
		
		if (cameraCount == 0)
		{
			pCamera = goCam -> getCam2();

			cameraCount++;
		}

		else if (cameraCount == 1)
		{
			pCamera = goCam -> getCam3();

			cameraCount++;
		}

		else if (cameraCount == 2)
		{
			pCamera = goCam -> getCam4();

			cameraCount++;
		}

		else if (cameraCount == 3)
		{
			pCamera = goCam -> getCam5();

			cameraCount++;
		}

		else if (cameraCount == 4)
		{
			pCamera = goCam -> getCam6();

			cameraCount++;
		}

		else if (cameraCount == 5)
		{
			pCamera = goCam -> getCam1();

			cameraCount++;
		}

		if (cameraCount > 5)
		{
			cameraCount = 0;
		}
	}
    
	glutPostRedisplay();
	
}




///////////////////////////////////////////////////////////////////////////////
// Window has changed size, or has just been created. In either case, we need
// to use the window dimensions to set the viewport and the projection matrix.
void ChangeSize(int w, int h)
{
	pCamera -> setViewport( 0, 0, w, h);
	pCamera -> setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    pCamera -> setOrientAndPosition( Vect(0,1,0), Vect(0,0,-1), Vect(0,0,7) );
}