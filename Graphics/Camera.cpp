#include "OpenGLWrapper.h"
#include "MathEngine.h"
#include "Camera.h"

// default constructor
 Camera :: Camera()
{
};
	
void Camera::setPerspective(const float Fovy, const float Aspect, const float NearDist, const float FarDist)
{
	this->aspectRatio = Aspect;
	this->fovy = Fovy;
	this->nearDist = NearDist;
	this->farDist = FarDist;

};

void Camera::setViewport(const int inX, const int inY, const int width, const int height)
{
	this->viewport_x = inX;
	this->viewport_y = inY;
	this->viewport_width = width;
	this->viewport_height = height;

   this->privSetViewState();
};

void Camera::privSetViewState( void )
{
	glViewport(this->viewport_x, this->viewport_y, this->viewport_width, this->viewport_height);
};


void Camera::privCalcPlaneHeightWidth( void )
{

   this->near_height = 2.0f * tan(( this->fovy * MATH_PI/180.0f ) * .5f) * this->nearDist;
   this->near_width = this->near_height * this->aspectRatio;

   this->far_height = 2.0f * tan(( this->fovy * MATH_PI/180.0f) * .5f) * this->farDist;
   this->far_width = this->far_height * this->aspectRatio;

};

void Camera::setOrientAndPosition(const Vect &inUp, const Vect &inLookAt, const Vect &inPos)
{
	// Remember the up, lookAt and right are unit, and are perpendicular.
	// Treat lookAt as king, find Right vect, then correct Up to insure perpendiculare.
	// Make sure that all vectors are unit vectors.

	//this->vDir = inLookAt;
	//this->vDir.norm();

	//this->vUp = inUp;
	//this->vRight = this->vDir.cross( this->vUp );
	//this->vRight.norm();

	//this->vUp = this->vRight.cross( this->vDir );
	//this->vUp.norm();


	this->vDir = inPos - inLookAt;
	this->vDir.norm();

	
	this->vRight = inUp.cross( this->vDir );
	this->vRight.norm();

	this->vUp = this->vDir.cross( this->vRight );
	this->vUp.norm();

	this->vPos = inPos;

};


void Camera::privCalcFrustumVerts( void )
{
	// Top Left corner and so forth.  In this form to see the pattern
	this->nearTopLeft		= this->vPos + this->vDir * this->nearDist + this->vUp * this->near_height * 0.5f - this->vRight * this->near_width * 0.5f;
	this->nearTopRight		= this->vPos + this->vDir * this->nearDist + this->vUp * this->near_height * 0.5f + this->vRight * this->near_width * 0.5f;
	this->nearBottomLeft	= this->vPos + this->vDir * this->nearDist - this->vUp * this->near_height * 0.5f - this->vRight * this->near_width * 0.5f;
	this->nearBottomRight	= this->vPos + this->vDir * this->nearDist - this->vUp * this->near_height * 0.5f + this->vRight * this->near_width * 0.5f;
	this->farTopLeft		= this->vPos + this->vDir * this->farDist  + this->vUp * this->far_height * 0.5f  - this->vRight * this->far_width * 0.5f;
	this->farTopRight		= this->vPos + this->vDir * this->farDist  + this->vUp * this->far_height * 0.5f  + this->vRight * this->far_width * 0.5f;
	this->farBottomLeft		= this->vPos + this->vDir * this->farDist  - this->vUp * this->far_height * 0.5f  - this->vRight * this->far_width * 0.5f;
	this->farBottomRight	= this->vPos + this->vDir * this->farDist  - this->vUp * this->far_height * 0.5f  + this->vRight * this->far_width * 0.5f;
};
	
