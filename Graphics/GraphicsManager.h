#ifndef GRAPHICS_OBJECT_MANAGER_H
#define GRAPHICS_OBJECT_MANAGER_H

#include <list>
#include "PCSTree.h"
#include "GraphicsObject.h"

// forward declare (get into the habit, it's good to use
class GraphicsObject;

// Singleton
class GraphicsObjectManager
{
public:

	void addObject( GraphicsObject *p);
	void clearList();
	PCSTree *getTree( void);
	void drawObjectsList( void );
	void drawObjectsTree( void );
	static GraphicsObjectManager * getInstance( void );

private:
	static GraphicsObjectManager *privGetInstance();
	void privDrawObjectsTreeDepthFirst(  PCSNode *node ) const;
	std::list< GraphicsObject *> goList;
	PCSTree  tree;
};


#endif
