#include <stdlib.h>
#include "OpenGLWrapper.h"

#include "Torus.h"
#include "TorusObject.h"
#include "Camera.h"
#include "Cube.h"

extern Camera			*pCamera;
extern Cube				*pCube;
extern Torus			*pTorus;
extern GLShaderManager	shaderManager;


TorusObject :: TorusObject()
{
	Matrix M(IDENTITY);

	xyz_scale = (float)(0.0f);

	x_angle = (float)(0.0f);
	y_angle = (float)(0.0f);//rand()%6);
	z_angle = (float)(0.0f);

	x_trans = (float)(0.0f);
	y_trans = (float)(0.0f);
	z_trans = (float)(0.0f);

	x_rotate = (float)(0.0f);
	y_rotate = (float)(0.0f);
	z_rotate = (float)(0.0f);

	x_translate = (float)(0.0f);
	y_translate = (float)(0.0f);
	z_translate = (float)(0.0f);

};

void TorusObject::setStartPos( const Vect & v)
{
	this->startPos = v;

	//Set sphere center
	pTorus -> setCenter(v);
};

void TorusObject::setLightColor( const Vect & v)
{
	this->lightColor = v;
};

void TorusObject::setLightPos( const Vect & v)
{
	this->lightPos = v;
};

void TorusObject::setScale(const float scaled)
{
	this -> xyz_scale = scaled;
}

void TorusObject::setXRotation(const float x_rotation)
{
	this -> x_rotate = x_rotation;
}

void TorusObject::setYRotation(const float y_rotation)
{
	this -> y_rotate = y_rotation;
}

void TorusObject::setZRotation(const float z_rotation)
{
	this -> z_rotate = z_rotation;
}

void TorusObject::setXTranslation(const float x_translation)
{
	this -> x_translate = x_translation;
}

void TorusObject::setYTranslation(const float y_translation)
{
	this -> y_translate = y_translation;
}

void TorusObject::setZTranslation(const float z_translation)
{
	this -> z_translate = z_translation;
}

void TorusObject::collisionTest()
{
	Vect v1;
	Vect v2;

	//Calculate vectors from cube corners to the torus center
	v1 = pTorus -> getCenter() - pCube -> getNearTopRight();

	v1.norm();

	v2 = pTorus -> getCenter() - pCube -> getFarBottomLeft();

	v2.norm();

	//Calculate distance between cubes front plane and torus center
	float frontDistance = v1.dot(pCube -> getFrontNormal());

	//Calculate distance between cubes right plane and torus center
	float rightDistance = v1.dot(pCube -> getRightNormal());

	//Calculate distance between cubes top plane and torus center
	float topDistance = v1.dot(pCube -> getTopNormal());

	//Calculate distance between cubes back plane and torus center
	float backDistance = v2.dot(pCube -> getBackNormal());

	//Calculate distance between cubes left plane and torus center
	float leftDistance = v2.dot(pCube -> getLeftNormal());

	//Calculate distance between cubes bottom plane and torus center
	float bottomDistance = v2.dot(pCube -> getBottomNormal());

	//Grab the torus' major radius
	float majorR = pTorus -> getMajorRadius();

	//Grab the torus' minor radius
	float minorR = pTorus -> getMinorRadius();

	//Determine collision
	if (leftDistance < (majorR + minorR) && rightDistance > (majorR - (majorR + majorR) - minorR) 
		&& topDistance < (majorR + minorR) && bottomDistance > (majorR - (majorR + majorR) - minorR) 
		&& backDistance < (majorR + minorR) && frontDistance > (majorR - (majorR + majorR) - minorR))
	{
		setLightColor( Vect(1.0f, 0.0f, 0.0f, 1.0f) );
	}

	else
	{
		setLightColor( Vect(1.0f, 1.0f, 1.0f, 1.0f));
	}

}

void TorusObject::transform( void )
{
	//Update angles
	this -> x_angle += x_rotate;

    this -> y_angle += y_rotate;

	this -> z_angle += z_rotate;

	//update translation
	this -> x_trans += x_translate;

	this -> y_trans += y_translate;

	this -> z_trans += z_translate;

	//Create temp matrices
	Matrix Scale(SCALE, xyz_scale, xyz_scale, xyz_scale);

	Matrix RotX(ROT_X, x_angle);

    Matrix RotY(ROT_Y, y_angle);

	Matrix RotZ(ROT_Z, z_angle);

	Matrix Trans( TRANS, this -> startPos[x] + x_trans, this -> startPos[y] + y_trans, this -> startPos[z] + z_trans );

	//Update torus center
	pTorus -> updateTorus(xyz_scale, Trans);

	//Collision test
	collisionTest();

	//Create the local to world matrix (ie Model)
	this -> World = Scale * RotX * RotY * RotZ * Trans;

	// Create the ModelView ( LocalToWorld * View)
	// Some pipelines have the project concatenated, others don't
	// Best to keep the separated, you can always join them with a quick multiply
	this -> ModelView = this -> World * pCamera -> getViewMatrix();

};


void TorusObject::setRenderState( void )
{
    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, pTorus->textureID);

	shaderManager.UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
			                        &ModelView,
				                    &pCamera->getProjMatrix(), 
					                &this->lightPos, 
						            &this->lightColor,
									0);
	
};

void TorusObject::draw( void )
{
       
   pTorus->torusBatch.Draw();

};