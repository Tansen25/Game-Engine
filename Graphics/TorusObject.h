#ifndef TORUS_OBJECT_H
#define TORUS_OBJECT_H

class Vect;
#include "GraphicsObject.h"

class TorusObject : public GraphicsObject
{
public:
	TorusObject();
	
	void setStartPos( const Vect & v);
	void setLightColor( const Vect & v);
	void setLightPos( const Vect & v);

	void setScale(const float scaled);

	void setXRotation(const float x_rotation);
	void setYRotation(const float y_rotation);
	void setZRotation(const float z_rotation);

	void setXTranslation(const float x_translation);
	void setYTranslation(const float y_translation);
	void setZTranslation(const float z_translation);

	//Test for collison with box
	void collisionTest();

	// must define, base class has abstract methods
	void transform( void );
	void draw( void );
	void setRenderState(void);


private:
	Vect	startPos;
	Vect	lightColor;
	Vect	lightPos;
	float   xyz_scale;
	float	x_angle;
	float	y_angle;
	float   z_angle;
	float   x_trans;
	float   y_trans;
	float   z_trans;

	float x_rotate;
	float y_rotate;
	float z_rotate;

	float x_translate;
	float y_translate;
	float z_translate;

};



#endif