#include <iostream>
using namespace std;

struct BST{
	int bil;
	BST* right;
	BST* left;
};

BST* InsertNode (int bil,BST* pohon1)
{
  if (pohon1==NULL)
    {
      BST* NewNode = new BST;
      NewNode->bil = bil;
      NewNode->left = NULL;
      NewNode->right = NULL;
      pohon1=NewNode;
      cout<<NewNode->bil;
    }
  else if (pohon1->bil>bil)
    {
      if (pohon1->left==NULL||pohon1->left->bil<bil||pohon1->left->bil>bil)
	{
	  cout<<endl;
	  pohon1->left=InsertNode(bil,pohon1->left);
	}
    }
  else if(pohon1->right==NULL||pohon1->right->bil>bil)
    {
      {
	cout<<" ";
	pohon1->right=InsertNode(bil,pohon1->right);
      }
    }
  return pohon1;
}

bool SearchNode(int bil,BST* pohon1)
{
  if(pohon1==NULL)
  return false;
  
  else if(pohon1->bil==bil)
  return true;
  
  else if(pohon1->bil<bil)
  return SearchNode(bil,pohon1->right);
  
  else
  return SearchNode(bil,pohon1->left);
}

void PrintLeftNodes(BST* pohon1)
{
  if (pohon1!=NULL)
    {
      cout<<pohon1->bil;
      PrintLeftNodes(pohon1->left);
    }

}

int main ()
{
  int x[10]={4,1,9,6,2,5,3,8,7,0};
  BST* Pohon2=NULL;
  for(int i = 0;i<10;i++)
    {
      Pohon2=InsertNode(x[i],Pohon2);
    }
}