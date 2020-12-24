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
#define max(x,y) (x>y?x:y)

bool isValid(char * s){

    int head = -1;
    
    int length = strlen(s);
    
    char* stack = calloc(length+1, sizeof(char));
    int stack_size = 0;
    
    for (int i = 0; i < length; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            stack[stack_size++] = s[i];
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if (stack_size == 0) {
                free(stack);
                return false;
            }
            
            if (s[i] == ']' && stack[stack_size-1] != '[') {
                return false;
            }
            if (s[i] == ')' && stack[stack_size-1] != '(') {
                return false;
            }
            if (s[i] == '}' && stack[stack_size-1] != '{') {
                return false;
            }
            
            stack_size--;
        }
    }
    
    free(stack);
    
    return (stack_size == 0);
}

int firstStar(char *s, int length) {
    for (int i = 0; i < length; i++) {
        if (s[i] == '*') {
            return i;
        }
    }
    
    return -1;
}

bool checkValidString(char * s){
    
    int length = strlen(s);
    if (length == 0) return true;
    printf("%s\n", s);
    
    int firstStarIndex = firstStar(s, length);
    
    if (firstStarIndex < 0) {
        return isValid(s);
    }
    
    s[firstStarIndex] = '(';
    
    if (checkValidString(s) == true) return true;
    
    s[firstStarIndex] = ')';
    
    if (checkValidString(s) == true) return true;
    
    
    char* newStr = calloc(length+2, sizeof(char));
    memcpy(newStr, s, length);
    
    for (int i = firstStarIndex; i < length; i++) {
        newStr[i] = newStr[i+1];
    }
    
    if (checkValidString(newStr) == true) {
        free(newStr);
        return true;
    }
    else {
        free(newStr);
        return false;
    }
}