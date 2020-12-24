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
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int* ret = (int*)calloc(digitsSize+1,sizeof(int));
    int* rev = (int*)calloc(digitsSize+1,sizeof(int));
    
    if (digits[digitsSize-1] < 9) {
        digits[digitsSize-1]++;
        
        memcpy(ret,digits,digitsSize*sizeof(int));
        free(rev);
        
        *returnSize = digitsSize;
        return ret;
    }
    
    int index = digitsSize - 1;
    int carry = 1;
    int length = 0;
    
    while (index >= 0 || carry > 0) {
        carry = (index >= 0) ? (digits[index]+carry) : carry;
        
        rev[length++] = carry % 10;
        carry /= 10;
        index--;
    }
    
    for (int i = 0; i < length; i++) {
        ret[i] = rev[length-1-i];
    }
    
    free(rev);
    *returnSize = length;
    
    return ret;
}