class MyCircularQueue {

private:

    int *data;      // 存放循环队列的数据
    int head;       // 循环队列头
    int tail;       // 循环队列尾
    int len;        // 循环队列的最大长度
    int count;      // 循环队列的元素个数


public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {

        data = new int[k];
        head = 0;
        tail = 0;
        len = k;
        count = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) //循环队列满
        {
            return false;
        }
        else    // 插入元素到队尾，队尾索引值增一，元素个数增一
         {
            data[tail] = value;
            count++;
            tail = (tail + 1) % len;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) //循环队列空
        {
            return false;
        }
        else    // 队头索引值增一，元素个数减一
        {
            head = (head + 1) % len;
            count--;
            return true;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) //循环队列空
        {
            return -1;
        }
        else
        {
            return data[head];
        }
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) //循环队列空
        {
            return -1;
        }
        // 队尾元素位于队尾索引值减一的位置，但若队尾循环到索引 0 的位置，队尾元素位于数组最后
        else
        {
            int temp = tail == 0 ? (len-1) : (tail-1);
            return data[temp];
        }
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;  // 队列元素个数为零，队列空
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return count == len;    // 队列元素个数为数组最大长度，队列满
    }
};
