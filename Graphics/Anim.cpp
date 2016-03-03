#include "OpenGLWrapper.h"
#include "Anim.h"
#include "VectApp.h"
#include "QuatApp.h"

extern Frame_Bucket *pHead;

void ProcessAnimation()
{
   // NOTE these static should be tied into an animation system
	static Time tCurr(TIME_ZERO);
	static Time deltaTime = 0.3f* Time(TIME_NTSC_30_FRAME);

   // I HATE this, but for now...
   // find max time
   Frame_Bucket *pTmp = pHead;
   while( pTmp->nextBucket != 0 )
   {
      pTmp = pTmp->nextBucket;
   }
   Time maxTime = pTmp->KeyTime;

   // protection for time values
   if( tCurr < Time(TIME_ZERO) )
   {
      tCurr = maxTime;
   }
   else if ( tCurr > maxTime )
	{
		tCurr = Time(TIME_ZERO);
	}
   else
   {
      // do nothing
   }

	// Get the result bone array
   Bone *bResult = pHead->pBone;

   // First one is the result, skip it
	pTmp = pHead->nextBucket;
 
   // Find which key frames
	while( tCurr >= pTmp->KeyTime  && pTmp->nextBucket != 0 )
	{
		pTmp = pTmp->nextBucket;
	}

	// pTmp is the "B" key frame
	// pTmp->prev is the "A" key frame
	Frame_Bucket *pA = pTmp->prevBucket;
	Frame_Bucket *pB = pTmp;

	// find the "S" of the time
	float tS = (tCurr - pA->KeyTime)  /(pB->KeyTime - pA->KeyTime);
	
	// interpolate to 
	Bone *bA = pA->pBone;
	Bone *bB = pB->pBone;

   // Interpolate to tS time, for all bones
   for( int i = 0; i < NUM_BONES; i++ )
   {
	   VectApp::Lerp(bResult->T, bA->T, bB->T, tS);
	   QuatApp::Slerp(bResult->Q, bA->Q, bB->Q, tS);
      VectApp::Lerp(bResult->S, bA->S, bB->S, tS);
	
	   bA++;
	   bB++;
      bResult++;
   }

	// update the time
	tCurr += deltaTime;
}

Matrix helper()
{
	Frame_Bucket *pTmp = pHead;
	pTmp = pHead->nextBucket;
	Bone *bResult = pTmp->pBone;

	Matrix M,T,S,R;

	Vect vTrans = bResult[2].T;
	Vect vScale = bResult[2].S;

	T.set(TRANS, vTrans[x],vTrans[y],vTrans[z]);
	S.set(SCALE, vScale[x],vScale[y],vScale[z]);
	R.set( bResult[0].Q );

	M = S * R * T;

	return M;
}
