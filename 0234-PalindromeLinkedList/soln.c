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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int size = 0;
struct ListNode* stack = NULL;

int pop() {
    if (size == 0 || stack == NULL) return 0;
    
    struct ListNode *current = stack;
    
    int ret = current->val;
    stack = current->next;
    size--;
    
    free(current);

    return ret;
}

void push(int val) {
    if (size == 0 || stack == NULL) {
        stack = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        stack->val = val;
    }
    else {
        struct ListNode* current = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        current->val  = val;
        current->next = stack;
        stack = current;
    }

    size++;
}

void print_head(struct ListNode* head) {
    if (head == NULL) return;
    printf("Value: %d\n", head->val);
    print_head(head->next);
}

bool isPalindrome(struct ListNode* head){
    
    struct ListNode* current = head;
    
    print_head(head);
    
    while(current) {
        push(current->val);
        current = current->next;
    }
    
    if (size <= 1) {
        return true;
    }
    
    int half_size = size / 2;
    
    current = head;
    
    printf("size: %d, half_size: %d\n", size, half_size);
    
    print_head(head);
    
    for (int i = 0; i < half_size && current; i++) {
        int val = pop();

        printf("val: %d, current->val: %d\n", val, current>val);
        
        if (current->val != val) return false;
        current = current->next;
    }
    
    return true;
}