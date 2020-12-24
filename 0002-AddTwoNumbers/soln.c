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

struct ListNode* create_node(int val) {
    struct ListNode* ret = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    
    ret->val = val;
    
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ret = NULL;
    struct ListNode* current = NULL;
    
    int carry = 0;
    
    while(l1 != NULL || l2 != NULL || carry > 0) {
        carry += (l1==NULL?0:l1->val);
        carry += (l2==NULL?0:l2->val);
        
        struct ListNode* node = create_node(carry % 10);
        carry /= 10;
        
        if (ret == NULL) {
            ret = node;
            current = node;
        }
        else {
            current->next = node;
            current = node;
        }
        
        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;
    }
    
    return ret;
}