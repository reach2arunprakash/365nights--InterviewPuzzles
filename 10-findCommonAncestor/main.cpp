#include <iostream>
#include <vector>
using namespace std;
struct Node
{
     Node* lChild;
     Node* rChild;
     bool contains;
     int number;
};

bool preprocess(Node* root, Node* p, Node* q)
{
     if(root == q || root == p)
     {
	  root->contains = true;
	  return true;
     }
     root->contains = false;
     if(root->lChild)
	  root->contains = preprocess(root->lChild, p, q);
     if(root->rChild)
	  root->contains |= preprocess(root->rChild, p, q);
     return root->contains;
}

Node* findCommonAncestor(Node* root, Node* p, Node* q)
{
     preprocess(root, p, q);
     if(root == p || root == q)
	  return root;
     if(!(root->lChild && root->rChild))
	  return root;
     if(root->lChild->contains && root->rChild->contains)
	  return root;
     if(root->lChild->contains)
	  return findCommonAncestor(root->lChild, p, q);
     if(root->rChild->contains)
	  return findCommonAncestor(root->rChild, p, q);
}

int main()
{
     vector<Node> a(7);
     for (int i = 0; i < 7; i++)
	  a[i].number = i;
     for (int i = 0; i < 3; i++)
     {
	  a[i].lChild = &a[i * 2 + 1];
	  a[i].rChild = &a[i * 2 + 2];
     }
     for (int i = 0; i < 7; i++)
     {
	  for (int j = 0; j < 7; j++)
	  {
	       if (i == j) continue;
	       cout << i <<" and " << j <<"'s common ancestor is "
		    << findCommonAncestor(&a[0], &a[i], &a[j])->number << endl;
 	  }
     }
}
