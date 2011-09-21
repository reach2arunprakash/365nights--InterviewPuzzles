
bool deleteNode(Node* n)
{
	if(n == 0||n->next == 0)
		return false;
	n->value = n->next->value;
	Node* tmp = n->next;
	n->next = n->next->next;
	delete tmp;
	return true;
}
