class MyCircularQueue {
public:
    deque<int>q;
    int size;int k;
    MyCircularQueue(int m) {
        size=m;
        k=m;
    }
    
    bool enQueue(int value) {
        if(size==0)
            return false;
        q.push_back(value);
        size--;
        return true;
    }
    
    bool deQueue() {
        if(size==k)
            return false;
        size++;
        q.pop_front();
        return true;
        
    }
    
    int Front() {
        if(size==k)
            return -1;
        return q.front();
    }
    
    int Rear() {
        
         if(size==k)
            return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return size==k;
    }
    
    bool isFull() {
        return size==0;
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