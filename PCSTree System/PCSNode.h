#ifndef PCSNODE_H
#define PCSNODE_H

#define PCSNODE_NAME_SIZE (32)

class PCSNode
{
public:
   // constructor
   PCSNode();
   
   // copy constructor
   PCSNode(const PCSNode &in );

   // Specialize Constructor
   PCSNode( PCSNode * const inParent, PCSNode * const inChild, PCSNode * const inSibling, const char * const inName);
   PCSNode( const char * const inName );


   // destructor
   ~PCSNode();

   // assignment operator
   PCSNode &operator = (const PCSNode &in);

   // accessors
   void setParent( PCSNode * const in );
   void setChild( PCSNode * const in );
   void setSibling( PCSNode * const in );
   PCSNode *getParent( void ) const;
   PCSNode *getChild( void ) const;
   PCSNode *getSibling( void ) const;

   // name
   void setName(const char * const inName );
   void getName(char * const outBuffer, int sizeOutBuffer ) const;

   // dump
   void print() const;
   void dumpChildren() const;
   void dumpSiblings() const;

   // get number of children/siblings
   int getNumSiblings() const;
   int getNumChildren() const;

private:
   PCSNode *parent;
   PCSNode *child;
   PCSNode *sibling;

   char     name[PCSNODE_NAME_SIZE];
};


#endif