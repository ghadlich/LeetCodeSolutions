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
};

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        head = NULL;
        size = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        struct linkedlist* node = (struct linkedlist*)calloc(1,sizeof(struct linkedlist));
        node->x = x;
        size++;
        
        if (head == NULL) {
            head = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (size == 0) {
            return -1;
        }
        struct linkedlist* node = head;
        int ret = node->x;
        
        head = node->next;
        
        free(node);
        size--;
        
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        if (size == 0) {
            return -1;
        }
        
        return head->x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (size == 0);
    }
    
private:
    
    struct linkedlist* head;
    int size;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */