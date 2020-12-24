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
static void swap(int* x, int* y)  {
    if (x != y && x && y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

static int findFirstNonZeroIndex(int* nums, int numsSize) {
    
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= 0) {
            swap(&nums[i],&nums[j]);
            j++;
        }
        
        /*for (int k = 0; k < numsSize; k++) {
        printf("[swap]: nums[%d]: %d\n", k, nums[k]);}*/
    }
    
    return j;
}

static int findFirstMissing(int* nums, int numsSize) {
    if (numsSize <= 0) return 1;
    
    //printf("numsSize: %d\n", numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        //printf("nums[%d]: %d\n", i, nums[i]);
        if (abs(nums[i])-1 < numsSize && nums[abs(nums[i])-1] > 0) {
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
    }
    
   /* for (int k = 0; k < numsSize; k++) {
        printf("[missing]: nums[%d]: %d\n", k, nums[k]);}*/
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return i+1;
        }
    }
    
    return numsSize+1;
}

int firstMissingPositive(int* nums, int numsSize){
    if (nums == NULL) return NULL;
    if (numsSize <= 0) return 1;
    
    int nonzeroIndex = findFirstNonZeroIndex(nums, numsSize);
    
   // printf("nonzeroIndex: %d\n", nonzeroIndex);
    
    return findFirstMissing(&nums[nonzeroIndex], numsSize-nonzeroIndex);
}