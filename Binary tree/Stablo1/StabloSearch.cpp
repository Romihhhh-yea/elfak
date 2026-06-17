Node* search(int key) {
	Node* curr = root;
	while (curr != nullptr && curr->key != key) {
		if (key > curr->key) {
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	return curr;
}