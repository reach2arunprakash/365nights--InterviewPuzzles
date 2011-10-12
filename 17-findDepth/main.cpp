#include <iostream>
#include <assert.h>
#include <queue>
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

int findDepth(Node * root)
{
     assert(root);
     queue<Node*> q;
     q.push(root);
     q.push(NULL);
     int count = 1;

     while (true)
     {
	  Node * n = q.front();
	  if (!n)
	  {
	       count ++;
	       q.push(NULL);
	  }
	  else
	  {
	       if(!n -> left && !n->right)
		    return count;
	       if(n -> left)
		    q.push(n->left);
	       if(n -> right)
		    q.push(n->right);
	  }
	  q.pop();
     }
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
     cout << findDepth(root) << endl;
}
