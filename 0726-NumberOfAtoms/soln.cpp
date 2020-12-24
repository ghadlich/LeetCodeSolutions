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

class Solution {
public:
    string countOfAtoms(string formula) {
        string symbol = "";
        stack<int> s;
        map<string, int> elements;
        int pow10 = 1;
        int num = 0;
        int multiplier = 1;
        
        for (int i = formula.length()-1; i >= 0; i--) {
            char current = formula[i];
            
            if (islower(current)) {
                symbol = current;
            }
            else if (isupper(current)) {
                symbol = current + symbol;
                num = max(num,1);
                elements[symbol] += num*multiplier;
                symbol = "";
                num = 0;
                pow10 = 1;
            }
            else if (current == ')') {
                num = max(num,1);
                multiplier = num*multiplier;
                s.push(num);
                num=0;
                pow10=1;
            }
            else if (current == '(') {
                multiplier = multiplier/s.top();
                s.pop();
                num = 0;
                pow10=1;
            }
            else if (isdigit(current)) {
                num = (current-'0')*pow10+num;
                pow10 *= 10;
            }
        }
        
        string ret;
        
        for (auto x: elements) {
            ret += x.first + ((x.second==1)?"":to_string(x.second));
        }
        
        return ret;
    }
};