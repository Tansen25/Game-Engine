#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Cube.h"
#include "Camera.h"
#include "CameraManager.h"
#include "WarBear.h"
#include "WarBearObject.h"

extern Camera			*pCamera;
extern Cube				*pCube;
extern WarBear			*pWarBear;
extern GLShaderManager	shaderManager;


WarBearObject :: WarBearObject()
{
	Matrix M(IDENTITY);

	sign = 1;

	test = false;

	xyz_change_scale = (float)(0.0f);
	maxScale = (float)(1.0f);
	minScale = (float)(0.1f);

	x_angle = (float)(0.0f);
	y_angle = (float)(0.0f);
	z_angle = (float)(0.0f);

	xx_angle = (float)(0.0f);
	yy_angle = (float)(0.0f);
	zz_angle = (float)(0.0f);

	x_trans = (float)(0.0f);
	y_trans = (float)(0.0f);
	z_trans = (float)(0.0f);

	xyz_scale = (float)(1.0f);

	x_rotate = (float)(0.0f);
	y_rotate = (float)(0.0f);
	z_rotate = (float)(0.0f);

	xx_rotate = (float)(0.0f);
	yy_rotate = (float)(0.0f);
	zz_rotate = (float)(0.0f);

	x_translate = (float)(0.0f);
	y_translate = (float)(0.0f);
	z_translate = (float)(0.0f);

};

void WarBearObject::setStartPos( const Vect & v)
{
	this->startPos = v;

	//pPyramid -> setPyramid(v);
};

void WarBearObject::setLightColor( const Vect & v)
{
	this->lightColor = v;

};

void WarBearObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void WarBearObject::setTest(const bool inTest)
{
	this -> test = inTest;
}

void WarBearObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void WarBearObject::setChangeScale(const float scaled)
{
	this -> xyz_change_scale = scaled;
}

void WarBearObject::setMaxScale(const float max)
{
	this -> maxScale = max;
}

void WarBearObject::setMinScale(const float min)
{
	this -> minScale = min;
}

void WarBearObject::setXAngle(const float xAngle)
{
	this -> x_angle = xAngle;
}

void WarBearObject::setYAngle(const float yAngle)
{
	this -> y_angle = yAngle;
}

void WarBearObject::setZAngle(const float zAngle)
{
	this -> z_angle = zAngle;
}

void WarBearObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void WarBearObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void WarBearObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void WarBearObject::setXXRotation(const float x_rotation)
{
	this -> xx_rotate = x_rotation;
}

void WarBearObject::setYYRotation(const float y_rotation)
{
	this -> yy_rotate = y_rotation;
}

void WarBearObject::setZZRotation(const float z_rotation)
{
	this -> zz_rotate = z_rotation;
}

void WarBearObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void WarBearObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void WarBearObject::setZTranslation(const float z_translation)
{
	this -> z_translate = z_translation;
}

//void PyramidObject::collisionTest()
//{
//	Vect v1;
//	Vect v2;
//
//	//Calculate vectors from cube corners to the pyramid center
//	v1 = pPyramid -> getCenter() - pCube -> getNearTopRight();
//
//	v1.norm();
//	
//	v2 = pPyramid -> getCenter() - pCube -> getFarBottomLeft();
//
//	v2.norm();
//
//	//Calculate distance between cubes front plane and pyramid center
//	float frontDistance = v1.dot(pCube -> getFrontNormal());
//
//	//Calculate distance between cubes right plane and pyramid center
//	float rightDistance = v1.dot(pCube -> getRightNormal());
//
//	//Calculate distance between cubes top plane and pyramid center
//	float topDistance = v1.dot(pCube -> getTopNormal());
//
//	//Calculate distance between cubes back plane and pyramid center
//	float backDistance = v2.dot(pCube -> getBackNormal());
//
//	//Calculate distance between cubes left plane and pyramid center
//	float leftDistance = v2.dot(pCube -> getLeftNormal());
//
//	//Calculate distance between cubes bottom plane and pyramid center
//	float bottomDistance = v2.dot(pCube -> getBottomNormal());
//
//	//Grab the spheres radius
//	float r = pPyramid -> getRadius();
//
//	//Determine collision
//	if (leftDistance < r && rightDistance > (r - (r + r)) && topDistance < r && bottomDistance > (r - (r + r)) && backDistance < r && frontDistance > (r - (r + r)))
//	{
//		setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
//	}
//
//	else
//	{
//		setLightColor( Vect(0.0f, 1.0f, 0.0f, 1.0f));
//	}
//
//}

void WarBearObject::transform( void )
{
	//update scale
	if (xyz_scale >= maxScale)
	{
		sign = -1;
	}

	else if (xyz_scale <= minScale)
	{
		sign = 1;
	}

	this -> xyz_scale += (xyz_change_scale * sign);
	
	//Update angles
	this -> x_angle += x_rotate;

    this -> y_angle += y_rotate;

	this -> z_angle += z_rotate;

	this -> xx_angle += xx_rotate;

	this -> yy_angle += yy_rotate;

	this -> zz_angle += zz_rotate;

	//update translation
	this -> x_trans += x_translate;

	this -> y_trans += y_translate;

	this -> z_trans += z_translate;

	//Create temp matrices
	Matrix Scale(SCALE, xyz_scale, xyz_scale, xyz_scale);

	Matrix RotX(ROT_X, x_angle);

    Matrix RotY(ROT_Y, y_angle);

	Matrix RotZ(ROT_Z, z_angle);

	Matrix RotXX(ROT_X, xx_angle);

	Matrix RotYY(ROT_Y, yy_angle);

	Matrix RotZZ(ROT_Z, zz_angle);

	Matrix Trans( TRANS, this -> startPos[x] + x_trans, this -> startPos[y] + y_trans, this -> startPos[z] + z_trans );

	//Update sphere center
	//pPyramid -> updatePyramid(xyz_scale, Trans);

	//Collision test
	//if (test)
	//{
	//	collisionTest();
	//}

	//Create the local to world matrix (ie Model)
	this -> World = Scale * RotX * RotY * RotZ * Trans * RotXX * RotYY * RotZZ;

	// Create the ModelView ( LocalToWorld * View)
	// Some pipelines have the project concatenated, others don't
	// Best to keep the separated, you can always join them with a quick multiply
	this -> ModelView = this -> World * pCamera -> getViewMatrix();

};


void WarBearObject::setRenderState( void )
{
	// Bind the texture
   glBindTexture(GL_TEXTURE_2D, pWarBear->textureID);

   // Use the stock shader
   shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
                                &ModelView,
                                &pCamera->getProjMatrix(), 
                                &this->lightPos, 
                                &this->lightColor,
								0);

};

void WarBearObject::draw( void )
{
	if (pWarBear -> getDuplicates() == false)
	{
		glBindVertexArray(pWarBear -> vao);

		/*  render primitives from array data */
		// (GLenum  mode,  GLsizei  count,  GLenum  type,  const GLvoid *  indices);
		glDrawElements(GL_TRIANGLES, pWarBear -> triangleCount * 3, GL_UNSIGNED_SHORT, 0);   //The starting point of the IBO
	}

	else
	{
		glBindVertexArray(pWarBear -> vao);

		glDrawArrays(GL_TRIANGLES, 0, pWarBear -> getNumVerts());
	}
};