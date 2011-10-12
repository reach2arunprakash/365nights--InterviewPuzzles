#include <iostream>
using namespace std;



/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};


/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
     struct Node* node = (struct Node*)
	  malloc(sizeof(struct Node));
     node->data  = data;
     node->left  = NULL;
     node->right = NULL;
 
     return(node);
}


bool __checkMirror(const Node* lRoot, const Node* rRoot)
{
     if (!lRoot || !rRoot)
	  return !lRoot && !rRoot;

     return (lRoot->data == rRoot->data) && __checkMirror(lRoot->left, rRoot->right) && __checkMirror(lRoot->right, rRoot->left);
}


bool checkMirror(const Node* root)
{
     return __checkMirror(root->left, root->right);
}



/* Driver program to test mirror() */
int main()
{
     struct Node *root  = newNode(4);
     root->left         = newNode(2);
     root->left->left   = newNode(1);
     root->left->right   = newNode(3);     
     root->right  = newNode(2);
     root->right->left  = newNode(3);
     root->right->right  = newNode(1);
     /* Constructed binary search tree is
	4
	/ \
	2   5
	/ \
	1   3
     */
     cout << checkMirror(root) << endl;
}


