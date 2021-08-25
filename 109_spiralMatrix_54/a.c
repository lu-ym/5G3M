#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
// leetcode还有一个模拟思路，用另一个数组标记是否visited,也是四个方向运动，空间复杂度高。
/**
 * 思路：按层模拟，和Leetcode标准答案思路一样，实现略有差别。
 * 时间 0ms. 内存5.6MB.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int tier = 0;
    int *flatMatrix = malloc(matrixSize *(*matrixColSize) * sizeof(int));
    if (flatMatrix == NULL) return NULL;
    int flatIndex = 0;
    int i;
    while((matrixSize > 2*tier) ||(*matrixColSize >2*tier )){
        // 第一个横向
        if (matrixSize > 2*tier)  { // 需要横向运动
            for(i = tier;i < (*matrixColSize-tier); i++){
                flatMatrix[flatIndex++] = matrix[tier][i];
            }
        }
        // 第一个竖向
        if(*matrixColSize > 2*tier){
            for(i = tier+1;i < matrixSize-tier; i++){
                flatMatrix[flatIndex++] = matrix[i][*matrixColSize-1-tier];
            }
        }
        // 横向返回
        if(matrixSize -1 > 2*tier){ // 的确有竖向运动
            for(i = *matrixColSize-2-tier;i >= tier; i--){
                flatMatrix[flatIndex++] = matrix[matrixSize-1-tier][i];
            }
        }
        
        // 竖向返回
        if(*matrixColSize - 1 > 2*tier){    // 的确有横向运动
            for(i = matrixSize-2-tier;i > tier;i--){
                flatMatrix[flatIndex++] = matrix[i][tier];
            }
        }
        tier++;
    }
    *returnSize = matrixSize*(*matrixColSize);
    return  flatMatrix;   
}
void main(){
    // int test[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // 不能这么用，要严格传入int**
    // malloc int**的初始化模式
    int rowCount = 1;
    int columnCount = 3;
    int **test;
    test = (int**)malloc(sizeof(int*)*rowCount);
    if(test == NULL) return;
    for (size_t i = 0; i < rowCount; i++)    {
        test[i] = malloc(sizeof(int)*columnCount);
        if (test[i] == NULL) {
            while(i){
                free(test[--i]);
            }
            free(test[i]);
            return;
        }
    }
    for(size_t i = 0; i < rowCount;i++){
        for (size_t j = 0; j < columnCount; j++){
            test[i][j] = i*columnCount + j +1;
        }
    }
    int *result;
    int returnSize = 0;
    result = spiralOrder(test,rowCount,&columnCount,&returnSize);
    for (size_t i = 0; i < returnSize; i++){
        printf("%d ",result[i]);
    }
    printf("\r\n");
    free(result);
    for (size_t i = 0; i < rowCount; i++)    {
            free(test[i]);
    }
    free(test);
    return;
}