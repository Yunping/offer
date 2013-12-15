// 此题看过答案后理解出来的
void Permutation(char *str, char *begin) {
	if (!str || *str == '\0')
		return;
	
	if (*begin == '\0') {
		printf("%s\n", str);
	} else {
		for (char *p = begin; *p != '\0'; ++p) {
			char temp = *p;
			*p = *begin;
			*begin = temp;
			
			Permutation(str, begin+1);
			
			temp = *p;
			*p = *begin;
			*begin = temp;
		}
	}
}