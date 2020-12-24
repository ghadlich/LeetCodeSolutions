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
#define min(a,b) (a<b?a:b)

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrix == NULL) return 0;
    if (matrixSize < 1) return 0;
    if (matrixColSize == NULL) return 0;
    
        for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            printf("%d ", matrix[i][j]-'0');
        }
        printf("\n");
    }
    
    printf("\n");
    char** dp = (char**)calloc(matrixSize,sizeof(char*));
    
    for (int i = 0; i < matrixSize; i++) {
        dp[i] = (char*)calloc(*matrixColSize, sizeof(char));
    }
    
    for (int i = 0; i < matrixSize; i++) {
        dp[i][0] = matrix[i][0]-'0';
    }
    
    for (int i = 0; i < *matrixColSize; i++) {
        dp[0][i] = matrix[0][i]-'0';
    }
    
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]) + 1;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    int max = INT_MIN;
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            printf("%d ", dp[i][j]);
            if (dp[i][j] > max) max = dp[i][j];
        }
        printf("\n");
    }

    return max*max;
}