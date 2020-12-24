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
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    printf("nums1Size: %d\n", nums1Size);
    int currentIndex = nums1Size-1;
    int num1Index = nums1Size-nums2Size-1;
    int num2Index = nums2Size-1;
    
    while (currentIndex >= 0) {
        //printf("currentIndex: %d, num1Index: %d, num2Index: %d\n", currentIndex, num1Index, num2Index);
        if (num1Index >= 0 && num2Index >= 0) {
            if (nums1[num1Index] > nums2[num2Index]) {
                nums1[currentIndex--] = nums1[num1Index--];
            }
            else {
                nums1[currentIndex--] = nums2[num2Index--];
            }
        }
        else if (num1Index >= 0) {
            nums1[currentIndex--] = nums1[num1Index--];
        }
        else {
            nums1[currentIndex--] = nums2[num2Index--];
        }
    }
}