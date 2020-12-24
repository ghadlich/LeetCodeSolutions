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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){

    if (returnSize == NULL) return NULL;
    *returnSize = 0;
    
    if (numsSize <= 0) return NULL;
    if (nums == NULL) return NULL;
    
    int arraySize = 2;
    int* ret = calloc(arraySize, sizeof(int));
    int retSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[abs(nums[i])-1] > 0) {
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            ret[retSize++] = i+1;
        }
        
        if (retSize>=arraySize) {
            arraySize *= 2;
            ret = realloc(ret, arraySize*sizeof(int));
        }
    }
    
    *returnSize = retSize;
    
    return ret;
}