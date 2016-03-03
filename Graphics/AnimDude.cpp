#include "OpenGLWrapper.h"
#include "PyramidObject.h"
#include "GraphicsManager.h"
#include "Pyramid.h"
#include "Anim.h"

// temporary hack
Frame_Bucket *pHead = 0;
PyramidObject *p0;
PyramidObject *p1;

PyramidObject *pRoot;
PyramidObject *pPelvis;
PyramidObject *pSpine;
PyramidObject *pSpine1;
PyramidObject *pSpine2;
PyramidObject *pSpine3;
PyramidObject *pNeck;
PyramidObject *pHead1;
PyramidObject *pL_eye_joint1;
PyramidObject *pR_eye_joint;
PyramidObject *pL_eyeBall_joint2;
PyramidObject *pR_eyeBall_joint;
PyramidObject *pL_Clavicle;
PyramidObject *pL_UpperArm;
PyramidObject *pL_Forearm;
PyramidObject *pL_Hand;
PyramidObject *pL_Thumb1;
PyramidObject *pL_Thumb2;
PyramidObject *pL_Thumb3;
PyramidObject *pL_Index1;
PyramidObject *pL_Index2;
PyramidObject *pL_Index3;
PyramidObject *pL_Middle1;
PyramidObject *pL_Middle2;
PyramidObject *pL_Middle3;
PyramidObject *pL_Ring1;
PyramidObject *pL_Ring2;
PyramidObject *pL_Ring3;
PyramidObject *pL_Pinky1;
PyramidObject *pL_Pinky2;
PyramidObject *pL_Pinky3;
PyramidObject *pR_Clavicle;
PyramidObject *pR_UpperArm;
PyramidObject *pR_Forearm;
PyramidObject *pR_Hand;
PyramidObject *pR_Thumb1;
PyramidObject *pR_Thumb2;
PyramidObject *pR_Thumb3;
PyramidObject *pR_Index1;
PyramidObject *pR_Index2;
PyramidObject *pR_Index3;
PyramidObject *pR_Middle1;
PyramidObject *pR_Middle2;
PyramidObject *pR_Middle3;
PyramidObject *pR_Ring1;
PyramidObject *pR_Ring2;
PyramidObject *pR_Ring3;
PyramidObject *pR_Pinky1;
PyramidObject *pR_Pinky2;
PyramidObject *pR_Pinky3;
PyramidObject *pL_Thigh1;
PyramidObject *pL_Knee2;
PyramidObject *pL_Ankle1;
PyramidObject *pL_Ball;
PyramidObject *pR_Thigh;
PyramidObject *pR_Knee;
PyramidObject *pR_Ankle;
PyramidObject *pR_Ball;

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

    pRoot = new PyramidObject;
	pRoot->setIndex(0);
	pRoot->setName("Root");
	pRoot->setTransformTest(false);
	tree->insert( pRoot, root );
	
	pPelvis = new PyramidObject;
	pPelvis->setIndex(1);
	pPelvis->setName("Pelvis");
	pPelvis->setTransformTest(false);
	tree->insert( pPelvis, pRoot );
	
	pSpine = new PyramidObject;
	pSpine->setIndex(2);
	pSpine->setName("Spine");
	pSpine->setTransformTest(false);
	tree->insert( pSpine, pPelvis );
	
	pSpine1 = new PyramidObject;
	pSpine1->setIndex(3);
	pSpine1->setName("Spine1");
	pSpine1->setTransformTest(false);
	tree->insert( pSpine1, pSpine );
	
	pSpine2 = new PyramidObject;
	pSpine2->setIndex(4);
	pSpine2->setName("Spine2");
	pSpine2->setTransformTest(false);
	tree->insert( pSpine2, pSpine1 );
	
	pSpine3 = new PyramidObject;
	pSpine3->setIndex(5);
	pSpine3->setName("Spine3");
	pSpine3->setTransformTest(false);
	tree->insert( pSpine3, pSpine2 );
	
	pNeck = new PyramidObject;
	pNeck->setIndex(6);
	pNeck->setName("Neck");
	pNeck->setTransformTest(false);
	tree->insert( pNeck, pSpine3 );
	
	pHead1 = new PyramidObject;
	pHead1->setIndex(7);
	pHead1->setName("Head");
	pHead1->setTransformTest(false);
	tree->insert( pHead1, pNeck );
	
	pL_eye_joint1 = new PyramidObject;
	pL_eye_joint1->setIndex(8);
	pL_eye_joint1->setName("L_eye_joint1");
	pL_eye_joint1->setTransformTest(false);
	tree->insert( pL_eye_joint1, pHead1 );
	
	pR_eye_joint = new PyramidObject;
	pR_eye_joint->setIndex(9);
	pR_eye_joint->setName("R_eye_joint");
	pR_eye_joint->setTransformTest(false);
	tree->insert( pR_eye_joint, pHead1 );
	
	pL_eyeBall_joint2 = new PyramidObject;
	pL_eyeBall_joint2->setIndex(10);
	pL_eyeBall_joint2->setName("L_eyeBall_joint2");
	pL_eyeBall_joint2->setTransformTest(false);
	tree->insert( pL_eyeBall_joint2, pHead1 );
	
	pR_eyeBall_joint = new PyramidObject;
	pR_eyeBall_joint->setIndex(11);
	pR_eyeBall_joint->setName("R_eyeBall_joint");
	pR_eyeBall_joint->setTransformTest(false);
	tree->insert( pR_eyeBall_joint, pHead1 );
	
	pL_Clavicle = new PyramidObject;
	pL_Clavicle->setIndex(12);
	pL_Clavicle->setName("L_Clavicle");
	pL_Clavicle->setTransformTest(false);
	tree->insert( pL_Clavicle, pNeck );
	
	pL_UpperArm = new PyramidObject;
	pL_UpperArm->setIndex(13);
	pL_UpperArm->setName("L_UpperArm");
	pL_UpperArm->setTransformTest(false);
	tree->insert( pL_UpperArm, pL_Clavicle );
	
	pL_Forearm = new PyramidObject;
	pL_Forearm->setIndex(14);
	pL_Forearm->setName("L_Forearm");
	pL_Forearm->setTransformTest(false);
	tree->insert( pL_Forearm, pL_UpperArm );

	pL_Hand = new PyramidObject;
	pL_Hand->setIndex(15);
	pL_Hand->setName("L_Hand");
	pL_Hand->setTransformTest(false);
	tree->insert( pL_Hand, pL_Forearm );

	pL_Thumb1 = new PyramidObject;
	pL_Thumb1->setIndex(16);
	pL_Thumb1->setName("L_Thumb1");
	pL_Thumb1->setTransformTest(false);
	tree->insert( pL_Thumb1, pL_Hand );

	pL_Thumb2 = new PyramidObject;
	pL_Thumb2->setIndex(17);
	pL_Thumb2->setName("L_Thumb2");
	pL_Thumb2->setTransformTest(false);
	tree->insert( pL_Thumb2, pL_Thumb1 );

	pL_Thumb3 = new PyramidObject;
	pL_Thumb3->setIndex(18);
	pL_Thumb3->setName("L_Thumb3");
	pL_Thumb3->setTransformTest(false);
	tree->insert( pL_Thumb3, pL_Thumb2 );

	pL_Index1 = new PyramidObject;
	pL_Index1->setIndex(19);
	pL_Index1->setName("L_Index1");
	pL_Index1->setTransformTest(false);
	tree->insert( pL_Index1, pL_Hand );

	pL_Index2 = new PyramidObject;
	pL_Index2->setIndex(20);
	pL_Index2->setName("L_Index2");
	pL_Index2->setTransformTest(false);
	tree->insert( pL_Index2, pL_Index1 );

	pL_Index3 = new PyramidObject;
	pL_Index3->setIndex(21);
	pL_Index3->setName("L_Index3");
	pL_Index3->setTransformTest(false);
	tree->insert( pL_Index3, pL_Index2 );

	pL_Middle1 = new PyramidObject;
	pL_Middle1->setIndex(22);
	pL_Middle1->setName("L_Middle1");
	pL_Middle1->setTransformTest(false);
	tree->insert( pL_Middle1, pL_Hand );

	pL_Middle2 = new PyramidObject;
	pL_Middle2->setIndex(23);
	pL_Middle2->setName("L_Middle2");
	pL_Middle2->setTransformTest(false);
	tree->insert( pL_Middle2, pL_Middle1 );

	pL_Middle3 = new PyramidObject;
	pL_Middle3->setIndex(24);
	pL_Middle3->setName("L_Middle3");
	pL_Middle3->setTransformTest(false);
	tree->insert( pL_Middle3, pL_Middle2 );

	pL_Ring1 = new PyramidObject;
	pL_Ring1->setIndex(25);
	pL_Ring1->setName("L_Ring1");
	pL_Ring1->setTransformTest(false);
	tree->insert( pL_Ring1, pL_Hand );

	pL_Ring2 = new PyramidObject;
	pL_Ring2->setIndex(26);
	pL_Ring2->setName("L_Ring2");
	pL_Ring2->setTransformTest(false);
	tree->insert( pL_Ring2, pL_Ring1 );

	pL_Ring3 = new PyramidObject;
	pL_Ring3->setIndex(27);
	pL_Ring3->setName("L_Ring3");
	pL_Ring3->setTransformTest(false);
	tree->insert( pL_Ring3, pL_Ring2 );

	pL_Pinky1 = new PyramidObject;
	pL_Pinky1->setIndex(28);
	pL_Pinky1->setName("L_Pinky1");
	pL_Pinky1->setTransformTest(false);
	tree->insert( pL_Pinky1, pL_Hand );

	pL_Pinky2 = new PyramidObject;
	pL_Pinky2->setIndex(29);
	pL_Pinky2->setName("L_Pinky2");
	pL_Pinky2->setTransformTest(false);
	tree->insert( pL_Pinky2, pL_Pinky1 );

	pL_Pinky3 = new PyramidObject;
	pL_Pinky3->setIndex(30);
	pL_Pinky3->setName("L_Pinky3");
	pL_Pinky3->setTransformTest(false);
	tree->insert( pL_Pinky3, pL_Pinky2 );
	
	pR_Clavicle = new PyramidObject;
	pR_Clavicle->setIndex(31);
	pR_Clavicle->setName("R_Clavicle");
	pR_Clavicle->setTransformTest(false);
	tree->insert( pR_Clavicle, pNeck );

	pR_UpperArm = new PyramidObject;
	pR_UpperArm->setIndex(32);
	pR_UpperArm->setName("R_UpperArm");
	pR_UpperArm->setTransformTest(false);
	tree->insert( pR_UpperArm, pR_Clavicle );

	pR_Forearm = new PyramidObject;
	pR_Forearm->setIndex(33);
	pR_Forearm->setName("R_Forearm");
	pR_Forearm->setTransformTest(false);
	tree->insert( pR_Forearm, pR_UpperArm );

	pR_Hand = new PyramidObject;
	pR_Hand->setIndex(34);
	pR_Hand->setName("R_Hand");
	pR_Hand->setTransformTest(false);
	tree->insert( pR_Hand, pR_Forearm );

	pR_Thumb1 = new PyramidObject;
	pR_Thumb1->setIndex(35);
	pR_Thumb1->setName("R_Thumb1");
	pR_Thumb1->setTransformTest(false);
	tree->insert( pR_Thumb1, pR_Hand );

	pR_Thumb2 = new PyramidObject;
	pR_Thumb2->setIndex(36);
	pR_Thumb2->setName("R_Thumb2");
	pR_Thumb2->setTransformTest(false);
	tree->insert( pR_Thumb2, pR_Thumb1 );

	pR_Thumb3 = new PyramidObject;
	pR_Thumb3->setIndex(37);
	pR_Thumb3->setName("R_Thumb3");
	pR_Thumb3->setTransformTest(false);
	tree->insert( pR_Thumb3, pR_Thumb2 );

	pR_Index1 = new PyramidObject;
	pR_Index1->setIndex(38);
	pR_Index1->setName("R_Index1");
	pR_Index1->setTransformTest(false);
	tree->insert( pR_Index1, pR_Hand );

	pR_Index2 = new PyramidObject;
	pR_Index2->setIndex(39);
	pR_Index2->setName("R_Index2");
	pR_Index2->setTransformTest(false);
	tree->insert( pR_Index2, pR_Index1 );

	pR_Index3 = new PyramidObject;
	pR_Index3->setIndex(40);
	pR_Index3->setName("R_Index3");
	pR_Index3->setTransformTest(false);
	tree->insert( pR_Index3, pR_Index2 );

	pR_Middle1 = new PyramidObject;
	pR_Middle1->setIndex(41);
	pR_Middle1->setName("R_Middle1");
	pR_Middle1->setTransformTest(false);
	tree->insert( pR_Middle1, pR_Hand );

	pR_Middle2 = new PyramidObject;
	pR_Middle2->setIndex(42);
	pR_Middle2->setName("R_Middle2");
	pR_Middle2->setTransformTest(false);
	tree->insert( pR_Middle2, pR_Middle1 );

	pR_Middle3 = new PyramidObject;
	pR_Middle3->setIndex(43);
	pR_Middle3->setName("R_Middle3");
	pR_Middle3->setTransformTest(false);
	tree->insert( pR_Middle3, pR_Middle2 );

	pR_Ring1 = new PyramidObject;
	pR_Ring1->setIndex(44);
	pR_Ring1->setName("R_Ring1");
	pR_Ring1->setTransformTest(false);
	tree->insert( pR_Ring1, pR_Hand );

	pR_Ring2 = new PyramidObject;
	pR_Ring2->setIndex(45);
	pR_Ring2->setName("R_Ring2");
	pR_Ring2->setTransformTest(false);
	tree->insert( pR_Ring2, pR_Ring1 );

	pR_Ring3 = new PyramidObject;
	pR_Ring3->setIndex(46);
	pR_Ring3->setName("R_Ring3");
	pR_Ring3->setTransformTest(false);
	tree->insert( pR_Ring3, pR_Ring2 );

	pR_Pinky1 = new PyramidObject;
	pR_Pinky1->setIndex(47);
	pR_Pinky1->setName("R_Pinky1");
	pR_Pinky1->setTransformTest(false);
	tree->insert( pR_Pinky1, pR_Hand );

	pR_Pinky2 = new PyramidObject;
	pR_Pinky2->setIndex(48);
	pR_Pinky2->setName("R_Pinky2");
	pR_Pinky2->setTransformTest(false);
	tree->insert( pR_Pinky2, pR_Pinky1 );

	pR_Pinky3 = new PyramidObject;
	pR_Pinky3->setIndex(49);
	pR_Pinky3->setName("R_Pinky3");
	pR_Pinky3->setTransformTest(false);
	tree->insert( pR_Pinky3, pR_Pinky2 );
	
	pL_Thigh1 = new PyramidObject;
	pL_Thigh1->setIndex(50);
	pL_Thigh1->setName("L_Thigh1");
	pL_Thigh1->setTransformTest(false);
	tree->insert( pL_Thigh1, pSpine );

	pL_Knee2 = new PyramidObject;
	pL_Knee2->setIndex(51);
	pL_Knee2->setName("L_Knee2");
	pL_Knee2->setTransformTest(false);
	tree->insert( pL_Knee2, pL_Thigh1 );

	pL_Ankle1 = new PyramidObject;
	pL_Ankle1->setIndex(52);
	pL_Ankle1->setName("L_Ankle1");
	pL_Ankle1->setTransformTest(false);
	tree->insert( pL_Ankle1, pL_Knee2 );

	pL_Ball = new PyramidObject;
	pL_Ball->setIndex(53);
	pL_Ball->setName("L_Ball");
	pL_Ball->setTransformTest(false);
	tree->insert( pL_Ball, pL_Ankle1 );

	pR_Thigh = new PyramidObject;
	pR_Thigh->setIndex(54);
	pR_Thigh->setName("R_Thigh");
	pR_Thigh->setTransformTest(false);
	tree->insert( pR_Thigh, pSpine );

	pR_Knee = new PyramidObject;
	pR_Knee->setIndex(55);
	pR_Knee->setName("R_Knee");
	pR_Knee->setTransformTest(false);
	tree->insert( pR_Knee, pR_Thigh );

	pR_Ankle = new PyramidObject;
	pR_Ankle->setIndex(56);
	pR_Ankle->setName("R_Ankle");
	pR_Ankle->setTransformTest(false);
	tree->insert( pR_Ankle, pR_Knee );

	pR_Ball = new PyramidObject;
	pR_Ball->setIndex(57);
	pR_Ball->setName("R_Ball");
	pR_Ball->setTransformTest(false);
	tree->insert( pR_Ball, pR_Ankle );
	
}

