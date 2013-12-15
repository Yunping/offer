// Question7
class StackQueue {
public:
	void appendTail(int value) {
		_stack1.push(value);
	};
	
	int deleteHead() {
		if (_stack2.empty()) {
			while (!_stack1.empty()) {
				_stack2.push(_stack1.top());
				_stack1.pop();
			}
		}
		int ret = _stack2.top();
		_stack2.pop();
		return ret;
	}
	
private:
	stack<int> _stack1;
	stack<int> _stack2;
};