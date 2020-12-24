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
    
    void countWord() {
        if (word.length() > 0) {
            if (m.find(word) == m.end()) {
                m[word] = 1;
            }
            else {
                m[word] += 1;
            }
        }
        word = "";
    }
    
    map<string,int> m;
    string word;
    
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for (auto s : banned) {
            m[s] = INT_MIN;
        }
        
        for (char a : paragraph) {
            if (isalpha(a)) {
                word+=tolower(a);
            }
            else {
                countWord();
            }
        }
        countWord();
        
        string max;
        int max_count = 0;
        
        for (auto a : m) {
            if (a.second > max_count) {
                max = a.first;
                max_count = a.second;
            }
        }
        
        return max;
    }
};