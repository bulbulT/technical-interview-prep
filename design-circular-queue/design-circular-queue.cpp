class MyCircularQueue {
public:
	int *arr;
	int frontIndex;
	int rearIndex;
	int size;
	int capacity;

	MyCircularQueue(int k) {
		arr = new int[k];
		rearIndex = 0;
		frontIndex = -1;
		size = 0;
		capacity = k;        
	}

	bool enQueue(int value) {
		if(size == capacity) {
			return false;
		}
		arr[rearIndex] = value;
		rearIndex = (rearIndex + 1) % capacity ;
		if(frontIndex == -1) {
			frontIndex = 0;
		}
		size++;
		return true;
	}

	bool deQueue() {
		if(isEmpty()) {
			return false;
		}
		frontIndex = (frontIndex + 1) % capacity;
		size--;
		if(size == 0) {
			frontIndex = -1;
			rearIndex = 0;
		}
		return true;        
	}

	int Front() {
		if(isEmpty()) {
			return -1;
		}
		return arr[frontIndex];        
	}

	int Rear() {
		if(isEmpty()) {
			return -1;
		}
		return arr[(rearIndex + capacity - 1) % capacity];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		if(size == capacity) {
			return true;
		}
		return false;
	}
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */