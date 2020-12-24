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
    int compareVersion(string version1, string version2) {
        queue<int> q1;
        queue<int> q2;
        
        stringstream s1(version1);
        stringstream s2(version2);
        
        for (std::string line; std::getline(s1, line, '.'); ) {
            q1.push(std::stoi(line));
        }
        
        for (std::string line; std::getline(s2, line, '.'); ) {
            q2.push(std::stoi(line));
        }
        
        while (q1.size() > 0 && q2.size() > 0) {
            if (q1.front() < q2.front()) {
                return -1;
            }
            else if (q1.front() > q2.front()) {
                return 1;
            }
            q1.pop();
            q2.pop();
        }
        
        while (q1.size() > 0) {
            if (q1.front() > 0) {
                return 1;
            }
            q1.pop();
        }
        
        while (q2.size() > 0) {
            if (q2.front() > 0) {
                return -1;
            }
            q2.pop();
        }
        
        return 0;
    }
};