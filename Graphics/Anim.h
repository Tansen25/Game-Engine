#ifndef ANIM_H
#define ANIM_H

#include "OpenGLWrapper.h"
#include "Vect.h"
#include "Quat.h"
#include "Timer.h"

//#define NUM_BONES 2
//#define NUM_BONES 82
#define NUM_BONES 58

struct Bone 
{
   Vect  T;
   Quat  Q;
   Vect  S;
};

struct Frame_Bucket
{
	Frame_Bucket *nextBucket;
	Frame_Bucket *prevBucket;
	Time		  KeyTime;
	Bone		  *pBone;
};

void SetAnimatioHierarchy();
//void setAnimationHierarchy1();
void SetAnimationData();
//void setAnimationData1();
void SetAnimationPose();
//void setAnimationPose1();

void ProcessAnimation();

Matrix helper();


#endif