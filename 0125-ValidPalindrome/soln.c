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
bool isPalLength(char * s, int firstIndex, int secondIndex) {
    if (secondIndex <= firstIndex) return true;
    
    if (s[firstIndex] != s[secondIndex]) return false;
    
    return isPalLength(s, firstIndex+1, secondIndex-1);
}


bool isPalindrome(char * s){

    int length = strlen(s);
    int newLength = 0;
    
    for (int i = 0 ; i < length; i++) {
        if (isalnum(s[i])) {
            s[newLength++] = tolower(s[i]);
        }
    }
    
    if (newLength < length) {
        s[newLength] = '\0';
    }
    
    printf("%s\n",s);
    
    return isPalLength(s,0,newLength-1);
    
}