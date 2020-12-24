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

int maxArea(int* height, int heightSize){

    if (heightSize < 2) return 0;
    
    int index_0 = 0, index_1 = heightSize-1, top_height = 0;
    int max_sum = 0;
    
    while (index_0 < index_1) {
        if (height[index_0] < height[index_1]) {
            top_height = height[index_0];
        }
        else {
            top_height = height[index_1];
        }
        int sum = top_height*(index_1-index_0);
        
        if (sum > max_sum) {
            max_sum = sum;
        }
        
        if (height[index_0] < height[index_1]) 
            index_0 += 1; 
        else
            index_1 -= 1; 
    }

    return max_sum;
    
}