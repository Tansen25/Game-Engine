#ifndef MODEL_OBJECT_H
#define MODEL_OBJECT_H

class Vect;
#include "GraphicsObject.h"

class ModelObject : public GraphicsObject
{
public:
	ModelObject();
	
	void setStartPos( const Vect & v);
	void setLightColor( const Vect & v);
	void setLightPos( const Vect & v);

	void setTest(const bool inTest);

	void setScale(const float scaled);
	void setChangeScale(const float scaled);
	void setMaxScale(const float max);
	void setMinScale(const float min);

	void setXAngle(const float xAngle);
	void setYAngle(const float yAngle);
	void setZAngle(const float zAngle);

	void setXRotation(const float x_rotation);
	void setYRotation(const float y_rotation);
	void setZRotation(const float z_rotation);

	void setXXRotation(const float x_rotation);
	void setYYRotation(const float y_rotation);
	void setZZRotation(const float z_rotation);

	void setXTranslation(const float x_translation);
	void setYTranslation(const float y_translation);
	void setZTranslation(const float z_translation);

	//Test for collison with box
	//void collisionTest();

	// must define, base class has abstract methods
	void transform( void );
	void draw( void );
	void setRenderState(void);


private:
	Vect	startPos;
	Vect	lightColor;
	Vect	lightPos;

	bool test;

	int sign;

	float   xyz_change_scale;
	float   maxScale;
	float   minScale;

	float	x_angle;
	float	y_angle;
	float   z_angle;

	float   xx_angle;
	float	yy_angle;
	float   zz_angle;

	float   x_trans;
	float   y_trans;
	float   z_trans;

	float   xyz_scale;

	float	x_rotate;
	float	y_rotate;
	float	z_rotate;

	float	xx_rotate;
	float	yy_rotate;
	float   zz_rotate;

	float x_translate;
	float y_translate;
	float z_translate;

};



#endif