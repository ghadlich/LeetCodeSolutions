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
#include <stack>
#include <iostream>

class Solution {
private:
    std::stack<char> createStack(string S) {
        std::stack<char> s_stack;
        
        for (char a : S) {
            if (a != '#') {
                s_stack.push(a);
            }
            else if (s_stack.size() > 0) {
                s_stack.pop();
            }
        }
        
        return s_stack;
    }
public:
    bool backspaceCompare(string S, string T) {
        std::stack<char> s_stack = createStack(S);
        std::stack<char> t_stack = createStack(T);
        
        if (s_stack.size() != t_stack.size()) return false;
        
        while (s_stack.size() && t_stack.size()) {
            char s = s_stack.top();
            char t = t_stack.top();
            
            if (s != t) return false;
            s_stack.pop(); t_stack.pop();
        }
        
        return (s_stack.size() == t_stack.size());
    }
};