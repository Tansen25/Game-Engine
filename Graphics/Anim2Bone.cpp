#include "OpenGLWrapper.h"
#include "PyramidObject.h"
#include "GraphicsManager.h"
#include "Pyramid.h"
#include "Anim.h"

// temporary hack
Frame_Bucket *pHead = 0;
PyramidObject *p0;
PyramidObject *p1;
extern Pyramid *pPyramid;

void SetAnimatioHierarchy()
{
   // setup the bone model, this case we are using pyramid
   // todo - create a cool Bone Object, ball(drk blue) + pyramid arm (dark yellow)
   pPyramid = new Pyramid();
   pPyramid->setTest(true);
   pPyramid->setTest1(false);
   pPyramid->createVAO();
	pPyramid->loadTexture();
	
   // Get the manager
	GraphicsObjectManager *goMgr = GraphicsObjectManager::getInstance();

   // Create the two objects
	p0 = new PyramidObject();
	p0->setStartPos( Vect(0.0f, 0.0f, 0.0f) );
	p0->setLightPos( Vect(50.0f, 50.0f, 0.0f) );
	p0->setLightColor( Vect(1.5f, 0.5f, 0.5f) );
	p0->setIndex(0);
	 p0->setTransformTest(false);

   p0->setName("Bone_0");

	p1 = new PyramidObject();
	p1->setStartPos( Vect(1.0f, 1.0f, 0.0f) );
	p1->setLightPos( Vect(50.0f, 50.0f, 0.0f) );
	p1->setLightColor( Vect(0.5f, 1.5f, 0.5f) );
   p1->setIndex(1);
   p1->setTransformTest(false);

   p1->setName("Bone_1");

   // Attached it into the tree
   PCSTree *tree = goMgr->getTree();
   PCSNode *root = tree->getRoot();

   // Add 1st two bones
   tree->insert( p0, root );
   tree->insert( p1, p0 );
}

void SetAnimationPose()
{
   // REMEMBER:
   //    that the bone pose are WORLD not GLOBAL
   //    Animations are relative!


	//Bone 0
	    Matrix bone_0(	Vect(    1.0000f, 0.0001f, 0.0000f,  0.0000f),
						      Vect(   -0.0001f, 1.0000f, -0.0000f, 0.0000f),
						      Vect(   -0.0000f, 0.0000f,  1.0000f, 0.0000f),
						      Vect( -120.0000f, 0.0000f,  0.0000f, 1.0000f));


		Vect start(0.0f,0.0f,0.0f);
		Vect vout;

      // Now the start position is oriented to the bone_0 matrix
		vout = start * bone_0;

      // Squirrel away for future
		Vect Pt_0 = vout;

      // Set the start position
		p0->setStartPos( vout );

	//Bone 1
		Matrix bone_1( Vect(  1.0000f, 0.0001f,  0.0000f, 0.0000),
				         Vect( -0.0001f, 1.0000f, -0.0000f, 0.0000),
				         Vect( -0.0000f, 0.0000f,  1.0000f, 0.0000f),
				         Vect( -5.1739f, 0.0104f,  0.0000f, 1.0000f));

      // Now the start position is oriented to the bone_0 matrix
		vout = start * bone_1;

      // Squirrel away for future
		Vect Pt_1 = vout;

      // Set position
		p1->setStartPos( vout );


   // Great:
   //       At this point, we have the two bones initial positions in world space
   //       Now get the length and directions

      // direction between the anchor points of the respective bones
		Vect dir = Pt_1 - Pt_0;

      // length of the bone 0
		float mag = dir.mag();

      // Set the orientation and length for bone 0
		p0->dir = dir;
		p0->length = mag;

      // Set the orientation and length for bone 1
		p1->dir = dir;
		p1->length = mag;

   // We are Awesome:
   //       At this point, we have the two bones initial positions in world space, directions and length
   //       Now get the parent relative orientations!

      // Bone 0 is simply the parent is the identity
      // local is the world matrix
		p0->Local = bone_0;

      // Bone 1 parent matrix is bone 0  
      //           <--- important (it has to be the parent bone that was just calculated
      // Now the local needs to be set with respect to the parent matrix.
      //          World  = Parent * Local
      //          Bone_1_world =  Bone_0_world * Local      <--- we are looking for this one
      //          Local = Bone_0_world->inv() * Bone_1_world
		Matrix temp = bone_0.getInv();

		p1->Local = temp * bone_1;

}



void SetAnimationData()
{

   // --------  Result Frame  ----------------------

   pHead = new Frame_Bucket();
	pHead->prevBucket = 0;
	pHead->nextBucket = 0;
	pHead->KeyTime = Time(TIME_ZERO);
	pHead->pBone = new Bone[2];

   // --------  Frame 0  ----------------------------

   Frame_Bucket *pTmp = new Frame_Bucket();
	pTmp->prevBucket = pHead;
	pTmp->nextBucket = 0;
	pTmp->KeyTime = 0 * Time(TIME_NTSC_30_FRAME);
	pTmp->pBone = new Bone[2];

	pHead->nextBucket = pTmp;

	pTmp->pBone[0].T = Vect(-113.894875f, 0.000000f, 0.000000f);
   pTmp->pBone[0].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.000095f);
   pTmp->pBone[0].S = Vect(1.0f, 1.0f, 1.0f);
 
   pTmp->pBone[1].T = Vect(114.826065f, -0.000016f, 0.000000f);
   pTmp->pBone[1].Q = Quat(ROT_XYZ,   0.000000f, 0.000000f, -0.000095f);
	pTmp->pBone[1].S = Vect(1.0f, 1.0f, 1.0f);

   // --------  Frame 35  -----------------------------
   
   Frame_Bucket *pTmp2 = new Frame_Bucket();
	pTmp2->prevBucket = pTmp;
	pTmp2->nextBucket = 0;
	pTmp2->KeyTime = 35 * Time(TIME_NTSC_30_FRAME);
	pTmp2->pBone = new Bone[2];

	pTmp->nextBucket = pTmp2;

   pTmp2->pBone[0].T = Vect(-69.141525f, 0.000000f, 0.000000f);
   pTmp2->pBone[0].Q = Quat(ROT_XYZ,-0.000000f, -0.000000f, 0.610865f);
	pTmp2->pBone[0].S = Vect(1.0f, 1.0f, 1.0f);

	pTmp2->pBone[1].T = Vect(114.826065f, -0.000016f, 0.000000f);
   pTmp2->pBone[1].Q = Quat(ROT_XYZ, -0.000000f, 0.000000f, -1.220934f );
   pTmp2->pBone[1].S = Vect(1.0f, 1.0f, 1.0f);

   // --------  Frame 70 ----------------------

   Frame_Bucket *pTmp3 = new Frame_Bucket();
	pTmp3->prevBucket = pTmp2;
	pTmp3->nextBucket = 0;
	pTmp3->KeyTime = 70 * Time(TIME_NTSC_30_FRAME);
	pTmp3->pBone = new Bone[2];

	pTmp2->nextBucket = pTmp3;

	pTmp3->pBone[0].T = Vect(-39.924347f, 0.000000f, 0.000000f);
   pTmp3->pBone[0].Q = Quat(ROT_XYZ, 0.000000f, -0.000000f, 0.000000f );
	pTmp3->pBone[0].S = Vect(1.0f, 1.0f, 1.0f);
   
   pTmp3->pBone[1].T = Vect(114.826065f, -0.000016f, 0.000000f);
   pTmp3->pBone[1].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, -0.000000f);
   pTmp3->pBone[1].S = Vect( 1.0f, 1.0f, 1.0f);

}