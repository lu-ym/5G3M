#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
 * 练习一下所有的排序算法：冒泡、选择、插入、希尔、归并、快排、堆、计数、桶排序、基数排序
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
提示：
1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
void swapVal(int *loc1,int *loc2 ){
    int swap = *loc1;
    *loc1 = *loc2;
    *loc2 = swap;
    return;
}
/**
 * 冒泡: 两个for循环，从头至尾的替换，每次能保证最后一个数是最小/大的
 * 时间复杂度：n^2
 * Leetcode test: 小的数组测试没问题，大的测试不过，会超时。
 * */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     int temp;
//     for (size_t i = 0; i < numsSize-1; i++)
//     {
//         for (size_t j = 0; j < numsSize-1-i; j++)   // 已经排好的在最后面，是从后向前排序。
//         {
//             if(nums[j] > nums[j+1]){
//                 temp = nums[j+1];
//                 nums[j+1] = nums[j];
//                 nums[j] = temp;
//             }
//         }
//     }
//     *returnSize = numsSize;
//     return nums;
// }
int* bobblingSort(int* nums, int numsSize){
    int temp;
    for (size_t i = 0; i < numsSize-1; i++)
    {
        for (size_t j = 0; j < numsSize-1-i; j++)   // 已经排好的在最后面，是从后向前排序。
        {
            if(nums[j] > nums[j+1]) swapVal(&nums[j],&nums[j+1]);
        }
    }
    return nums;
}
/**
 * 插入:从第二个开始，每次把下一个值插入到前面的有序队列中
 * PS： C有自己的排序函数qsort, 可以试试
 * 时间复杂度：n^2. 
 * leetcode还是在大的数组超时。
 * */
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     int temp;
//     for(size_t i = 1;i<numsSize;i++){
//         for (size_t j = 0; j < i; j++)
//         {
//             if (nums[j] > nums[i])
//             {
//                 temp = nums[j];
//                 nums[j] = nums[i];
//                 nums[i] = temp;
//             }
//         }
//     }
//     *returnSize = numsSize;
//     return nums;
// }
/**
 * 快排：分治思想。每次先找出一个中位数，把这些数据分成左右两份。然后左右分开继续次
 *  操作（分治），直到不能分为止。
 * 时间复杂度:nlg(n)
 * 暂时放弃，太不稳定了，经常fail
 * */
/**
 * 寻找一个中位数来把数组分成两部分，不一定需要等分.
 * @param nums 数组的头指针
 * @param startLoc 分区起始的位置
 * @param endLoc 分区终止的位置
 * @return 新的右侧分区的头
 * */
int partition(int* nums, int startLoc,int endLoc){
    // 可以取三个随机数的中间值来作为中位数，不一定准确，但是相对有效.
    // 算法不稳定性正是来自于此
    int a[3];
    a[0] = rand()%(endLoc - startLoc + 1) + startLoc;
    a[1] = rand()%(endLoc - startLoc + 1) + startLoc;
    a[2] = rand()%(endLoc - startLoc + 1) + startLoc;
    bobblingSort(a,3);
    // 开始分成左右两个子队列
    // startLoc--;
    while(1){
        do{  endLoc--;  }while (nums[endLoc] > a[1]);
        // do{  startLoc++;  }while (nums[startLoc] < a[1]);
        while (nums[startLoc] < a[1]){ startLoc++;  }
        if (endLoc <= startLoc ) {
            break;
        }else{
            swapVal(&nums[startLoc],&nums[endLoc]);
        }
    }
    return endLoc+1;
}
int qksort(int* nums, int startLoc,int endLoc){
    int rightLoc;
    if ((endLoc - startLoc) >= 2){ 
        rightLoc = partition(nums,startLoc,endLoc);
        // if ((rightLoc - startLoc) > 2) {
        qksort(nums,startLoc,rightLoc);
        // }
        // if ((endLoc - rightLoc) > 2) {
        qksort(nums,rightLoc,endLoc) ;
        // }
    }
    return 0;
}

// int* sortArray(int* nums, int numsSize, int* returnSize){
//     int left,right;
//     // srand(5);
//     right = qksort(nums,0,numsSize);
//     *returnSize = numsSize;
//     return nums;
// }
/**
 * 归并：先拆到最小，然后两两合并。每次合并的时候都是有序队列，按照顺序放进去即可。
 * 时间复杂度:nlg(n) 空间复杂度O(n)
 * pass: Leetcode结果。
 * 把array2 取消前后，时间从392ms变成264ms,memory从89.1MB变成60.9MB
 * */
