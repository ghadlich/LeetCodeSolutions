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
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m_;
        stack<char> s_;
        unordered_map<char,bool> seen;
        
        for (int i = 0; i < s.length(); i++) {
            m_[s[i]] = i;
        }

        
        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            
            if (!seen[a]){
                while (!s_.empty() && a < s_.top() && m_[s_.top()] > i) {
                    seen[s_.top()] = false;
                    s_.pop();
                }
                
                seen[a] = true;
                s_.push(a);
            }
        }
        
        
        string ret = "";
        
        while (!s_.empty()) {
            ret = s_.top() + ret;
            s_.pop();
        }
        
        return ret;
    }
};