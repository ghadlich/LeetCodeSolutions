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
#define STATE_CHECK_FIRST 0
#define STATE_ALL_CAPS 1
#define STATE_ALL_LOWER 2
#define STATE_ONLY_FIRST 3

bool detectCapitalUse(char * word){
    
    int length = strlen(word);
    
    if (length < 2) {
        return true;
    }
    bool ret = true;
    
    int state = STATE_CHECK_FIRST;
    
    for (int i = 0; i < length; i++) {
        switch (state) {
                default:
                case STATE_CHECK_FIRST:
                    if (isupper(word[i])) {
                        if (isupper(word[i+1])) {
                            state = STATE_ALL_CAPS;
                        }
                        else {
                            state = STATE_ONLY_FIRST;
                        }
                    }
                    else {
                        state = STATE_ALL_LOWER;
                    }
                break;
                
                case STATE_ALL_CAPS:
                
                if (!isupper(word[i])) return false;
                
                break;
                
                case STATE_ONLY_FIRST:
                case STATE_ALL_LOWER:
                
                if (!islower(word[i])) return false;
                
                break;
        }
    }
    
    return true;
}