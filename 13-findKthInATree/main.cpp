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

int __returnKth(Node* node, int & k)
{
     if(node == 0)
	  return -999999;
     int r;
     r = __returnKth(node->left, k);
     if (k == 0)
	  return r;
     --k;
     if (k == 0)
	  return node->data;
     r = __returnKth(node->right, k);
     if (k == 0)
	  return r;     
     return -999999;
}

int returnKth(Node* node, int k)
{
     return __returnKth(node, k);
}


struct Node* newNode(int );

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

/* Driver program to test mirror() */
int main()
{
     struct Node *root  = newNode(4);
     root->left         = newNode(2);
     root->left->left   = newNode(1);
     root->left->right   = newNode(3);     
     root->right  = newNode(5);
     /* Constructed binary search tree is
	4
	/ \
	2   5
	/ \
	1   3
     */
     cout << returnKth(root, 1) << endl;
     cout << returnKth(root, 2) << endl;
     cout << returnKth(root, 3) << endl;
     cout << returnKth(root, 4) << endl;
     cout << returnKth(root, 5) << endl;     
}
