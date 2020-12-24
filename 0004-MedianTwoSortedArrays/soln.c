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
double findMedianSortedArrays(int* nums1, int num1Size, int* nums2, int num2Size){
   int *array = calloc(num1Size+num2Size,sizeof(int));
   int size = num1Size+num2Size;
   int i = 0, j = 0, k = 0;
   double median = 0;
    
   while(i < num1Size || j < num2Size) {
       if (i < num1Size && j < num2Size) {
           if (nums1[i] < nums2[j]) {
               array[k++] = nums1[i++];
           }
           else {
               array[k++] = nums2[j++];
           }
       }
       else if (i < num1Size) {
           array[k++] = nums1[i++];
       }
       else {
           array[k++] = nums2[j++];
       }
       printf ("array[%d] = %d\n", k-1, array[k-1]);
   }
    
   if (size % 2 == 0) {
       median = (double)(array[size/2]+array[(size/2)-1])/2;
   }
   else {
       median = (double)(array[(size/2)]);
    }
    
    free(array);
    return median;
}