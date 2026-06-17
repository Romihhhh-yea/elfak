void remove(int key) {
	Node* prev = nullptr;
	Node* curr = root;
	if (root->key == key) { delete root; root = nullptr; return; }
	while (curr != nullptr && curr->key != key) {
		if (key > curr->key) {
			prev = curr;
			curr = curr->right;
		}
		else {
			prev = curr;
			curr = curr->left;
		}

	}
	if (curr->left == nullptr && curr->right == nullptr) {
		if (prev->right == curr)prev->right = nullptr;
		else prev->left = nullptr;
		delete curr;
	}
	else if (curr->left == nullptr || curr->right == nullptr) {
		Node* dete = (curr->left != nullptr) ? curr->left : curr->right;
		if (prev->right == curr) prev->right = dete;
		else prev->left = dete;
		delete curr;
	}
	else {
		Node* tmpPrev = curr;
		Node* tmp = curr->left;
		while (tmp->right != nullptr) {
			tmpPrev = tmp;
			tmp = tmp->right;
		}
		curr->key = tmp->key;
		tmpPrev->right = tmp->left;
		delete tmp;
	}

	if (curr == nullptr)return;
}