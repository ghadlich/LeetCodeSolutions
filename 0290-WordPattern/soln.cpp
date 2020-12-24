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
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> hmap;
        unordered_map<string,char> hmap2;
        
        vector<string> tokens;

        stringstream ss(str); 

        string temp; 
        
        while(getline(ss, temp, ' ')) 
        { 
            tokens.push_back(temp); 
        } 
        
        int index = 0;
        
        if (tokens.size() != pattern.length()) return false;
        
        for (char c : pattern) {
            if (hmap.find(c) == hmap.end()) {
                hmap[c] = tokens.at(index);
            }
            else {
                if (hmap[c] != tokens.at(index)) {
                    return false;
                }
            }
            
            if (hmap2.find(tokens.at(index)) == hmap2.end()) {
                hmap2[tokens.at(index)] = c;
            }
            else {
                if (hmap2[tokens.at(index)] != c) {
                    return false;
                }
            }
            index++;
        }
        
        index = 0;
        
        for (char c : pattern) {
            if (hmap[c] != tokens.at(index++)) {
                return false;
            }
        }
        
        return true;
    }
};