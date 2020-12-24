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
#include <stdio.h>
#include <stdlib.h>

int cmpfn(const void* ptr1, const void* ptr2) {
    return (*((int*)ptr1)-*((int*)ptr2));
}

int singleNumber(int* nums, int numsSize){

    if (nums == NULL || numsSize < 1) {
        return 0;
    }
    
    if (numsSize == 1) {
        return nums[0];
    }
    
    qsort(nums, numsSize, sizeof(int), cmpfn);
    
    for (int i = 0; i < numsSize; i+=2) {
        if ((i+1) == numsSize) {
            return nums[i];
        }
        
        if (nums[i]!=nums[i+1]) {
            return nums[i];
        }
    }
    
    return 0;
}