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
    struct Dis{
        int d;
        int worker;
        int bike;
        bool operator<(const Dis& rhs) const {
            if(rhs.d != d) return d > rhs.d;
            if(worker != rhs.worker) return worker > rhs.worker;
            return bike > rhs.bike;
        }
    };
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<Dis> q;
        for(int i=0;i<workers.size();i++){
            for(int j=0;j<bikes.size();j++){
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                q.push({d, i, j});    
            }
        }
        vector<int> v(workers.size(), -1);
        vector<bool> visitedBike(bikes.size(), false);
        while(!q.empty()){
            auto [d, i, j] = q.top(); q.pop();
            if(v[i] == -1 && visitedBike[j] == false){
                visitedBike[j] = true;
                v[i] = j;
            }                
        }
        return v;
    }
};