void Camera::privCalcFrustumCollisionNormals( void )
{
	// Normals of the frustum around nearTopLeft
	Vect A = this->nearBottomLeft - this->nearTopLeft;
	Vect B = this->nearTopRight - this->nearTopLeft;
	Vect C = this->farTopLeft - this->nearTopLeft;
	
	this->frontNorm = A.cross(B);
	this->frontNorm.norm();

	this->leftNorm = C.cross(A);
	this->leftNorm.norm();
	
	this->topNorm = B.cross(C);
	this->topNorm.norm();

	// Normals of the frustum around farBottomRight
	A = this->farBottomLeft - this->farBottomRight;
	B = this->farTopRight - this->farBottomRight;
	C = this->nearBottomRight - this->farBottomRight;
	
	this->backNorm = A.cross(B);
	this->backNorm.norm();
	
	this->rightNorm = B.cross(C);
	this->rightNorm.norm();

	this->bottomNorm = C.cross(A);
	this->bottomNorm.norm();
};



void Camera::privUpdateProjectionMatrix( void )
{
	
	this->projMatrix[m0] = 2.0f * this->nearDist / this->near_width;
	this->projMatrix[m1] = 0.0f;
	this->projMatrix[m2] = 0.0f;
	this->projMatrix[m3] = 0.0f;
	this->projMatrix[m4] = 0.0f;
	this->projMatrix[m5] = 2.0f * this->nearDist / this->near_height;
	this->projMatrix[m6] = 0.0f;
	this->projMatrix[m7] = 0.0f;
	this->projMatrix[m8] = 0.0f;
	this->projMatrix[m9] = 0.0f;
	this->projMatrix[m10] = (this->farDist + this->nearDist)/(this->nearDist - this->farDist);
	this->projMatrix[m11] = -1.0f;
	this->projMatrix[m12] = 0.0f;
	this->projMatrix[m13] = 0.0f;
	this->projMatrix[m14] = (2.0f * this->farDist * this->nearDist)/(this->nearDist - this->farDist);
	this->projMatrix[m15] = 1.0f;

};


void Camera::privUpdateViewMatrix( void )
{
	// This functions assumes the your vUp, vRight, vDir are still unit
	// And perpendicular to each other


	this->viewMatrix[m0] = this->vRight[x];
	this->viewMatrix[m1] = this->vRight[y];
	this->viewMatrix[m2] = this->vRight[z];
	this->viewMatrix[m3] =  -vPos.dot(vRight);

	this->viewMatrix[m4] = this->vUp[x];
	this->viewMatrix[m5] = this->vUp[y];
	this->viewMatrix[m6] = this->vUp[z];
	this->viewMatrix[m7] =   -vPos.dot(vUp);

	// BS left-handed stuff
	this->viewMatrix[m8] = this->vDir[x];
	this->viewMatrix[m9] = this->vDir[y];
	this->viewMatrix[m10] = this->vDir[z];
	this->viewMatrix[m11] = -vPos.dot(vDir);

	this->viewMatrix[m12] = 0.0f;
	this->viewMatrix[m13] = 0.0f;
	this->viewMatrix[m14] = 0.0f;
	this->viewMatrix[m15] = 1.0f;

	this->viewMatrix.T();

   //???
   //Matrix Trans( TRANS, -this->vPos[x], -this->vPos[y],-this->vPos[z]);
   //this->viewMatrix = this->viewMatrix * Trans;
	
};


void Camera::updateCamera(void)
{

	this->privCalcPlaneHeightWidth( );

	this->privCalcFrustumVerts( );
	this->privCalcFrustumCollisionNormals( );

	this->privUpdateProjectionMatrix( );
	this->privUpdateViewMatrix( );

}

Matrix & Camera::getViewMatrix( void )
{
	return this->viewMatrix;
}

Matrix & Camera::getProjMatrix( void)
{
	return this->projMatrix;
}

void Camera::getPos( Vect &outPos) const
{
	outPos = this->vPos;
}

void Camera::setPos(const Vect &inPos)
{
	this->vPos = inPos;
};

void Camera::getUp( Vect &outUp) const
{
	outUp = this -> vUp;
}


void Camera::getFieldOfView( float &Value) const
{
	Value = this->aspectRatio;
};

void Camera::setFieldOfView( const float Value)
{
	this->aspectRatio = Value;
};

void Camera::getNearDist( float &Value) const
{
	Value = this->nearDist;
}

void Camera::setNearDist( const float Value)
{
	this->nearDist = Value;
}