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


int lengthOfLongestSubstringTwoDistinct(char * s){

    int length = strlen(s);
    
    char hashMap[256];
    
    memset(hashMap, 0, sizeof(char)*256);
    
    int longestRepeatedSubstring = 0;
    
    for (int i = 0; i < length; i++) {
        int repeatedSubstringLength = 0;
        int repeatedChars = 0;
        char first = '\0';
        
        for (int j = i; j < length; j++) {
            // First Time Seeing this character
            if (hashMap[s[j]] == 0) {
                if (repeatedChars == 2) {
                    break;
                }
                
                hashMap[s[j]] = 1;
                repeatedSubstringLength++;
                
                if (repeatedChars == 0) {
                    first = s[j];
                    repeatedChars++;
                }
                else if ((repeatedChars == 1) && (first != s[j])) {
                    repeatedChars++;
                }
                
            }
            // Character Seen Before
            else {
                if ((repeatedChars == 1) && (first != s[j])) {
                    repeatedChars++;
                }
                
                repeatedSubstringLength++;
            }
        }

        if (repeatedSubstringLength > longestRepeatedSubstring) {
            longestRepeatedSubstring = repeatedSubstringLength;
        }
        memset(hashMap, 0, sizeof(char)*256);
    }
 
    return longestRepeatedSubstring;
    
}