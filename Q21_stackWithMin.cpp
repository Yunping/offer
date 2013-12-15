class stackWithMin {
public:
	void push(int value) {
		if (m_min.empty() || m_min.top() <= value) {
			m_min.push(value);
		}
		m_stack.push(value);
	}
	
	void pop() {
		int t = m_stack.top();
		if (t == m_min.top())
			m_min.pop();
		m_stack.pop();
	}
	
	int min() {
		return m_min.top();
	}
	
private:
	vector<int> m_stack;
	vector<int> m_min;
};