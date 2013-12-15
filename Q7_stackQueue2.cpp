class stackQueue {
public:
	int pop() {
		if (_stack2.empty()) {
			while (!_stack1.empty()) {
				_stack2.push(_stack1.top());
				_stack1.pop();
			}
		}
		
		if (_stack2.empty()) {
			throw new exception("queue is empty");
		}
		_stack2.pop();
	}
	
	void push(int v) {
		_stack1.push(v);
	}
	
	int top() {
		if (_stack2.empty()) {
			while (!_stack1.empty()) {
				_stack2.push(_stack1.top());
				_stack1.pop();
			}
		}
		
		if (_stack2.empty()) {
			throw new exception("queue is empty");
		}
		
		return _stack2.top();
	}
	
private:
	stack<int> _stack1;
	stack<int> _stack2;
};

class queueStack {
public:
	int pop() {
		if (_queue1.empty() && _queue2.empty())
			throw new exception("stack is empty");
		
		if (_queue1.empty()) {
			while (_queue2.size() > 1) {
				_queue1.push(_queue2.front());
				_queue2.dequeue();
			}
			int ret = _queue2.front();
			_queue2.dequeue();
			return ret;
		} else {
			while (_queue1.size() > 1) {
				_queue2.push(_queue1.front());
				_queue1.dequeue();
			}
			int ret = _queue1.front();
			_queue1.dequeue();
			return ret;
		}
	}
	
	void push(int v) {
		if (_queue1.empty())
			_queue2.push(v);
		else 
			_queue1.push(v);
	}
private:
	queue<int> _queue1;
	queue<int> _queue2;
};