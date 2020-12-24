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
/*

Case 1: (arr1[i]+arr2[i]+i) - (arr1[j]+arr2[j]+j)
Case 2: (arr1[i]+arr2[i]-i) - (arr1[j]+arr2[j]-j)
Case 3: (arr1[i]-arr2[i]+i) - (arr1[j]-arr2[j]+j)
Case 4: (arr1[i]-arr2[i]-i) - (arr1[j]-arr2[j]-j)

*/


int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size){
    if (arr1 == NULL) {
        return 0;
    }
    else if (arr1Size != arr2Size) {
        return 0;
    }
    else if (arr1Size == 0 || arr2Size == 0) {
        return 0;
    }
    
    int a_max = INT_MIN;
    int a_min = INT_MAX;
    int b_max = INT_MIN;
    int b_min = INT_MAX;
    int c_max = INT_MIN;
    int c_min = INT_MAX;
    int d_max = INT_MIN;
    int d_min = INT_MAX;
    
    #define min(x,y) (x<y?x:y)
    #define max(x,y) (x>y?x:y)
    
    for (int i = 0; i < arr1Size; i < i++) {
       int a = (arr1[i]+arr2[i]+i);
       int b =  (arr1[i]+arr2[i]-i);
       int c =  (arr1[i]-arr2[i]+i);
       int d =  (arr1[i]-arr2[i]-i);
        
        a_max = max(a,a_max);
        a_min = min(a,a_min);
        b_max = max(b,b_max);
        b_min = min(b,b_min);
        c_max = max(c,c_max);
        c_min = min(c,c_min);
        d_max = max(d,d_max);
        d_min = min(d,d_min);
    }
    
    return max(max(a_max-a_min, b_max-b_min),max(c_max-c_min,d_max-d_min));
}