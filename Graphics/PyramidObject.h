#ifndef PYRAMID_OBJECT_H
#define PYRAMID_OBJECT_H

class Vect;
#include "GraphicsObject.h"

class PyramidObject : public GraphicsObject
{
public:
	PyramidObject();
	
	void setStartPos( const Vect & v);
	void setLightColor( const Vect & v);
	void setLightPos( const Vect & v);
	void setIndex( int val );

	void setTest(const bool inTest);
	void setTransformTest(const bool inTest);

	void setScale(const float scaled);
	void setChangeScale(const float scaled);
	void setMaxScale(const float max);
	void setMinScale(const float min);

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
	void collisionTest();

	// must define, base class has abstract methods
	void transform( void );
	void draw( void );
	void setRenderState(void);

	Vect	dir;
	float	length;

	Matrix	Local;

private:
	Vect	startPos;
	Vect	lightColor;
	Vect	lightPos;

	int   indexBoneArray;

	bool test;

	bool transformTest;

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