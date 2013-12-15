char theFirstOnceChar(char *string) {
	if (!string) return '\0';
	
	int hash[256] = { 0 };
	char *p = string;
	while (*p != '\0') {
		++hash[(unsigned)(*p)];
		++p;
	}
	
	p = string;
	while (*p != '\0') {
		if (hash[(unsigned)(*p)] == 1)
			return *p;
		++p;
	}
	
	return '\0';
}