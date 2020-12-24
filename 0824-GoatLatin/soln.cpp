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
class Solution {
private:
    inline bool isVowel(char a) {
        char low = tolower(a);
        
        return (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u');
    }
    
    inline void finishWord() {
        activeWord = true;
                
        if (stack.size() > 0) {
            out += stack.top();
            stack.pop();
        }
                
        out += 'm';
        out += 'a';
                
        aaa += 'a';
        out += aaa;
        
    }
    
    int a_count = 1;
    bool activeWord = true;
    std::stack<char> stack;
    string out;
    string aaa;
    
public:
    string toGoatLatin(string S) {

        for (char a : S) {
            if (activeWord) {
                if (isVowel(a)) {
                    out += a;
                }
                else {
                    stack.push(a);
                }

                activeWord = false;
            }
            else if (a == ' ') {
                finishWord();
                out += ' ';
                a_count++;
            }
            else {
                out += a;
            }
        }
        
        finishWord();
        
        return out;
    }
};