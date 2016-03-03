#ifndef CUBE_H
#define CUBE_H


#include "MathEngine.h"

class Cube
{
public:
    Cube();

	void createVAO(void);

	void updateVertices(Matrix &inMatrix);

	//Accessors
	Vect getNearTopRight();
	Vect getFarBottomLeft();
	Vect getTopNormal();
	Vect getBottomNormal();
	Vect getRightNormal();
	Vect getLeftNormal();
	Vect getFrontNormal();
	Vect getBackNormal();

    GLuint vao;

private:
	//Update the normals
	void updateNormals();
	
	//Set default coords
	void defaultCoords();
	
	// World space coords for cube
	Vect	nearTopLeft;
	Vect	nearTopRight;
	Vect	nearBottomLeft;
	Vect	nearBottomRight;	
	Vect	farTopLeft;
	Vect	farTopRight;
	Vect	farBottomLeft;
	Vect	farBottomRight;

	//Face normals
	Vect topNormal;
	Vect bottomNormal;
	Vect rightNormal;
	Vect leftNormal;
	Vect frontNormal;
	Vect backNormal;
};

#endif