#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，
 * 使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
https://leetcode-cn.com/problems/minimum-path-sum/
 * */
/**
 * 动态规划，标准方法
 * leetcode 时间：8ms. 内存：7.3MB
 * */
int minPathSum(int** grid, int gridSize, int* gridColSize){
    if ((grid == NULL)|| (*grid == NULL)) return 0;
    for (size_t i = 0; i < gridSize; i++){
        for (size_t j = 0; j < *gridColSize; j++) {
            if (i == 0 && j == 0){
                continue;
            }
            if (i == 0) {
                grid[i][j] = grid[i][j-1] +  grid[i][j];
            }else if (j==0){
                grid[i][j] = grid[i-1][j] +  grid[i][j];
            }else{
                if ((grid[i][j-1]+grid[i][j])>(grid[i-1][j]+grid[i][j]))
                {
                    grid[i][j] = grid[i-1][j]+grid[i][j];
                }else{
                    grid[i][j] = grid[i][j-1]+grid[i][j];
                }
            }
        }
    }
    return grid[gridSize-1][*gridColSize-1];
}
void main(){
    // int test[] = {5,3,2,1};
    // malloc int**的初始化模式
    int **test;
    int colSize = 3;
    test = (int**)malloc(sizeof(int*)*3);
    if(test == NULL) return;
    for (size_t i = 0; i < 3; i++)    {
        test[i] = malloc(sizeof(int)*3);
        if (test[i] == NULL) {
            while(i){
                free(test[--i]);
            }
            free(test[i]);
            return;
        }
    }
    test[0][0] = 1;
    test[0][1] = 3;
    test[0][2] = 1;
    test[1][0] = 1;
    test[1][1] = 5;
    test[1][2] = 1;
    test[2][0] = 4;
    test[2][1] = 2;
    test[2][2] = 1;
    int result;
    result = minPathSum(test,3,&colSize);
    printf("%d ",result);
    printf("\r\n");
    for (size_t i = 0; i < 3; i++)    {
            free(test[i]);
    }
    free(test);
    return;
}