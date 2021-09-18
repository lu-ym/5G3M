#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * 求排列数 -- 阶乘的值，尾递归。
 * */ 
int permuteNumi(int n,int result){ 
  if(n == 1){
      return result;
  }else{
      return permuteNumi(n-1,n*result);
  }
}
// int permuteNum(int n){   // 如果是API，这样比较友好。
//     return permuteNumi(n,1);
// }
void swap(int* array,int id0,int id1){
    int temp = array[id1];
    array[id1] = array[id0];
    array[id0] = temp;
    return;
}
/**
 * @param array 双重指针，指向array数组
 * @param arrayid 目前需要用的数组id。
 * @param size 每个子数组的长度，也就是
 * */
void backtrack(int **array,int arrayid,int size,int start){
  // 终止条件，到达了末尾
  if (start == (size-1)){
    return;
  }
  int stepSize1 = permuteNumi(size-1-start,1); // next step pointer
  for (size_t i = start; i < size; i++){
    // swap value
    swap(array[arrayid],start,i);
    for (size_t j = 1; j < stepSize1; j++){ // change all subarray
      memcpy(array[arrayid+j],array[arrayid],sizeof(int)*size);
    }
    // next level swap
    backtrack(array,arrayid,size,start+1);
    // recall. Just move pointer because use different array pointer.
    arrayid+= stepSize1;
  }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = permuteNumi(numsSize,1);
    *returnColumnSizes = malloc((*returnSize)*sizeof(int));
    if (*returnColumnSizes == NULL) return NULL;
    for (size_t i = 0; i < (*returnSize); i++){
        returnColumnSizes[0][i] = numsSize;
    }
    int **permArray = (int**)malloc(sizeof(int*)*(*returnSize));
    if (permArray == NULL) return NULL;
    // 正常的malloc方式
    for (size_t i = 0; i < *returnSize; i++){
        permArray[i] = malloc(sizeof(int)*numsSize);
        if (permArray[i] == NULL){
            do{
                free(permArray[--i]);
            } while (i>0);
            return NULL;
        }else{
            // initialized w/ original data sequence.
            memcpy(permArray[i],nums,sizeof(int)*numsSize); 
        }
    }
    // malloc一个连续的空间
    // int *temp = malloc((*returnSize)*(**returnColumnSizes)*sizeof(int));
    // if (temp == NULL){
    //     free(*returnColumnSizes);
    //     free(permArray);
    //     return NULL;
    // }
    // for (size_t i = 0; i < *returnSize; i++){
    //     permArray[i] = temp + i*(**returnColumnSizes);
    //     memcpy(permArray[i],nums,sizeof(int)*numsSize); 
    // }
    backtrack(permArray,0,numsSize,0);
    // for (size_t i = 0; i < *returnSize; i++){
    //     printf("%02ld is: ",(i+1));
    //     for (size_t j = 0; j < **returnColumnSizes; j++){
    //         printf("%d ",permArray[i][j]);
    //     }
    //     printf("\r\n");
    //     // free(result[i]);
    // }
    return permArray;
}
void main(){
    int test[] = {1,2,3,4};
    int length = sizeof(test)/sizeof(int);
    int **result;
    int returnSize;
    int **returnColumnSizes = (int**)malloc(sizeof(int*)*1);
    if (returnColumnSizes == NULL) return;
    result = permute(test,length,&returnSize,returnColumnSizes);

    for (size_t i = 0; i < returnSize; i++){
        printf("%02ld is: ",(i+1));
        for (size_t j = 0; j < **returnColumnSizes; j++){
            printf("%d ",result[i][j]);
        }
        printf("\r\n");
        free(result[i]);
    }
    // free(*result);
    free(result);
    free(*returnColumnSizes);
    free(returnColumnSizes);
    return;
}