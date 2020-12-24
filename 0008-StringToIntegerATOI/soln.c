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
int myAtoi(char * str){

    long ret = 0;
    int sign = 1;
    
    while (str[0] && *str==' '){
        str+=1;
    }
    
    if (*str == '-') {
        str+=1;
        sign = -1;
    }
    else if (*str == '+') {
        str+=1;
    }
    
    while (str[0] && *str=='0'){
        str+=1;
    }
    
    int count = 0;
    while (isdigit(str[0])) {
        ret = (ret*10) + (*str++ - '0');
        count++;
        
        if (count > 10) {
            break;
        }
    }
    
    ret*=sign;
    
    if (ret < INT_MIN) {
        ret = INT_MIN;
    }
    else if (ret > INT_MAX) {
        ret = INT_MAX;
    }
    
    return (int)ret;
}