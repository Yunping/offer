// Q42_2_leftRotateString

void revertString(char *l, char *r) {
	if (l && r) {
		while (r > l) {
			char t = *l;
			*l = *r;
			*r = t;
			++l;
			--r;
		}
	}
}

void leftRotateString(char *str, int offset) {
	char *p = str;
	int len = 0;
	while (p && *p != '\0') {
		++len;
		++p;
	}
	
	if (offset > len) return;
	
	revertString(str, str+offset-1);
	revertString(str+offset, str+len-1);
	revertString(str, str+len-1);
}