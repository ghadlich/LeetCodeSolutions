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

typedef struct Node{
   struct Node* next;
   int val;
} Node;

typedef struct {
    Node* head;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    return calloc(1,sizeof(MyStack));
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj == NULL) return;
    Node *current = calloc(1,sizeof(Node));

    current->val = x;
    if (obj->head == NULL) {
        obj->head = current;
    }
    else{
        Node *currentHead = obj->head;
        obj->head = current;
        current->next = currentHead;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if ((obj == NULL)||(obj->head == NULL)) return 0;
    
    Node *current = obj->head;
    
    int ret = obj->head->val;
    obj->head = obj->head->next;
    
    free(current);
    
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if ((obj == NULL)||(obj->head == NULL)) return 0;
    
    Node *current = obj->head;
    
    int ret = obj->head->val;
    
    return ret;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return ((obj == NULL)||(obj->head == NULL));
}

void myStackFree(MyStack* obj) {
    while ((obj != NULL) && (obj->head != NULL)) {
        Node *current = obj->head;

        obj->head = obj->head->next;
    
        free(current);
    }
    
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/