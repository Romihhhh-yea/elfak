void insert(int key) {
	Node* curr = root;
	Node* prev = nullptr;
	Node* novi = new Node();
	novi->key = key;
	novi->left = nullptr;
	novi->right = nullptr;
	while (curr != nullptr) {
		if (key > curr->key) {
			prev = curr;
			curr = curr->right;
		}
		else {
			prev = curr;
			curr = curr->left;
		}
	}
	if (prev == nullptr) {
		root = novi;
	}
	if (novi->key > prev->key) {
		prev->right = novi;
	}
	else {
		prev->left = novi;
	}
}