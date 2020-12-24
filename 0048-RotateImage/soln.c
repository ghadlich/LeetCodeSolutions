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
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL) return;
    if (matrixSize < 1) return;
    if (matrixColSize == NULL) return;
    
    printf("matrix size: %d\n", matrixSize);
    int rowSize = matrixSize;
    int colSize = *matrixColSize;
    for (int i = 0; i < rowSize/2; i++) {
        for (int j = i; j < colSize - i - 1; j++) {
            int temp = matrix[i][j];
            matrix[i][j]           = matrix[rowSize-j-1][i];
            matrix[rowSize-j-1][i] = matrix[rowSize-i-1][rowSize-j-1];
            matrix[rowSize-i-1][rowSize-j-1] = matrix[j][rowSize-i-1];
            matrix[j][rowSize-i-1] = temp;
        }
    }
}