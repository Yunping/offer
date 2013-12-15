void combination(char *str, vector<char> &result, vector<vector<char> > &ret) {
	int len = strlen(str);
	if (len > 0) {
		result.push_back(str[0]);
		combination(str+1, result, ret);
		result.pop_back(str[0]);
		combination(str+1, result, ret);
	} else {
		if (!result.empty()) {
			ret.push_back(result);
			
			vector<char>::iterator it = result.begin();
			while (it != result.end()) {
				printf("%c", *it);
				++it;
			}
			printf("\n");
		}
	}
}

vector<vector<char> > combination(char *str) {
	vector<vector<char> > ret;
	if (str && strlen(str) > 0) {
		vector<char> result;
		combination(str, result, ret);
	}
	
	return ret;
}