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
int isPalindrome(char * input, int size) {
    if (size <= 1) {
        return 1;
    }
    if (input[0]!=input[size-1]) {
        return 0;
    }
    return isPalindrome(input+1,size-2);
}

char * longestPalindrome(char * s){

    if (s == NULL) {return NULL;}
    
    int length = strlen(s);
    int maxLength = 1;
    char *ret = calloc(1001,sizeof(char));
    ret[0] = s[0];
    int maxPalFound = 1;
    
    for (int i = 0; i < length; i++) {
        for (int palLengthCheck = maxLength; (palLengthCheck+i) <= length;palLengthCheck++) {
            if (isPalindrome(&s[i],palLengthCheck)) {
            //printf("%d %d\n", i, palLengthCheck);
            if (palLengthCheck > maxLength) {
                maxLength = palLengthCheck;
                memcpy(ret,&s[i],palLengthCheck);
                ret[palLengthCheck] = '\0';
            }
            }
        }
    }
    
    return ret;
    
}