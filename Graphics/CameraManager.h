#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Camera.h"

// forward declare (get into the habit, it's good to use
class Camera;

// Singleton
class CameraManager
{
public:
	void initializeCameras(void);
	
	static CameraManager * getInstance( void );

	Camera *getCam1();

	Camera *getCam2();

	Camera *getCam3();

	Camera *getCam4();

	Camera *getCam5();

	Camera *getCam6();

	Camera *getCam7();

	Camera *getCam8();

private:
	static CameraManager *privGetInstance();
	void privInitializeCameras(void);

	Camera *cam1;
	Camera *cam2;
	Camera *cam3;
	Camera *cam4;
	Camera *cam5;
	Camera *cam6;
	Camera *cam7;
	Camera *cam8;
	

};


#endif
