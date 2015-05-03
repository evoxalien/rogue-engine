#ifndef TEXTURELIST_H
#define TEXTURELIST_H
#include "../Texture.h"

struct node
{
   int textureCount;
   Texture texture;
   node *next;
};

class TetureList
{
   private:
      node *head;
	  int nodeCount;

   public:
      TetureList();
	  TetureList(Texture &firstTexture);
	  ~TetureList();
	  bool next();
	  void add();
	  void goToHead();
	  void destroyAll();
	  int getCount();
	  bool isEmpty();
	  
	  node *current;
};

TetureList::TetureList()
{
   head = NULL;
   current = NULL;
   nodeCount = 0;
}

TetureList::TetureList(Texture &firstTexture)
{
   //set up one node being the head
   head = new node;
   head->texture = firstTexture;
   head->textureCount = 1;
   head->next = NULL;
   
   current = head;
   nodeCount = 1;
}

TetureList::~TetureList()
{
   this->destroyAll();
}

bool TetureList::next()
{
   if(head == NULL || current == NULL)
      return false;
   
   if(current->next == NULL)
      return false;
   else
   {
      current = current->next;
   }
}

void TetureList::add()
{
   //if there are no nodes create first at head
   if(head == NULL)
   {
      head = new node;
      head->textureCount = 1;
      head->next = NULL;
   
      current = head;
      nodeCount++;
   }
   else
   {
      node *tempNode = head;
	  
	  //point temp node to last node on list
	  while(tempNode->next != NULL)
	     tempNode = tempNode->next;
      
	  //make new node and fill it
	  tempNode->next = new node;
	  tempNode = tempNode->next;
      tempNode->textureCount = 1;
      tempNode->next = NULL;
   
      nodeCount++;
   }
   
}

void TetureList::goToHead()
{
   current = head;
}

void TetureList::destroyAll()
{
   //pointer to go through list
   node *tempNode = head;
   //using current to follow behind pointer and delete list
   current = head;
   
   while(tempNode != NULL)
   {
      tempNode = tempNode->next;
	  delete current;
	  current = tempNode;
   }
   
   head = NULL;
   current = NULL;
   nodeCount = 0;
}

int TetureList::getCount()
{
   return nodeCount;
}

bool TetureList::isEmpty()
{
   if(head == NULL)
      return true;
   return false;
}
#endif
