#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Pyramid.h"
#include "PyramidObject.h"
#include "Cube.h"
#include "Camera.h"
#include "CameraManager.h"
#include "Anim.h"

extern Camera			*pCamera;
extern Pyramid			*pPyramid;
extern  Cube			*pCube;
extern Frame_Bucket		*pHead;
extern GLShaderManager	shaderManager;


PyramidObject :: PyramidObject()
{
	Matrix M(IDENTITY);

	sign = 1;

	test = false;

	transformTest = true;

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

	this->startPos = Vect(0.0f, 0.0f, 0.0f );
	this->lightPos = Vect(50.0f, 50.0f, 0.0f);
	this->lightColor = Vect(0.5f, 1.5f, 0.5f);

};

void PyramidObject::setStartPos( const Vect & v)
{
	this->startPos = v;

	pPyramid -> setPyramid(v);
};

void PyramidObject::setLightColor( const Vect & v)
{
	this->lightColor = v;

};

void PyramidObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void PyramidObject::setIndex( int val )
{
    this->indexBoneArray = val;
}

void PyramidObject::setTest(const bool inTest)
{
	this -> test = inTest;
}

void PyramidObject::setTransformTest(const bool inTest)
{
	this -> transformTest = inTest;
}

void PyramidObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void PyramidObject::setChangeScale(const float scaled)
{
	this -> xyz_change_scale = scaled;
}

void PyramidObject::setMaxScale(const float max)
{
	this -> maxScale = max;
}

void PyramidObject::setMinScale(const float min)
{
	this -> minScale = min;
}

void PyramidObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void PyramidObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void PyramidObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void PyramidObject::setXXRotation(const float x_rotation)
{
	this -> xx_rotate = x_rotation;
}

void PyramidObject::setYYRotation(const float y_rotation)
{
	this -> yy_rotate = y_rotation;
}

void PyramidObject::setZZRotation(const float z_rotation)
{
	this -> zz_rotate = z_rotation;
}

void PyramidObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void PyramidObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void PyramidObject::setZTranslation(const float z_translation)
{
	this -> z_translate = z_translation;
}

void PyramidObject::collisionTest()
{
	Vect v1;
	Vect v2;

	//Calculate vectors from cube corners to the pyramid center
	v1 = pPyramid -> getCenter() - pCube -> getNearTopRight();

	v1.norm();
	
	v2 = pPyramid -> getCenter() - pCube -> getFarBottomLeft();

	v2.norm();

	//Calculate distance between cubes front plane and pyramid center
	float frontDistance = v1.dot(pCube -> getFrontNormal());

	//Calculate distance between cubes right plane and pyramid center
	float rightDistance = v1.dot(pCube -> getRightNormal());

	//Calculate distance between cubes top plane and pyramid center
	float topDistance = v1.dot(pCube -> getTopNormal());

	//Calculate distance between cubes back plane and pyramid center
	float backDistance = v2.dot(pCube -> getBackNormal());

	//Calculate distance between cubes left plane and pyramid center
	float leftDistance = v2.dot(pCube -> getLeftNormal());

	//Calculate distance between cubes bottom plane and pyramid center
	float bottomDistance = v2.dot(pCube -> getBottomNormal());

	//Grab the spheres radius
	float r = pPyramid -> getRadius();

	//Determine collision
	if (leftDistance < r && rightDistance > (r - (r + r)) && topDistance < r && bottomDistance > (r - (r + r)) && backDistance < r && frontDistance > (r - (r + r)))
	{
		setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	}

	else
	{
		setLightColor( Vect(0.0f, 1.0f, 0.0f, 1.0f));
	}

}

void PyramidObject::transform( void )
{
	if(transformTest)
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
		pPyramid -> updatePyramid(xyz_scale, Trans);

		//Collision test
		if (test)
		{
			collisionTest();
		}

		//Create the local to world matrix (ie Model)
		this -> World = Scale * RotX * RotY * RotZ * Trans * RotXX * RotYY * RotZZ;

		// Create the ModelView ( LocalToWorld * View)
		// Some pipelines have the project concatenated, others don't
		// Best to keep the separated, you can always join them with a quick multiply
		this -> ModelView = this -> World * pCamera -> getViewMatrix();

	}

	else
	{
		Matrix ParentWorld;
		
		// Does this node have a parent?
		if( this->getParent() == 0 )
		{
		  // no - set to identity
			ParentWorld.set(IDENTITY);
		}
		else
		{
		  // yes - get it
		  PCSNode *p = this->getParent();

		  // The following statements can be reduced due to polymorphism
		  // 1) GraphicsObject *go = (GraphicsObject *) p;
		  // 2) PyramidObject *parentObj = (PyramidObject *) go;
		  PyramidObject *parentObj = (PyramidObject *) p;

		  // Now get the world matrix
		  ParentWorld = parentObj->World;
		}

		// Get the result bone array
		Bone *bResult = pHead->pBone;


		Matrix M,T,S,R;


		Vect vTrans = bResult[indexBoneArray].T;
		Vect vScale = bResult[indexBoneArray].S;

		T.set(TRANS, vTrans[x],vTrans[y],vTrans[z]);
		S.set(SCALE, vScale[x],vScale[y],vScale[z]);
		R.set( bResult[indexBoneArray].Q );

		M = S * R * T;

		this -> Local = M;
		
		this->World =  this->Local * ParentWorld;

		// Create the ModelView ( LocalToWorld * View)
		// Some pipelines have the project concatenated, others don't
		// Best to keep the separated, you can always join them with a quick multiply
		this->ModelView = this->World * pCamera->getViewMatrix();
	}

};


void PyramidObject::setRenderState( void )
{
	// Bind the texture
   glBindTexture(GL_TEXTURE_2D, pPyramid->textureID);

   // Use the stock shader
   shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
                                &ModelView,
                                &pCamera->getProjMatrix(), 
                                &this->lightPos, 
                                &this->lightColor,
								0);

};

void PyramidObject::draw( void )
{
       
   //pPyramid->pyramidBatch.Draw();

	glBindVertexArray(pPyramid -> vao);
	
	//glDrawArrays(GL_TRIANGLES, 0, 18);

	/*  render primitives from array data */
    // (GLenum  mode,  GLsizei  count,  GLenum  type,  const GLvoid *  indices);
    glDrawElements(GL_TRIANGLES, 6*3, GL_UNSIGNED_SHORT, 0);   //The starting point of the IBO
};