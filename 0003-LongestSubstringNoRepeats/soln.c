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

#define max(a,b) (a>b?a:b)

int lengthOfLongestSubstring(char * s){

    if (s == NULL) return -1;
    
    char* hashMap = (char*)calloc(256, sizeof(char));
    
    int length = strlen(s);
    int max_length = 0;
    
    for (int i = 0; i < length; i++) {
        
        int current_length = 0;
        for (int j = i; j < length; j++) {
            
            if (hashMap[s[j]] == 1) {
                max_length = max(max_length,current_length);
                break;
            }
            else {
                current_length++;
                max_length = max(max_length,current_length);
                hashMap[s[j]] = 1;
            }
        }
        
        
        memset(hashMap, 0, sizeof(char)*256);
    }
    
    free(hashMap);
    
    return max_length;
}