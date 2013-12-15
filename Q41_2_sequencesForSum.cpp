vector<vector<int> > sequencesForSum(int sum) {
	if (s < 3) {
	}
	
	vector<vector<int> > ret;
	int from = 1;
	int to = 1;
	int cur = from;
	do {
		if (cur < sum) {
			++to;
			cur += to;
		}
		else if (cur > sum) {
			cur -= from;
			++from;
		}
		else {
			vector<int> result;
			for (int i = from; i < to; ++i) {
				result.push(i);
			}
			ret.push(result);
			
			++to;
			cur += to;
		}
	} while (from <= sum/2)
	
	return ret;
}