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
    vector<int> prevPermOpt1(vector<int>& A) {
        
        int n = A.size();
        
        if (is_sorted(A.begin(), A.end()))
            return A;
        
        int i = 0;
        for (i = n-1; i > 0; i--) {
            if (A[i-1] > A[i])
                break;
        }
        
        int s = i-1;
        int mx = INT_MIN;
        int index = i;
        for (; i < n; i++) {
            if (A[i] < A[s] && A[i] > mx) {
                mx = A[i];
                index = i;
            }
        }
        
        swap(A[s], A[index]);
            
        return A;
    }
};