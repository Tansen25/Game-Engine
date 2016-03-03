#ifndef SHARED_DATA_WRAPPER
#define SHARED_DATA_WRAPPER

#define FILE_NAME_SIZE 20
#define TEXTURE_NAME_SIZE 20

struct modelStride
{ 
	float x;
	float y;
	float z;
	float s;
	float t;
	float nx;
	float ny;
	float nz;
};

struct modelTriangleList
{
	unsigned short v1;
	unsigned short v2;
	unsigned short v3;
};

struct modelHeader
{
	char fileName[FILE_NAME_SIZE];
	char textureName[TEXTURE_NAME_SIZE];
	int vertCount;
	int uvCount;
	int normCount;
	int triangleCount;
	int textureSize;
	bool duplicates;
};

#endif