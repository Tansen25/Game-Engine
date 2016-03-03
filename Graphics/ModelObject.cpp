#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Cube.h"
#include "Camera.h"
#include "CameraManager.h"
#include "Model.h"
#include "ModelObject.h"

extern Camera			*pCamera;
extern  Cube			*pCube;
extern Model			*pModel;
extern GLShaderManager	shaderManager;


ModelObject :: ModelObject()
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

void ModelObject::setStartPos( const Vect & v)
{
	this->startPos = v;

	//pPyramid -> setPyramid(v);
};

void ModelObject::setLightColor( const Vect & v)
{
	this->lightColor = v;

};

void ModelObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void ModelObject::setTest(const bool inTest)
{
	this -> test = inTest;
}

void ModelObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void ModelObject::setChangeScale(const float scaled)
{
	this -> xyz_change_scale = scaled;
}

void ModelObject::setMaxScale(const float max)
{
	this -> maxScale = max;
}

void ModelObject::setMinScale(const float min)
{
	this -> minScale = min;
}

void ModelObject::setXAngle(const float xAngle)
{
	this -> x_angle = xAngle;
}

void ModelObject::setYAngle(const float yAngle)
{
	this -> y_angle = yAngle;
}

void ModelObject::setZAngle(const float zAngle)
{
	this -> z_angle = zAngle;
}

void ModelObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void ModelObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void ModelObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void ModelObject::setXXRotation(const float x_rotation)
{
	this -> xx_rotate = x_rotation;
}

void ModelObject::setYYRotation(const float y_rotation)
{
	this -> yy_rotate = y_rotation;
}

void ModelObject::setZZRotation(const float z_rotation)
{
	this -> zz_rotate = z_rotation;
}

void ModelObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void ModelObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void ModelObject::setZTranslation(const float z_translation)
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

void ModelObject::transform( void )
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
	this -> LocalToWorld = Scale * RotX * RotY * RotZ * Trans * RotXX * RotYY * RotZZ;

	// Create the ModelView ( LocalToWorld * View)
	// Some pipelines have the project concatenated, others don't
	// Best to keep the separated, you can always join them with a quick multiply
	this -> ModelView = this -> LocalToWorld * pCamera -> getViewMatrix();

};


void ModelObject::setRenderState( void )
{
	// Bind the texture
   glBindTexture(GL_TEXTURE_2D, pModel->textureID);

   // Use the stock shader
   shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
                                &ModelView,
                                &pCamera->getProjMatrix(), 
                                &this->lightPos, 
                                &this->lightColor,
								0);

};

void ModelObject::draw( void )
{
	if (pModel -> getDuplicates() == false)
	{
		glBindVertexArray(pModel -> vao);

		/*  render primitives from array data */
		// (GLenum  mode,  GLsizei  count,  GLenum  type,  const GLvoid *  indices);
		glDrawElements(GL_TRIANGLES, pModel -> triangleCount * 3, GL_UNSIGNED_SHORT, 0);   //The starting point of the IBO
	}

	else
	{
		glBindVertexArray(pModel -> vao);

		glDrawArrays(GL_TRIANGLES, 0, pModel -> getNumVerts());
	}
};