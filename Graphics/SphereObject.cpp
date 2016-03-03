#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Sphere.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Cube.h"

extern Camera			*pCamera;
extern Cube				*pCube;
extern Sphere			*pSphere;
extern GLShaderManager	shaderManager;


SphereObject :: SphereObject()
{
	Matrix M(IDENTITY);

	test = false;

	xyz_scale = (float)(1.0f);

	x_angle = (float)(0.0f);
	y_angle = (float)(0.0f);//rand()%6);
	z_angle = (float)(0.0f);

	xx_angle = (float)(0.0f);
	yy_angle = (float)(0.0f);
	zz_angle = (float)(0.0f);

	x_trans = (float)(0.0f);
	y_trans = (float)(0.0f);
	z_trans = (float)(0.0f);

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

void SphereObject::setStartPos( const Vect & v)
{
	this->startPos = v;

	//Set sphere center
	pSphere -> setCenter(v);
};

void SphereObject::setLightColor( const Vect & v)
{
	this->lightColor = v;
};

void SphereObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void SphereObject::setTest(const bool inTest)
{
	this -> test = inTest;
}

void SphereObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void SphereObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void SphereObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void SphereObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void SphereObject::setXXRotation(const float x_rotation)
{
	this -> xx_rotate = x_rotation;
}

void SphereObject::setYYRotation(const float y_rotation)
{
	this -> yy_rotate = y_rotation;
}

void SphereObject::setZZRotation(const float z_rotation)
{
	this -> zz_rotate = z_rotation;
}

void SphereObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void SphereObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void SphereObject::setZTranslation(const float z_translation)
{
	this -> z_translate = z_translation;
}

void SphereObject::collisionTest()
{
	Vect v1;
	Vect v2;

	//Calculate vectors from cube corners to the sphere center
	v1 = pSphere -> getCenter() - pCube -> getNearTopRight();

	v1.norm();

	v2 = pSphere -> getCenter() - pCube -> getFarBottomLeft();

	v2.norm();

	//Calculate distance between cubes front plane and sphere center
	float frontDistance = v1.dot(pCube -> getFrontNormal());

	//Calculate distance between cubes right plane and sphere center
	float rightDistance = v1.dot(pCube -> getRightNormal());

	//Calculate distance between cubes top plane and sphere center
	float topDistance = v1.dot(pCube -> getTopNormal());

	//Calculate distance between cubes back plane and sphere center
	float backDistance = v2.dot(pCube -> getBackNormal());

	//Calculate distance between cubes left plane and sphere center
	float leftDistance = v2.dot(pCube -> getLeftNormal());

	//Calculate distance between cubes bottom plane and sphere center
	float bottomDistance = v2.dot(pCube -> getBottomNormal());

	//Grab the spheres radius
	float r = pSphere -> getRadius();

	//Determine collision
	if (leftDistance < r && rightDistance > (r - (r + r)) && topDistance < r && bottomDistance > (r - (r + r)) && backDistance < r && frontDistance > (r - (r + r)))
	{
		setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	}

	else
	{
		setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f));
	}

}

void SphereObject::transform( void )
{
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
	pSphere -> updateSphere(xyz_scale, Trans);

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

};


void SphereObject::setRenderState( void )
{
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, pSphere->textureID);

	shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
			                        &ModelView,
				                    &pCamera->getProjMatrix(), 
					                &this->lightPos, 
						            &this->lightColor,
									0);
	
};

void SphereObject::draw( void )
{
       
    glBindVertexArray(pSphere -> vao);
	glDrawArrays(GL_TRIANGLES, 0, 3 * 676);

};