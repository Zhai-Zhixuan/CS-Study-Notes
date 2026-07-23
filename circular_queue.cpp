class MyCircularQueue {
private:
    vector<int>queue;
    int l,r,size,limit;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        l=0;
        r=0; //r永远指向“下一个要放元素的位置”，不指向队尾元素本身
        size=0;
        limit=k;
    }
    
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        else{
            queue[r]=value;
            r=(r==limit-1)?0:r+1;
            size++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            l=(l==limit-1)?0:(l+1);
            size--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        else{
            return queue[l];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        else{
            int last=(r==0)?(limit-1):(r-1);
            return queue[last];
        }
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
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
