void replaceBlank(char *str) {
	if (!str) return;
	
	char *p = str;
	int blankCount = 0;
	while (*p != '\0') {
		if (*p == ' ')
			++blankCount;
		++p;
	}
	
	int offset = blankCount * 2;
	while (offset > 0) {
		if (*p == ' ') {
			*(p+offset) = '0';
			*(p+offset-1) = '2';
			*(p+offset-2) = '\%';
			offset -= 2;
		} else
			*(p+offset) = *p;
		--p;
	}
}