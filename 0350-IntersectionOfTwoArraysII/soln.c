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
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    int left = *(int*)a;
    int right = *(int*)b;
    
    if (right > left) {
        return -1;
    }
    else if (right < left) {
        return 1;
    }
    else {
        return 0;
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    if (returnSize == NULL) {
        return NULL;
    }
    
    if (nums1Size <= 0 || nums2Size <= 0 || nums1 == NULL || nums2 == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    qsort(nums1, nums1Size, sizeof(int), cmpfunc);
    qsort(nums2, nums2Size, sizeof(int), cmpfunc);
    
    int* ret = (int*)calloc(nums1Size+nums2Size, sizeof(int));
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < nums1Size && j < nums2Size) {
        
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            ret[k++] = nums1[i];
            i++;j++;
        }
    }
    
    *returnSize = k;
    return ret;
}