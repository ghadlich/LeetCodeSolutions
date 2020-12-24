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

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int val;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    return calloc(1,sizeof(MyQueue));
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj == NULL) return;
    
    Node* newNode = calloc(1,sizeof(Node));
    newNode->val = x;
    
    if (obj->head == NULL) {
        obj->head = newNode;
        obj->tail = newNode;
    }
    else {
        newNode->next = obj->head;
        obj->head->prev = newNode;
        obj->head = newNode;
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (obj == NULL) return 0;
    
    if (obj->tail == NULL) {
        return 0;
    }
    
    Node* retNode = obj->tail;
    
    int retInt = retNode->val;
    
    if (retNode->prev == NULL) {
        // Tail was the Head
        obj->head = NULL;
        obj->tail = NULL;
    }
    else {
        obj->tail = retNode->prev;
        obj->tail->next = NULL;
    }
    
    free(retNode);
    
    return retInt;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj == NULL) return 0;
    
    if (obj->tail == NULL) {
        return 0;
    }
    
    Node* retNode = obj->tail;
    
    int retInt = retNode->val;
    
    return retInt;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj == NULL) return true;
    
    if (obj->tail == NULL) {
        return true;
    }
    
    return false;
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return true;
    
    if (obj->head == NULL) return;
    
    Node* current = obj->head;
    
    while (current) {
        Node* toBeFreed = current;
        current = current->next;
        free(toBeFreed);
    }
    
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/