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
    
    int lookup[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
    
    bool isHappy(int n) {
        unordered_map<int,int> umap;
        
        int sum = n;
        
        while (sum != 1) {
            
            int innersum = 0;
            while (sum > 0) {
                innersum += lookup[sum%10];
                sum/=10;
            }
            
            //std::cout << innersum << std::endl;
            
            if (umap.find(innersum) != umap.end()) return false;
            umap[innersum] = 1;
            sum = innersum;
        }
        
        return true;
    }
};