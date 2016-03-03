#include <stdio.h>
#include "OpenGLWrapper.h"
#include "GlobalState.h"
#include "UserInterface.h"
#include "RenderScene.h"
#include "pyramid.h"
#include "PyramidObject.h"
#include "GraphicsManager.h"
#include "Camera.h"
#include "CameraManager.h"
#include "Cube.h"
#include "CubeObject.h"
#include "Sphere.h"
#include "SphereObject.h"
#include "Torus.h"
#include "TorusObject.h"
#include "SpaceFrigate.h"
#include "SpaceFrigateObject.h"
#include "WarBear.h"
#include "WarBearObject.h"
#include "AstroBoy.h"
#include "AstroBoyObject.h"

#include "VectApp.h"
#include "QuatApp.h"
#include "Timer.h"
#include "Anim.h"

Pyramid			*pPyramid;
Camera			*pCamera;
Cube			*pCube;
Sphere			*pSphere;
Torus			*pTorus;
SpaceFrigate	*pSpaceFrigate;
WarBear			*pWarBear;
AstroBoy		*pAstroBoy;

static int test;

void createGraphicsWindow()
{
	//Set the display mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);

	//Set the window size
	glutInitWindowSize(800, 600);

	//Create the window and name it
	glutCreateWindow("Graphics Demo");

	//Callback if someone changes size
    glutReshapeFunc(ChangeSize);

	//Callback for key presses
    glutSpecialFunc(SpecialKeys);

	//Call back for Rendering (Draw) Scene
    glutDisplayFunc(RenderScene);
    
	//Extension library - initialize
	GLenum err = glewInit();
	if (GLEW_OK != err) 
	{
		fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
		// return error
	}

	//Create cameras
	//cameraSetup();
	pCamera = new Camera();
	
	CameraManager *goCam = CameraManager::getInstance();

	goCam ->initializeCameras();

	// add a callback timer
	glutTimerFunc(16, TimerFunction, 1);
}

void TimerFunction(int )
{
	//Create a timer
	static Timer timer;

	Time elapsedTime = timer.toc();

	int timeInMs = Time::quotient(elapsedTime, Time(TIME_ONE_MILLISECOND));

	printf("Frames: ms:%d\n", timeInMs);

	//Mark our begin time
	timer.tic();
	
	// reset the timer
    glutTimerFunc(16,TimerFunction, 1);
	
	// trigger the game loop, every 16ms
	GameLoop();
}

void GameLoop( void )
{
	// This function is called once every frame.
	// Use this function to control process order
	// Input, AI, Physics, Animation, and Graphics

	//processInputs

	if (test == 1)
	{
		ProcessAnimation();
	}

	if (test == 2)
	{
		//ProcessAnimation5();
	}

    //static int i=0;

    //i++;
    //printf(" game loop(): %d\n",i);


}

