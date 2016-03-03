#include "GraphicsManager.h"
#include "GraphicsObject.h"



void GraphicsObjectManager::addObject(GraphicsObject *p)
{
	this->goList.push_front( p );
}

PCSTree *GraphicsObjectManager::getTree( void )
{
   return &this->tree;
}

void GraphicsObjectManager::clearList()
{
	//Clear the list
	this -> goList.clear();
}

void GraphicsObjectManager::drawObjectsList()
{
	// Walk the graphics object list
	std::list<GraphicsObject *>::iterator it;
	for ( it=goList.begin(); it != goList.end(); it++ )
	{
		// local pointer
		GraphicsObject *go = *it;

		// Transform and draw graphics object
		go->transform();
		go->setRenderState();
		go->draw();
	}
}

void GraphicsObjectManager::drawObjectsTree()
{
 //  printf("\n");
 //  printf("DrawObjects() -------------------------------\n");

   this->privDrawObjectsTreeDepthFirst( this->tree.getRoot() );
}

void GraphicsObjectManager::privDrawObjectsTreeDepthFirst( PCSNode *node ) const
{
   PCSNode *child = 0;

   GraphicsObject *go = (GraphicsObject *)node;

   // Transform and draw graphics object
	go->transform();
	go->setRenderState();
	go->draw();

   // iterate through all of the active children 
   if (node->getChild() != 0)
	{  
	   child =	node->getChild();
	   // make sure that allocation is not a child node 
	   while (child != 0)
	   {
         privDrawObjectsTreeDepthFirst( child );
         // goto next sibling
         child = child->getSibling();
	   }
   }
   else
	{
      // bye bye exit condition
	}

}

GraphicsObjectManager * GraphicsObjectManager::getInstance( void )
{
	return privGetInstance();
}




GraphicsObjectManager * GraphicsObjectManager::privGetInstance( void )
{
	static GraphicsObjectManager gom;
	return &gom;
}
