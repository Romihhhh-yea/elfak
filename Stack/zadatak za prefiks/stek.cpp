double calcPrefix(char* inStr) {
    for (int i = strlen(inStr) - 1; i >= 0; i--) {
        char c = inStr[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            double value1 = stek.pop();
            double value2 = stek.pop();
            if (c == '+') stek.push(value1 + value2);
            else if (c == '-') stek.push(value1 - value2);
            else if (c == '*') stek.push(value1 * value2);
            else if (c == '/') stek.push(value1 / value2);
        }
        else {
            stek.push(c - '0');
        }
    }
    return stek.pop();
}