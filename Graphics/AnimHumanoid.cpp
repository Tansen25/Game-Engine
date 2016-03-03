#include "OpenGLWrapper.h"
#include "PyramidObject.h"
#include "GraphicsManager.h"
#include "Pyramid.h"
#include "Anim.h"

// temporary hack
Frame_Bucket *pHead = 0;
//PyramidObject *p0;
//PyramidObject *p1;
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

   // Attached it into the tree
   PCSTree *tree = goMgr->getTree();
   PCSNode *root = tree->getRoot();

   //---------  Cut and Paste Below ------------------------

   PyramidObject *pMaxToFilmbox_Root = new PyramidObject;
	pMaxToFilmbox_Root->setIndex(0);
	pMaxToFilmbox_Root->setName("MaxToFilmbox_Root");
	pMaxToFilmbox_Root->setTransformTest(false);
	tree->insert( pMaxToFilmbox_Root, root );

	PyramidObject *pReference = new PyramidObject;
	pReference->setIndex(1);
	pReference->setName("Reference");
	pReference->setTransformTest(false);
	tree->insert( pReference, pMaxToFilmbox_Root );

	PyramidObject *pHips = new PyramidObject;
	pHips->setIndex(2);
	pHips->setName("Hips");
	pHips->setTransformTest(false);
	tree->insert( pHips, pReference );

	PyramidObject *pSpine_Dummy = new PyramidObject;
	pSpine_Dummy->setIndex(3);
	pSpine_Dummy->setName("Spine_Dummy");
	pSpine_Dummy->setTransformTest(false);
	tree->insert( pSpine_Dummy, pHips );

	PyramidObject *pSpine = new PyramidObject;
	pSpine->setIndex(4);
	pSpine->setName("Spine");
	pSpine->setTransformTest(false);
	tree->insert( pSpine, pSpine_Dummy );

	PyramidObject *pSpine1 = new PyramidObject;
	pSpine1->setIndex(5);
	pSpine1->setName("Spine1");
	pSpine1->setTransformTest(false);
	tree->insert( pSpine1, pSpine );

	PyramidObject *pSpine2 = new PyramidObject;
	pSpine2->setIndex(6);
	pSpine2->setName("Spine2");
	pSpine2->setTransformTest(false);
	tree->insert( pSpine2, pSpine1 );

	PyramidObject *pNeck = new PyramidObject;
	pNeck->setIndex(7);
	pNeck->setName("Neck");
	pNeck->setTransformTest(false);
	tree->insert( pNeck, pSpine2 );

	PyramidObject *pHead = new PyramidObject;
	pHead->setIndex(8);
	pHead->setName("Head");
	pHead->setTransformTest(false);
	tree->insert( pHead, pNeck );

	PyramidObject *pHead_End = new PyramidObject;
	pHead_End->setIndex(9);
	pHead_End->setName("Head_End");
	pHead_End->setTransformTest(false);
	tree->insert( pHead_End, pHead );

	PyramidObject *pLeftShoulder_Dummy = new PyramidObject;
	pLeftShoulder_Dummy->setIndex(10);
	pLeftShoulder_Dummy->setName("LeftShoulder_Dummy");
	pLeftShoulder_Dummy->setTransformTest(false);
	tree->insert( pLeftShoulder_Dummy, pSpine2 );

	PyramidObject *pLeftShoulder = new PyramidObject;
	pLeftShoulder->setIndex(11);
	pLeftShoulder->setName("LeftShoulder");
	pLeftShoulder->setTransformTest(false);
	tree->insert( pLeftShoulder, pLeftShoulder_Dummy );

	PyramidObject *pLeftArm_Dummy = new PyramidObject;
	pLeftArm_Dummy->setIndex(12);
	pLeftArm_Dummy->setName("LeftArm_Dummy");
	pLeftArm_Dummy->setTransformTest(false);
	tree->insert( pLeftArm_Dummy, pLeftShoulder );

	PyramidObject *pLeftArm = new PyramidObject;
	pLeftArm->setIndex(13);
	pLeftArm->setName("LeftArm");
	pLeftArm->setTransformTest(false);
	tree->insert( pLeftArm, pLeftArm_Dummy );

	PyramidObject *pLeftArmRoll = new PyramidObject;
	pLeftArmRoll->setIndex(14);
	pLeftArmRoll->setName("LeftArmRoll");
	pLeftArmRoll->setTransformTest(false);
	tree->insert( pLeftArmRoll, pLeftArm );

	PyramidObject *pLeftForeArm = new PyramidObject;
	pLeftForeArm->setIndex(15);
	pLeftForeArm->setName("LeftForeArm");
	pLeftForeArm->setTransformTest(false);
	tree->insert( pLeftForeArm, pLeftArmRoll );

	PyramidObject *pLeftForeArmRoll = new PyramidObject;
	pLeftForeArmRoll->setIndex(16);
	pLeftForeArmRoll->setName("LeftForeArmRoll");
	pLeftForeArmRoll->setTransformTest(false);
	tree->insert( pLeftForeArmRoll, pLeftForeArm );

	PyramidObject *pLeftHand = new PyramidObject;
	pLeftHand->setIndex(17);
	pLeftHand->setName("LeftHand");
	pLeftHand->setTransformTest(false);
	tree->insert( pLeftHand, pLeftForeArmRoll );

	PyramidObject *pLeftThumb1 = new PyramidObject;
	pLeftThumb1->setIndex(18);
	pLeftThumb1->setName("LeftThumb1");
	pLeftThumb1->setTransformTest(false);
	tree->insert( pLeftThumb1, pLeftHand );

	PyramidObject *pLeftThumb2 = new PyramidObject;
	pLeftThumb2->setIndex(19);
	pLeftThumb2->setName("LeftThumb2");
	pLeftThumb2->setTransformTest(false);
	tree->insert( pLeftThumb2, pLeftThumb1 );

	PyramidObject *pLeftThumb3 = new PyramidObject;
	pLeftThumb3->setIndex(20);
	pLeftThumb3->setName("LeftThumb3");
	pLeftThumb3->setTransformTest(false);
	tree->insert( pLeftThumb3, pLeftThumb2 );

	PyramidObject *pLeftThumb_End = new PyramidObject;
	pLeftThumb_End->setIndex(21);
	pLeftThumb_End->setName("LeftThumb_End");
	pLeftThumb_End->setTransformTest(false);
	tree->insert( pLeftThumb_End, pLeftThumb3 );

	PyramidObject *pLeftIndex1 = new PyramidObject;
	pLeftIndex1->setIndex(22);
	pLeftIndex1->setName("LeftIndex1");
	pLeftIndex1->setTransformTest(false);
	tree->insert( pLeftIndex1, pLeftHand );

	PyramidObject *pLeftIndex2 = new PyramidObject;
	pLeftIndex2->setIndex(23);
	pLeftIndex2->setName("LeftIndex2");
	pLeftIndex2->setTransformTest(false);
	tree->insert( pLeftIndex2, pLeftIndex1 );

	PyramidObject *pLeftIndex3 = new PyramidObject;
	pLeftIndex3->setIndex(24);
	pLeftIndex3->setName("LeftIndex3");
	pLeftIndex3->setTransformTest(false);
	tree->insert( pLeftIndex3, pLeftIndex2 );

	PyramidObject *pLeftIndex_End = new PyramidObject;
	pLeftIndex_End->setIndex(25);
	pLeftIndex_End->setName("LeftIndex_End");
	pLeftIndex_End->setTransformTest(false);
	tree->insert( pLeftIndex_End, pLeftIndex3 );

	PyramidObject *pLeftMiddle1 = new PyramidObject;
	pLeftMiddle1->setIndex(26);
	pLeftMiddle1->setName("LeftMiddle1");
	pLeftMiddle1->setTransformTest(false);
	tree->insert( pLeftMiddle1, pLeftHand );

	PyramidObject *pLeftMiddle2 = new PyramidObject;
	pLeftMiddle2->setIndex(27);
	pLeftMiddle2->setName("LeftMiddle2");
	pLeftMiddle2->setTransformTest(false);
	tree->insert( pLeftMiddle2, pLeftMiddle1 );

	PyramidObject *pLeftMiddle3 = new PyramidObject;
	pLeftMiddle3->setIndex(28);
	pLeftMiddle3->setName("LeftMiddle3");
	pLeftMiddle3->setTransformTest(false);
	tree->insert( pLeftMiddle3, pLeftMiddle2 );

	PyramidObject *pLeftMiddle_End = new PyramidObject;
	pLeftMiddle_End->setIndex(29);
	pLeftMiddle_End->setName("LeftMiddle_End");
	pLeftMiddle_End->setTransformTest(false);
	tree->insert( pLeftMiddle_End, pLeftMiddle3 );

	PyramidObject *pLeftRing1 = new PyramidObject;
	pLeftRing1->setIndex(30);
	pLeftRing1->setName("LeftRing1");
	pLeftRing1->setTransformTest(false);
	tree->insert( pLeftRing1, pLeftHand );

	PyramidObject *pLeftRing2 = new PyramidObject;
	pLeftRing2->setIndex(31);
	pLeftRing2->setName("LeftRing2");
	pLeftRing2->setTransformTest(false);
	tree->insert( pLeftRing2, pLeftRing1 );

	PyramidObject *pLeftRing3 = new PyramidObject;
	pLeftRing3->setIndex(32);
	pLeftRing3->setName("LeftRing3");
	pLeftRing3->setTransformTest(false);
	tree->insert( pLeftRing3, pLeftRing2 );

	PyramidObject *pLeftRing_End = new PyramidObject;
	pLeftRing_End->setIndex(33);
	pLeftRing_End->setName("LeftRing_End");
	pLeftRing_End->setTransformTest(false);
	tree->insert( pLeftRing_End, pLeftRing3 );

	PyramidObject *pLeftPinky1 = new PyramidObject;
	pLeftPinky1->setIndex(34);
	pLeftPinky1->setName("LeftPinky1");
	pLeftPinky1->setTransformTest(false);
	tree->insert( pLeftPinky1, pLeftHand );

	PyramidObject *pLeftPinky2 = new PyramidObject;
	pLeftPinky2->setIndex(35);
	pLeftPinky2->setName("LeftPinky2");
	pLeftPinky2->setTransformTest(false);
	tree->insert( pLeftPinky2, pLeftPinky1 );

	PyramidObject *pLeftPinky3 = new PyramidObject;
	pLeftPinky3->setIndex(36);
	pLeftPinky3->setName("LeftPinky3");
	pLeftPinky3->setTransformTest(false);
	tree->insert( pLeftPinky3, pLeftPinky2 );

	PyramidObject *pLeftPinky_End = new PyramidObject;
	pLeftPinky_End->setIndex(37);
	pLeftPinky_End->setName("LeftPinky_End");
	pLeftPinky_End->setTransformTest(false);
	tree->insert( pLeftPinky_End, pLeftPinky3 );

	PyramidObject *pRightShoulder_Dummy = new PyramidObject;
	pRightShoulder_Dummy->setIndex(38);
	pRightShoulder_Dummy->setName("RightShoulder_Dummy");
	pRightShoulder_Dummy->setTransformTest(false);
	tree->insert( pRightShoulder_Dummy, pSpine2 );

	PyramidObject *pRightShoulder = new PyramidObject;
	pRightShoulder->setIndex(39);
	pRightShoulder->setName("RightShoulder");
	pRightShoulder->setTransformTest(false);
	tree->insert( pRightShoulder, pRightShoulder_Dummy );

	PyramidObject *pRightArm_Dummy = new PyramidObject;
	pRightArm_Dummy->setIndex(40);
	pRightArm_Dummy->setName("RightArm_Dummy");
	pRightArm_Dummy->setTransformTest(false);
	tree->insert( pRightArm_Dummy, pRightShoulder );

	PyramidObject *pRightArm = new PyramidObject;
	pRightArm->setIndex(41);
	pRightArm->setName("RightArm");
	pRightArm->setTransformTest(false);
	tree->insert( pRightArm, pRightArm_Dummy );

	PyramidObject *pRightArmRoll = new PyramidObject;
	pRightArmRoll->setIndex(42);
	pRightArmRoll->setName("RightArmRoll");
	pRightArmRoll->setTransformTest(false);
	tree->insert( pRightArmRoll, pRightArm );

	PyramidObject *pRightForeArm = new PyramidObject;
	pRightForeArm->setIndex(43);
	pRightForeArm->setName("RightForeArm");
	pRightForeArm->setTransformTest(false);
	tree->insert( pRightForeArm, pRightArmRoll );

	PyramidObject *pRightForeArmRoll = new PyramidObject;
	pRightForeArmRoll->setIndex(44);
	pRightForeArmRoll->setName("RightForeArmRoll");
	pRightForeArmRoll->setTransformTest(false);
	tree->insert( pRightForeArmRoll, pRightForeArm );

	PyramidObject *pRightHand = new PyramidObject;
	pRightHand->setIndex(45);
	pRightHand->setName("RightHand");
	pRightHand->setTransformTest(false);
	tree->insert( pRightHand, pRightForeArmRoll );

	PyramidObject *pRightThumb1 = new PyramidObject;
	pRightThumb1->setIndex(46);
	pRightThumb1->setName("RightThumb1");
	pRightThumb1->setTransformTest(false);
	tree->insert( pRightThumb1, pRightHand );

	PyramidObject *pRightThumb2 = new PyramidObject;
	pRightThumb2->setIndex(47);
	pRightThumb2->setName("RightThumb2");
	pRightThumb2->setTransformTest(false);
	tree->insert( pRightThumb2, pRightThumb1 );

	PyramidObject *pRightThumb3 = new PyramidObject;
	pRightThumb3->setIndex(48);
	pRightThumb3->setName("RightThumb3");
	pRightThumb3->setTransformTest(false);
	tree->insert( pRightThumb3, pRightThumb2 );

	PyramidObject *pRightThumb_End = new PyramidObject;
	pRightThumb_End->setIndex(49);
	pRightThumb_End->setName("RightThumb_End");
	pRightThumb_End->setTransformTest(false);
	tree->insert( pRightThumb_End, pRightThumb3 );

	PyramidObject *pRightIndex1 = new PyramidObject;
	pRightIndex1->setIndex(50);
	pRightIndex1->setName("RightIndex1");
	pRightIndex1->setTransformTest(false);
	tree->insert( pRightIndex1, pRightHand );

	PyramidObject *pRightIndex2 = new PyramidObject;
	pRightIndex2->setIndex(51);
	pRightIndex2->setName("RightIndex2");
	pRightIndex2->setTransformTest(false);
	tree->insert( pRightIndex2, pRightIndex1 );

	PyramidObject *pRightIndex3 = new PyramidObject;
	pRightIndex3->setIndex(52);
	pRightIndex3->setName("RightIndex3");
	pRightIndex3->setTransformTest(false);
	tree->insert( pRightIndex3, pRightIndex2 );

	PyramidObject *pRightIndex_End = new PyramidObject;
	pRightIndex_End->setIndex(53);
	pRightIndex_End->setName("RightIndex_End");
	pRightIndex_End->setTransformTest(false);
	tree->insert( pRightIndex_End, pRightIndex3 );

	PyramidObject *pRightMiddle1 = new PyramidObject;
	pRightMiddle1->setIndex(54);
	pRightMiddle1->setName("RightMiddle1");
	pRightMiddle1->setTransformTest(false);
	tree->insert( pRightMiddle1, pRightHand );

	PyramidObject *pRightMiddle2 = new PyramidObject;
	pRightMiddle2->setIndex(55);
	pRightMiddle2->setName("RightMiddle2");
	pRightMiddle2->setTransformTest(false);
	tree->insert( pRightMiddle2, pRightMiddle1 );

	PyramidObject *pRightMiddle3 = new PyramidObject;
	pRightMiddle3->setIndex(56);
	pRightMiddle3->setName("RightMiddle3");
	pRightMiddle3->setTransformTest(false);
	tree->insert( pRightMiddle3, pRightMiddle2 );

	PyramidObject *pRightMiddle_End = new PyramidObject;
	pRightMiddle_End->setIndex(57);
	pRightMiddle_End->setName("RightMiddle_End");
	pRightMiddle_End->setTransformTest(false);
	tree->insert( pRightMiddle_End, pRightMiddle3 );

	PyramidObject *pRightRing1 = new PyramidObject;
	pRightRing1->setIndex(58);
	pRightRing1->setName("RightRing1");
	pRightRing1->setTransformTest(false);
	tree->insert( pRightRing1, pRightHand );

	PyramidObject *pRightRing2 = new PyramidObject;
	pRightRing2->setIndex(59);
	pRightRing2->setName("RightRing2");
	pRightRing2->setTransformTest(false);
	tree->insert( pRightRing2, pRightRing1 );

	PyramidObject *pRightRing3 = new PyramidObject;
	pRightRing3->setIndex(60);
	pRightRing3->setName("RightRing3");
	pRightRing3->setTransformTest(false);
	tree->insert( pRightRing3, pRightRing2 );

	PyramidObject *pRightRing_End = new PyramidObject;
	pRightRing_End->setIndex(61);
	pRightRing_End->setName("RightRing_End");
	pRightRing_End->setTransformTest(false);
	tree->insert( pRightRing_End, pRightRing3 );

	PyramidObject *pRightPinky1 = new PyramidObject;
	pRightPinky1->setIndex(62);
	pRightPinky1->setName("RightPinky1");
	pRightPinky1->setTransformTest(false);
	tree->insert( pRightPinky1, pRightHand );

	PyramidObject *pRightPinky2 = new PyramidObject;
	pRightPinky2->setIndex(63);
	pRightPinky2->setName("RightPinky2");
	pRightPinky2->setTransformTest(false);
	tree->insert( pRightPinky2, pRightPinky1 );

	PyramidObject *pRightPinky3 = new PyramidObject;
	pRightPinky3->setIndex(64);
	pRightPinky3->setName("RightPinky3");
	pRightPinky3->setTransformTest(false);
	tree->insert( pRightPinky3, pRightPinky2 );

	PyramidObject *pRightPinky_End = new PyramidObject;
	pRightPinky_End->setIndex(65);
	pRightPinky_End->setName("RightPinky_End");
	pRightPinky_End->setTransformTest(false);
	tree->insert( pRightPinky_End, pRightPinky3 );

	PyramidObject *pLeftHips_Dummy = new PyramidObject;
	pLeftHips_Dummy->setIndex(66);
	pLeftHips_Dummy->setName("LeftHips_Dummy");
	pLeftHips_Dummy->setTransformTest(false);
	tree->insert( pLeftHips_Dummy, pHips );

	PyramidObject *pLeftUpLeg = new PyramidObject;
	pLeftUpLeg->setIndex(67);
	pLeftUpLeg->setName("LeftUpLeg");
	pLeftUpLeg->setTransformTest(false);
	tree->insert( pLeftUpLeg, pLeftHips_Dummy );

	PyramidObject *pLeftUpLegRoll = new PyramidObject;
	pLeftUpLegRoll->setIndex(68);
	pLeftUpLegRoll->setName("LeftUpLegRoll");
	pLeftUpLegRoll->setTransformTest(false);
	tree->insert( pLeftUpLegRoll, pLeftUpLeg );

	PyramidObject *pLeftLeg = new PyramidObject;
	pLeftLeg->setIndex(69);
	pLeftLeg->setName("LeftLeg");
	pLeftLeg->setTransformTest(false);
	tree->insert( pLeftLeg, pLeftUpLegRoll );

	PyramidObject *pLeftLegRoll = new PyramidObject;
	pLeftLegRoll->setIndex(70);
	pLeftLegRoll->setName("LeftLegRoll");
	pLeftLegRoll->setTransformTest(false);
	tree->insert( pLeftLegRoll, pLeftLeg );

	PyramidObject *pLeftFoot = new PyramidObject;
	pLeftFoot->setIndex(71);
	pLeftFoot->setName("LeftFoot");
	pLeftFoot->setTransformTest(false);
	tree->insert( pLeftFoot, pLeftLegRoll );

	PyramidObject *pLeftToes = new PyramidObject;
	pLeftToes->setIndex(72);
	pLeftToes->setName("LeftToes");
	pLeftToes->setTransformTest(false);
	tree->insert( pLeftToes, pLeftFoot );

	PyramidObject *pLeftToes_End = new PyramidObject;
	pLeftToes_End->setIndex(73);
	pLeftToes_End->setName("LeftToes_End");
	pLeftToes_End->setTransformTest(false);
	tree->insert( pLeftToes_End, pLeftToes );

	PyramidObject *pRightHips_Dummy = new PyramidObject;
	pRightHips_Dummy->setIndex(74);
	pRightHips_Dummy->setName("RightHips_Dummy");
	pRightHips_Dummy->setTransformTest(false);
	tree->insert( pRightHips_Dummy, pHips );

	PyramidObject *pRightUpLeg = new PyramidObject;
	pRightUpLeg->setIndex(75);
	pRightUpLeg->setName("RightUpLeg");
	pRightUpLeg->setTransformTest(false);
	tree->insert( pRightUpLeg, pRightHips_Dummy );

	PyramidObject *pRightUpLegRoll = new PyramidObject;
	pRightUpLegRoll->setIndex(76);
	pRightUpLegRoll->setName("RightUpLegRoll");
	pRightUpLegRoll->setTransformTest(false);
	tree->insert( pRightUpLegRoll, pRightUpLeg );

	PyramidObject *pRightLeg = new PyramidObject;
	pRightLeg->setIndex(77);
	pRightLeg->setName("RightLeg");
	pRightLeg->setTransformTest(false);
	tree->insert( pRightLeg, pRightUpLegRoll );

	PyramidObject *pRightLegRoll = new PyramidObject;
	pRightLegRoll->setIndex(78);
	pRightLegRoll->setName("RightLegRoll");
	pRightLegRoll->setTransformTest(false);
	tree->insert( pRightLegRoll, pRightLeg );

	PyramidObject *pRightFoot = new PyramidObject;
	pRightFoot->setIndex(79);
	pRightFoot->setName("RightFoot");
	pRightFoot->setTransformTest(false);
	tree->insert( pRightFoot, pRightLegRoll );

	PyramidObject *pRightToes = new PyramidObject;
	pRightToes->setIndex(80);
	pRightToes->setName("RightToes");
	pRightToes->setTransformTest(false);
	tree->insert( pRightToes, pRightFoot );

	PyramidObject *pRightToes_End = new PyramidObject;
	pRightToes_End->setIndex(81);
	pRightToes_End->setName("RightToes_End");
	pRightToes_End->setTransformTest(false);
	tree->insert( pRightToes_End, pRightToes );



   tree->dumpTree();



}

