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
#include <string.h>

#define max(x,y) (y>x?y:x)

char * addBinary(char * a, char * b){

    int i = strlen(a)-1;
    int j = strlen(b)-1;

    int ret_length = max(strlen(a),strlen(b)) + 2;
    
    char *ret = (char*)calloc(ret_length,sizeof(char));
    char *rev = (char*)calloc(ret_length,sizeof(char));
    
    int s = 0;
    int length = 0;
    
    while (i >= 0 || j >= 0 || s > 0) {
        s += (i>=0?a[i]-'0':0);
        s += (j>=0?b[j]-'0':0);
        
        rev[length++] = (s%2)+'0';
        s /= 2;
        
        i--;
        j--;
    }
    
    for (int i = 0; i < length; i++) {
        ret[i] = rev[length-1-i];
    }
    
    free(rev);

    return ret;
}