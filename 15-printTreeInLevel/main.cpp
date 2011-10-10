#include <iostream>
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

void __print(queue<Node*>& q)
{
     if (q.size() == 0)
	  return;
     queue<Node*> q2;
     while(q.size()!=0)
     {
	  cout << q.front()->data << ' ';

	  if(q.front()->left)
	       q2.push(q.front()->left);
	  if(q.front()->right)
	       q2.push(q.front()->right);
	  q.pop();
     }
     cout << endl;
     __print(q2);
}

void print(Node* header)
{
     queue<Node*> q;
     q.push(header);
     __print(q);
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
     print(root);
}
