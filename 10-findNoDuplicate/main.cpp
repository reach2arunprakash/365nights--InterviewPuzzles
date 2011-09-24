Node* findNext(Node *root)
{
     if(0 == root)
	  return root;
     if (root->parent == null || root->rChild)
	  return searchLeft(root->rChild);
     while (root->parent != null)
     {
	  if(root->parent->lChild == root)
	       return root->parent;
	  root = root->parent;
     }
     return 0;
}

Node* searchLeft(Node* root)
{
     if(0 == root) return 0;
     while(root->left) root = root.left;
     return root;
}


 