void SetAnimationPose()
{
    Matrix temp = helper();
	
printf("Hello");	
	// REMEMBER:
   //    that the bone pose are WORLD not GLOBAL
   //    Animations are relative!
/*

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
		p1->Local = bone_0.inv() * bone_1;
*/
}



void SetAnimationData()
{

   // --------  Result Frame  ----------------------

   pHead = new Frame_Bucket();
	pHead->prevBucket = 0;
	pHead->nextBucket = 0;
	pHead->KeyTime = Time(TIME_ZERO);
	pHead->pBone = new Bone[NUM_BONES];

   // --------  Frame 0  ----------------------------

   Frame_Bucket *pTmp = new Frame_Bucket();
	pTmp->prevBucket = pHead;
	pTmp->nextBucket = 0;
	pTmp->KeyTime = 0 * Time(TIME_NTSC_30_FRAME);
	pTmp->pBone = new Bone[NUM_BONES];

	pHead->nextBucket = pTmp;

   // ------- Key Time: 0  ms: 0 ------------------ 


      //     Node Name: Humanoid:MaxToFilmbox_Root
      pTmp->pBone[0].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Reference
      pTmp->pBone[1].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Hips
      pTmp->pBone[2].T = Vect( -280.172638f, 1288.917847f, 526.212402f );
      pTmp->pBone[2].Q = Quat( ROT_XYZ, 0.401148f, 0.069213f, -0.030462f );
      pTmp->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine_Dummy
      pTmp->pBone[3].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Spine
      pTmp->pBone[4].T = Vect( 73.400002f, 0.000001f, 0.000000f );
      pTmp->pBone[4].Q = Quat( ROT_XYZ, -0.031461f, 0.001422f, 0.030284f );
      pTmp->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine1
      pTmp->pBone[5].T = Vect( 70.001335f, -0.000002f, -0.000000f );
      pTmp->pBone[5].Q = Quat( ROT_XYZ, -0.060012f, 0.005307f, 0.060495f );
      pTmp->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine2
      pTmp->pBone[6].T = Vect( 71.400032f, -0.000000f, 0.000000f );
      pTmp->pBone[6].Q = Quat( ROT_XYZ, -0.060005f, 0.005307f, 0.060495f );
      pTmp->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Neck
      pTmp->pBone[7].T = Vect( 121.576225f, -0.000001f, -0.000000f );
      pTmp->pBone[7].Q = Quat( ROT_XYZ, -0.083518f, 0.064311f, 0.228354f );
      pTmp->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head
      pTmp->pBone[8].T = Vect( 67.855774f, 0.000039f, -0.000000f );
      pTmp->pBone[8].Q = Quat( ROT_XYZ, -0.119745f, -0.014206f, -0.072717f );
      pTmp->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head_End
      pTmp->pBone[9].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder_Dummy
      pTmp->pBone[10].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder
      pTmp->pBone[11].T = Vect( -36.845097f, -0.000012f, -0.000005f );
      pTmp->pBone[11].Q = Quat( ROT_XYZ, -0.086833f, -0.017928f, -0.028073f );
      pTmp->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftArm_Dummy
      pTmp->pBone[12].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftArm
      pTmp->pBone[13].T = Vect( -20.843035f, -1.709348f, 11.313786f );
      pTmp->pBone[13].Q = Quat( ROT_XYZ, -0.141143f, 0.317536f, 2.825809f );
      pTmp->pBone[13].S = Vect( 0.999999f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftArmRoll
      pTmp->pBone[14].T = Vect( 78.950714f, 0.000019f, 0.000006f );
      pTmp->pBone[14].Q = Quat( ROT_XYZ, 0.113023f, 0.000000f, 0.000000f );
      pTmp->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftForeArm
      pTmp->pBone[15].T = Vect( 65.979294f, 0.000019f, -0.000010f );
      pTmp->pBone[15].Q = Quat( ROT_XYZ, 0.065537f, 0.030556f, -2.037498f );
      pTmp->pBone[15].S = Vect( 1.000002f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftForeArmRoll
      pTmp->pBone[16].T = Vect( 101.404221f, 0.000009f, 0.000010f );
      pTmp->pBone[16].Q = Quat( ROT_XYZ, 0.100070f, 0.000000f, 0.000000f );
      pTmp->pBone[16].S = Vect( 0.999999f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftHand
      pTmp->pBone[17].T = Vect( 71.692039f, 0.000010f, 0.000004f );
      pTmp->pBone[17].Q = Quat( ROT_XYZ, -0.030181f, 0.374359f, -0.159030f );
      pTmp->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb1
      pTmp->pBone[18].T = Vect( 29.257690f, -22.640423f, -5.069802f );
      pTmp->pBone[18].Q = Quat( ROT_XYZ, 0.709381f, 0.537656f, -0.914867f );
      pTmp->pBone[18].S = Vect( 0.999999f, 1.000001f, 1.000003f );

      //     Node Name: Humanoid:LeftThumb2
      pTmp->pBone[19].T = Vect( 22.746157f, -0.353276f, -0.113011f );
      pTmp->pBone[19].Q = Quat( ROT_XYZ, 0.081784f, 0.342417f, 0.683623f );
      pTmp->pBone[19].S = Vect( 0.999997f, 1.000002f, 1.000001f );

      //     Node Name: Humanoid:LeftThumb3
      pTmp->pBone[20].T = Vect( 17.496328f, 0.116578f, 0.089712f );
      pTmp->pBone[20].Q = Quat( ROT_XYZ, 0.027024f, 0.198537f, 0.096617f );
      pTmp->pBone[20].S = Vect( 0.999999f, 1.000001f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb_End
      pTmp->pBone[21].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftIndex1
      pTmp->pBone[22].T = Vect( 58.921104f, -18.573286f, 1.447069f );
      pTmp->pBone[22].Q = Quat( ROT_XYZ, 1.586099f, 0.426615f, 0.025352f );
      pTmp->pBone[22].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftIndex2
      pTmp->pBone[23].T = Vect( 27.947330f, -0.000028f, 0.000011f );
      pTmp->pBone[23].Q = Quat( ROT_XYZ, -0.015023f, 0.000552f, -0.279687f );
      pTmp->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex3
      pTmp->pBone[24].T = Vect( 17.556934f, -0.000062f, -0.000005f );
      pTmp->pBone[24].Q = Quat( ROT_XYZ, -0.015553f, -0.011463f, -0.281321f );
      pTmp->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex_End
      pTmp->pBone[25].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftMiddle1
      pTmp->pBone[26].T = Vect( 57.844334f, -4.515547f, 3.569310f );
      pTmp->pBone[26].Q = Quat( ROT_XYZ, 1.525321f, 0.667963f, 0.018870f );
      pTmp->pBone[26].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftMiddle2
      pTmp->pBone[27].T = Vect( 32.362274f, -0.000006f, -0.000017f );
      pTmp->pBone[27].Q = Quat( ROT_XYZ, -0.024592f, 0.021554f, -0.488195f );
      pTmp->pBone[27].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle3
      pTmp->pBone[28].T = Vect( 18.401133f, 0.000069f, 0.000003f );
      pTmp->pBone[28].Q = Quat( ROT_XYZ, -0.024587f, 0.021555f, -0.488208f );
      pTmp->pBone[28].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle_End
      pTmp->pBone[29].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftRing1
      pTmp->pBone[30].T = Vect( 57.439991f, 9.168867f, 2.940117f );
      pTmp->pBone[30].Q = Quat( ROT_XYZ, 1.483405f, 0.852180f, 0.008604f );
      pTmp->pBone[30].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftRing2
      pTmp->pBone[31].T = Vect( 30.068848f, 0.000063f, 0.000002f );
      pTmp->pBone[31].Q = Quat( ROT_XYZ, -0.041307f, 0.045509f, -0.696692f );
      pTmp->pBone[31].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing3
      pTmp->pBone[32].T = Vect( 15.270657f, 0.000024f, 0.000004f );
      pTmp->pBone[32].Q = Quat( ROT_XYZ, -0.041310f, 0.045508f, -0.696687f );
      pTmp->pBone[32].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing_End
      pTmp->pBone[33].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftPinky1
      pTmp->pBone[34].T = Vect( 56.621067f, 20.249598f, -1.450183f );
      pTmp->pBone[34].Q = Quat( ROT_XYZ, 1.406783f, 0.858990f, 0.038222f );
      pTmp->pBone[34].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftPinky2
      pTmp->pBone[35].T = Vect( 19.894529f, 0.000152f, -0.000017f );
      pTmp->pBone[35].Q = Quat( ROT_XYZ, -0.070957f, 0.120430f, -0.831169f );
      pTmp->pBone[35].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky3
      pTmp->pBone[36].T = Vect( 12.904247f, 0.000005f, 0.000009f );
      pTmp->pBone[36].Q = Quat( ROT_XYZ, -0.070955f, 0.120425f, -0.831149f );
      pTmp->pBone[36].S = Vect( 1.000002f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky_End
      pTmp->pBone[37].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder_Dummy
      pTmp->pBone[38].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder
      pTmp->pBone[39].T = Vect( 36.845016f, 0.000015f, 0.000005f );
      pTmp->pBone[39].Q = Quat( ROT_XYZ, -0.062317f, -0.007251f, -0.047899f );
      pTmp->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArm_Dummy
      pTmp->pBone[40].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightArm
      pTmp->pBone[41].T = Vect( 20.843040f, 1.709348f, -11.313787f );
      pTmp->pBone[41].Q = Quat( ROT_XYZ, 0.317549f, 0.075090f, -2.764645f );
      pTmp->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArmRoll
      pTmp->pBone[42].T = Vect( -78.950615f, 0.000005f, 0.000027f );
      pTmp->pBone[42].Q = Quat( ROT_XYZ, 0.886762f, 0.000001f, 0.000000f );
      pTmp->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightForeArm
      pTmp->pBone[43].T = Vect( -65.979179f, -0.000020f, 0.000040f );
      pTmp->pBone[43].Q = Quat( ROT_XYZ, 0.108827f, 0.019707f, -1.300434f );
      pTmp->pBone[43].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightForeArmRoll
      pTmp->pBone[44].T = Vect( -101.404114f, -0.000007f, 0.000018f );
      pTmp->pBone[44].Q = Quat( ROT_XYZ, 0.152709f, 0.000000f, -0.000000f );
      pTmp->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightHand
      pTmp->pBone[45].T = Vect( -71.691925f, -0.000011f, 0.000047f );
      pTmp->pBone[45].Q = Quat( ROT_XYZ, -0.020400f, -0.458479f, 0.087373f );
      pTmp->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb1
      pTmp->pBone[46].T = Vect( -29.257633f, 22.640385f, 5.069794f );
      pTmp->pBone[46].Q = Quat( ROT_XYZ, 0.709378f, 0.537650f, -0.914868f );
      pTmp->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb2
      pTmp->pBone[47].T = Vect( -22.746113f, 0.353250f, 0.112989f );
      pTmp->pBone[47].Q = Quat( ROT_XYZ, 0.081785f, 0.342420f, 0.683621f );
      pTmp->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb3
      pTmp->pBone[48].T = Vect( -17.496260f, -0.116582f, -0.089711f );
      pTmp->pBone[48].Q = Quat( ROT_XYZ, 0.027026f, 0.198541f, 0.096615f );
      pTmp->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb_End
      pTmp->pBone[49].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightIndex1
      pTmp->pBone[50].T = Vect( -58.920994f, 18.573256f, -1.447088f );
      pTmp->pBone[50].Q = Quat( ROT_XYZ, 1.586071f, 0.426614f, 0.025344f );
      pTmp->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex2
      pTmp->pBone[51].T = Vect( -27.947296f, -0.000004f, -0.000010f );
      pTmp->pBone[51].Q = Quat( ROT_XYZ, -0.015047f, 0.000544f, -0.279685f );
      pTmp->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex3
      pTmp->pBone[52].T = Vect( -17.556936f, 0.000007f, 0.000005f );
      pTmp->pBone[52].Q = Quat( ROT_XYZ, -0.015576f, -0.011470f, -0.281319f );
      pTmp->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex_End
      pTmp->pBone[53].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightMiddle1
      pTmp->pBone[54].T = Vect( -57.844231f, 4.515540f, -3.569327f );
      pTmp->pBone[54].Q = Quat( ROT_XYZ, 1.525267f, 0.667962f, 0.018847f );
      pTmp->pBone[54].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle2
      pTmp->pBone[55].T = Vect( -32.362286f, -0.000032f, 0.000014f );
      pTmp->pBone[55].Q = Quat( ROT_XYZ, -0.024632f, 0.021536f, -0.488193f );
      pTmp->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle3
      pTmp->pBone[56].T = Vect( -18.401140f, -0.000102f, -0.000003f );
      pTmp->pBone[56].Q = Quat( ROT_XYZ, -0.024626f, 0.021536f, -0.488206f );
      pTmp->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle_End
      pTmp->pBone[57].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightRing1
      pTmp->pBone[58].T = Vect( -57.439896f, -9.168852f, -2.940132f );
      pTmp->pBone[58].Q = Quat( ROT_XYZ, 1.483317f, 0.852179f, 0.008559f );
      pTmp->pBone[58].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightRing2
      pTmp->pBone[59].T = Vect( -30.068869f, -0.000103f, -0.000006f );
      pTmp->pBone[59].Q = Quat( ROT_XYZ, -0.041361f, 0.045479f, -0.696690f );
      pTmp->pBone[59].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing3
      pTmp->pBone[60].T = Vect( -15.270673f, 0.000013f, -0.000004f );
      pTmp->pBone[60].Q = Quat( ROT_XYZ, -0.041363f, 0.045478f, -0.696685f );
      pTmp->pBone[60].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing_End
      pTmp->pBone[61].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightPinky1
      pTmp->pBone[62].T = Vect( -56.620979f, -20.249563f, 1.450169f );
      pTmp->pBone[62].Q = Quat( ROT_XYZ, 1.406680f, 0.858990f, 0.038173f );
      pTmp->pBone[62].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightPinky2
      pTmp->pBone[63].T = Vect( -19.894527f, -0.000120f, 0.000016f );
      pTmp->pBone[63].Q = Quat( ROT_XYZ, -0.071022f, 0.120399f, -0.831170f );
      pTmp->pBone[63].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky3
      pTmp->pBone[64].T = Vect( -12.904246f, -0.000024f, -0.000012f );
      pTmp->pBone[64].Q = Quat( ROT_XYZ, -0.071021f, 0.120393f, -0.831149f );
      pTmp->pBone[64].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky_End
      pTmp->pBone[65].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftHips_Dummy
      pTmp->pBone[66].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftUpLeg
      pTmp->pBone[67].T = Vect( 0.000000f, 0.000000f, 29.999998f );
      pTmp->pBone[67].Q = Quat( ROT_XYZ, -0.050134f, -0.055586f, -0.099378f );
      pTmp->pBone[67].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftUpLegRoll
      pTmp->pBone[68].T = Vect( 112.510529f, 0.000000f, 0.000020f );
      pTmp->pBone[68].Q = Quat( ROT_XYZ, -0.030479f, -0.000000f, -0.000000f );
      pTmp->pBone[68].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLeg
      pTmp->pBone[69].T = Vect( 129.020859f, -0.000000f, 0.000070f );
      pTmp->pBone[69].Q = Quat( ROT_XYZ, 0.061168f, -0.006313f, 0.545807f );
      pTmp->pBone[69].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLegRoll
      pTmp->pBone[70].T = Vect( 183.400421f, -0.000001f, -0.000005f );
      pTmp->pBone[70].Q = Quat( ROT_XYZ, 0.090728f, 0.000000f, 0.000000f );
      pTmp->pBone[70].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftFoot
      pTmp->pBone[71].T = Vect( 71.066254f, 0.000009f, 0.000012f );
      pTmp->pBone[71].Q = Quat( ROT_XYZ, -0.050824f, 0.007916f, -1.238458f );
      pTmp->pBone[71].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes
      pTmp->pBone[72].T = Vect( 64.739685f, 0.000002f, -0.000000f );
      pTmp->pBone[72].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, -0.619500f );
      pTmp->pBone[72].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes_End
      pTmp->pBone[73].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightHips_Dummy
      pTmp->pBone[74].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightUpLeg
      pTmp->pBone[75].T = Vect( -0.000000f, -0.000000f, -29.999926f );
      pTmp->pBone[75].Q = Quat( ROT_XYZ, -0.047229f, 0.278622f, -1.509598f );
      pTmp->pBone[75].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightUpLegRoll
      pTmp->pBone[76].T = Vect( -112.510269f, -0.000004f, -0.000017f );
      pTmp->pBone[76].Q = Quat( ROT_XYZ, 0.028273f, -0.000000f, 0.000000f );
      pTmp->pBone[76].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLeg
      pTmp->pBone[77].T = Vect( -129.020554f, 0.000002f, -0.000071f );
      pTmp->pBone[77].Q = Quat( ROT_XYZ, -0.025544f, 0.002375f, 2.002476f );
      pTmp->pBone[77].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLegRoll
      pTmp->pBone[78].T = Vect( -183.399948f, -0.000002f, 0.000005f );
      pTmp->pBone[78].Q = Quat( ROT_XYZ, -0.040242f, -0.000000f, 0.000000f );
      pTmp->pBone[78].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightFoot
      pTmp->pBone[79].T = Vect( -71.066093f, -0.000015f, -0.000011f );
      pTmp->pBone[79].Q = Quat( ROT_XYZ, -0.040273f, 0.003243f, -1.226986f );
      pTmp->pBone[79].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes
      pTmp->pBone[80].T = Vect( -64.739525f, 0.000005f, 0.000000f );
      pTmp->pBone[80].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, -0.619500f );
      pTmp->pBone[80].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes_End
      pTmp->pBone[81].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].S = Vect( 1.0f, 1.0f, 1.0f );

   // --------  Frame 10  -----------------------------
   
   Frame_Bucket *pTmp2 = new Frame_Bucket();
	pTmp2->prevBucket = pTmp;
	pTmp2->nextBucket = 0;
	pTmp2->KeyTime = 10 * Time(TIME_NTSC_30_FRAME);
	pTmp2->pBone = new Bone[NUM_BONES];

	pTmp->nextBucket = pTmp2;

   // ------- Key Time: 10  ms: 333 ------------------ 


      //     Node Name: Humanoid:MaxToFilmbox_Root
      pTmp->pBone[0].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Reference
      pTmp->pBone[1].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Hips
      pTmp->pBone[2].T = Vect( -256.619812f, 441.826447f, 501.189575f );
      pTmp->pBone[2].Q = Quat( ROT_XYZ, 0.364318f, 0.149111f, -0.191151f );
      pTmp->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine_Dummy
      pTmp->pBone[3].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Spine
      pTmp->pBone[4].T = Vect( 73.400002f, 0.000001f, 0.000000f );
      pTmp->pBone[4].Q = Quat( ROT_XYZ, 0.020757f, 0.042474f, 0.020015f );
      pTmp->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine1
      pTmp->pBone[5].T = Vect( 70.001335f, -0.000002f, -0.000000f );
      pTmp->pBone[5].Q = Quat( ROT_XYZ, 0.041746f, 0.060430f, 0.040666f );
      pTmp->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine2
      pTmp->pBone[6].T = Vect( 71.400032f, -0.000000f, 0.000000f );
      pTmp->pBone[6].Q = Quat( ROT_XYZ, 0.041753f, 0.060429f, 0.040667f );
      pTmp->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Neck
      pTmp->pBone[7].T = Vect( 121.576225f, -0.000001f, -0.000000f );
      pTmp->pBone[7].Q = Quat( ROT_XYZ, 0.013605f, -0.085976f, 0.088848f );
      pTmp->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head
      pTmp->pBone[8].T = Vect( 67.855774f, 0.000039f, -0.000000f );
      pTmp->pBone[8].Q = Quat( ROT_XYZ, 0.013175f, -0.082701f, -0.066379f );
      pTmp->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head_End
      pTmp->pBone[9].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder_Dummy
      pTmp->pBone[10].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder
      pTmp->pBone[11].T = Vect( -36.845097f, -0.000012f, -0.000005f );
      pTmp->pBone[11].Q = Quat( ROT_XYZ, -0.080324f, -0.002378f, -0.131281f );
      pTmp->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftArm_Dummy
      pTmp->pBone[12].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftArm
      pTmp->pBone[13].T = Vect( -20.843035f, -1.709348f, 11.313786f );
      pTmp->pBone[13].Q = Quat( ROT_XYZ, 0.235176f, 0.256876f, -2.792554f );
      pTmp->pBone[13].S = Vect( 0.999999f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftArmRoll
      pTmp->pBone[14].T = Vect( 78.950714f, 0.000008f, -0.000001f );
      pTmp->pBone[14].Q = Quat( ROT_XYZ, 0.628308f, 0.000000f, 0.000000f );
      pTmp->pBone[14].S = Vect( 1.000000f, 0.999999f, 1.000002f );

      //     Node Name: Humanoid:LeftForeArm
      pTmp->pBone[15].T = Vect( 65.979294f, 0.000019f, -0.000010f );
      pTmp->pBone[15].Q = Quat( ROT_XYZ, 0.135429f, 0.016311f, -1.134472f );
      pTmp->pBone[15].S = Vect( 1.000002f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftForeArmRoll
      pTmp->pBone[16].T = Vect( 101.404221f, 0.000009f, 0.000010f );
      pTmp->pBone[16].Q = Quat( ROT_XYZ, 0.191644f, 0.000000f, 0.000000f );
      pTmp->pBone[16].S = Vect( 0.999999f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftHand
      pTmp->pBone[17].T = Vect( 71.692039f, 0.000010f, 0.000004f );
      pTmp->pBone[17].Q = Quat( ROT_XYZ, -0.006825f, -0.137932f, 0.098730f );
      pTmp->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb1
      pTmp->pBone[18].T = Vect( 29.257690f, -22.640423f, -5.069802f );
      pTmp->pBone[18].Q = Quat( ROT_XYZ, 0.709381f, 0.537656f, -0.914867f );
      pTmp->pBone[18].S = Vect( 0.999999f, 1.000001f, 1.000003f );

      //     Node Name: Humanoid:LeftThumb2
      pTmp->pBone[19].T = Vect( 22.746157f, -0.353276f, -0.113011f );
      pTmp->pBone[19].Q = Quat( ROT_XYZ, 0.081784f, 0.342417f, 0.683623f );
      pTmp->pBone[19].S = Vect( 0.999997f, 1.000002f, 1.000001f );

      //     Node Name: Humanoid:LeftThumb3
      pTmp->pBone[20].T = Vect( 17.496328f, 0.116578f, 0.089712f );
      pTmp->pBone[20].Q = Quat( ROT_XYZ, 0.027024f, 0.198537f, 0.096617f );
      pTmp->pBone[20].S = Vect( 0.999999f, 1.000001f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb_End
      pTmp->pBone[21].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftIndex1
      pTmp->pBone[22].T = Vect( 58.921104f, -18.573286f, 1.447069f );
      pTmp->pBone[22].Q = Quat( ROT_XYZ, 1.586099f, 0.426615f, 0.025352f );
      pTmp->pBone[22].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftIndex2
      pTmp->pBone[23].T = Vect( 27.947330f, -0.000028f, 0.000011f );
      pTmp->pBone[23].Q = Quat( ROT_XYZ, -0.015023f, 0.000552f, -0.279687f );
      pTmp->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex3
      pTmp->pBone[24].T = Vect( 17.556934f, -0.000062f, -0.000005f );
      pTmp->pBone[24].Q = Quat( ROT_XYZ, -0.015553f, -0.011463f, -0.281321f );
      pTmp->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex_End
      pTmp->pBone[25].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftMiddle1
      pTmp->pBone[26].T = Vect( 57.844334f, -4.515547f, 3.569310f );
      pTmp->pBone[26].Q = Quat( ROT_XYZ, 1.525321f, 0.667963f, 0.018870f );
      pTmp->pBone[26].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftMiddle2
      pTmp->pBone[27].T = Vect( 32.362274f, -0.000006f, -0.000017f );
      pTmp->pBone[27].Q = Quat( ROT_XYZ, -0.024592f, 0.021554f, -0.488195f );
      pTmp->pBone[27].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle3
      pTmp->pBone[28].T = Vect( 18.401133f, 0.000069f, 0.000003f );
      pTmp->pBone[28].Q = Quat( ROT_XYZ, -0.024587f, 0.021555f, -0.488208f );
      pTmp->pBone[28].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle_End
      pTmp->pBone[29].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftRing1
      pTmp->pBone[30].T = Vect( 57.439991f, 9.168867f, 2.940117f );
      pTmp->pBone[30].Q = Quat( ROT_XYZ, 1.483405f, 0.852180f, 0.008604f );
      pTmp->pBone[30].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftRing2
      pTmp->pBone[31].T = Vect( 30.068848f, 0.000063f, 0.000002f );
      pTmp->pBone[31].Q = Quat( ROT_XYZ, -0.041307f, 0.045509f, -0.696692f );
      pTmp->pBone[31].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing3
      pTmp->pBone[32].T = Vect( 15.270657f, 0.000024f, 0.000004f );
      pTmp->pBone[32].Q = Quat( ROT_XYZ, -0.041310f, 0.045508f, -0.696687f );
      pTmp->pBone[32].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing_End
      pTmp->pBone[33].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftPinky1
      pTmp->pBone[34].T = Vect( 56.621067f, 20.249598f, -1.450183f );
      pTmp->pBone[34].Q = Quat( ROT_XYZ, 1.406783f, 0.858990f, 0.038222f );
      pTmp->pBone[34].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftPinky2
      pTmp->pBone[35].T = Vect( 19.894529f, 0.000152f, -0.000017f );
      pTmp->pBone[35].Q = Quat( ROT_XYZ, -0.070957f, 0.120430f, -0.831169f );
      pTmp->pBone[35].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky3
      pTmp->pBone[36].T = Vect( 12.904247f, 0.000005f, 0.000009f );
      pTmp->pBone[36].Q = Quat( ROT_XYZ, -0.070955f, 0.120425f, -0.831149f );
      pTmp->pBone[36].S = Vect( 1.000002f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky_End
      pTmp->pBone[37].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder_Dummy
      pTmp->pBone[38].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder
      pTmp->pBone[39].T = Vect( 36.845016f, 0.000015f, 0.000005f );
      pTmp->pBone[39].Q = Quat( ROT_XYZ, -0.038851f, 0.010303f, -0.110741f );
      pTmp->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArm_Dummy
      pTmp->pBone[40].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightArm
      pTmp->pBone[41].T = Vect( 20.843040f, 1.709348f, -11.313787f );
      pTmp->pBone[41].Q = Quat( ROT_XYZ, 0.129952f, 0.330781f, 2.608197f );
      pTmp->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArmRoll
      pTmp->pBone[42].T = Vect( -78.950615f, -0.000003f, 0.000018f );
      pTmp->pBone[42].Q = Quat( ROT_XYZ, 0.546464f, 0.000001f, 0.000000f );
      pTmp->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightForeArm
      pTmp->pBone[43].T = Vect( -65.979179f, -0.000020f, 0.000040f );
      pTmp->pBone[43].Q = Quat( ROT_XYZ, 0.194680f, 0.022063f, -1.522365f );
      pTmp->pBone[43].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightForeArmRoll
      pTmp->pBone[44].T = Vect( -101.404114f, -0.000004f, 0.000019f );
      pTmp->pBone[44].Q = Quat( ROT_XYZ, 0.283913f, 0.000000f, -0.000000f );
      pTmp->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightHand
      pTmp->pBone[45].T = Vect( -71.691925f, -0.000011f, 0.000047f );
      pTmp->pBone[45].Q = Quat( ROT_XYZ, -0.035990f, -0.407964f, 0.173566f );
      pTmp->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb1
      pTmp->pBone[46].T = Vect( -29.257633f, 22.640385f, 5.069794f );
      pTmp->pBone[46].Q = Quat( ROT_XYZ, 0.709378f, 0.537650f, -0.914868f );
      pTmp->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb2
      pTmp->pBone[47].T = Vect( -22.746113f, 0.353250f, 0.112989f );
      pTmp->pBone[47].Q = Quat( ROT_XYZ, 0.081785f, 0.342420f, 0.683621f );
      pTmp->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb3
      pTmp->pBone[48].T = Vect( -17.496260f, -0.116582f, -0.089711f );
      pTmp->pBone[48].Q = Quat( ROT_XYZ, 0.027026f, 0.198541f, 0.096615f );
      pTmp->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb_End
      pTmp->pBone[49].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightIndex1
      pTmp->pBone[50].T = Vect( -58.920994f, 18.573256f, -1.447088f );
      pTmp->pBone[50].Q = Quat( ROT_XYZ, 1.586071f, 0.426614f, 0.025344f );
      pTmp->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex2
      pTmp->pBone[51].T = Vect( -27.947296f, -0.000004f, -0.000010f );
      pTmp->pBone[51].Q = Quat( ROT_XYZ, -0.015047f, 0.000544f, -0.279685f );
      pTmp->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex3
      pTmp->pBone[52].T = Vect( -17.556936f, 0.000007f, 0.000005f );
      pTmp->pBone[52].Q = Quat( ROT_XYZ, -0.015576f, -0.011470f, -0.281319f );
      pTmp->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex_End
      pTmp->pBone[53].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightMiddle1
      pTmp->pBone[54].T = Vect( -57.844231f, 4.515540f, -3.569327f );
      pTmp->pBone[54].Q = Quat( ROT_XYZ, 1.525267f, 0.667962f, 0.018847f );
      pTmp->pBone[54].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle2
      pTmp->pBone[55].T = Vect( -32.362286f, -0.000032f, 0.000014f );
      pTmp->pBone[55].Q = Quat( ROT_XYZ, -0.024632f, 0.021536f, -0.488193f );
      pTmp->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle3
      pTmp->pBone[56].T = Vect( -18.401140f, -0.000102f, -0.000003f );
      pTmp->pBone[56].Q = Quat( ROT_XYZ, -0.024626f, 0.021536f, -0.488206f );
      pTmp->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle_End
      pTmp->pBone[57].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightRing1
      pTmp->pBone[58].T = Vect( -57.439896f, -9.168852f, -2.940132f );
      pTmp->pBone[58].Q = Quat( ROT_XYZ, 1.483317f, 0.852179f, 0.008559f );
      pTmp->pBone[58].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightRing2
      pTmp->pBone[59].T = Vect( -30.068869f, -0.000103f, -0.000006f );
      pTmp->pBone[59].Q = Quat( ROT_XYZ, -0.041361f, 0.045479f, -0.696690f );
      pTmp->pBone[59].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing3
      pTmp->pBone[60].T = Vect( -15.270673f, 0.000013f, -0.000004f );
      pTmp->pBone[60].Q = Quat( ROT_XYZ, -0.041363f, 0.045478f, -0.696685f );
      pTmp->pBone[60].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing_End
      pTmp->pBone[61].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightPinky1
      pTmp->pBone[62].T = Vect( -56.620979f, -20.249563f, 1.450169f );
      pTmp->pBone[62].Q = Quat( ROT_XYZ, 1.406680f, 0.858990f, 0.038173f );
      pTmp->pBone[62].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightPinky2
      pTmp->pBone[63].T = Vect( -19.894527f, -0.000120f, 0.000016f );
      pTmp->pBone[63].Q = Quat( ROT_XYZ, -0.071022f, 0.120399f, -0.831170f );
      pTmp->pBone[63].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky3
      pTmp->pBone[64].T = Vect( -12.904246f, -0.000024f, -0.000012f );
      pTmp->pBone[64].Q = Quat( ROT_XYZ, -0.071021f, 0.120393f, -0.831149f );
      pTmp->pBone[64].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky_End
      pTmp->pBone[65].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftHips_Dummy
      pTmp->pBone[66].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftUpLeg
      pTmp->pBone[67].T = Vect( 0.000000f, 0.000000f, 29.999998f );
      pTmp->pBone[67].Q = Quat( ROT_XYZ, -0.015828f, -0.264825f, -1.154203f );
      pTmp->pBone[67].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftUpLegRoll
      pTmp->pBone[68].T = Vect( 112.510529f, -0.000000f, 0.000020f );
      pTmp->pBone[68].Q = Quat( ROT_XYZ, -0.041067f, -0.000000f, -0.000000f );
      pTmp->pBone[68].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLeg
      pTmp->pBone[69].T = Vect( 129.020859f, -0.000000f, 0.000070f );
      pTmp->pBone[69].Q = Quat( ROT_XYZ, 0.066096f, -0.007045f, 2.419231f );
      pTmp->pBone[69].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLegRoll
      pTmp->pBone[70].T = Vect( 183.400421f, -0.000001f, -0.000005f );
      pTmp->pBone[70].Q = Quat( ROT_XYZ, 0.097820f, 0.000000f, 0.000000f );
      pTmp->pBone[70].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftFoot
      pTmp->pBone[71].T = Vect( 71.066254f, 0.000009f, 0.000012f );
      pTmp->pBone[71].Q = Quat( ROT_XYZ, 0.065816f, -0.053965f, -0.903218f );
      pTmp->pBone[71].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes
      pTmp->pBone[72].T = Vect( 64.739685f, 0.000002f, -0.000000f );
      pTmp->pBone[72].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, -0.619500f );
      pTmp->pBone[72].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes_End
      pTmp->pBone[73].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightHips_Dummy
      pTmp->pBone[74].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightUpLeg
      pTmp->pBone[75].T = Vect( -0.000000f, -0.000000f, -29.999926f );
      pTmp->pBone[75].Q = Quat( ROT_XYZ, 0.031907f, 0.203667f, -0.537901f );
      pTmp->pBone[75].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightUpLegRoll
      pTmp->pBone[76].T = Vect( -112.510269f, -0.000002f, -0.000016f );
      pTmp->pBone[76].Q = Quat( ROT_XYZ, -0.031790f, -0.000000f, 0.000000f );
      pTmp->pBone[76].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLeg
      pTmp->pBone[77].T = Vect( -129.020554f, 0.000002f, -0.000071f );
      pTmp->pBone[77].Q = Quat( ROT_XYZ, 0.078844f, -0.010243f, 0.829756f );
      pTmp->pBone[77].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLegRoll
      pTmp->pBone[78].T = Vect( -183.399948f, -0.000003f, 0.000007f );
      pTmp->pBone[78].Q = Quat( ROT_XYZ, 0.116728f, -0.000000f, 0.000000f );
      pTmp->pBone[78].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightFoot
      pTmp->pBone[79].T = Vect( -71.066093f, -0.000015f, -0.000011f );
      pTmp->pBone[79].Q = Quat( ROT_XYZ, 0.192552f, -0.099209f, -1.429342f );
      pTmp->pBone[79].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes
      pTmp->pBone[80].T = Vect( -64.739525f, 0.000005f, 0.000000f );
      pTmp->pBone[80].Q = Quat( ROT_XYZ, 0.029321f, -0.005328f, -0.715872f );
      pTmp->pBone[80].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes_End
      pTmp->pBone[81].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].S = Vect( 1.0f, 1.0f, 1.0f );



   

   // --------  Frame 70 ----------------------

   Frame_Bucket *pTmp3 = new Frame_Bucket();
	pTmp3->prevBucket = pTmp2;
	pTmp3->nextBucket = 0;
	pTmp3->KeyTime = 20 * Time(TIME_NTSC_30_FRAME);
	pTmp3->pBone = new Bone[NUM_BONES];

	pTmp2->nextBucket = pTmp3;

   
   // ------- Key Time: 20  ms: 666 ------------------ 

      //     Node Name: Humanoid:MaxToFilmbox_Root
      pTmp->pBone[0].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[0].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Reference
      pTmp->pBone[1].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[1].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Hips
      pTmp->pBone[2].T = Vect( -250.201721f, -424.964691f, 497.058563f );
      pTmp->pBone[2].Q = Quat( ROT_XYZ, 0.339490f, 0.034172f, -0.005714f );
      pTmp->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine_Dummy
      pTmp->pBone[3].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[3].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:Spine
      pTmp->pBone[4].T = Vect( 73.400002f, 0.000001f, 0.000000f );
      pTmp->pBone[4].Q = Quat( ROT_XYZ, 0.018605f, -0.050232f, 0.019213f );
      pTmp->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine1
      pTmp->pBone[5].T = Vect( 70.001335f, -0.000002f, -0.000000f );
      pTmp->pBone[5].Q = Quat( ROT_XYZ, 0.038260f, -0.067118f, 0.037115f );
      pTmp->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Spine2
      pTmp->pBone[6].T = Vect( 71.400032f, -0.000000f, 0.000000f );
      pTmp->pBone[6].Q = Quat( ROT_XYZ, 0.038283f, -0.067115f, 0.037105f );
      pTmp->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Neck
      pTmp->pBone[7].T = Vect( 121.576225f, -0.000001f, -0.000000f );
      pTmp->pBone[7].Q = Quat( ROT_XYZ, -0.039728f, -0.145142f, 0.076797f );
      pTmp->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head
      pTmp->pBone[8].T = Vect( 67.855774f, 0.000039f, -0.000000f );
      pTmp->pBone[8].Q = Quat( ROT_XYZ, -0.098165f, 0.165993f, -0.091142f );
      pTmp->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:Head_End
      pTmp->pBone[9].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[9].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder_Dummy
      pTmp->pBone[10].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[10].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftShoulder
      pTmp->pBone[11].T = Vect( -36.845097f, -0.000012f, -0.000005f );
      pTmp->pBone[11].Q = Quat( ROT_XYZ, -0.086308f, -0.001909f, -0.152237f );
      pTmp->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftArm_Dummy
      pTmp->pBone[12].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[12].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftArm
      pTmp->pBone[13].T = Vect( -20.843035f, -1.709348f, 11.313786f );
      pTmp->pBone[13].Q = Quat( ROT_XYZ, 0.181002f, 0.266178f, 3.042246f );
      pTmp->pBone[13].S = Vect( 0.999999f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftArmRoll
      pTmp->pBone[14].T = Vect( 78.950714f, 0.000008f, -0.000000f );
      pTmp->pBone[14].Q = Quat( ROT_XYZ, 0.585755f, 0.000000f, 0.000000f );
      pTmp->pBone[14].S = Vect( 1.000000f, 0.999999f, 1.000001f );

      //     Node Name: Humanoid:LeftForeArm
      pTmp->pBone[15].T = Vect( 65.979294f, 0.000019f, -0.000010f );
      pTmp->pBone[15].Q = Quat( ROT_XYZ, 0.062478f, 0.024741f, -1.572402f );
      pTmp->pBone[15].S = Vect( 1.000002f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftForeArmRoll
      pTmp->pBone[16].T = Vect( 101.404221f, 0.000009f, 0.000010f );
      pTmp->pBone[16].Q = Quat( ROT_XYZ, 0.086325f, 0.000000f, 0.000000f );
      pTmp->pBone[16].S = Vect( 0.999999f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftHand
      pTmp->pBone[17].T = Vect( 71.692039f, 0.000010f, 0.000004f );
      pTmp->pBone[17].Q = Quat( ROT_XYZ, -0.053381f, -0.427500f, 0.244753f );
      pTmp->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb1
      pTmp->pBone[18].T = Vect( 29.257690f, -22.640423f, -5.069802f );
      pTmp->pBone[18].Q = Quat( ROT_XYZ, 0.709381f, 0.537656f, -0.914867f );
      pTmp->pBone[18].S = Vect( 0.999999f, 1.000001f, 1.000003f );

      //     Node Name: Humanoid:LeftThumb2
      pTmp->pBone[19].T = Vect( 22.746157f, -0.353276f, -0.113011f );
      pTmp->pBone[19].Q = Quat( ROT_XYZ, 0.081784f, 0.342417f, 0.683623f );
      pTmp->pBone[19].S = Vect( 0.999997f, 1.000002f, 1.000001f );

      //     Node Name: Humanoid:LeftThumb3
      pTmp->pBone[20].T = Vect( 17.496328f, 0.116578f, 0.089712f );
      pTmp->pBone[20].Q = Quat( ROT_XYZ, 0.027024f, 0.198537f, 0.096617f );
      pTmp->pBone[20].S = Vect( 0.999999f, 1.000001f, 1.000000f );

      //     Node Name: Humanoid:LeftThumb_End
      pTmp->pBone[21].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[21].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftIndex1
      pTmp->pBone[22].T = Vect( 58.921104f, -18.573286f, 1.447069f );
      pTmp->pBone[22].Q = Quat( ROT_XYZ, 1.586099f, 0.426615f, 0.025352f );
      pTmp->pBone[22].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftIndex2
      pTmp->pBone[23].T = Vect( 27.947330f, -0.000028f, 0.000011f );
      pTmp->pBone[23].Q = Quat( ROT_XYZ, -0.015023f, 0.000552f, -0.279687f );
      pTmp->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex3
      pTmp->pBone[24].T = Vect( 17.556934f, -0.000062f, -0.000005f );
      pTmp->pBone[24].Q = Quat( ROT_XYZ, -0.015553f, -0.011463f, -0.281321f );
      pTmp->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftIndex_End
      pTmp->pBone[25].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[25].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftMiddle1
      pTmp->pBone[26].T = Vect( 57.844334f, -4.515547f, 3.569310f );
      pTmp->pBone[26].Q = Quat( ROT_XYZ, 1.525321f, 0.667963f, 0.018870f );
      pTmp->pBone[26].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftMiddle2
      pTmp->pBone[27].T = Vect( 32.362274f, -0.000006f, -0.000017f );
      pTmp->pBone[27].Q = Quat( ROT_XYZ, -0.024592f, 0.021554f, -0.488195f );
      pTmp->pBone[27].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle3
      pTmp->pBone[28].T = Vect( 18.401133f, 0.000069f, 0.000003f );
      pTmp->pBone[28].Q = Quat( ROT_XYZ, -0.024587f, 0.021555f, -0.488208f );
      pTmp->pBone[28].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:LeftMiddle_End
      pTmp->pBone[29].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[29].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftRing1
      pTmp->pBone[30].T = Vect( 57.439991f, 9.168867f, 2.940117f );
      pTmp->pBone[30].Q = Quat( ROT_XYZ, 1.483405f, 0.852180f, 0.008604f );
      pTmp->pBone[30].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftRing2
      pTmp->pBone[31].T = Vect( 30.068848f, 0.000063f, 0.000002f );
      pTmp->pBone[31].Q = Quat( ROT_XYZ, -0.041307f, 0.045509f, -0.696692f );
      pTmp->pBone[31].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing3
      pTmp->pBone[32].T = Vect( 15.270657f, 0.000024f, 0.000004f );
      pTmp->pBone[32].Q = Quat( ROT_XYZ, -0.041310f, 0.045508f, -0.696687f );
      pTmp->pBone[32].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftRing_End
      pTmp->pBone[33].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[33].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftPinky1
      pTmp->pBone[34].T = Vect( 56.621067f, 20.249598f, -1.450183f );
      pTmp->pBone[34].Q = Quat( ROT_XYZ, 1.406783f, 0.858990f, 0.038222f );
      pTmp->pBone[34].S = Vect( 1.000001f, 0.999997f, 1.000005f );

      //     Node Name: Humanoid:LeftPinky2
      pTmp->pBone[35].T = Vect( 19.894529f, 0.000152f, -0.000017f );
      pTmp->pBone[35].Q = Quat( ROT_XYZ, -0.070957f, 0.120430f, -0.831169f );
      pTmp->pBone[35].S = Vect( 1.000001f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky3
      pTmp->pBone[36].T = Vect( 12.904247f, 0.000005f, 0.000009f );
      pTmp->pBone[36].Q = Quat( ROT_XYZ, -0.070955f, 0.120425f, -0.831149f );
      pTmp->pBone[36].S = Vect( 1.000002f, 0.999998f, 1.000000f );

      //     Node Name: Humanoid:LeftPinky_End
      pTmp->pBone[37].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[37].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder_Dummy
      pTmp->pBone[38].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[38].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightShoulder
      pTmp->pBone[39].T = Vect( 36.845016f, 0.000015f, 0.000005f );
      pTmp->pBone[39].Q = Quat( ROT_XYZ, -0.062429f, 0.001865f, -0.114540f );
      pTmp->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArm_Dummy
      pTmp->pBone[40].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[40].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightArm
      pTmp->pBone[41].T = Vect( 20.843040f, 1.709348f, -11.313787f );
      pTmp->pBone[41].Q = Quat( ROT_XYZ, 0.228832f, 0.352865f, 3.105653f );
      pTmp->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightArmRoll
      pTmp->pBone[42].T = Vect( -78.950615f, -0.000001f, 0.000020f );
      pTmp->pBone[42].Q = Quat( ROT_XYZ, 0.613992f, 0.000001f, 0.000000f );
      pTmp->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightForeArm
      pTmp->pBone[43].T = Vect( -65.979179f, -0.000020f, 0.000040f );
      pTmp->pBone[43].Q = Quat( ROT_XYZ, 0.066966f, 0.017857f, -1.162821f );
      pTmp->pBone[43].S = Vect( 1.000001f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightForeArmRoll
      pTmp->pBone[44].T = Vect( -101.404114f, -0.000008f, 0.000018f );
      pTmp->pBone[44].Q = Quat( ROT_XYZ, 0.089061f, 0.000000f, -0.000000f );
      pTmp->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightHand
      pTmp->pBone[45].T = Vect( -71.691925f, -0.000011f, 0.000047f );
      pTmp->pBone[45].Q = Quat( ROT_XYZ, -0.015983f, -0.271162f, 0.117029f );
      pTmp->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb1
      pTmp->pBone[46].T = Vect( -29.257633f, 22.640385f, 5.069794f );
      pTmp->pBone[46].Q = Quat( ROT_XYZ, 0.709378f, 0.537650f, -0.914868f );
      pTmp->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb2
      pTmp->pBone[47].T = Vect( -22.746113f, 0.353250f, 0.112989f );
      pTmp->pBone[47].Q = Quat( ROT_XYZ, 0.081785f, 0.342420f, 0.683621f );
      pTmp->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb3
      pTmp->pBone[48].T = Vect( -17.496260f, -0.116582f, -0.089711f );
      pTmp->pBone[48].Q = Quat( ROT_XYZ, 0.027026f, 0.198541f, 0.096615f );
      pTmp->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightThumb_End
      pTmp->pBone[49].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[49].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightIndex1
      pTmp->pBone[50].T = Vect( -58.920994f, 18.573256f, -1.447088f );
      pTmp->pBone[50].Q = Quat( ROT_XYZ, 1.586071f, 0.426614f, 0.025344f );
      pTmp->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex2
      pTmp->pBone[51].T = Vect( -27.947296f, -0.000004f, -0.000010f );
      pTmp->pBone[51].Q = Quat( ROT_XYZ, -0.015047f, 0.000544f, -0.279685f );
      pTmp->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex3
      pTmp->pBone[52].T = Vect( -17.556936f, 0.000007f, 0.000005f );
      pTmp->pBone[52].Q = Quat( ROT_XYZ, -0.015576f, -0.011470f, -0.281319f );
      pTmp->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightIndex_End
      pTmp->pBone[53].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[53].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightMiddle1
      pTmp->pBone[54].T = Vect( -57.844231f, 4.515540f, -3.569327f );
      pTmp->pBone[54].Q = Quat( ROT_XYZ, 1.525267f, 0.667962f, 0.018847f );
      pTmp->pBone[54].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle2
      pTmp->pBone[55].T = Vect( -32.362286f, -0.000032f, 0.000014f );
      pTmp->pBone[55].Q = Quat( ROT_XYZ, -0.024632f, 0.021536f, -0.488193f );
      pTmp->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle3
      pTmp->pBone[56].T = Vect( -18.401140f, -0.000102f, -0.000003f );
      pTmp->pBone[56].Q = Quat( ROT_XYZ, -0.024626f, 0.021536f, -0.488206f );
      pTmp->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightMiddle_End
      pTmp->pBone[57].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[57].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightRing1
      pTmp->pBone[58].T = Vect( -57.439896f, -9.168852f, -2.940132f );
      pTmp->pBone[58].Q = Quat( ROT_XYZ, 1.483317f, 0.852179f, 0.008559f );
      pTmp->pBone[58].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightRing2
      pTmp->pBone[59].T = Vect( -30.068869f, -0.000103f, -0.000006f );
      pTmp->pBone[59].Q = Quat( ROT_XYZ, -0.041361f, 0.045479f, -0.696690f );
      pTmp->pBone[59].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing3
      pTmp->pBone[60].T = Vect( -15.270673f, 0.000013f, -0.000004f );
      pTmp->pBone[60].Q = Quat( ROT_XYZ, -0.041363f, 0.045478f, -0.696685f );
      pTmp->pBone[60].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightRing_End
      pTmp->pBone[61].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[61].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightPinky1
      pTmp->pBone[62].T = Vect( -56.620979f, -20.249563f, 1.450169f );
      pTmp->pBone[62].Q = Quat( ROT_XYZ, 1.406680f, 0.858990f, 0.038173f );
      pTmp->pBone[62].S = Vect( 1.000000f, 0.999999f, 1.000000f );

      //     Node Name: Humanoid:RightPinky2
      pTmp->pBone[63].T = Vect( -19.894527f, -0.000120f, 0.000016f );
      pTmp->pBone[63].Q = Quat( ROT_XYZ, -0.071022f, 0.120399f, -0.831170f );
      pTmp->pBone[63].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky3
      pTmp->pBone[64].T = Vect( -12.904246f, -0.000024f, -0.000012f );
      pTmp->pBone[64].Q = Quat( ROT_XYZ, -0.071021f, 0.120393f, -0.831149f );
      pTmp->pBone[64].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightPinky_End
      pTmp->pBone[65].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[65].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftHips_Dummy
      pTmp->pBone[66].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[66].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:LeftUpLeg
      pTmp->pBone[67].T = Vect( 0.000000f, 0.000000f, 29.999998f );
      pTmp->pBone[67].Q = Quat( ROT_XYZ, -0.036586f, -0.094107f, -0.902982f );
      pTmp->pBone[67].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftUpLegRoll
      pTmp->pBone[68].T = Vect( 112.510529f, -0.000000f, 0.000020f );
      pTmp->pBone[68].Q = Quat( ROT_XYZ, -0.042026f, -0.000000f, -0.000000f );
      pTmp->pBone[68].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLeg
      pTmp->pBone[69].T = Vect( 129.020859f, -0.000000f, 0.000070f );
      pTmp->pBone[69].Q = Quat( ROT_XYZ, 0.072625f, -0.008685f, 1.050132f );
      pTmp->pBone[69].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftLegRoll
      pTmp->pBone[70].T = Vect( 183.400421f, -0.000000f, -0.000005f );
      pTmp->pBone[70].Q = Quat( ROT_XYZ, 0.107101f, 0.000000f, 0.000000f );
      pTmp->pBone[70].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftFoot
      pTmp->pBone[71].T = Vect( 71.066254f, 0.000009f, 0.000012f );
      pTmp->pBone[71].Q = Quat( ROT_XYZ, 0.123777f, -0.074897f, -1.366606f );
      pTmp->pBone[71].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes
      pTmp->pBone[72].T = Vect( 64.739685f, 0.000002f, -0.000000f );
      pTmp->pBone[72].Q = Quat( ROT_XYZ, 0.000016f, 0.000207f, -0.619515f );
      pTmp->pBone[72].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:LeftToes_End
      pTmp->pBone[73].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[73].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightHips_Dummy
      pTmp->pBone[74].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[74].S = Vect( 1.0f, 1.0f, 1.0f );

      //     Node Name: Humanoid:RightUpLeg
      pTmp->pBone[75].T = Vect( -0.000000f, -0.000000f, -29.999926f );
      pTmp->pBone[75].Q = Quat( ROT_XYZ, -0.123017f, -0.020763f, -0.587696f );
      pTmp->pBone[75].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightUpLegRoll
      pTmp->pBone[76].T = Vect( -112.510269f, 0.000001f, -0.000016f );
      pTmp->pBone[76].Q = Quat( ROT_XYZ, -0.175303f, -0.000000f, 0.000000f );
      pTmp->pBone[76].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLeg
      pTmp->pBone[77].T = Vect( -129.020554f, 0.000002f, -0.000071f );
      pTmp->pBone[77].Q = Quat( ROT_XYZ, 0.010487f, -0.000927f, 2.311750f );
      pTmp->pBone[77].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightLegRoll
      pTmp->pBone[78].T = Vect( -183.399948f, -0.000002f, 0.000006f );
      pTmp->pBone[78].Q = Quat( ROT_XYZ, 0.014209f, -0.000000f, 0.000000f );
      pTmp->pBone[78].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightFoot
      pTmp->pBone[79].T = Vect( -71.066093f, -0.000015f, -0.000011f );
      pTmp->pBone[79].Q = Quat( ROT_XYZ, 0.094114f, -0.072746f, -0.970859f );
      pTmp->pBone[79].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes
      pTmp->pBone[80].T = Vect( -64.739525f, 0.000005f, 0.000000f );
      pTmp->pBone[80].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, -0.619500f );
      pTmp->pBone[80].S = Vect( 1.000000f, 1.000000f, 1.000000f );

      //     Node Name: Humanoid:RightToes_End
      pTmp->pBone[81].T = Vect( 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].Q = Quat( ROT_XYZ, 0.0f, 0.0f, 0.0f );
      pTmp->pBone[81].S = Vect( 1.0f, 1.0f, 1.0f );



}