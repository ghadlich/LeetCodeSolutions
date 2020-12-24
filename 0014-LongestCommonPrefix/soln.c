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

char * longestCommonPrefix(char ** strs, int strsSize){

    if (strsSize == 0 || strs == NULL || strs[0] == NULL) {
        return (char*)calloc(1, sizeof(char));
    }
    
    printf("here");
    
    int* lengths = (int*)calloc(strsSize, sizeof(int));
    
    int maxLength = 0;
    
    for (int i = 0; i < strsSize; i++) {
        lengths[i] = strlen(strs[0]);
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
        }
    }
    
    printf("Max Length: %d\n", maxLength);
    
    char* ret = (char*)calloc(maxLength+1, sizeof(char));
    
    if (maxLength == 0) {
        return ret;
    }
    
    for (int i = 0; i < strsSize; i++) {
        for (int j = i+1; j < strsSize; j++){
           int k = 0;
           while (k < lengths[i] && k < lengths[j] && k < maxLength) {
               if (strs[i][k] != strs[j][k]) {
                   break;
               }
               k++;
           }

           if (k < maxLength) {
               maxLength = k;
               printf("Max Length: %d\n", maxLength);
           }
        }
    }
    
    memcpy(ret,strs[0], maxLength);
    
    return ret;
}