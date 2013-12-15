void revertString(char *l, char *r) {
	while (r > l) {
		char temp = *l;
		*l = *r;
		*r = temp;
		++l;
		--r;
	}
}

void revertWords(char *str) {
	int len = strlen(str);
	if (len <= 0) return;
	
	revertString(str, str+len-1);
	
	char *p = str;
	char *wordBegin = 0;
	while (p && *p != '\0') {
		if (*p == ' ') {
			if (wordBegin) {
				revertString(wordBegin, p-1);
				wordBegin = 0;
			}
		} else {
			if (!wordBegin)
				wordBegin = p;
		}
		++p;
	}
	if (wordBegin) {
		revertString(wordBegin, p-1);
	}
}
