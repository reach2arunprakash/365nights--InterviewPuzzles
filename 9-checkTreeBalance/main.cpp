int min;
int max;
bool checkTree(Node* root)
{
	searchMin(root, 0);
	searchMax(root, 0);
	return (max - min) <= 1;
}

void search(Node* root, int level)
{
	if(root->lChild == 0 && root->rChild == 0)
	{
		if(level < min)
			min = level;
		if(level > max)
			max = level;
	}
	else
	{
		search(root->lChild, level + 1);
		search(root->rChild, level + 1);
	}		
		
}

