bool isPopOrder(int push[], int pop[], int length) {
	if (length <= 0 || !push || !pop)
		return false;
	
	vector<int> stack;
	int i = 0;
	int j = 0;
	while (i < length) {
		stack.push_back(push[i]);
		while (!stack.empty() && stack.back() == pop[j]) {
			++j;
			stack.pop();
		}
		++i;
	}
	
	while (!stack.empty() && stack.back() == pop[j]) {
		++j;
		stack.pop();
	}
	
	return stack.empty();
}