#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Cube.h"
#include "CubeObject.h"
#include "Camera.h"

extern Camera			*pCamera;
extern Cube 			*pCube;
extern GLShaderManager	shaderManager;


CubeObject :: CubeObject()
{
	Matrix M(IDENTITY);

	sign = 1;

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

void CubeObject::setStartPos( const Vect & v)
{
	this->startPos = v;
};

void CubeObject::setLightColor( const Vect & v)
{
	this->lightColor = v;
};

void CubeObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void CubeObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void CubeObject::setChangeScale(const float scaled)
{
	this -> xyz_change_scale = scaled;
}

void CubeObject::setMaxScale(const float max)
{
	this -> maxScale = max;
}

void CubeObject::setMinScale(const float min)
{
	this -> minScale = min;
}

void CubeObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void CubeObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void CubeObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void CubeObject::setXXRotation(const float x_rotation)
{
	this -> xx_rotate = x_rotation;
}

void CubeObject::setYYRotation(const float y_rotation)
{
	this -> yy_rotate = y_rotation;
}

void CubeObject::setZZRotation(const float z_rotation)
{
	this -> zz_rotate = z_rotation;
}

void CubeObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void CubeObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void CubeObject::setZTranslation(const float z_translation)
{
	this -> z_translate = z_translation;
}

void CubeObject::transform( void )
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

	//Create the local to world matrix (ie Model)
	this -> World = Scale * RotX * RotY * RotZ * Trans * RotXX * RotYY * RotZZ;

	//Update cube vertices
	pCube -> updateVertices(World);

	// Create the ModelView ( LocalToWorld * View)
	// Some pipelines have the project concatenated, others don't
	// Best to keep the separated, you can always join them with a quick multiply
	this -> ModelView = this -> World * pCamera -> getViewMatrix();

};


void CubeObject::setRenderState( void )
{
   // Use the stock shader
   shaderManager.UseStockShader(GLT_SHADER_POINT_LIGHT_DIFF, 
                                &ModelView,
                                &pCamera->getProjMatrix(),
								&this->lightPos,
                                &this->lightColor);

};

void CubeObject::draw( void )
{
       
   glBindVertexArray(pCube -> vao);

   /*  render primitives from array data */
   // (GLenum  mode,  GLsizei  count,  GLenum  type,  const GLvoid *  indices);
   glDrawElements(GL_TRIANGLES, 12*3, GL_UNSIGNED_SHORT, 0);   //The starting point of the IBO

};