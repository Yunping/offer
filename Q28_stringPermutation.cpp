void Permutation(char *str, vector<char> &result, vector<vector<char> > &ret) {
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		char first = str[i];
		str[i] = str[0];
		str[0] = first;
		result.push_back(first);
		if (len > 1)
			Permutation(str+1, result, ret);
		else {
			ret.push_back(result);
			vector<char>::iterator it = result.begin();
			while (it != result.end()) {
				printf("%c", *it);
				++it;
			}
			printf("\n");
		}

		first = str[0];
		str[0] = str[i];
		str[i] = first;
		result.pop_back();
	}
}

vector<vector<char> > Permutation(char *str) {
	vector<vector<char> > ret;
	vector<char> result;
	Permutation(str, result, ret);
	
	return ret;
}