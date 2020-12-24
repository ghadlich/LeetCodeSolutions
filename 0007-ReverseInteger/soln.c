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
#include <math.h>

int reverse(int x){
    long number = x;
    
    int negative = (number<0);
    
    if (negative) number = -number;
    
    int* rev = (char*)calloc(11,sizeof(int));
    int length = 0;
    
    while (number > 0) {
        rev[length++] = number % 10;
        number /= 10;
    }
    
    long factor = 1;
    long ret = 0;
    
    for (int i = length-1; i >= 0; i--){
        ret += (long)rev[i]*factor;
        factor*=10;
    }
    
    if (negative) ret*=-1;
    
    if (ret > INT_MAX) {
        return 0;
    }
    else if (ret < INT_MIN) {
        return 0;
    }
    
	free(rev)
	
    return (int)ret;
}