// merge，两个都是排好序的，直接从左往后排即可
// 把array2 取消掉可以，时间从392ms变成264ms,memory从89.1MB变成60.9MB
int merge(int* nums,size_t startLoc,size_t middle,size_t endLoc){
  int size1 = middle-startLoc ;
  int pos1=0;
  int *array1 = malloc(size1*sizeof(int));
  if (array1 == NULL) return -1;
  // array2需不需要？右边的不会覆盖可以用自带的数据？
  memcpy(array1,&nums[startLoc],size1*sizeof(int)) ;   
  while(pos1 < size1 || middle < endLoc){  // 至少一个数组没有空
      if (pos1 >= size1)  // 第一个数组已经空了
      {
          nums[startLoc++] = nums[middle++];
      }else if (middle >= endLoc) // 第二个数组已经空了
      {
          nums[startLoc++] = array1[pos1++];
      }else{  // 两个数组都没有空
          if (array1[pos1] > nums[middle])
          {
              nums[startLoc++] = nums[middle++];
              /* code */
          }else{
              nums[startLoc++] = array1[pos1++];
          }
      }
  } 
  free(array1);
  // manuallly malloc array2 
  // int size2 = endLoc-middle ;
  // int pos2 =0;
  // int *array2 = malloc(size2*sizeof(int));
  // if (array2 == NULL){
  //     free(array1);
  //     return -1;
  // }
  // memcpy(array1,&nums[startLoc],size1*sizeof(int)) ;   
  // memcpy(array2,&nums[middle],size2*sizeof(int)) ;   
  // while(pos1 < size1 || pos2 < size2){  // 至少一个数组没有空
  //     if (pos1 >= size1)  // 第一个数组已经空了
  //     {
  //         nums[startLoc++] = array2[pos2++];
  //     }else if (pos2 >= size2) // 第二个数组已经空了
  //     {
  //         nums[startLoc++] = array1[pos1++];
  //     }else{  // 两个数组都没有空
  //         if (array1[pos1] > array2[pos2])
  //         {
  //             nums[startLoc++] = array2[pos2++];
  //             /* code */
  //         }else{
  //             nums[startLoc++] = array1[pos1++];
  //         }
  //     }
  // } 
  // free(array1);
  // free(array2);
  return 0;      
}
int mgsort(int* nums,size_t startLoc,size_t endLoc){
    if (endLoc - startLoc < 2 ) return 0;
    int middle = (startLoc + endLoc)/2;
    mgsort(nums,startLoc,middle);
    mgsort(nums,middle,endLoc);
    merge(nums,startLoc,middle,endLoc);
    return 0;
}
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     mgsort(nums,0,numsSize);
//     *returnSize = numsSize;
//     return nums;
// }
/**
 * 计数：找到最大值，创建一个数组，用这个数组统计每个数值出现的累计次数，
 *  根据次数来确定每个数的位置。
 * 时间复杂度:n+k.空间复杂度(k) 
 * leetcode结果：时间280ms. memory 25.8MB. memory优化比较明显。
 * */
// update max and min value int the list.
// *max and *min should be initialized by invoker.
int peekSearch(int* nums,int numsSize,int *max, int*min){
    for (size_t i = 0; i < numsSize; i++)
    {
        if (nums[i] > *max)         *max = nums[i];
        else if (nums[i] < *min)    *min = nums[i];
    }
    return 0;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    int max = 0, min = 0;
    peekSearch(nums,numsSize,&max,&min);
    int range = max - min + 1;
    int counts[range];
    memset(counts,0,range*sizeof(int));
    // memset // 数组默认初始化，全部是0，donot need memset--Wrong.
    // 统计每个数字出现的次数
    for (size_t i = 0; i < numsSize; i++) {
        counts[nums[i]-min]++;
    }
    // accumulated counts 
    for (size_t i = 0; i < range-1; i++){
        counts[i+1] += counts[i];
    }
    // sorting based on accumulated counts
    int *temp = malloc(numsSize * sizeof(int));
    if(temp == NULL) return NULL;
    for (size_t i = 0; i < numsSize; i++) {
        temp[--counts[nums[i]-min]]=nums[i];
        // counts[nums[i]-min]--;
    }
    *returnSize = numsSize;
    return temp;
}
/**
 * 基数排序：选定一个基数，对基数取余，每次按照余数确定几个位，按照从小到大的位排序。
 * 时间复杂度:n*k
 * */
// int* sortArray(int* nums, int numsSize, int* returnSize){
    // *returnSize = numsSize;
    // return nums;
// }
/**
 * 
 * */
// int* sortArray(int* nums, int numsSize, int* returnSize){
//     *returnSize = numsSize;
//     return nums;
// }

void main(){
    // int test[] = {5,3,2,1};
    int test[] = {5,1,1,0,2,0,0};
    int length = sizeof(test)/sizeof(int);
    int *result;
    result = sortArray(test,length,&length);
    for (size_t i = 0; i < length; i++){
        printf("%d ",result[i]);
    }
    printf("\r\n");
    free(result);
    return;
}