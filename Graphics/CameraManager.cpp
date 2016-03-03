#include "CameraManager.h"
#include "Camera.h"

void CameraManager::initializeCameras(void)
{
	privInitializeCameras();
}
	
CameraManager * CameraManager::getInstance( void )
{
	return privGetInstance();
}

Camera *CameraManager::getCam1()
{
	return cam1;
}

Camera *CameraManager::getCam2()
{
	return cam2;
}

Camera *CameraManager::getCam3()
{
	return cam3;
}

Camera *CameraManager::getCam4()
{
	return cam4;
}

Camera *CameraManager::getCam5()
{
	return cam5;
}

Camera *CameraManager::getCam6()
{
	return cam6;
}

Camera *CameraManager::getCam7()
{
	return cam7;
}

Camera *CameraManager::getCam8()
{
	return cam8;
}

CameraManager *CameraManager::privGetInstance()
{
	static CameraManager cm;
	return &cm;
}

void CameraManager::privInitializeCameras(void)
{
	cam1 = new Camera();
	cam1->setViewport( 0, 0,800, 600);
	cam1->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam1->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(0,0,7) );

	cam2 = new Camera();
	cam2->setViewport( 0, 0,800, 600);
	cam2->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam2->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(14,14,14) );

	cam3 = new Camera();
	cam3->setViewport( 0, 0,800, 600);
	cam3->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam3->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(14,14,-14) );

	cam4 = new Camera();
	cam4->setViewport( 0, 0,800, 600);
	cam4->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam4->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(-14,14,-14) );

	cam5 = new Camera();
	cam5->setViewport( 0, 0,800, 600);
	cam5->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam5->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(-14,14,14) );

	cam6 = new Camera();
	cam6->setViewport( 0, 0,800, 600);
	cam6->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam6->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(250,50,0) );

	cam7 = new Camera();
	cam7->setViewport( 0, 0,800, 600);
	cam7->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam7->setOrientAndPosition( Vect(0,1,0), Vect(0,0,0), Vect(40,0,400) );

	cam8 = new Camera();
	cam8->setViewport( 0, 0,800, 600);
	cam8->setPerspective( 35.0f, float(800)/float(600), 1.0f, 500.0f);
    cam8->setOrientAndPosition( Vect(0,0,1), Vect(0,0,0), Vect(0,400,0) );
}