void SetAnimationPose()
{
	Vect start(0.0f,0.0f,0.0f);
	Vect vout;

	Matrix temp;
	
	// REMEMBER:
	// that the bone pose are WORLD not GLOBAL
	// Animations are relative!

	Matrix boneRoot(
        Vect(   0.0000f,   -0.0000f,    1.0000f,    0.0000f),
        Vect(   1.0000f,    0.0000f,   -0.0000f,    0.0000f),
        Vect(  -0.0000f,    1.0000f,    0.0000f,    0.0000f),
        Vect(   0.0376f,   37.4610f,    2.2305f,    1.0000f));

	Matrix bonePelvis(
        Vect(  -0.0000f,    1.0000f,    0.0000f,    0.0000f),
        Vect(   0.0000f,   -0.0000f,    1.0000f,    0.0000f),
        Vect(   1.0000f,    0.0000f,   -0.0000f,    0.0000f),
        Vect(   0.0376f,   37.4610f,    1.2747f,    1.0000f));

	Matrix boneSpine(
        Vect(   0.0000f,    0.9955f,   -0.0948f,    0.0000f),
        Vect(  -0.0000f,    0.0948f,    0.9955f,    0.0000f),
        Vect(   1.0000f,   -0.0000f,    0.0000f,    0.0000f),
        Vect(   0.0376f,   41.2470f,    1.2711f,    1.0000f));

	Matrix boneSpine1(
        Vect(   0.0000f,    0.9807f,   -0.1953f,    0.0000f),
        Vect(  -0.0000f,    0.1953f,    0.9807f,    0.0000f),
        Vect(   1.0000f,   -0.0000f,    0.0000f,    0.0000f),
        Vect(   0.0376f,   45.7695f,    0.8369f,    1.0000f));

	Matrix boneL_Thigh1(
        Vect(   0.2110f,   -0.9753f,    0.0661f,    0.0000f),
        Vect(   0.1780f,    0.1048f,    0.9784f,    0.0000f),
        Vect(  -0.9611f,   -0.1947f,    0.1957f,    0.0000f),
        Vect(   3.5327f,   37.4610f,    1.2747f,    1.0000f));

	Matrix boneR_Thigh(
        Vect(  -0.2110f,   -0.9753f,    0.0661f,    0.0000f),
        Vect(  -0.1780f,    0.1048f,    0.9784f,    0.0000f),
        Vect(  -0.9611f,    0.1947f,   -0.1957f,    0.0000f),
        Vect(  -3.4576f,   37.4610f,    1.2747f,    1.0000f));

	Matrix boneSpine2(
        Vect(   0.0000f,    0.9953f,   -0.0969f,    0.0000f),
        Vect(  -0.0000f,    0.0969f,    0.9953f,    0.0000f),
        Vect(   1.0000f,   -0.0000f,    0.0000f,    0.0000f),
        Vect(   0.0376f,   50.2254f,   -0.0539f,    1.0000f));

	Matrix boneL_Knee2(
        Vect(   0.1409f,   -0.9557f,   -0.2585f,    0.0000f),
        Vect(   0.2374f,   -0.2209f,    0.9460f,    0.0000f),
        Vect(  -0.9611f,   -0.1947f,    0.1957f,    0.0000f),
        Vect(   7.3847f,   19.6556f,    2.4810f,    1.0000f));

	Matrix boneR_Knee(
        Vect(  -0.1409f,   -0.9557f,   -0.2585f,    0.0000f),
        Vect(  -0.2374f,   -0.2209f,    0.9460f,    0.0000f),
        Vect(  -0.9611f,    0.1947f,   -0.1957f,    0.0000f),
        Vect(  -7.3096f,   19.6556f,    2.4810f,    1.0000f));

	Matrix boneSpine3(
        Vect(   0.0267f,    0.9972f,   -0.0695f,    0.0000f),
        Vect(   0.0696f,    0.0675f,    0.9953f,    0.0000f),
        Vect(   0.9972f,   -0.0315f,   -0.0676f,    0.0000f),
        Vect(   0.0376f,   54.7475f,   -0.4988f,    1.0000f));

	Matrix boneL_Ankle1(
        Vect(  -0.0097f,   -0.9981f,   -0.0611f,    0.0000f),
        Vect(   0.2616f,   -0.0615f,    0.9632f,    0.0000f),
        Vect(  -0.9651f,   -0.0066f,    0.2617f,    0.0000f),
        Vect(   9.5589f,    4.9116f,   -1.5078f,    1.0000f));

	Matrix boneR_Ankle(
        Vect(   0.0097f,   -0.9981f,   -0.0611f,    0.0000f),
        Vect(  -0.2616f,   -0.0615f,    0.9632f,    0.0000f),
        Vect(  -0.9651f,    0.0066f,   -0.2617f,    0.0000f),
        Vect(  -9.4838f,    4.9116f,   -1.5078f,    1.0000f));

	Matrix boneNeck(
        Vect(   0.0525f,    0.9400f,    0.3370f,    0.0000f),
        Vect(   0.0529f,   -0.3396f,    0.9391f,    0.0000f),
        Vect(   0.9972f,   -0.0315f,   -0.0676f,    0.0000f),
        Vect(   0.1855f,   60.2682f,   -0.8865f,    1.0000f));

	Matrix boneL_Ball(
        Vect(   0.2556f,    0.1920f,    0.9475f,    0.0000f),
        Vect(  -0.0565f,    0.9814f,   -0.1836f,    0.0000f),
        Vect(  -0.9651f,   -0.0066f,    0.2617f,    0.0000f),
        Vect(  11.1488f,   -0.7146f,    4.2144f,    1.0000f));

	Matrix boneR_Ball(
        Vect(  -0.2556f,    0.1920f,    0.9475f,    0.0000f),
        Vect(   0.0565f,    0.9814f,   -0.1836f,    0.0000f),
        Vect(  -0.9651f,    0.0066f,   -0.2617f,    0.0000f),
        Vect( -11.0738f,   -0.7146f,    4.2145f,    1.0000f));

	Matrix boneHead(
        Vect(   0.0413f,    0.9878f,    0.1499f,    0.0000f),
        Vect(   0.0620f,   -0.1523f,    0.9864f,    0.0000f),
        Vect(   0.9972f,   -0.0315f,   -0.0676f,    0.0000f),
        Vect(   0.3930f,   63.9850f,    0.4460f,    1.0000f));

	Matrix boneL_Clavicle(
        Vect(   0.9785f,   -0.1990f,   -0.0548f,    0.0000f),
        Vect(  -0.0696f,   -0.0683f,   -0.9952f,    0.0000f),
        Vect(   0.1943f,    0.9776f,   -0.0807f,    0.0000f),
        Vect(   1.3484f,   60.2019f,   -1.7966f,    1.0000f));

	Matrix boneR_Clavicle(
        Vect(  -0.9875f,   -0.1370f,    0.0784f,    0.0000f),
        Vect(  -0.0696f,   -0.0683f,   -0.9952f,    0.0000f),
        Vect(   0.1417f,   -0.9882f,    0.0579f,    0.0000f),
        Vect(  -1.0914f,   60.2789f,   -1.6313f,    1.0000f));

	Matrix boneL_eye_joint1(
        Vect(   0.9933f,   -0.0244f,   -0.1127f,    0.0000f),
        Vect(   0.1076f,   -0.1536f,    0.9823f,    0.0000f),
        Vect(  -0.0413f,   -0.9878f,   -0.1499f,    0.0000f),
        Vect(   2.0456f,   67.8964f,    2.3714f,    1.0000f));

	Matrix boneR_eye_joint(
        Vect(   0.9933f,   -0.0244f,   -0.1127f,    0.0000f),
        Vect(   0.1076f,   -0.1536f,    0.9823f,    0.0000f),
        Vect(  -0.0413f,   -0.9878f,   -0.1499f,    0.0000f),
        Vect(  -0.4099f,   68.0595f,    2.4771f,    1.0000f));

	Matrix boneL_eyeBall_joint2(
        Vect(   0.0413f,    0.9878f,    0.1502f,    0.0000f),
        Vect(   0.1247f,   -0.1543f,    0.9801f,    0.0000f),
        Vect(   0.9913f,   -0.0218f,   -0.1295f,    0.0000f),
        Vect(   2.0507f,   67.8783f,    4.2356f,    1.0000f));

	Matrix boneR_eyeBall_joint(
        Vect(   0.0388f,    0.9852f,    0.1667f,    0.0000f),
        Vect(   0.1000f,   -0.1699f,    0.9804f,    0.0000f),
        Vect(   0.9942f,   -0.0213f,   -0.1051f,    0.0000f),
        Vect(  -0.4295f,   68.0711f,    4.2785f,    1.0000f));

	Matrix boneL_UpperArm(
        Vect(   0.6745f,   -0.7348f,    0.0707f,    0.0000f),
        Vect(  -0.0057f,   -0.1010f,   -0.9949f,    0.0000f),
        Vect(   0.7382f,    0.6707f,   -0.0724f,    0.0000f),
        Vect(   8.0449f,   58.8400f,   -2.1714f,    1.0000f));

	Matrix boneR_UpperArm(
        Vect(  -0.7036f,   -0.6914f,    0.1641f,    0.0000f),
        Vect(  -0.1347f,   -0.0970f,   -0.9861f,    0.0000f),
        Vect(   0.6977f,   -0.7160f,   -0.0249f,    0.0000f),
        Vect(  -7.8494f,   59.3414f,   -1.0944f,    1.0000f));

	Matrix boneL_Forearm(
        Vect(   0.6622f,   -0.7001f,    0.2670f,    0.0000f),
        Vect(   0.1284f,   -0.2450f,   -0.9610f,    0.0000f),
        Vect(   0.7382f,    0.6707f,   -0.0724f,    0.0000f),
        Vect(  16.9098f,   49.1825f,   -1.2417f,    1.0000f));

	Matrix boneR_Forearm(
        Vect(  -0.6628f,   -0.6583f,    0.3568f,    0.0000f),
        Vect(  -0.2718f,   -0.2324f,   -0.9339f,    0.0000f),
        Vect(   0.6977f,   -0.7160f,   -0.0249f,    0.0000f),
        Vect( -17.0964f,   50.2552f,    1.0625f,    1.0000f));

	Matrix boneL_Hand(
        Vect(   0.5252f,   -0.8195f,    0.2294f,    0.0000f),
        Vect(  -0.7902f,   -0.5697f,   -0.2257f,    0.0000f),
        Vect(   0.3157f,   -0.0627f,   -0.9468f,    0.0000f),
        Vect(  24.0788f,   41.6033f,    1.6485f,    1.0000f));

	Matrix boneR_Hand(
        Vect(  -0.5399f,   -0.7859f,    0.3015f,    0.0000f),
        Vect(   0.7153f,   -0.6172f,   -0.3278f,    0.0000f),
        Vect(   0.4437f,    0.0387f,    0.8953f,    0.0000f),
        Vect( -24.2718f,   43.1284f,    4.9246f,    1.0000f));

	Matrix boneL_Thumb1(
        Vect(  -0.2415f,   -0.6232f,    0.7438f,    0.0000f),
        Vect(   0.7488f,   -0.6072f,   -0.2656f,    0.0000f),
        Vect(   0.6172f,    0.4929f,    0.6133f,    0.0000f),
        Vect(  23.9072f,   40.0198f,    3.4692f,    1.0000f));

	Matrix boneL_Index1(
        Vect(   0.4762f,   -0.8262f,    0.3011f,    0.0000f),
        Vect(  -0.7142f,   -0.5631f,   -0.4157f,    0.0000f),
        Vect(   0.5130f,   -0.0171f,   -0.8582f,    0.0000f),
        Vect(  25.8572f,   38.1283f,    4.1206f,    1.0000f));

	Matrix boneL_Middle1(
        Vect(   0.5703f,   -0.8094f,    0.1398f,    0.0000f),
        Vect(  -0.7738f,   -0.5865f,   -0.2392f,    0.0000f),
        Vect(   0.2756f,    0.0282f,   -0.9609f,    0.0000f),
        Vect(  26.2533f,   38.0536f,    2.9959f,    1.0000f));

	Matrix boneL_Ring1(
        Vect(   0.5829f,   -0.8121f,   -0.0281f,    0.0000f),
        Vect(  -0.8109f,   -0.5791f,   -0.0844f,    0.0000f),
        Vect(   0.0523f,    0.0720f,   -0.9960f,    0.0000f),
        Vect(  26.6641f,   38.0871f,    1.8915f,    1.0000f));

	Matrix boneL_Pinky1(
        Vect(   0.4671f,   -0.8654f,   -0.1813f,    0.0000f),
        Vect(  -0.8639f,   -0.4904f,    0.1148f,    0.0000f),
        Vect(  -0.1883f,    0.1029f,   -0.9767f,    0.0000f),
        Vect(  26.5389f,   38.1113f,    0.8591f,    1.0000f));

	Matrix boneR_Thumb1(
        Vect(   0.3000f,   -0.6403f,    0.7072f,    0.0000f),
        Vect(  -0.8144f,   -0.5579f,   -0.1597f,    0.0000f),
        Vect(   0.4968f,   -0.5280f,   -0.6888f,    0.0000f),
        Vect( -23.9561f,   41.5296f,    6.7123f,    1.0000f));

	Matrix boneR_Index1(
        Vect(  -0.4822f,   -0.7960f,    0.3660f,    0.0000f),
        Vect(   0.6149f,   -0.6051f,   -0.5058f,    0.0000f),
        Vect(   0.6240f,   -0.0188f,    0.7812f,    0.0000f),
        Vect( -25.9153f,   39.7614f,    7.6285f,    1.0000f));

	Matrix boneR_Middle1(
        Vect(  -0.5959f,   -0.7727f,    0.2188f,    0.0000f),
        Vect(   0.6962f,   -0.6329f,   -0.3388f,    0.0000f),
        Vect(   0.4002f,   -0.0496f,    0.9151f,    0.0000f),
        Vect( -26.4632f,   39.7165f,    6.5679f,    1.0000f));

	Matrix boneR_Ring1(
        Vect(  -0.6311f,   -0.7738f,    0.0541f,    0.0000f),
        Vect(   0.7542f,   -0.6285f,   -0.1904f,    0.0000f),
        Vect(   0.1814f,   -0.0794f,    0.9802f,    0.0000f),
        Vect( -27.0163f,   39.7804f,    5.5287f,    1.0000f));

	Matrix boneR_Pinky1(
        Vect(  -0.5407f,   -0.8336f,   -0.1130f,    0.0000f),
        Vect(   0.8390f,   -0.5441f,   -0.0006f,    0.0000f),
        Vect(  -0.0610f,   -0.0951f,    0.9936f,    0.0000f),
        Vect( -27.0300f,   39.8010f,    4.4888f,    1.0000f));

	Matrix boneL_Thumb2(
        Vect(  -0.1352f,   -0.7015f,    0.6997f,    0.0000f),
        Vect(   0.7751f,   -0.5148f,   -0.3664f,    0.0000f),
        Vect(   0.6172f,    0.4929f,    0.6133f,    0.0000f),
        Vect(  23.6318f,   39.3091f,    4.3175f,    1.0000f));

	Matrix boneL_Index2(
        Vect(   0.3413f,   -0.9133f,    0.2222f,    0.0000f),
        Vect(  -0.7876f,   -0.4069f,   -0.4627f,    0.0000f),
        Vect(   0.5130f,   -0.0171f,   -0.8582f,    0.0000f),
        Vect(  26.5590f,   36.9107f,    4.5643f,    1.0000f));

	Matrix boneL_Middle2(
        Vect(   0.4998f,   -0.8581f,    0.1181f,    0.0000f),
        Vect(  -0.8212f,   -0.5128f,   -0.2506f,    0.0000f),
        Vect(   0.2756f,    0.0282f,   -0.9609f,    0.0000f),
        Vect(  27.1253f,   36.8159f,    3.2097f,    1.0000f));

	Matrix boneL_Ring2(
        Vect(   0.3872f,   -0.9208f,   -0.0462f,    0.0000f),
        Vect(  -0.9205f,   -0.3833f,   -0.0760f,    0.0000f),
        Vect(   0.0523f,    0.0720f,   -0.9960f,    0.0000f),
        Vect(  27.4821f,   36.9475f,    1.8520f,    1.0000f));

	Matrix boneL_Pinky2(
        Vect(   0.4671f,   -0.8654f,   -0.1813f,    0.0000f),
        Vect(  -0.8639f,   -0.4904f,    0.1148f,    0.0000f),
        Vect(  -0.1883f,    0.1029f,   -0.9767f,    0.0000f),
        Vect(  27.0676f,   37.1318f,    0.6540f,    1.0000f));

	Matrix boneR_Thumb2(
        Vect(   0.1839f,   -0.7116f,    0.6781f,    0.0000f),
        Vect(  -0.8482f,   -0.4636f,   -0.2564f,    0.0000f),
        Vect(   0.4968f,   -0.5280f,   -0.6888f,    0.0000f),
        Vect( -23.6140f,   40.7994f,    7.5188f,    1.0000f));

	Matrix boneR_Index2(
        Vect(  -0.3649f,   -0.8910f,    0.2700f,    0.0000f),
        Vect(   0.6910f,   -0.4535f,   -0.5629f,    0.0000f),
        Vect(   0.6240f,   -0.0188f,    0.7812f,    0.0000f),
        Vect( -26.6259f,   38.5884f,    8.1679f,    1.0000f));

	Matrix boneR_Middle2(
        Vect(  -0.5321f,   -0.8255f,    0.1880f,    0.0000f),
        Vect(   0.7461f,   -0.5622f,   -0.3568f,    0.0000f),
        Vect(   0.4002f,   -0.0496f,    0.9151f,    0.0000f),
        Vect( -27.3744f,   38.5350f,    6.9025f,    1.0000f));

	Matrix boneR_Ring2(
        Vect(  -0.4469f,   -0.8945f,    0.0103f,    0.0000f),
        Vect(   0.8760f,   -0.4400f,   -0.1977f,    0.0000f),
        Vect(   0.1814f,   -0.0794f,    0.9802f,    0.0000f),
        Vect( -27.9020f,   38.6945f,    5.6047f,    1.0000f));

	Matrix boneR_Pinky2(
        Vect(  -0.5407f,   -0.8336f,   -0.1130f,    0.0000f),
        Vect(   0.8390f,   -0.5441f,   -0.0006f,    0.0000f),
        Vect(  -0.0610f,   -0.0951f,    0.9936f,    0.0000f),
        Vect( -27.6420f,   38.8576f,    4.3610f,    1.0000f));

	Matrix boneL_Thumb3(
        Vect(  -0.1503f,   -0.6913f,    0.7068f,    0.0000f),
        Vect(   0.7723f,   -0.5284f,   -0.3526f,    0.0000f),
        Vect(   0.6172f,    0.4929f,    0.6133f,    0.0000f),
        Vect(  23.4450f,   38.3393f,    5.2849f,    1.0000f));

	Matrix boneL_Index3(
        Vect(   0.3413f,   -0.9133f,    0.2222f,    0.0000f),
        Vect(  -0.7876f,   -0.4069f,   -0.4627f,    0.0000f),
        Vect(   0.5130f,   -0.0171f,   -0.8582f,    0.0000f),
        Vect(  26.9217f,   35.9400f,    4.8004f,    1.0000f));

	Matrix boneL_Middle3(
        Vect(   0.4441f,   -0.8902f,    0.1012f,    0.0000f),
        Vect(  -0.8525f,   -0.4547f,   -0.2579f,    0.0000f),
        Vect(   0.2756f,    0.0282f,   -0.9609f,    0.0000f),
        Vect(  27.8895f,   35.5038f,    3.3903f,    1.0000f));

	Matrix boneL_Ring3(
        Vect(   0.3872f,   -0.9208f,   -0.0462f,    0.0000f),
        Vect(  -0.9205f,   -0.3833f,   -0.0760f,    0.0000f),
        Vect(   0.0523f,    0.0720f,   -0.9960f,    0.0000f),
        Vect(  28.0197f,   35.6692f,    1.7878f,    1.0000f));

	Matrix boneL_Pinky3(
        Vect(   0.4078f,   -0.8965f,   -0.1731f,    0.0000f),
        Vect(  -0.8935f,   -0.4308f,    0.1268f,    0.0000f),
        Vect(  -0.1883f,    0.1029f,   -0.9767f,    0.0000f),
        Vect(  27.4689f,   36.3885f,    0.4983f,    1.0000f));

	Matrix boneR_Thumb3(
        Vect(   0.2005f,   -0.7023f,    0.6830f,    0.0000f),
        Vect(  -0.8444f,   -0.4774f,   -0.2430f,    0.0000f),
        Vect(   0.4968f,   -0.5280f,   -0.6888f,    0.0000f),
        Vect( -23.3597f,   39.8157f,    8.4563f,    1.0000f));

	Matrix boneR_Index3(
        Vect(  -0.3649f,   -0.8910f,    0.2700f,    0.0000f),
        Vect(   0.6910f,   -0.4535f,   -0.5629f,    0.0000f),
        Vect(   0.6240f,   -0.0188f,    0.7812f,    0.0000f),
        Vect( -27.0137f,   37.6413f,    8.4549f,    1.0000f));

	Matrix boneR_Middle3(
        Vect(  -0.4814f,   -0.8610f,    0.1639f,    0.0000f),
        Vect(   0.7798f,   -0.5061f,   -0.3685f,    0.0000f),
        Vect(   0.4002f,   -0.0496f,    0.9151f,    0.0000f),
        Vect( -28.1881f,   37.2727f,    7.1900f,    1.0000f));

	Matrix boneR_Ring3(
        Vect(  -0.4469f,   -0.8945f,    0.0103f,    0.0000f),
        Vect(   0.8760f,   -0.4400f,   -0.1977f,    0.0000f),
        Vect(   0.1814f,   -0.0794f,    0.9802f,    0.0000f),
        Vect( -28.5224f,   37.4527f,    5.6190f,    1.0000f));

	Matrix boneR_Pinky3(
        Vect(  -0.4828f,   -0.8684f,   -0.1127f,    0.0000f),
        Vect(   0.8736f,   -0.4866f,    0.0071f,    0.0000f),
        Vect(  -0.0610f,   -0.0951f,    0.9936f,    0.0000f),
        Vect( -28.1064f,   38.1415f,    4.2639f,    1.0000f));

	//Root
	vout = start * boneRoot;
	pRoot->setStartPos( vout );

	pRoot->Local = boneRoot;
	
	//Pelvis
	vout = start * bonePelvis;
	pPelvis->setStartPos( vout );

	temp = boneRoot.getInv();
	pPelvis->Local = temp * bonePelvis;
	
	//Spine
	vout = start * boneSpine;
	pSpine->setStartPos( vout );
	
	temp = bonePelvis.getInv();
	pSpine->Local = temp * boneSpine;
	
	//Spine1
	vout = start * boneSpine1;
	pSpine1->setStartPos( vout );

	temp = boneSpine.getInv();
	pSpine1->Local = temp * boneSpine1;
	
	//Spine2
	vout = start * boneSpine2;
	pSpine2->setStartPos( vout );

	temp = boneSpine1.getInv();
	pSpine2->Local = temp * boneSpine2;
	
	//Spine3
	vout = start * boneSpine3;
	pSpine3->setStartPos( vout );

	temp = boneSpine2.getInv();
	pSpine3->Local = temp * boneSpine3;
	
	//Neck
	vout = start * boneNeck;
	pNeck->setStartPos( vout );

	temp = boneSpine3.getInv();
	pNeck->Local = temp * boneNeck;
	
	//Head
	vout = start * boneHead;
	pHead1->setStartPos( vout );

	temp = boneNeck.getInv();
	pHead1->Local = temp * boneHead;
	
	//L_eye_joint1
	vout = start * boneL_eye_joint1;
	pL_eye_joint1->setStartPos( vout );

	temp = boneHead.getInv();
	pL_eye_joint1->Local = temp * boneL_eye_joint1;
	
	//R_eye_joint
	vout = start * boneR_eye_joint;
	pR_eye_joint->setStartPos( vout );

	temp = boneHead.getInv();
	pR_eye_joint->Local = temp * boneR_eye_joint;
	
	//L_eyeBall_joint2
	vout = start * boneL_eyeBall_joint2;
	pL_eyeBall_joint2->setStartPos( vout );

	temp = boneHead.getInv();
	pL_eyeBall_joint2->Local = temp * boneL_eyeBall_joint2;
	
	//R_eyeBall_joint
	vout = start * boneR_eyeBall_joint;
	pR_eyeBall_joint->setStartPos( vout );

	temp = boneHead.getInv();
	pR_eyeBall_joint->Local = temp * boneR_eyeBall_joint;
	
	//L_Clavicle
	vout = start * boneL_Clavicle;
	pL_Clavicle->setStartPos( vout );

	temp = boneNeck.getInv();
	pL_Clavicle->Local = temp * boneL_Clavicle;
	
	//L_UpperArm
	vout = start * boneL_UpperArm;
	pL_UpperArm->setStartPos( vout );

	temp = boneL_Clavicle.getInv();
	pL_UpperArm->Local = temp * boneL_UpperArm;
	
	//L_Forearm
	vout = start * boneL_Forearm;
	pL_Forearm->setStartPos( vout );

	temp = boneL_UpperArm.getInv();
	pL_Forearm->Local = temp * boneL_Forearm;

	//L_Hand
	vout = start * boneL_Hand;
	pL_Hand->setStartPos( vout );

	temp = boneL_Forearm.getInv();
	pL_Hand->Local = temp * boneL_Hand;

	//L_Thumb1
	vout = start * boneL_Thumb1;
	pL_Thumb1->setStartPos( vout );

	temp = boneL_Hand.getInv();
	pL_Thumb1->Local = temp * boneL_Thumb1;

	//L_Thumb2
	vout = start * boneL_Thumb2;
	pL_Thumb2->setStartPos( vout );

	temp = boneL_Thumb1.getInv();
	pL_Thumb2->Local = temp * boneL_Thumb2;

	//L_Thumb3
	vout = start * boneL_Thumb3;
	pL_Thumb3->setStartPos( vout );

	temp = boneL_Thumb2.getInv();
	pL_Thumb3->Local = temp * boneL_Thumb3;

	//L_Index1
	vout = start * boneL_Index1;
	pL_Index1->setStartPos( vout );

	temp = boneL_Hand.getInv();
	pL_Index1->Local = temp * boneL_Index1;

	//L_Index2
	vout = start * boneL_Index2;
	pL_Index2->setStartPos( vout );

	temp = boneL_Index1.getInv();
	pL_Index2->Local = temp * boneL_Index2;

	//L_Index3
	vout = start * boneL_Index3;
	pL_Index3->setStartPos( vout );

	temp = boneL_Index2.getInv();
	pL_Index3->Local = temp * boneL_Index3;

	//L_Middle1
	vout = start * boneL_Middle1;
	pL_Middle1->setStartPos( vout );

	temp = boneL_Hand.getInv();
	pL_Middle1->Local = temp * boneL_Middle1;

	//L_Middle2
	vout = start * boneL_Middle2;
	pL_Middle2->setStartPos( vout );

	temp = boneL_Middle1.getInv();
	pL_Middle2->Local = temp * boneL_Middle2;

	//L_Middle3
	vout = start * boneL_Middle3;
	pL_Middle3->setStartPos( vout );

	temp = boneL_Middle2.getInv();
	pL_Middle3->Local = temp * boneL_Middle3;

	//L_Ring1
	vout = start * boneL_Ring1;
	pL_Ring1->setStartPos( vout );

	temp = boneL_Hand.getInv();
	pL_Ring1->Local = temp * boneL_Ring1;

	//L_Ring2
	vout = start * boneL_Ring2;
	pL_Ring2->setStartPos( vout );

	temp = boneL_Ring1.getInv();
	pL_Ring2->Local = temp * boneL_Ring2;

	//L_Ring3
	vout = start * boneL_Ring3;
	pL_Ring3->setStartPos( vout );

	temp = boneL_Ring2.getInv();
	pL_Ring3->Local = temp * boneL_Ring3;

	//L_Pinky1
	vout = start * boneL_Pinky1;
	pL_Pinky1->setStartPos( vout );

	temp = boneL_Hand.getInv();
	pL_Pinky1->Local = temp * boneL_Pinky1;

	//L_Pinky2
	vout = start * boneL_Pinky2;
	pL_Pinky2->setStartPos( vout );

	temp = boneL_Pinky1.getInv();
	pL_Pinky2->Local = temp * boneL_Pinky2;

	//L_Pinky3
	vout = start * boneL_Pinky3;
	pL_Pinky3->setStartPos( vout );

	temp = boneL_Pinky2.getInv();
	pL_Pinky3->Local = temp * boneL_Pinky3;
	
	//R_Clavicle
	vout = start * boneR_Clavicle;
	pR_Clavicle->setStartPos( vout );

	temp = boneNeck.getInv();
	pR_Clavicle->Local = temp * boneR_Clavicle;

	//R_UpperArm
	vout = start * boneR_UpperArm;
	pR_UpperArm->setStartPos( vout );

	temp = boneR_Clavicle.getInv();
	pR_UpperArm->Local = temp * boneR_UpperArm;

	//R_Forearm
	vout = start * boneR_Forearm;
	pR_Forearm->setStartPos( vout );

	temp = boneR_UpperArm.getInv();
	pR_Forearm->Local = temp * boneR_Forearm;

	//R_Hand
	vout = start * boneR_Hand;
	pR_Hand->setStartPos( vout );

	temp = boneR_Forearm.getInv();
	pR_Hand->Local = temp * boneR_Hand;

	//R_Thumb1
	vout = start * boneR_Thumb1;
	pR_Thumb1->setStartPos( vout );

	temp = boneR_Hand.getInv();
	pR_Thumb1->Local = temp * boneR_Thumb1;

	//R_Thumb2
	vout = start * boneR_Thumb2;
	pR_Thumb2->setStartPos( vout );

	temp = boneR_Thumb1.getInv();
	pR_Thumb2->Local = temp * boneR_Thumb2;

	//R_Thumb3
	vout = start * boneR_Thumb3;
	pR_Thumb3->setStartPos( vout );

	temp = boneR_Thumb2.getInv();
	pR_Thumb3->Local = temp * boneR_Thumb3;

	//R_Index1
	vout = start * boneR_Index1;
	pR_Index1->setStartPos( vout );

	temp = boneR_Hand.getInv();
	pR_Index1->Local = temp * boneR_Index1;

	//R_Index2
	vout = start * boneR_Index2;
	pR_Index2->setStartPos( vout );

	temp = boneR_Index1.getInv();
	pR_Index2->Local = temp * boneR_Index2;

	//R_Index3
	vout = start * boneR_Index3;
	pR_Index3->setStartPos( vout );

	temp = boneR_Index2.getInv();
	pR_Index3->Local = temp * boneR_Index3;

	//R_Middle1
	vout = start * boneR_Middle1;
	pR_Middle1->setStartPos( vout );

	temp = boneR_Hand.getInv();
	pR_Middle1->Local = temp * boneR_Middle1;

	//R_Middle2
	vout = start * boneR_Middle2;
	pR_Middle2->setStartPos( vout );

	temp = boneR_Middle1.getInv();
	pR_Middle2->Local = temp * boneR_Middle2;

	//R_Middle3
	vout = start * boneR_Middle3;
	pR_Middle3->setStartPos( vout );

	temp = boneR_Middle2.getInv();
	pR_Middle3->Local = temp * boneR_Middle3;

	//R_Ring1
	vout = start * boneR_Ring1;
	pR_Ring1->setStartPos( vout );

	temp = boneR_Hand.getInv();
	pR_Ring1->Local = temp * boneR_Ring1;

	//R_Ring2
	vout = start * boneR_Ring2;
	pR_Ring2->setStartPos( vout );

	temp = boneR_Ring1.getInv();
	pR_Ring2->Local = temp * boneR_Ring2;

	//R_Ring3
	vout = start * boneR_Ring3;
	pR_Ring3->setStartPos( vout );

	temp = boneR_Ring2.getInv();
	pR_Ring3->Local = temp * boneR_Ring3;

	//R_Pinky1
	vout = start * boneR_Pinky1;
	pR_Pinky1->setStartPos( vout );

	temp = boneR_Hand.getInv();
	pR_Pinky1->Local = temp * boneR_Pinky1;

	//R_Pinky2
	vout = start * boneR_Pinky2;
	pR_Pinky2->setStartPos( vout );

	temp = boneR_Pinky1.getInv();
	pR_Pinky2->Local = temp * boneR_Pinky2;

	//R_Pinky3
	vout = start * boneR_Pinky3;
	pR_Pinky3->setStartPos( vout );

	temp = boneR_Pinky2.getInv();
	pR_Pinky3->Local = temp * boneR_Pinky3;
	
	//L_Thigh1
	vout = start * boneL_Thigh1;
	pL_Thigh1->setStartPos( vout );

	temp = boneSpine.getInv();
	pL_Thigh1->Local = temp * boneL_Thigh1;

	//L_Knee2
	vout = start * boneL_Knee2;
	pL_Knee2->setStartPos( vout );

	temp = boneL_Thigh1.getInv();
	pL_Knee2->Local = temp * boneL_Knee2;

	//L_Ankle1
	vout = start * boneL_Ankle1;
	pL_Ankle1->setStartPos( vout );

	temp = boneL_Knee2.getInv();
	pL_Ankle1->Local = temp * boneL_Ankle1;

	//L_Ball
	vout = start * boneL_Ball;
	pL_Ball->setStartPos( vout );

	temp = boneL_Ankle1.getInv();
	pL_Ball->Local = temp * boneL_Ball;

	//R_Thigh
	vout = start * boneR_Thigh;
	pR_Thigh->setStartPos( vout );

	temp = boneSpine.getInv();
	pR_Thigh->Local = temp * boneR_Thigh;

	//R_Knee
	vout = start * boneR_Knee;
	pR_Knee->setStartPos( vout );

	temp = boneR_Thigh.getInv();
	pR_Knee->Local = temp * boneR_Knee;

	//R_Ankle
	vout = start * boneR_Ankle;
	pR_Ankle->setStartPos( vout );

	temp = boneR_Knee.getInv();
	pR_Ankle->Local = temp * boneR_Ankle;

	//R_Ball
	vout = start * boneR_Ball;
	pR_Ball->setStartPos( vout );

	temp = boneR_Ankle.getInv();
	pR_Ball->Local = temp * boneR_Ball;
	
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

	//     Node Name: Root
	pTmp->pBone[0].T = Vect( 0.037563f, 37.460987f, 2.230549f );
	pTmp->pBone[0].Q = Quat( ROT_XYZ, -1.570796f, -1.570796f, 0.000000f );
	pTmp->pBone[0].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Pelvis
	pTmp->pBone[1].T = Vect( -0.586211f, -0.068035f, -0.068577f );
	pTmp->pBone[1].Q = Quat( ROT_XYZ, -2.398737f, -1.519119f, -2.465605f );
	pTmp->pBone[1].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Spine
	pTmp->pBone[2].T = Vect( 3.786006f, -0.003600f, 0.000005f );
	pTmp->pBone[2].Q = Quat( ROT_XYZ, -0.000004f, -0.000002f, -0.094916f );
	pTmp->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Spine1
	pTmp->pBone[3].T = Vect( 4.543316f, -0.003600f, -0.000000f );
	pTmp->pBone[3].Q = Quat( ROT_XYZ, 0.074040f, -0.017783f, -0.104661f );
	pTmp->pBone[3].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Spine2
	pTmp->pBone[4].T = Vect( 4.544050f, -0.003600f, 0.000000f );
	pTmp->pBone[4].Q = Quat( ROT_XYZ, 0.073508f, 0.017841f, 0.083882f );
	pTmp->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Spine3
	pTmp->pBone[5].T = Vect( 4.543960f, -0.004399f, 0.000000f );
	pTmp->pBone[5].Q = Quat( ROT_XYZ, 0.074468f, 0.013752f, 0.045952f );
	pTmp->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Neck
	pTmp->pBone[6].T = Vect( 5.536252f, -0.002882f, 0.000000f );
	pTmp->pBone[6].Q = Quat( ROT_XYZ, -0.113618f, 0.054242f, 0.502790f );
	pTmp->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: Head
	pTmp->pBone[7].T = Vect( 3.953896f, 0.000001f, 0.000000f );
	pTmp->pBone[7].Q = Quat( ROT_XYZ, -0.031537f, -0.000028f, -0.305469f );
	pTmp->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_eye_joint1
	pTmp->pBone[8].T = Vect( 4.220695f, 1.406053f, 1.394846f );
	pTmp->pBone[8].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: R_eye_joint
	pTmp->pBone[9].T = Vect( 4.296264f, 1.333193f, -1.066092f );
	pTmp->pBone[9].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp->pBone[9].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_eyeBall_joint2
	pTmp->pBone[10].T = Vect( 4.482600f, 3.247940f, 1.274591f );
	pTmp->pBone[10].Q = Quat( ROT_XYZ, 0.080872f, -0.000000f, 0.000600f );
	pTmp->pBone[10].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: R_eyeBall_joint
	pTmp->pBone[11].T = Vect( 4.577010f, 3.107063f, -1.207679f );
	pTmp->pBone[11].Q = Quat( ROT_XYZ, 0.032624f, 0.007158f, 0.033678f );
	pTmp->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_Clavicle
	pTmp->pBone[12].T = Vect( -0.307962f, -0.770595f, 1.223297f );
	pTmp->pBone[12].Q = Quat( ROT_XYZ, -0.000015f, -1.401522f, 2.726524f );
	pTmp->pBone[12].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_UpperArm
	pTmp->pBone[13].T = Vect( 6.704924f, 0.887522f, -0.127745f );
	pTmp->pBone[13].Q = Quat( ROT_XYZ, 0.296404f, 0.965520f, 0.963492f );
	pTmp->pBone[13].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_Forearm
	pTmp->pBone[14].T = Vect( 13.142184f, -0.000000f, -0.000000f );
	pTmp->pBone[14].Q = Quat( ROT_XYZ, 0.578096f, 0.278216f, -0.204345f );
	pTmp->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Hand
	pTmp->pBone[15].T = Vect( 10.825552f, 0.000001f, 0.000001f );
	pTmp->pBone[15].Q = Quat( ROT_XYZ, -1.294576f, 0.175747f, 0.053448f );
	pTmp->pBone[15].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Thumb1
	pTmp->pBone[16].T = Vect( 1.625108f, 0.626630f, -1.678760f );
	pTmp->pBone[16].Q = Quat( ROT_XYZ, 2.066355f, 0.502461f, 0.321803f );
	pTmp->pBone[16].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Thumb2
	pTmp->pBone[17].T = Vect( 1.140432f, 0.000003f, -0.000002f );
	pTmp->pBone[17].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.311601f );
	pTmp->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Thumb3
	pTmp->pBone[18].T = Vect( 1.382469f, -0.000001f, 0.000004f );
	pTmp->pBone[18].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.271129f );
	pTmp->pBone[18].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Index1
	pTmp->pBone[19].T = Vect( 4.348744f, 0.016253f, -1.561334f );
	pTmp->pBone[19].Q = Quat( ROT_XYZ, 0.210165f, 0.012737f, 0.081211f );
	pTmp->pBone[19].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Index2
	pTmp->pBone[20].T = Vect( 1.473696f, 0.000000f, 0.000001f );
	pTmp->pBone[20].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.291144f );
	pTmp->pBone[20].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Index3
	pTmp->pBone[21].T = Vect( 1.062845f, 0.000000f, 0.000002f );
	pTmp->pBone[21].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.000000f );
	pTmp->pBone[21].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Middle1
	pTmp->pBone[22].T = Vect( 4.359987f, -0.000295f, -0.366860f );
	pTmp->pBone[22].Q = Quat( ROT_XYZ, 0.035253f, 0.015204f, 0.286301f );
	pTmp->pBone[22].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Middle2
	pTmp->pBone[23].T = Vect( 1.529124f, 0.000001f, -0.000000f );
	pTmp->pBone[23].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.300153f );
	pTmp->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Middle3
	pTmp->pBone[24].T = Vect( 1.529128f, 0.000001f, 0.000001f );
	pTmp->pBone[24].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.066429f );
	pTmp->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Ring1
	pTmp->pBone[25].T = Vect( 4.295015f, -0.094743f, 0.806466f );
	pTmp->pBone[25].Q = Quat( ROT_XYZ, -0.156824f, -0.024457f, 0.359100f );
	pTmp->pBone[25].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Ring2
	pTmp->pBone[26].T = Vect( 1.403335f, 0.000001f, -0.000000f );
	pTmp->pBone[26].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.446212f );
	pTmp->pBone[26].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Ring3
	pTmp->pBone[27].T = Vect( 1.388261f, 0.000000f, -0.000000f );
	pTmp->pBone[27].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.157449f );
	pTmp->pBone[27].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Pinky1
	pTmp->pBone[28].T = Vect( 3.972678f, 0.223488f, 1.742838f );
	pTmp->pBone[28].Q = Quat( ROT_XYZ, -0.360488f, -0.014302f, 0.391946f );
	pTmp->pBone[28].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Pinky2
	pTmp->pBone[29].T = Vect( 1.131793f, -0.000002f, -0.000000f );
	pTmp->pBone[29].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.000000f );
	pTmp->pBone[29].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Pinky3
	pTmp->pBone[30].T = Vect( 0.858955f, 0.000001f, 0.000001f );
	pTmp->pBone[30].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.067550f );
	pTmp->pBone[30].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: R_Clavicle
	pTmp->pBone[31].T = Vect( -0.307962f, -0.770588f, -1.223302f );
	pTmp->pBone[31].Q = Quat( ROT_XYZ, -0.000015f, 1.401520f, 2.726494f );
	pTmp->pBone[31].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_UpperArm
	pTmp->pBone[32].T = Vect( 6.882456f, -1.112103f, 0.033368f );
	pTmp->pBone[32].Q = Quat( ROT_XYZ, 0.780354f, -0.750769f, -0.946529f );
	pTmp->pBone[32].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Forearm
	pTmp->pBone[33].T = Vect( 13.142184f, 0.000001f, 0.000003f );
	pTmp->pBone[33].Q = Quat( ROT_XYZ, -0.483913f, -0.430580f, -0.867147f );
	pTmp->pBone[33].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Hand
	pTmp->pBone[34].T = Vect( 10.825553f, 0.000000f, -0.000001f );
	pTmp->pBone[34].Q = Quat( ROT_XYZ, 1.225525f, 0.238023f, -0.299857f );
	pTmp->pBone[34].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Thumb1
	pTmp->pBone[35].T = Vect( 1.625108f, 0.626631f, 1.678760f );
	pTmp->pBone[35].Q = Quat( ROT_XYZ, -2.240891f, -0.835203f, 0.598326f );
	pTmp->pBone[35].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Thumb2
	pTmp->pBone[36].T = Vect( 1.140432f, -0.000001f, 0.000001f );
	pTmp->pBone[36].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.559595f );
	pTmp->pBone[36].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Thumb3
	pTmp->pBone[37].T = Vect( 1.382469f, 0.000000f, -0.000003f );
	pTmp->pBone[37].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.019594f );
	pTmp->pBone[37].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Index1
	pTmp->pBone[38].T = Vect( 4.348744f, 0.016252f, 1.561333f );
	pTmp->pBone[38].Q = Quat( ROT_XYZ, -0.205749f, -0.064492f, -0.074559f );
	pTmp->pBone[38].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Index2
	pTmp->pBone[39].T = Vect( 1.473695f, -0.000003f, 0.000000f );
	pTmp->pBone[39].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.319365f );
	pTmp->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Index3
	pTmp->pBone[40].T = Vect( 1.062847f, -0.000000f, -0.000000f );
	pTmp->pBone[40].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.230576f );
	pTmp->pBone[40].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Middle1
	pTmp->pBone[41].T = Vect( 4.359987f, -0.000294f, 0.366859f );
	pTmp->pBone[41].Q = Quat( ROT_XYZ, -0.018978f, -0.038017f, -0.018609f );
	pTmp->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Middle2
	pTmp->pBone[42].T = Vect( 1.529123f, -0.000003f, 0.000000f );
	pTmp->pBone[42].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.324054f );
	pTmp->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Middle3
	pTmp->pBone[43].T = Vect( 1.529128f, -0.000002f, -0.000000f );
	pTmp->pBone[43].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.062832f );
	pTmp->pBone[43].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Ring1
	pTmp->pBone[44].T = Vect( 4.295013f, -0.094741f, -0.806466f );
	pTmp->pBone[44].Q = Quat( ROT_XYZ, 0.171570f, 0.133906f, 0.190960f );
	pTmp->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Ring2
	pTmp->pBone[45].T = Vect( 1.403335f, 0.000004f, 0.000001f );
	pTmp->pBone[45].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.476269f );
	pTmp->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Ring3
	pTmp->pBone[46].T = Vect( 1.388261f, -0.000000f, 0.000000f );
	pTmp->pBone[46].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.227678f );
	pTmp->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Pinky1
	pTmp->pBone[47].T = Vect( 3.972679f, 0.223487f, -1.742838f );
	pTmp->pBone[47].Q = Quat( ROT_XYZ, 0.425628f, 0.116269f, 0.428874f );
	pTmp->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Pinky2
	pTmp->pBone[48].T = Vect( 1.131793f, -0.000005f, -0.000000f );
	pTmp->pBone[48].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.381672f );
	pTmp->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Pinky3
	pTmp->pBone[49].T = Vect( 0.858953f, -0.000003f, 0.000000f );
	pTmp->pBone[49].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.100513f );
	pTmp->pBone[49].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	//     Node Name: L_Thigh1
	pTmp->pBone[50].T = Vect( -3.769306f, -0.355238f, 3.495145f );
	pTmp->pBone[50].Q = Quat( ROT_XYZ, 2.909750f, -0.207141f, 2.612290f );
	pTmp->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Knee2
	pTmp->pBone[51].T = Vect( 18.257195f, -0.000001f, 0.000001f );
	pTmp->pBone[51].Q = Quat( ROT_XYZ, 0.031664f, 0.018035f, -0.450307f );
	pTmp->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Ankle1
	pTmp->pBone[52].T = Vect( 15.428004f, -0.000000f, 0.000000f );
	pTmp->pBone[52].Q = Quat( ROT_XYZ, -0.075492f, -0.076665f, 0.035528f );
	pTmp->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: L_Ball
	pTmp->pBone[53].T = Vect( 5.250221f, 6.273849f, -0.000001f );
	pTmp->pBone[53].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp->pBone[53].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Thigh
	pTmp->pBone[54].T = Vect( -3.769306f, -0.355218f, -3.495146f );
	pTmp->pBone[54].Q = Quat( ROT_XYZ, -2.999542f, 0.004655f, -2.774203f );
	pTmp->pBone[54].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Knee
	pTmp->pBone[55].T = Vect( 18.257195f, -0.000001f, -0.000001f );
	pTmp->pBone[55].Q = Quat( ROT_XYZ, -0.067001f, -0.003982f, -0.193773f );
	pTmp->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Ankle
	pTmp->pBone[56].T = Vect( 15.428004f, 0.000000f, 0.000001f );
	pTmp->pBone[56].Q = Quat( ROT_XYZ, 0.076040f, 0.052334f, 0.421714f );
	pTmp->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );

	//     Node Name: R_Ball
	pTmp->pBone[57].T = Vect( 5.250221f, 6.273849f, -0.000000f );
	pTmp->pBone[57].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp->pBone[57].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
   // --------  Frame 10  -----------------------------
   
   Frame_Bucket *pTmp2 = new Frame_Bucket();
	pTmp2->prevBucket = pTmp;
	pTmp2->nextBucket = 0;
	pTmp2->KeyTime = 10 * Time(TIME_NTSC_30_FRAME);
	pTmp2->pBone = new Bone[NUM_BONES];

	pTmp->nextBucket = pTmp2;

	//     Node Name: Root
	pTmp2->pBone[0].T = Vect( 0.037563f, 37.460987f, 2.230549f );
	pTmp2->pBone[0].Q = Quat( ROT_XYZ, -1.570796f, -1.570796f, 0.000000f );
	pTmp2->pBone[0].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Pelvis
	pTmp2->pBone[1].T = Vect( -0.657043f, -2.258767f, 1.005161f );
	pTmp2->pBone[1].Q = Quat( ROT_XYZ, -0.450216f, -1.531815f, 1.831038f );
	pTmp2->pBone[1].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine
	pTmp2->pBone[2].T = Vect( 3.786006f, -0.003600f, 0.000005f );
	pTmp2->pBone[2].Q = Quat( ROT_XYZ, -0.000004f, -0.000002f, -0.094916f );
	pTmp2->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine1
	pTmp2->pBone[3].T = Vect( 4.543316f, -0.003600f, -0.000000f );
	pTmp2->pBone[3].Q = Quat( ROT_XYZ, 0.011348f, -0.068279f, -0.107705f );
	pTmp2->pBone[3].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine2
	pTmp2->pBone[4].T = Vect( 4.544050f, -0.003600f, 0.000000f );
	pTmp2->pBone[4].Q = Quat( ROT_XYZ, -0.006398f, -0.030488f, 0.082263f );
	pTmp2->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine3
	pTmp2->pBone[5].T = Vect( 4.543960f, -0.004399f, 0.000000f );
	pTmp2->pBone[5].Q = Quat( ROT_XYZ, -0.008004f, -0.030073f, 0.044521f );
	pTmp2->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Neck
	pTmp2->pBone[6].T = Vect( 5.536252f, -0.002882f, 0.000000f );
	pTmp2->pBone[6].Q = Quat( ROT_XYZ, -0.070141f, 0.036784f, 0.514390f );
	pTmp2->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Head
	pTmp2->pBone[7].T = Vect( 3.953896f, 0.000001f, 0.000000f );
	pTmp2->pBone[7].Q = Quat( ROT_XYZ, 0.086222f, 0.084231f, -0.280738f );
	pTmp2->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eye_joint1
	pTmp2->pBone[8].T = Vect( 4.220695f, 1.406053f, 1.394846f );
	pTmp2->pBone[8].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp2->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eye_joint
	pTmp2->pBone[9].T = Vect( 4.296264f, 1.333193f, -1.066092f );
	pTmp2->pBone[9].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp2->pBone[9].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eyeBall_joint2
	pTmp2->pBone[10].T = Vect( 4.482600f, 3.247940f, 1.274591f );
	pTmp2->pBone[10].Q = Quat( ROT_XYZ, 0.009866f, 0.000000f, 0.031081f );
	pTmp2->pBone[10].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eyeBall_joint
	pTmp2->pBone[11].T = Vect( 4.577010f, 3.107063f, -1.207679f );
	pTmp2->pBone[11].Q = Quat( ROT_XYZ, 0.009866f, 0.000000f, 0.031081f );
	pTmp2->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Clavicle
	pTmp2->pBone[12].T = Vect( -0.307962f, -0.770595f, 1.223297f );
	pTmp2->pBone[12].Q = Quat( ROT_XYZ, -0.000015f, -1.401522f, 2.726524f );
	pTmp2->pBone[12].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_UpperArm
	pTmp2->pBone[13].T = Vect( 6.777908f, 0.508422f, -0.134154f );
	pTmp2->pBone[13].Q = Quat( ROT_XYZ, -0.640564f, 0.927432f, -0.495405f );
	pTmp2->pBone[13].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Forearm
	pTmp2->pBone[14].T = Vect( 13.142184f, -0.000000f, -0.000000f );
	pTmp2->pBone[14].Q = Quat( ROT_XYZ, 0.527416f, 0.368242f, -0.356079f );
	pTmp2->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Hand
	pTmp2->pBone[15].T = Vect( 10.825552f, 0.000001f, 0.000001f );
	pTmp2->pBone[15].Q = Quat( ROT_XYZ, -1.280598f, -0.080585f, -0.072611f );
	pTmp2->pBone[15].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb1
	pTmp2->pBone[16].T = Vect( 1.625108f, 0.626630f, -1.678760f );
	pTmp2->pBone[16].Q = Quat( ROT_XYZ, 2.108267f, 0.611212f, 0.397499f );
	pTmp2->pBone[16].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb2
	pTmp2->pBone[17].T = Vect( 1.140432f, 0.000003f, -0.000002f );
	pTmp2->pBone[17].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.311601f );
	pTmp2->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb3
	pTmp2->pBone[18].T = Vect( 1.382469f, -0.000001f, 0.000004f );
	pTmp2->pBone[18].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, -0.058013f );
	pTmp2->pBone[18].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index1
	pTmp2->pBone[19].T = Vect( 4.348744f, 0.016253f, -1.561334f );
	pTmp2->pBone[19].Q = Quat( ROT_XYZ, 0.207647f, 0.059579f, 0.044776f );
	pTmp2->pBone[19].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index2
	pTmp2->pBone[20].T = Vect( 1.473696f, 0.000000f, 0.000001f );
	pTmp2->pBone[20].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.216550f );
	pTmp2->pBone[20].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index3
	pTmp2->pBone[21].T = Vect( 1.062845f, 0.000000f, 0.000002f );
	pTmp2->pBone[21].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.000000f );
	pTmp2->pBone[21].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle1
	pTmp2->pBone[22].T = Vect( 4.359987f, -0.000295f, -0.366860f );
	pTmp2->pBone[22].Q = Quat( ROT_XYZ, 0.030639f, 0.036449f, 0.177817f );
	pTmp2->pBone[22].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle2
	pTmp2->pBone[23].T = Vect( 1.529124f, 0.000001f, -0.000000f );
	pTmp2->pBone[23].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.247712f );
	pTmp2->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle3
	pTmp2->pBone[24].T = Vect( 1.529128f, 0.000001f, 0.000001f );
	pTmp2->pBone[24].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.066429f );
	pTmp2->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring1
	pTmp2->pBone[25].T = Vect( 4.295015f, -0.094743f, 0.806466f );
	pTmp2->pBone[25].Q = Quat( ROT_XYZ, -0.157013f, -0.012633f, 0.295141f );
	pTmp2->pBone[25].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring2
	pTmp2->pBone[26].T = Vect( 1.403335f, 0.000001f, -0.000000f );
	pTmp2->pBone[26].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.446212f );
	pTmp2->pBone[26].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring3
	pTmp2->pBone[27].T = Vect( 1.388261f, 0.000000f, -0.000000f );
	pTmp2->pBone[27].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.157449f );
	pTmp2->pBone[27].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky1
	pTmp2->pBone[28].T = Vect( 3.972678f, 0.223488f, 1.742838f );
	pTmp2->pBone[28].Q = Quat( ROT_XYZ, -0.360488f, -0.014302f, 0.391946f );
	pTmp2->pBone[28].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky2
	pTmp2->pBone[29].T = Vect( 1.131793f, -0.000002f, -0.000000f );
	pTmp2->pBone[29].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.000000f );
	pTmp2->pBone[29].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky3
	pTmp2->pBone[30].T = Vect( 0.858955f, 0.000001f, 0.000001f );
	pTmp2->pBone[30].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.067550f );
	pTmp2->pBone[30].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Clavicle
	pTmp2->pBone[31].T = Vect( -0.307962f, -0.770588f, -1.223302f );
	pTmp2->pBone[31].Q = Quat( ROT_XYZ, -0.000015f, 1.401520f, 2.726494f );
	pTmp2->pBone[31].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_UpperArm
	pTmp2->pBone[32].T = Vect( 6.886871f, -0.749441f, 0.028041f );
	pTmp2->pBone[32].Q = Quat( ROT_XYZ, 0.397641f, -1.110404f, -0.187130f );
	pTmp2->pBone[32].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Forearm
	pTmp2->pBone[33].T = Vect( 13.142184f, 0.000001f, 0.000003f );
	pTmp2->pBone[33].Q = Quat( ROT_XYZ, -0.934344f, -0.435032f, -0.548756f );
	pTmp2->pBone[33].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Hand
	pTmp2->pBone[34].T = Vect( 10.825553f, 0.000000f, -0.000001f );
	pTmp2->pBone[34].Q = Quat( ROT_XYZ, 1.274183f, -0.047257f, -0.088901f );
	pTmp2->pBone[34].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb1
	pTmp2->pBone[35].T = Vect( 1.625108f, 0.626631f, 1.678760f );
	pTmp2->pBone[35].Q = Quat( ROT_XYZ, -2.276692f, -0.561493f, 0.605146f );
	pTmp2->pBone[35].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb2
	pTmp2->pBone[36].T = Vect( 1.140432f, -0.000001f, 0.000001f );
	pTmp2->pBone[36].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.559595f );
	pTmp2->pBone[36].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb3
	pTmp2->pBone[37].T = Vect( 1.382469f, 0.000000f, -0.000003f );
	pTmp2->pBone[37].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.127924f );
	pTmp2->pBone[37].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index1
	pTmp2->pBone[38].T = Vect( 4.348744f, 0.016252f, 1.561333f );
	pTmp2->pBone[38].Q = Quat( ROT_XYZ, -0.210541f, 0.002639f, 0.143040f );
	pTmp2->pBone[38].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index2
	pTmp2->pBone[39].T = Vect( 1.473695f, -0.000003f, 0.000000f );
	pTmp2->pBone[39].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.319365f );
	pTmp2->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index3
	pTmp2->pBone[40].T = Vect( 1.062847f, -0.000000f, -0.000000f );
	pTmp2->pBone[40].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.230576f );
	pTmp2->pBone[40].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle1
	pTmp2->pBone[41].T = Vect( 4.359987f, -0.000294f, 0.366859f );
	pTmp2->pBone[41].Q = Quat( ROT_XYZ, -0.021988f, 0.011172f, 0.083858f );
	pTmp2->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle2
	pTmp2->pBone[42].T = Vect( 1.529123f, -0.000003f, 0.000000f );
	pTmp2->pBone[42].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.324054f );
	pTmp2->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle3
	pTmp2->pBone[43].T = Vect( 1.529128f, -0.000002f, -0.000000f );
	pTmp2->pBone[43].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.062832f );
	pTmp2->pBone[43].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring1
	pTmp2->pBone[44].T = Vect( 4.295013f, -0.094741f, -0.806466f );
	pTmp2->pBone[44].Q = Quat( ROT_XYZ, 0.179134f, 0.079016f, 0.265803f );
	pTmp2->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring2
	pTmp2->pBone[45].T = Vect( 1.403335f, 0.000004f, 0.000001f );
	pTmp2->pBone[45].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.476269f );
	pTmp2->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring3
	pTmp2->pBone[46].T = Vect( 1.388261f, -0.000000f, 0.000000f );
	pTmp2->pBone[46].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.227678f );
	pTmp2->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky1
	pTmp2->pBone[47].T = Vect( 3.972679f, 0.223487f, -1.742838f );
	pTmp2->pBone[47].Q = Quat( ROT_XYZ, 0.424100f, 0.041767f, 0.395211f );
	pTmp2->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky2
	pTmp2->pBone[48].T = Vect( 1.131793f, -0.000005f, -0.000000f );
	pTmp2->pBone[48].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.381672f );
	pTmp2->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky3
	pTmp2->pBone[49].T = Vect( 0.858953f, -0.000003f, 0.000000f );
	pTmp2->pBone[49].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.100513f );
	pTmp2->pBone[49].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thigh1
	pTmp2->pBone[50].T = Vect( -3.769306f, -0.355238f, 3.495145f );
	pTmp2->pBone[50].Q = Quat( ROT_XYZ, 2.933983f, -0.007531f, 2.975062f );
	pTmp2->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Knee2
	pTmp2->pBone[51].T = Vect( 18.257195f, -0.000001f, 0.000001f );
	pTmp2->pBone[51].Q = Quat( ROT_XYZ, 0.010971f, 0.055854f, -0.622830f );
	pTmp2->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ankle1
	pTmp2->pBone[52].T = Vect( 15.428004f, -0.000000f, 0.000000f );
	pTmp2->pBone[52].Q = Quat( ROT_XYZ, -0.077800f, -0.040699f, 0.330191f );
	pTmp2->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ball
	pTmp2->pBone[53].T = Vect( 5.250221f, 6.273849f, -0.000001f );
	pTmp2->pBone[53].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp2->pBone[53].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thigh
	pTmp2->pBone[54].T = Vect( -3.769306f, -0.355218f, -3.495146f );
	pTmp2->pBone[54].Q = Quat( ROT_XYZ, -2.926619f, 0.148355f, 2.739681f );
	pTmp2->pBone[54].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Knee
	pTmp2->pBone[55].T = Vect( 18.257195f, -0.000001f, -0.000001f );
	pTmp2->pBone[55].Q = Quat( ROT_XYZ, -0.115949f, -0.139204f, -1.092828f );
	pTmp2->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ankle
	pTmp2->pBone[56].T = Vect( 15.428004f, 0.000000f, 0.000001f );
	pTmp2->pBone[56].Q = Quat( ROT_XYZ, 0.072928f, 0.041185f, -0.000560f );
	pTmp2->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ball
	pTmp2->pBone[57].T = Vect( 5.250221f, 6.273849f, -0.000000f );
	pTmp2->pBone[57].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp2->pBone[57].S = Vect( 1.000000f, 1.000000f, 1.000000f );
  
  
   // --------  Frame 20 ----------------------

   Frame_Bucket *pTmp3 = new Frame_Bucket();
	pTmp3->prevBucket = pTmp2;
	pTmp3->nextBucket = 0;
	pTmp3->KeyTime = 20 * Time(TIME_NTSC_30_FRAME);
	pTmp3->pBone = new Bone[NUM_BONES];

	pTmp2->nextBucket = pTmp3;

	//     Node Name: Root
	pTmp3->pBone[0].T = Vect( 0.037563f, 37.460987f, 2.230549f );
	pTmp3->pBone[0].Q = Quat( ROT_XYZ, -1.570796f, -1.570796f, 0.000000f );
	pTmp3->pBone[0].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Pelvis
	pTmp3->pBone[1].T = Vect( -0.878887f, -1.023536f, -0.419941f );
	pTmp3->pBone[1].Q = Quat( ROT_XYZ, -0.693396f, -1.484913f, 2.137719f );
	pTmp3->pBone[1].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine
	pTmp3->pBone[2].T = Vect( 3.786006f, -0.003600f, 0.000005f );
	pTmp3->pBone[2].Q = Quat( ROT_XYZ, -0.000004f, -0.000002f, -0.094916f );
	pTmp3->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine1
	pTmp3->pBone[3].T = Vect( 4.543316f, -0.003600f, -0.000000f );
	pTmp3->pBone[3].Q = Quat( ROT_XYZ, -0.070676f, -0.069722f, -0.110663f );
	pTmp3->pBone[3].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine2
	pTmp3->pBone[4].T = Vect( 4.544050f, -0.003600f, 0.000000f );
	pTmp3->pBone[4].Q = Quat( ROT_XYZ, -0.096190f, 0.001515f, 0.069819f );
	pTmp3->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine3
	pTmp3->pBone[5].T = Vect( 4.543960f, -0.004399f, 0.000000f );
	pTmp3->pBone[5].Q = Quat( ROT_XYZ, -0.095703f, 0.007268f, 0.031245f );
	pTmp3->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Neck
	pTmp3->pBone[6].T = Vect( 5.536252f, -0.002882f, 0.000000f );
	pTmp3->pBone[6].Q = Quat( ROT_XYZ, -0.074513f, -0.008635f, 0.495780f );
	pTmp3->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Head
	pTmp3->pBone[7].T = Vect( 3.953896f, 0.000001f, 0.000000f );
	pTmp3->pBone[7].Q = Quat( ROT_XYZ, 0.248060f, -0.007023f, -0.278643f );
	pTmp3->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eye_joint1
	pTmp3->pBone[8].T = Vect( 4.220695f, 1.406053f, 1.394846f );
	pTmp3->pBone[8].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp3->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eye_joint
	pTmp3->pBone[9].T = Vect( 4.296264f, 1.333193f, -1.066092f );
	pTmp3->pBone[9].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp3->pBone[9].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eyeBall_joint2
	pTmp3->pBone[10].T = Vect( 4.482600f, 3.247940f, 1.274591f );
	pTmp3->pBone[10].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.000000f );
	pTmp3->pBone[10].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eyeBall_joint
	pTmp3->pBone[11].T = Vect( 4.577010f, 3.107063f, -1.207679f );
	pTmp3->pBone[11].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.000000f );
	pTmp3->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Clavicle
	pTmp3->pBone[12].T = Vect( -0.307962f, -0.770595f, 1.223297f );
	pTmp3->pBone[12].Q = Quat( ROT_XYZ, -0.000015f, -1.401522f, 2.726524f );
	pTmp3->pBone[12].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_UpperArm
	pTmp3->pBone[13].T = Vect( 6.779107f, 0.421175f, 0.230994f );
	pTmp3->pBone[13].Q = Quat( ROT_XYZ, -0.734685f, 0.716082f, -0.476719f );
	pTmp3->pBone[13].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Forearm
	pTmp3->pBone[14].T = Vect( 13.142184f, -0.000000f, -0.000000f );
	pTmp3->pBone[14].Q = Quat( ROT_XYZ, 0.761200f, 0.581310f, -0.640050f );
	pTmp3->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Hand
	pTmp3->pBone[15].T = Vect( 10.825552f, 0.000001f, 0.000001f );
	pTmp3->pBone[15].Q = Quat( ROT_XYZ, -1.285034f, -0.290721f, -0.165810f );
	pTmp3->pBone[15].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb1
	pTmp3->pBone[16].T = Vect( 1.625108f, 0.626630f, -1.678760f );
	pTmp3->pBone[16].Q = Quat( ROT_XYZ, 2.128739f, 0.664329f, 0.434471f );
	pTmp3->pBone[16].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb2
	pTmp3->pBone[17].T = Vect( 1.140432f, 0.000003f, -0.000002f );
	pTmp3->pBone[17].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.311601f );
	pTmp3->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb3
	pTmp3->pBone[18].T = Vect( 1.382469f, -0.000001f, 0.000004f );
	pTmp3->pBone[18].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, -0.218777f );
	pTmp3->pBone[18].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index1
	pTmp3->pBone[19].T = Vect( 4.348744f, 0.016253f, -1.561334f );
	pTmp3->pBone[19].Q = Quat( ROT_XYZ, 0.205644f, 0.082459f, 0.026979f );
	pTmp3->pBone[19].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index2
	pTmp3->pBone[20].T = Vect( 1.473696f, 0.000000f, 0.000001f );
	pTmp3->pBone[20].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.180115f );
	pTmp3->pBone[20].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index3
	pTmp3->pBone[21].T = Vect( 1.062845f, 0.000000f, 0.000002f );
	pTmp3->pBone[21].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.000000f );
	pTmp3->pBone[21].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle1
	pTmp3->pBone[22].T = Vect( 4.359987f, -0.000295f, -0.366860f );
	pTmp3->pBone[22].Q = Quat( ROT_XYZ, 0.026969f, 0.053344f, 0.124830f );
	pTmp3->pBone[22].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle2
	pTmp3->pBone[23].T = Vect( 1.529124f, 0.000001f, -0.000000f );
	pTmp3->pBone[23].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.222098f );
	pTmp3->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle3
	pTmp3->pBone[24].T = Vect( 1.529128f, 0.000001f, 0.000001f );
	pTmp3->pBone[24].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.066429f );
	pTmp3->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring1
	pTmp3->pBone[25].T = Vect( 4.295015f, -0.094743f, 0.806466f );
	pTmp3->pBone[25].Q = Quat( ROT_XYZ, -0.157163f, -0.003229f, 0.263901f );
	pTmp3->pBone[25].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring2
	pTmp3->pBone[26].T = Vect( 1.403335f, 0.000001f, -0.000000f );
	pTmp3->pBone[26].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.446212f );
	pTmp3->pBone[26].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring3
	pTmp3->pBone[27].T = Vect( 1.388261f, 0.000000f, -0.000000f );
	pTmp3->pBone[27].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.157449f );
	pTmp3->pBone[27].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky1
	pTmp3->pBone[28].T = Vect( 3.972678f, 0.223488f, 1.742838f );
	pTmp3->pBone[28].Q = Quat( ROT_XYZ, -0.360488f, -0.014302f, 0.391946f );
	pTmp3->pBone[28].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky2
	pTmp3->pBone[29].T = Vect( 1.131793f, -0.000002f, -0.000000f );
	pTmp3->pBone[29].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.000000f );
	pTmp3->pBone[29].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky3
	pTmp3->pBone[30].T = Vect( 0.858955f, 0.000001f, 0.000001f );
	pTmp3->pBone[30].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.067550f );
	pTmp3->pBone[30].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Clavicle
	pTmp3->pBone[31].T = Vect( -0.307962f, -0.770588f, -1.223302f );
	pTmp3->pBone[31].Q = Quat( ROT_XYZ, -0.000015f, 1.401520f, 2.726494f );
	pTmp3->pBone[31].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_UpperArm
	pTmp3->pBone[32].T = Vect( 6.885871f, -0.609074f, 0.363912f );
	pTmp3->pBone[32].Q = Quat( ROT_XYZ, -0.158624f, -0.938988f, 0.609366f );
	pTmp3->pBone[32].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Forearm
	pTmp3->pBone[33].T = Vect( 13.142184f, 0.000001f, 0.000003f );
	pTmp3->pBone[33].Q = Quat( ROT_XYZ, -0.654899f, -0.302201f, -0.539906f );
	pTmp3->pBone[33].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Hand
	pTmp3->pBone[34].T = Vect( 10.825553f, 0.000000f, -0.000001f );
	pTmp3->pBone[34].Q = Quat( ROT_XYZ, 1.297949f, -0.262740f, 0.074988f );
	pTmp3->pBone[34].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb1
	pTmp3->pBone[35].T = Vect( 1.625108f, 0.626631f, 1.678760f );
	pTmp3->pBone[35].Q = Quat( ROT_XYZ, -2.297680f, -0.401031f, 0.611793f );
	pTmp3->pBone[35].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb2
	pTmp3->pBone[36].T = Vect( 1.140432f, -0.000001f, 0.000001f );
	pTmp3->pBone[36].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.559595f );
	pTmp3->pBone[36].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb3
	pTmp3->pBone[37].T = Vect( 1.382469f, 0.000000f, -0.000003f );
	pTmp3->pBone[37].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.214407f );
	pTmp3->pBone[37].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index1
	pTmp3->pBone[38].T = Vect( 4.348744f, 0.016252f, 1.561333f );
	pTmp3->pBone[38].Q = Quat( ROT_XYZ, -0.215211f, 0.041994f, 0.270608f );
	pTmp3->pBone[38].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index2
	pTmp3->pBone[39].T = Vect( 1.473695f, -0.000003f, 0.000000f );
	pTmp3->pBone[39].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.319365f );
	pTmp3->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index3
	pTmp3->pBone[40].T = Vect( 1.062847f, -0.000000f, -0.000000f );
	pTmp3->pBone[40].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.230576f );
	pTmp3->pBone[40].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle1
	pTmp3->pBone[41].T = Vect( 4.359987f, -0.000294f, 0.366859f );
	pTmp3->pBone[41].Q = Quat( ROT_XYZ, -0.024921f, 0.040009f, 0.143929f );
	pTmp3->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle2
	pTmp3->pBone[42].T = Vect( 1.529123f, -0.000003f, 0.000000f );
	pTmp3->pBone[42].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.324054f );
	pTmp3->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle3
	pTmp3->pBone[43].T = Vect( 1.529128f, -0.000002f, -0.000000f );
	pTmp3->pBone[43].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.062832f );
	pTmp3->pBone[43].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring1
	pTmp3->pBone[44].T = Vect( 4.295013f, -0.094741f, -0.806466f );
	pTmp3->pBone[44].Q = Quat( ROT_XYZ, 0.186505f, 0.046837f, 0.309680f );
	pTmp3->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring2
	pTmp3->pBone[45].T = Vect( 1.403335f, 0.000004f, 0.000001f );
	pTmp3->pBone[45].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.476269f );
	pTmp3->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring3
	pTmp3->pBone[46].T = Vect( 1.388261f, -0.000000f, 0.000000f );
	pTmp3->pBone[46].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.227678f );
	pTmp3->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky1
	pTmp3->pBone[47].T = Vect( 3.972679f, 0.223487f, -1.742838f );
	pTmp3->pBone[47].Q = Quat( ROT_XYZ, 0.422611f, -0.001910f, 0.375476f );
	pTmp3->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky2
	pTmp3->pBone[48].T = Vect( 1.131793f, -0.000005f, -0.000000f );
	pTmp3->pBone[48].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.381672f );
	pTmp3->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky3
	pTmp3->pBone[49].T = Vect( 0.858953f, -0.000003f, 0.000000f );
	pTmp3->pBone[49].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.100513f );
	pTmp3->pBone[49].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thigh1
	pTmp3->pBone[50].T = Vect( -3.769306f, -0.355238f, 3.495145f );
	pTmp3->pBone[50].Q = Quat( ROT_XYZ, 2.942463f, -0.012457f, -2.875535f );
	pTmp3->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Knee2
	pTmp3->pBone[51].T = Vect( 18.257195f, -0.000001f, 0.000001f );
	pTmp3->pBone[51].Q = Quat( ROT_XYZ, 0.186838f, 0.001071f, -0.531495f );
	pTmp3->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ankle1
	pTmp3->pBone[52].T = Vect( 15.428004f, -0.000000f, 0.000000f );
	pTmp3->pBone[52].Q = Quat( ROT_XYZ, -0.066479f, -0.034821f, 0.453749f );
	pTmp3->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ball
	pTmp3->pBone[53].T = Vect( 5.250221f, 6.273849f, -0.000001f );
	pTmp3->pBone[53].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp3->pBone[53].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thigh
	pTmp3->pBone[54].T = Vect( -3.769306f, -0.355218f, -3.495146f );
	pTmp3->pBone[54].Q = Quat( ROT_XYZ, -2.975685f, 0.073541f, 2.547070f );
	pTmp3->pBone[54].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Knee
	pTmp3->pBone[55].T = Vect( 18.257195f, -0.000001f, -0.000001f );
	pTmp3->pBone[55].Q = Quat( ROT_XYZ, -0.152267f, -0.053145f, -0.523999f );
	pTmp3->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ankle
	pTmp3->pBone[56].T = Vect( 15.428004f, 0.000000f, 0.000001f );
	pTmp3->pBone[56].Q = Quat( ROT_XYZ, 0.074026f, -0.016587f, -0.059438f );
	pTmp3->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ball
	pTmp3->pBone[57].T = Vect( 5.250221f, 6.273849f, -0.000000f );
	pTmp3->pBone[57].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp3->pBone[57].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	// --------  Frame 30 ----------------------

   Frame_Bucket *pTmp4 = new Frame_Bucket();
	pTmp4->prevBucket = pTmp3;
	pTmp4->nextBucket = 0;
	pTmp4->KeyTime = 30 * Time(TIME_NTSC_30_FRAME);
	pTmp4->pBone = new Bone[NUM_BONES];

	pTmp3->nextBucket = pTmp4;

	//     Node Name: Root
	pTmp4->pBone[0].T = Vect( 0.037563f, 37.460987f, 2.230549f );
	pTmp4->pBone[0].Q = Quat( ROT_XYZ, -1.570796f, -1.570796f, 0.000000f );
	pTmp4->pBone[0].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Pelvis
	pTmp4->pBone[1].T = Vect( -0.642727f, 1.148975f, 0.187836f );
	pTmp4->pBone[1].Q = Quat( ROT_XYZ, -3.036232f, -1.498275f, -1.801242f );
	pTmp4->pBone[1].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine
	pTmp4->pBone[2].T = Vect( 3.786006f, -0.003600f, 0.000005f );
	pTmp4->pBone[2].Q = Quat( ROT_XYZ, -0.000004f, -0.000002f, -0.094916f );
	pTmp4->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine1
	pTmp4->pBone[3].T = Vect( 4.543316f, -0.003600f, -0.000000f );
	pTmp4->pBone[3].Q = Quat( ROT_XYZ, -0.003307f, 0.057382f, -0.102262f );
	pTmp4->pBone[3].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine2
	pTmp4->pBone[4].T = Vect( 4.544050f, -0.003600f, 0.000000f );
	pTmp4->pBone[4].Q = Quat( ROT_XYZ, -0.005039f, 0.041220f, 0.091350f );
	pTmp4->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine3
	pTmp4->pBone[5].T = Vect( 4.543960f, -0.004399f, 0.000000f );
	pTmp4->pBone[5].Q = Quat( ROT_XYZ, -0.002613f, 0.041424f, 0.053482f );
	pTmp4->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Neck
	pTmp4->pBone[6].T = Vect( 5.536252f, -0.002882f, 0.000000f );
	pTmp4->pBone[6].Q = Quat( ROT_XYZ, -0.113981f, 0.006800f, 0.510952f );
	pTmp4->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Head
	pTmp4->pBone[7].T = Vect( 3.953896f, 0.000001f, 0.000000f );
	pTmp4->pBone[7].Q = Quat( ROT_XYZ, 0.117515f, -0.043790f, -0.311321f );
	pTmp4->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eye_joint1
	pTmp4->pBone[8].T = Vect( 4.220695f, 1.406053f, 1.394846f );
	pTmp4->pBone[8].Q = Quat( ROT_XYZ, 1.607915f, -1.524983f, -1.570796f );
	pTmp4->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eye_joint
	pTmp4->pBone[9].T = Vect( 4.296264f, 1.333193f, -1.066092f );
	pTmp4->pBone[9].Q = Quat( ROT_XYZ, 1.607915f, -1.524983f, -1.570796f );
	pTmp4->pBone[9].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eyeBall_joint2
	pTmp4->pBone[10].T = Vect( 4.482600f, 3.247940f, 1.274591f );
	pTmp4->pBone[10].Q = Quat( ROT_XYZ, -0.041295f, -0.000000f, 0.000000f );
	pTmp4->pBone[10].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eyeBall_joint
	pTmp4->pBone[11].T = Vect( 4.577010f, 3.107063f, -1.207679f );
	pTmp4->pBone[11].Q = Quat( ROT_XYZ, -0.032412f, -0.000000f, 0.000000f );
	pTmp4->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Clavicle
	pTmp4->pBone[12].T = Vect( -0.307962f, -0.770595f, 1.223297f );
	pTmp4->pBone[12].Q = Quat( ROT_XYZ, -0.000015f, -1.401522f, 2.726524f );
	pTmp4->pBone[12].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_UpperArm
	pTmp4->pBone[13].T = Vect( 6.723647f, 0.736880f, 0.223196f );
	pTmp4->pBone[13].Q = Quat( ROT_XYZ, -0.123036f, 1.117573f, 0.253086f );
	pTmp4->pBone[13].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Forearm
	pTmp4->pBone[14].T = Vect( 13.142184f, -0.000000f, -0.000000f );
	pTmp4->pBone[14].Q = Quat( ROT_XYZ, 0.605266f, 0.354132f, -0.288902f );
	pTmp4->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Hand
	pTmp4->pBone[15].T = Vect( 10.825552f, 0.000001f, 0.000001f );
	pTmp4->pBone[15].Q = Quat( ROT_XYZ, -1.624918f, -0.174635f, 0.056133f );
	pTmp4->pBone[15].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb1
	pTmp4->pBone[16].T = Vect( 1.625108f, 0.626630f, -1.678760f );
	pTmp4->pBone[16].Q = Quat( ROT_XYZ, 2.097566f, 0.583443f, 0.378171f );
	pTmp4->pBone[16].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb2
	pTmp4->pBone[17].T = Vect( 1.140432f, 0.000003f, -0.000002f );
	pTmp4->pBone[17].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.311601f );
	pTmp4->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb3
	pTmp4->pBone[18].T = Vect( 1.382469f, -0.000001f, 0.000004f );
	pTmp4->pBone[18].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.026029f );
	pTmp4->pBone[18].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index1
	pTmp4->pBone[19].T = Vect( 4.348744f, 0.016253f, -1.561334f );
	pTmp4->pBone[19].Q = Quat( ROT_XYZ, 0.208553f, 0.047619f, 0.054079f );
	pTmp4->pBone[19].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index2
	pTmp4->pBone[20].T = Vect( 1.473696f, 0.000000f, 0.000001f );
	pTmp4->pBone[20].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.235596f );
	pTmp4->pBone[20].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index3
	pTmp4->pBone[21].T = Vect( 1.062845f, 0.000000f, 0.000002f );
	pTmp4->pBone[21].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.000000f );
	pTmp4->pBone[21].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle1
	pTmp4->pBone[22].T = Vect( 4.359987f, -0.000295f, -0.366860f );
	pTmp4->pBone[22].Q = Quat( ROT_XYZ, 0.032299f, 0.028803f, 0.205517f );
	pTmp4->pBone[22].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle2
	pTmp4->pBone[23].T = Vect( 1.529124f, 0.000001f, -0.000000f );
	pTmp4->pBone[23].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.261102f );
	pTmp4->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle3
	pTmp4->pBone[24].T = Vect( 1.529128f, 0.000001f, 0.000001f );
	pTmp4->pBone[24].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.066429f );
	pTmp4->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring1
	pTmp4->pBone[25].T = Vect( 4.295015f, -0.094743f, 0.806466f );
	pTmp4->pBone[25].Q = Quat( ROT_XYZ, -0.156945f, -0.016888f, 0.311472f );
	pTmp4->pBone[25].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring2
	pTmp4->pBone[26].T = Vect( 1.403335f, 0.000001f, -0.000000f );
	pTmp4->pBone[26].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.446212f );
	pTmp4->pBone[26].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring3
	pTmp4->pBone[27].T = Vect( 1.388261f, 0.000000f, -0.000000f );
	pTmp4->pBone[27].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.157449f );
	pTmp4->pBone[27].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky1
	pTmp4->pBone[28].T = Vect( 3.972678f, 0.223488f, 1.742838f );
	pTmp4->pBone[28].Q = Quat( ROT_XYZ, -0.360488f, -0.014302f, 0.391946f );
	pTmp4->pBone[28].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky2
	pTmp4->pBone[29].T = Vect( 1.131793f, -0.000002f, -0.000000f );
	pTmp4->pBone[29].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.000000f );
	pTmp4->pBone[29].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky3
	pTmp4->pBone[30].T = Vect( 0.858955f, 0.000001f, 0.000001f );
	pTmp4->pBone[30].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.067550f );
	pTmp4->pBone[30].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Clavicle
	pTmp4->pBone[31].T = Vect( -0.307962f, -0.770588f, -1.223302f );
	pTmp4->pBone[31].Q = Quat( ROT_XYZ, -0.000015f, 1.401520f, 2.726494f );
	pTmp4->pBone[31].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_UpperArm
	pTmp4->pBone[32].T = Vect( 6.887267f, -0.965631f, 0.389823f );
	pTmp4->pBone[32].Q = Quat( ROT_XYZ, 0.672951f, -1.086517f, -0.659362f );
	pTmp4->pBone[32].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Forearm
	pTmp4->pBone[33].T = Vect( 13.142184f, 0.000001f, 0.000003f );
	pTmp4->pBone[33].Q = Quat( ROT_XYZ, -0.620028f, -0.428107f, -0.687024f );
	pTmp4->pBone[33].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Hand
	pTmp4->pBone[34].T = Vect( 10.825553f, 0.000000f, -0.000001f );
	pTmp4->pBone[34].Q = Quat( ROT_XYZ, 1.261759f, 0.050839f, -0.163382f );
	pTmp4->pBone[34].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb1
	pTmp4->pBone[35].T = Vect( 1.625108f, 0.626631f, 1.678760f );
	pTmp4->pBone[35].Q = Quat( ROT_XYZ, -2.269302f, -0.617987f, 0.603127f );
	pTmp4->pBone[35].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb2
	pTmp4->pBone[36].T = Vect( 1.140432f, -0.000001f, 0.000001f );
	pTmp4->pBone[36].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.559595f );
	pTmp4->pBone[36].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb3
	pTmp4->pBone[37].T = Vect( 1.382469f, 0.000000f, -0.000003f );
	pTmp4->pBone[37].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.097476f );
	pTmp4->pBone[37].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index1
	pTmp4->pBone[38].T = Vect( 4.348744f, 0.016252f, 1.561333f );
	pTmp4->pBone[38].Q = Quat( ROT_XYZ, -0.209123f, -0.011217f, 0.098128f );
	pTmp4->pBone[38].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index2
	pTmp4->pBone[39].T = Vect( 1.473695f, -0.000003f, 0.000000f );
	pTmp4->pBone[39].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.319365f );
	pTmp4->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index3
	pTmp4->pBone[40].T = Vect( 1.062847f, -0.000000f, -0.000000f );
	pTmp4->pBone[40].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.230576f );
	pTmp4->pBone[40].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle1
	pTmp4->pBone[41].T = Vect( 4.359987f, -0.000294f, 0.366859f );
	pTmp4->pBone[41].Q = Quat( ROT_XYZ, -0.021097f, 0.001019f, 0.062709f );
	pTmp4->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle2
	pTmp4->pBone[42].T = Vect( 1.529123f, -0.000003f, 0.000000f );
	pTmp4->pBone[42].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.324054f );
	pTmp4->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle3
	pTmp4->pBone[43].T = Vect( 1.529128f, -0.000002f, -0.000000f );
	pTmp4->pBone[43].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.062832f );
	pTmp4->pBone[43].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring1
	pTmp4->pBone[44].T = Vect( 4.295013f, -0.094741f, -0.806466f );
	pTmp4->pBone[44].Q = Quat( ROT_XYZ, 0.176895f, 0.090345f, 0.250356f );
	pTmp4->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring2
	pTmp4->pBone[45].T = Vect( 1.403335f, 0.000004f, 0.000001f );
	pTmp4->pBone[45].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.476269f );
	pTmp4->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring3
	pTmp4->pBone[46].T = Vect( 1.388261f, -0.000000f, 0.000000f );
	pTmp4->pBone[46].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.227678f );
	pTmp4->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky1
	pTmp4->pBone[47].T = Vect( 3.972679f, 0.223487f, -1.742838f );
	pTmp4->pBone[47].Q = Quat( ROT_XYZ, 0.424552f, 0.057144f, 0.402159f );
	pTmp4->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky2
	pTmp4->pBone[48].T = Vect( 1.131793f, -0.000005f, -0.000000f );
	pTmp4->pBone[48].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.381672f );
	pTmp4->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky3
	pTmp4->pBone[49].T = Vect( 0.858953f, -0.000003f, 0.000000f );
	pTmp4->pBone[49].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.100513f );
	pTmp4->pBone[49].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thigh1
	pTmp4->pBone[50].T = Vect( -3.769306f, -0.355238f, 3.495145f );
	pTmp4->pBone[50].Q = Quat( ROT_XYZ, 2.902807f, -0.379123f, 2.625168f );
	pTmp4->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Knee2
	pTmp4->pBone[51].T = Vect( 18.257195f, -0.000001f, 0.000001f );
	pTmp4->pBone[51].Q = Quat( ROT_XYZ, 0.320609f, 0.032286f, -1.180087f );
	pTmp4->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ankle1
	pTmp4->pBone[52].T = Vect( 15.428004f, -0.000000f, 0.000000f );
	pTmp4->pBone[52].Q = Quat( ROT_XYZ, -0.073805f, -0.158321f, -0.015616f );
	pTmp4->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ball
	pTmp4->pBone[53].T = Vect( 5.250221f, 6.273849f, -0.000001f );
	pTmp4->pBone[53].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp4->pBone[53].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thigh
	pTmp4->pBone[54].T = Vect( -3.769306f, -0.355218f, -3.495146f );
	pTmp4->pBone[54].Q = Quat( ROT_XYZ, -2.974400f, -0.129131f, 2.945769f );
	pTmp4->pBone[54].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Knee
	pTmp4->pBone[55].T = Vect( 18.257195f, -0.000001f, -0.000001f );
	pTmp4->pBone[55].Q = Quat( ROT_XYZ, 0.016940f, -0.129312f, -0.722886f );
	pTmp4->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ankle
	pTmp4->pBone[56].T = Vect( 15.428004f, 0.000000f, 0.000001f );
	pTmp4->pBone[56].Q = Quat( ROT_XYZ, 0.074300f, 0.024139f, 0.387751f );
	pTmp4->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ball
	pTmp4->pBone[57].T = Vect( 5.250221f, 6.273849f, -0.000000f );
	pTmp4->pBone[57].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp4->pBone[57].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
	// --------  Frame 38 ----------------------

   Frame_Bucket *pTmp5 = new Frame_Bucket();
	pTmp5->prevBucket = pTmp4;
	pTmp5->nextBucket = 0;
	pTmp5->KeyTime = 38 * Time(TIME_NTSC_30_FRAME);
	pTmp5->pBone = new Bone[NUM_BONES];

	pTmp4->nextBucket = pTmp5;

	//     Node Name: Root
	pTmp5->pBone[0].T = Vect( 0.037563f, 37.460987f, 2.230549f );
	pTmp5->pBone[0].Q = Quat( ROT_XYZ, -1.570796f, -1.570796f, 0.000000f );
	pTmp5->pBone[0].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Pelvis
	pTmp5->pBone[1].T = Vect( -0.586263f, -0.067967f, -0.068527f );
	pTmp5->pBone[1].Q = Quat( ROT_XYZ, -2.399785f, -1.519077f, -2.464564f );
	pTmp5->pBone[1].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine
	pTmp5->pBone[2].T = Vect( 3.786006f, -0.003600f, 0.000005f );
	pTmp5->pBone[2].Q = Quat( ROT_XYZ, -0.000004f, -0.000002f, -0.094916f );
	pTmp5->pBone[2].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine1
	pTmp5->pBone[3].T = Vect( 4.543316f, -0.003600f, -0.000000f );
	pTmp5->pBone[3].Q = Quat( ROT_XYZ, 0.074038f, -0.017775f, -0.104662f );
	pTmp5->pBone[3].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine2
	pTmp5->pBone[4].T = Vect( 4.544050f, -0.003600f, 0.000000f );
	pTmp5->pBone[4].Q = Quat( ROT_XYZ, 0.073508f, 0.017842f, 0.083881f );
	pTmp5->pBone[4].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Spine3
	pTmp5->pBone[5].T = Vect( 4.543960f, -0.004399f, 0.000000f );
	pTmp5->pBone[5].Q = Quat( ROT_XYZ, 0.074468f, 0.013753f, 0.045951f );
	pTmp5->pBone[5].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Neck
	pTmp5->pBone[6].T = Vect( 5.536252f, -0.002882f, 0.000000f );
	pTmp5->pBone[6].Q = Quat( ROT_XYZ, -0.113612f, 0.054267f, 0.502790f );
	pTmp5->pBone[6].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: Head
	pTmp5->pBone[7].T = Vect( 3.953896f, 0.000001f, 0.000000f );
	pTmp5->pBone[7].Q = Quat( ROT_XYZ, -0.031530f, -0.000013f, -0.305467f );
	pTmp5->pBone[7].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eye_joint1
	pTmp5->pBone[8].T = Vect( 4.220695f, 1.406053f, 1.394846f );
	pTmp5->pBone[8].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp5->pBone[8].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eye_joint
	pTmp5->pBone[9].T = Vect( 4.296264f, 1.333193f, -1.066092f );
	pTmp5->pBone[9].Q = Quat( ROT_XYZ, 1.635570f, -1.524983f, -1.570796f );
	pTmp5->pBone[9].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_eyeBall_joint2
	pTmp5->pBone[10].T = Vect( 4.482600f, 3.247940f, 1.274591f );
	pTmp5->pBone[10].Q = Quat( ROT_XYZ, 0.080872f, -0.000000f, 0.000600f );
	pTmp5->pBone[10].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_eyeBall_joint
	pTmp5->pBone[11].T = Vect( 4.577010f, 3.107063f, -1.207679f );
	pTmp5->pBone[11].Q = Quat( ROT_XYZ, 0.032624f, 0.007158f, 0.033678f );
	pTmp5->pBone[11].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Clavicle
	pTmp5->pBone[12].T = Vect( -0.307962f, -0.770595f, 1.223297f );
	pTmp5->pBone[12].Q = Quat( ROT_XYZ, -0.000015f, -1.401522f, 2.726524f );
	pTmp5->pBone[12].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_UpperArm
	pTmp5->pBone[13].T = Vect( 6.704920f, 0.887552f, -0.127949f );
	pTmp5->pBone[13].Q = Quat( ROT_XYZ, 0.296437f, 0.965537f, 0.963523f );
	pTmp5->pBone[13].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Forearm
	pTmp5->pBone[14].T = Vect( 13.142184f, -0.000000f, -0.000000f );
	pTmp5->pBone[14].Q = Quat( ROT_XYZ, 0.578096f, 0.278216f, -0.204345f );
	pTmp5->pBone[14].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Hand
	pTmp5->pBone[15].T = Vect( 10.825552f, 0.000001f, 0.000001f );
	pTmp5->pBone[15].Q = Quat( ROT_XYZ, -1.294576f, 0.175747f, 0.053448f );
	pTmp5->pBone[15].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb1
	pTmp5->pBone[16].T = Vect( 1.625108f, 0.626630f, -1.678760f );
	pTmp5->pBone[16].Q = Quat( ROT_XYZ, 2.066355f, 0.502461f, 0.321803f );
	pTmp5->pBone[16].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb2
	pTmp5->pBone[17].T = Vect( 1.140432f, 0.000003f, -0.000002f );
	pTmp5->pBone[17].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.311601f );
	pTmp5->pBone[17].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thumb3
	pTmp5->pBone[18].T = Vect( 1.382469f, -0.000001f, 0.000004f );
	pTmp5->pBone[18].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.271129f );
	pTmp5->pBone[18].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index1
	pTmp5->pBone[19].T = Vect( 4.348744f, 0.016253f, -1.561334f );
	pTmp5->pBone[19].Q = Quat( ROT_XYZ, 0.210165f, 0.012737f, 0.081211f );
	pTmp5->pBone[19].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index2
	pTmp5->pBone[20].T = Vect( 1.473696f, 0.000000f, 0.000001f );
	pTmp5->pBone[20].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.291144f );
	pTmp5->pBone[20].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Index3
	pTmp5->pBone[21].T = Vect( 1.062845f, 0.000000f, 0.000002f );
	pTmp5->pBone[21].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.000000f );
	pTmp5->pBone[21].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle1
	pTmp5->pBone[22].T = Vect( 4.359987f, -0.000295f, -0.366860f );
	pTmp5->pBone[22].Q = Quat( ROT_XYZ, 0.035253f, 0.015204f, 0.286301f );
	pTmp5->pBone[22].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle2
	pTmp5->pBone[23].T = Vect( 1.529124f, 0.000001f, -0.000000f );
	pTmp5->pBone[23].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.300153f );
	pTmp5->pBone[23].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Middle3
	pTmp5->pBone[24].T = Vect( 1.529128f, 0.000001f, 0.000001f );
	pTmp5->pBone[24].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.066429f );
	pTmp5->pBone[24].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring1
	pTmp5->pBone[25].T = Vect( 4.295015f, -0.094743f, 0.806466f );
	pTmp5->pBone[25].Q = Quat( ROT_XYZ, -0.156824f, -0.024457f, 0.359100f );
	pTmp5->pBone[25].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring2
	pTmp5->pBone[26].T = Vect( 1.403335f, 0.000001f, -0.000000f );
	pTmp5->pBone[26].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.446212f );
	pTmp5->pBone[26].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ring3
	pTmp5->pBone[27].T = Vect( 1.388261f, 0.000000f, -0.000000f );
	pTmp5->pBone[27].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.157449f );
	pTmp5->pBone[27].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky1
	pTmp5->pBone[28].T = Vect( 3.972678f, 0.223488f, 1.742838f );
	pTmp5->pBone[28].Q = Quat( ROT_XYZ, -0.360488f, -0.014302f, 0.391946f );
	pTmp5->pBone[28].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky2
	pTmp5->pBone[29].T = Vect( 1.131793f, -0.000002f, -0.000000f );
	pTmp5->pBone[29].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.000000f );
	pTmp5->pBone[29].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Pinky3
	pTmp5->pBone[30].T = Vect( 0.858955f, 0.000001f, 0.000001f );
	pTmp5->pBone[30].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, 0.067550f );
	pTmp5->pBone[30].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Clavicle
	pTmp5->pBone[31].T = Vect( -0.307962f, -0.770588f, -1.223302f );
	pTmp5->pBone[31].Q = Quat( ROT_XYZ, -0.000015f, 1.401520f, 2.726494f );
	pTmp5->pBone[31].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_UpperArm
	pTmp5->pBone[32].T = Vect( 6.882450f, -1.112141f, 0.033165f );
	pTmp5->pBone[32].Q = Quat( ROT_XYZ, 0.780327f, -0.750752f, -0.946516f );
	pTmp5->pBone[32].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Forearm
	pTmp5->pBone[33].T = Vect( 13.142184f, 0.000001f, 0.000003f );
	pTmp5->pBone[33].Q = Quat( ROT_XYZ, -0.483913f, -0.430580f, -0.867147f );
	pTmp5->pBone[33].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Hand
	pTmp5->pBone[34].T = Vect( 10.825553f, 0.000000f, -0.000001f );
	pTmp5->pBone[34].Q = Quat( ROT_XYZ, 1.225525f, 0.238023f, -0.299857f );
	pTmp5->pBone[34].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb1
	pTmp5->pBone[35].T = Vect( 1.625108f, 0.626631f, 1.678760f );
	pTmp5->pBone[35].Q = Quat( ROT_XYZ, -2.240891f, -0.835203f, 0.598326f );
	pTmp5->pBone[35].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb2
	pTmp5->pBone[36].T = Vect( 1.140432f, -0.000001f, 0.000001f );
	pTmp5->pBone[36].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.559595f );
	pTmp5->pBone[36].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thumb3
	pTmp5->pBone[37].T = Vect( 1.382469f, 0.000000f, -0.000003f );
	pTmp5->pBone[37].Q = Quat( ROT_XYZ, -0.000000f, 0.000000f, -0.019594f );
	pTmp5->pBone[37].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index1
	pTmp5->pBone[38].T = Vect( 4.348744f, 0.016252f, 1.561333f );
	pTmp5->pBone[38].Q = Quat( ROT_XYZ, -0.205749f, -0.064492f, -0.074559f );
	pTmp5->pBone[38].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index2
	pTmp5->pBone[39].T = Vect( 1.473695f, -0.000003f, 0.000000f );
	pTmp5->pBone[39].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.319365f );
	pTmp5->pBone[39].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Index3
	pTmp5->pBone[40].T = Vect( 1.062847f, -0.000000f, -0.000000f );
	pTmp5->pBone[40].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.230576f );
	pTmp5->pBone[40].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle1
	pTmp5->pBone[41].T = Vect( 4.359987f, -0.000294f, 0.366859f );
	pTmp5->pBone[41].Q = Quat( ROT_XYZ, -0.018978f, -0.038017f, -0.018609f );
	pTmp5->pBone[41].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle2
	pTmp5->pBone[42].T = Vect( 1.529123f, -0.000003f, 0.000000f );
	pTmp5->pBone[42].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.324054f );
	pTmp5->pBone[42].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Middle3
	pTmp5->pBone[43].T = Vect( 1.529128f, -0.000002f, -0.000000f );
	pTmp5->pBone[43].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.062832f );
	pTmp5->pBone[43].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring1
	pTmp5->pBone[44].T = Vect( 4.295013f, -0.094741f, -0.806466f );
	pTmp5->pBone[44].Q = Quat( ROT_XYZ, 0.171570f, 0.133906f, 0.190960f );
	pTmp5->pBone[44].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring2
	pTmp5->pBone[45].T = Vect( 1.403335f, 0.000004f, 0.000001f );
	pTmp5->pBone[45].Q = Quat( ROT_XYZ, -0.000000f, -0.000000f, 0.476269f );
	pTmp5->pBone[45].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ring3
	pTmp5->pBone[46].T = Vect( 1.388261f, -0.000000f, 0.000000f );
	pTmp5->pBone[46].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 0.227678f );
	pTmp5->pBone[46].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky1
	pTmp5->pBone[47].T = Vect( 3.972679f, 0.223487f, -1.742838f );
	pTmp5->pBone[47].Q = Quat( ROT_XYZ, 0.425628f, 0.116269f, 0.428874f );
	pTmp5->pBone[47].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky2
	pTmp5->pBone[48].T = Vect( 1.131793f, -0.000005f, -0.000000f );
	pTmp5->pBone[48].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.381672f );
	pTmp5->pBone[48].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Pinky3
	pTmp5->pBone[49].T = Vect( 0.858953f, -0.000003f, 0.000000f );
	pTmp5->pBone[49].Q = Quat( ROT_XYZ, 0.000000f, 0.000000f, 0.100513f );
	pTmp5->pBone[49].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Thigh1
	pTmp5->pBone[50].T = Vect( -3.769306f, -0.355238f, 3.495145f );
	pTmp5->pBone[50].Q = Quat( ROT_XYZ, 2.909751f, -0.207150f, 2.612295f );
	pTmp5->pBone[50].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Knee2
	pTmp5->pBone[51].T = Vect( 18.257195f, -0.000001f, 0.000001f );
	pTmp5->pBone[51].Q = Quat( ROT_XYZ, 0.031669f, 0.018034f, -0.450300f );
	pTmp5->pBone[51].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ankle1
	pTmp5->pBone[52].T = Vect( 15.428004f, -0.000000f, 0.000000f );
	pTmp5->pBone[52].Q = Quat( ROT_XYZ, -0.075493f, -0.076670f, 0.035526f );
	pTmp5->pBone[52].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: L_Ball
	pTmp5->pBone[53].T = Vect( 5.250221f, 6.273849f, -0.000001f );
	pTmp5->pBone[53].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp5->pBone[53].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Thigh
	pTmp5->pBone[54].T = Vect( -3.769306f, -0.355218f, -3.495146f );
	pTmp5->pBone[54].Q = Quat( ROT_XYZ, -2.999542f, 0.004658f, -2.774245f );
	pTmp5->pBone[54].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Knee
	pTmp5->pBone[55].T = Vect( 18.257195f, -0.000001f, -0.000001f );
	pTmp5->pBone[55].Q = Quat( ROT_XYZ, -0.067008f, -0.003987f, -0.193852f );
	pTmp5->pBone[55].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ankle
	pTmp5->pBone[56].T = Vect( 15.428004f, 0.000000f, 0.000001f );
	pTmp5->pBone[56].Q = Quat( ROT_XYZ, 0.076050f, 0.052391f, 0.421699f );
	pTmp5->pBone[56].S = Vect( 1.000000f, 1.000000f, 1.000000f );
		
	//     Node Name: R_Ball
	pTmp5->pBone[57].T = Vect( 5.250221f, 6.273849f, -0.000000f );
	pTmp5->pBone[57].Q = Quat( ROT_XYZ, 0.000000f, -0.000000f, 1.825521f );
	pTmp5->pBone[57].S = Vect( 1.000000f, 1.000000f, 1.000000f );
	
}