//Initialize pyramid scene
void frameworkStartup(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	//Clear the list
	goMgr -> clearList();
	
	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	PyramidObject *p = new PyramidObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p->setLightColor( Vect(0.0f, 1.0f, 0.0f, 1.0f) );
	p->setScale(0.5f);
	p->setYRotation(0.09f);
	goMgr->addObject(p);

	PyramidObject	*p1 = new PyramidObject;
	p1->setStartPos( Vect(-2.0f, 0.0f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(5.0f, 1.0f, 5.0f, 1.0f) );
	p1->setScale(0.5f);
	p1->setXRotation(0.05f);
	goMgr->addObject(p1);


    PyramidObject *p2 = new PyramidObject;
	p2->setStartPos( Vect(2.0f, 0.0f, 0.0f) );
	p2->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p2->setLightColor( Vect(0.30f, 1.0f, 0.8f, 1.0f) );
	p2->setScale(0.5f);
	p2->setZRotation(0.15f);
	goMgr->addObject(p2);

    PyramidObject *p3 = new PyramidObject;
	p3->setStartPos( Vect(0.0f, 2.0f, 0.0f) );
	p3->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p3->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p3->setScale(0.5f);
	p3->setYRotation(0.07f);
	p3->setZRotation(0.09f);
	goMgr->addObject(p3);


    PyramidObject	*p4 = new PyramidObject;
	p4->setStartPos( Vect(-2.0f, 2.0f, 0.0f) );
	p4->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p4->setLightColor( Vect(1.0f, 0.2f, 0.5f, 1.0f) );
	p4->setScale(0.5f);
	p4->setXRotation(0.06f);
	p4->setYRotation(0.03f);
	goMgr->addObject(p4);


    PyramidObject *p5 = new PyramidObject;
	p5->setStartPos( Vect(2.0f, 2.0f, 0.0f) );
	p5->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p5->setLightColor( Vect(1.0f, 0.4f, 0.7f, 1.0f) );
	p5->setScale(0.5f);
	p5->setZRotation(0.15f);
	p5->setXRotation(0.04f);
	goMgr->addObject(p5);


    PyramidObject *p6 = new PyramidObject;
	p6->setStartPos( Vect(0.0f, -2.0f, 0.0f) );
	p6->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p6->setLightColor( Vect(0.0f, 0.0f, 5.0f, 1.0f) );
	p6->setScale(0.5f);
	p6->setXRotation(0.06f);
	p6->setYRotation(0.03f);
	p6->setZRotation(0.05f);
	goMgr->addObject(p6);


    PyramidObject	*p7 = new PyramidObject;
	p7->setStartPos( Vect(-2.0f, -2.0f, 0.0f) );
	p7->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p7->setLightColor( Vect(0.4f, 0.8f, 1.0f, 1.0f) );
	p7->setScale(0.5f);
	p7->setXRotation(0.09f);
	p7->setYRotation(0.09f);
	p7->setZRotation(0.09f);
	goMgr->addObject(p7);


    PyramidObject *p8 = new PyramidObject;
	p8->setStartPos( Vect(2.0f, -2.0f, 0.0f) );
	p8->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p8->setLightColor( Vect(0.7f, 0.2f, 1.0f, 1.0f) );
	p8->setScale(0.5f);
	p8->setXRotation(0.02f);
	p8->setYRotation(0.03f);
	p8->setZRotation(0.04f);
	goMgr->addObject(p8);

}

//Initialize first sphere collision test
void frameworkStartup1(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(-3.5f, 0.0f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setZRotation(-0.02f);
	p1 -> setXTranslation(0.050f);
	goMgr -> addObject(p1);

}

//Initialize second sphere collision test
void frameworkStartup2(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(3.5f, 0.0f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setZRotation(0.02f);
	p1 -> setXTranslation(-0.050f);
	goMgr -> addObject(p1);

}

//Initialize third sphere collision test
void frameworkStartup3(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(0.0f, 2.5f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setXRotation(0.02f);
	p1 -> setYTranslation(-0.050f);
	goMgr -> addObject(p1);

}

//Initialize fourth sphere collision test
void frameworkStartup4(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(0.0f, -2.5f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setXRotation(-0.02f);
	p1 -> setYTranslation(0.050f);
	goMgr -> addObject(p1);

}

//Initialize fifth sphere collision test
void frameworkStartup5(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(0.0f, 0.0f, 2.5f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setXRotation(-0.02f);
	p1 -> setZTranslation(-0.050f);
	goMgr -> addObject(p1);

}

//Initialize sixth sphere collision test
void frameworkStartup6(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	SphereObject *p1 = new SphereObject;
	p1 -> setStartPos( Vect(0.0f, 0.0f, -2.5f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setTest(true);
	p1 -> setScale(1.5f);
	p1 -> setXRotation(0.02f);
	p1 -> setZTranslation(0.050f);
	goMgr -> addObject(p1);

}

//Initialize first torus collision test
void frameworkStartup7(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(-3.5f, 0.0f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setZRotation(-0.02f);
	p1 -> setXTranslation(0.010f);
	goMgr -> addObject(p1);

}

//Initialize second torus collision test
void frameworkStartup8(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(3.5f, 0.0f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setZRotation(0.02f);
	p1 -> setXTranslation(-0.010f);
	goMgr -> addObject(p1);

}

//Initialize third torus collision test
void frameworkStartup9(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(0.0f, 2.5f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setZRotation(-0.02f);
	p1 -> setYTranslation(-0.010f);
	goMgr -> addObject(p1);

}

//Initialize fourth torus collision test
void frameworkStartup10(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(0.0f, -2.5f, 0.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setZRotation(0.02f);
	p1 -> setYTranslation(0.010f);
	goMgr -> addObject(p1);

}

//Initialize fifth torus collision test
void frameworkStartup11(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(0.0f, 0.0f, 2.5f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setXRotation(-0.02f);
	p1 -> setZTranslation(-0.010f);
	goMgr -> addObject(p1);

}

//Initialize sixth torus collision test
void frameworkStartup12(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pTorus = new Torus();
	pTorus -> createTriangleBatch();
	pTorus -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);

	TorusObject *p1 = new TorusObject;
	p1 -> setStartPos( Vect(0.0f, 0.0f, -2.5f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 0.5f) );
	p1 -> setScale(1.5f);
	p1 -> setXRotation(0.02f);
	p1 -> setZTranslation(0.010f);
	goMgr -> addObject(p1);

}

//Setup cube scene - just playing around here
void frameworkStartup13(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();

	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	//Clear the list
	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(1.0f);
	p->setChangeScale(0.01f);
	p->setMaxScale(2.0f);
	p->setMinScale(0.1f);
	p->setXRotation(0.1f);
	p->setYRotation(0.05f);
	p->setZRotation(0.025f);
	goMgr->addObject(p);
}

//Pyramid collision test 1
void frameworkStartup14(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(-2.5f, 0.0f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setXTranslation(0.05f);
	goMgr->addObject(p1);

}

//Pyramid collision test 2
void frameworkStartup15(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(2.5f, 0.0f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setXTranslation(-0.05f);
	goMgr->addObject(p1);

}

//Pyramid collision test 3
void frameworkStartup16(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(0.0f, 2.5f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setYTranslation(-0.05f);
	goMgr->addObject(p1);

}

//Pyramid collision test 4
void frameworkStartup17(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(0.0f, -2.5f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setYTranslation(0.05f);
	goMgr->addObject(p1);

}

//Pyramid collision test 5
void frameworkStartup18(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(0.0f, 0.0f, 2.5f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setZTranslation(-0.05f);
	goMgr->addObject(p1);

}

//Pyramid collision test 6
void frameworkStartup19(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam2();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	CubeObject *p = new CubeObject;
	p->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p->setLightPos( Vect(1.0f, 1.0f, 0.0f, 1.0f) );
	p->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p->setScale(0.4f);
	goMgr->addObject(p);


	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(0.0f, 0.0f, -2.5f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p1->setTest(true);
	p1->setScale(0.5f);
	p1->setZTranslation(0.05f);
	goMgr->addObject(p1);

}

//Final scene
void frameworkStartup20(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam1();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	pCube = new Cube();
	pCube -> createVAO();

	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSphere = new Sphere();
	pSphere -> createVAO();
	pSphere -> loadTexture();

	PyramidObject *p1 = new PyramidObject;
	p1->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p1->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p1->setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f) );
	p1->setScale(0.5f);
	p1->setYRotation(0.03f);
	goMgr->addObject(p1);

	SphereObject *p2 = new SphereObject;
	p2->setStartPos(Vect(1.5f, 0.0f, 0.0f));
	p2->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p2->setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f) );
	p2->setScale(1.0f);
	p2->setXRotation(-0.02f);
	p2->setZRotation(-0.02f);
	p2->setYYRotation(0.05f);
	goMgr->addObject(p2);

	SphereObject *p3 = new SphereObject;
	p3->setStartPos(Vect(0.0f, 2.5f, 0.0f));
	p3->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p3->setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	p3->setScale(1.5f);
	p3->setYRotation(0.05f);
	p3->setXXRotation(0.07f);
	goMgr->addObject(p3);

	SphereObject *p4 = new SphereObject;
	p4->setStartPos(Vect(-3.0f, 0.0f, 0.0f));
	p4->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p4->setLightColor( Vect(0.0f, 0.0f, 1.0f, 1.0f) );
	p4->setScale(0.5f);
	p4->setXRotation(0.01f);
	p4->setZZRotation(0.02f);
	goMgr->addObject(p4);

	SphereObject *p5 = new SphereObject;
	p5->setStartPos(Vect(2.5f, 2.5f, 2.5f));
	p5->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p5->setLightColor( Vect(1.0f, 0.0f, 1.0f, 1.0f) );
	p5->setScale(2.0f);
	p5->setXRotation(0.03f);
	p5->setYRotation(-0.05f);
	p5->setZRotation(0.07f);
	p5->setXXRotation(-0.02f);
	p5->setYYRotation(0.03f);
	p5->setZZRotation(-0.04f);
	goMgr->addObject(p5);

	PyramidObject *p6 = new PyramidObject;
	p6->setStartPos( Vect(5.0f, 5.0f, 0.0f) );
	p6->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p6->setLightColor( Vect(0.0f, 1.0f, 0.0f, 1.0f) );
	p6->setScale(1.0f);
	p6->setChangeScale(0.005f);
	p6->setMaxScale(1.5f);
	p6->setMinScale(0.75f);
	goMgr->addObject(p6);

	PyramidObject *p7 = new PyramidObject;
	p7->setStartPos( Vect(0.0f, -5.0f, 5.0f) );
	p7->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p7->setLightColor( Vect(0.0f, 0.5f, 0.7f, 1.0f) );
	p7->setScale(1.0f);
	p7->setChangeScale(0.01f);
	p7->setMaxScale(2.5f);
	p7->setMinScale(0.3f);
	p7->setXRotation(0.04f);
	p7->setZTranslation(-0.04f);
	goMgr->addObject(p7);

	PyramidObject *p8 = new PyramidObject;
	p8->setStartPos( Vect(-5.0f, 0.0f, 5.0f) );
	p8->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p8->setLightColor( Vect(0.6f, 0.3f, 0.1f, 1.0f) );
	p8->setScale(0.3f);
	p8->setChangeScale(0.03f);
	p8->setMaxScale(2.0f);
	p8->setMinScale(0.1f);
	p8->setYRotation(0.06f);
	p8->setXXRotation(0.005f);
	goMgr->addObject(p8);

	CubeObject *p9 = new CubeObject;
	p9->setStartPos( Vect(-5.0f, 0.0f, 5.0f) );
	p9->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p9->setLightColor( Vect(0.6f, 0.3f, 0.1f, 1.0f) );
	p9->setScale(0.3f);
	p9->setChangeScale(0.03f);
	p9->setMaxScale(2.0f);
	p9->setMinScale(0.1f);
	p9->setYRotation(0.06f);
	p9->setXXRotation(0.005f);
	goMgr->addObject(p9);

	CubeObject *p10 = new CubeObject;
	p10->setStartPos( Vect(0.0f, -5.0f, 0.0f) );
	p10->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p10->setLightColor( Vect(0.9f, 0.3f, 0.1f, 1.0f) );
	p10->setScale(0.3f);
	p10->setChangeScale(0.03f);
	p10->setMaxScale(0.6f);
	p10->setMinScale(0.1f);
	p10->setZRotation(0.1f);
	p10->setZZRotation(0.01f);
	goMgr->addObject(p10);

	CubeObject *p11 = new CubeObject;
	p11->setStartPos( Vect(-5.0f, -5.0f, -5.0f) );
	p11->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p11->setLightColor( Vect(0.9f, 0.0f, 0.2f, 1.0f) );
	p11->setScale(0.6f);
	p11->setChangeScale(0.06f);
	p11->setMaxScale(1.0f);
	p11->setMinScale(0.2f);
	p11->setXRotation(-0.05f);
	p11->setZRotation(0.1f);
	p11->setYYRotation(-0.1f);
	p11->setZZRotation(0.01f);
	goMgr->addObject(p11);

	CubeObject *p12 = new CubeObject;
	p12->setStartPos( Vect(-5.0f, 5.0f, -5.0f) );
	p12->setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p12->setLightColor( Vect(0.3f, 0.0f, 1.0f, 1.0f) );
	p12->setScale(0.4f);
	p12->setChangeScale(0.04f);
	p12->setMaxScale(0.8f);
	p12->setMinScale(0.1f);
	p12->setXRotation(-0.08f);
	p12->setYRotation(0.07f);
	p12->setZRotation(-0.06f);
	p12->setXXRotation(0.04f);
	p12->setYYRotation(-0.05f);
	p12->setZZRotation(0.03f);
	goMgr->addObject(p12);

}

//First true model scene
void frameworkStartup21(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam6();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	//This sucks, but it makes the whole thing work
	pPyramid = new Pyramid();
	pPyramid -> createVAO();
	pPyramid -> loadTexture();

	pSpaceFrigate = new SpaceFrigate();
	pSpaceFrigate -> loadData("Space_Frigate.vbo");
	pSpaceFrigate -> createVAO();
	pSpaceFrigate -> loadTexture();

	SpaceFrigateObject *p1 = new SpaceFrigateObject();
	p1 -> setStartPos( Vect(0.0f, 0.0f, -75.0f) );
	p1 -> setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p1 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f) );
	p1 -> setYAngle(3.14f);
	p1 -> setZRotation(-0.01f);
	goMgr -> addObject(p1);

	pWarBear = new WarBear();
	pWarBear -> loadData("War_Bear.vbo");
	pWarBear -> createVAO();
	pWarBear -> loadTexture();

	WarBearObject *p2 = new WarBearObject();
	p2 -> setStartPos( Vect(0.0f, -20.0f, 75.0f) );
	p2 -> setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p2 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f) );
	p2 -> setYAngle(1.57f);
	p2 -> setZAngle(1.57f);
	p2 -> setScale(0.5f);
	p2 -> setXRotation(0.01f);
	goMgr -> addObject(p2);

	pAstroBoy = new AstroBoy();
	pAstroBoy -> loadData("Astro_Boy.vbo");
	pAstroBoy -> createVAO();
	pAstroBoy -> loadTexture();

	AstroBoyObject *p3 = new AstroBoyObject();
	p3 -> setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p3 -> setLightPos( Vect(1.0f, 1.0f, 1.0f) );
	p3 -> setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f) );
	p3 -> setYAngle(1.57f);
	p3 -> setZAngle(1.57f);
	p3 -> setScale(0.5f);
	p3 -> setXRotation(0.01f);
	goMgr -> addObject(p3);
}

//Animation Test
void frameworkStartup22(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam7();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	//This sucks, but it makes the whole thing work
	//pPyramid = new Pyramid();
	//pPyramid->setTest1(false);
	//pPyramid -> createVAO();
	//pPyramid -> loadTexture();

	test = 1;

	// Initialize the bone hierarchy, create the bones and attach them into a PCSTree
   SetAnimatioHierarchy();

   // Set up one default pose with bones,
   //    from this point, the animation system will move these bones around
   //    This is done automagically - FUCK YEAH
   SetAnimationPose();

   // Initialize the animation data to use for playback
   SetAnimationData();
	
}

//Humanoid Animation Test
void frameworkStartup23(void)
{
	CameraManager *goCam = CameraManager::getInstance();

    pCamera = goCam -> getCam8();
	
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

	goMgr -> clearList();

	test = 1;

	// Initialize the bone hierarchy, create the bones and attach them into a PCSTree
   SetAnimatioHierarchy();

    // Set up one default pose with bones,
   //    from this point, the animation system will move these bones around
   //    This is done automagically - FUCK YEAH
   SetAnimationPose();

   // Initialize the animation data to use for playback
   SetAnimationData();
	
}
