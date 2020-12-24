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
#define min(x,y) (x<y?x:y)

int maxScore(int* nums, int numsLength) {
    if (nums == NULL) return 0;
    if (numsLength <= 0) return 0;
    if (numsLength == 1) return nums[0];
    
    int total = 0;
    
    for (int i = 0; i < numsLength; i++) {
        total += nums[i];
    }
    
    int oppScore1 = maxScore(nums+1, numsLength-1);
    int oppScore2 = maxScore(nums, numsLength-1);
    
    return total-min(oppScore1,oppScore2);
}

bool PredictTheWinner(int* nums, int numsSize){
    if (nums == NULL) return false;
    
    int total = 0;
    
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    
    return maxScore(nums, numsSize) >= (total/2.0);
}