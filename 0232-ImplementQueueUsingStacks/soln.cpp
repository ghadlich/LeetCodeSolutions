/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
struct linkedlist {
   int x;
   struct linkedlist* next;
   struct linkedlist* prev;
};


class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
        head = NULL; 
        tail = NULL; 
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        struct linkedlist* node = (struct linkedlist*) calloc(1,sizeof(struct linkedlist));
        node->x = x;
        if (head == NULL) {
            head = node;
            head->next = NULL;
            head->prev = NULL;
            tail = head;
            size++;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
            size++;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if (size == 0) {
            return -1;
        }
        
        int ret = -1;
        
        if (tail) {
            if (tail->prev) {
                tail->prev->next = NULL;
            }
            struct linkedlist* node = tail;
            ret = node->x;
            tail = node->prev;
            free(node);
            size--;
        }
        
        if (size == 0) {
            tail = head = NULL;
        }
        
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (size > 0) {
            return tail->x;
        }
        else {
            return -1;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (size == 0);
    }
private:
    struct linkedlist* head;
    struct linkedlist* tail;
    int size;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */