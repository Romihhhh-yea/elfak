bool CheckExpression(char* exp) {
	for (int i = 0; exp[i] != '\0'; i++) {
		char c = exp[i];

		if (c == '(' || c == '[' || c == '{') {
			stek.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (stek.empty()) return false;
			char otvorena = stek.pop();
			if (c == ')' && otvorena != '(') return false;
			if (c == ']' && otvorena != '[') return false;
			if (c == '}' && otvorena != '{') return false;

		}
	}
	return stek.empty();
}