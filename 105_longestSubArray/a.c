#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/** 
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。

提示：

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 暴力解法：两个数组，分别从头开始找自数组，有的话，log一下最长长度
 * 时间复杂度：n^3。
 * leetcode 编译显示超出时间限制。
 **/
// int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     int max_length = 0;
//     int temp_length,temp_pointer1,temp_pointer2; // use temp pointer as floating-window chek
//     for (int i = 0; i < nums1Size; i++){
//         for(int j = 0; j < nums2Size; j++){
//             temp_length = 0;
//             temp_pointer1 = i;
//             if (nums1[temp_pointer1] == nums2[j]){ // enter subArray check
//                 temp_length++;
//                 temp_pointer2 = (j+1); // use temp_pointer2 in subArray
//                 temp_pointer1++;
//                 if(temp_pointer1 != nums1Size && temp_pointer2 != nums2Size ) {
//                     // if neither hit the end, continue subArray check
//                     for (; temp_pointer2 < nums2Size; temp_pointer2++){
//                         if (nums1[temp_pointer1] == nums2[temp_pointer2]){
//                             temp_pointer1++;
//                             temp_length++;
//                             if(temp_pointer2 == (nums2Size -1)){
//                                 // B subArray hits end. Do not need check this subarray now.
//                                 j = nums2Size;
//                             }
//                             if(temp_pointer1 == nums1Size){ 
//                                 // A subArray hits end.
//                                 j = nums2Size;
//                                 i = nums1Size;
//                                 break;
//                             }
//                         }else{
//                             break;
//                         }
//                     }
//                 }
//                 if (temp_length > max_length)   max_length = temp_length;
//             }
//         }
//     }
//     return max_length;
// }
// TODO: next level study based on Leetcode
/**
 * 思路：用滑动窗的方法把相邻两个数组元素拼到一起来创建n-1个值的数组,单个值大小0-9999；
 *      用hash table来快速检索（），有匹配的，表示有一个数值对。
 * 例外： 1）数组元素为0-- 0
 *      2）总元素有一个为1 ，结果可能是0或者1
 *      3）总数组长度大于1， 但是subArray 为0 或者 1
 * */
// struct sub2Array{
//     struct sub2Array *next;
//     uint16_t    location:15;
//     uint16_t    tag:1;
//     uint16_t     value;
// };

// int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
//     if(nums1Size*nums2Size == 0)
//     {
//         return 0;
//     }
//     if(nums1Size == 1 ){
//         for(int i= 0;i<nums2Size;i++){
//             if(nums2[i] == nums1[0]){
//                 return 1;
//             }
//         }
//         return 0;
//     }else if(nums2Size == 1){
//         for(int i= 0;i<nums1Size;i++){
//             if(nums2[i] == nums1[0]){
//                 return 1;
//             }
//         }
//         return 0;
//     }
//     int max_size;

//     // 看看两个数组中有没有一个相同的值，如果有，则为1，反之则为0

//     return max_size;
// }
/**
 * 滑动窗口的解法
 * 时间复杂度（m+n）
 * 执行时间：84ms. 内存消耗：5.8MB.
 * */
// 求一个固定窗口内的最大相同组,固定区间非常好求。
int maxlen(int* temp1,int* temp2, int size,int max){
    int k = 0;
    for(int i  = 0;i< size;i++){
        if (temp1[i] == temp2[i]){
            k++;
        }else{
            k = 0;
        }
        if (k > max)    max = k;
    }
    return max;
}
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int max = 0;
    int big,small;
    int *bigArray,*smallArray;

    // nums1Size > nums2Size? (nums2Size = ):();
    if (nums1Size > nums2Size)
    {
        big = nums1Size;
        small = nums2Size;
        bigArray = nums1;
        smallArray = nums2;
    }else{
        big = nums1Size;
        small = nums2Size;
        bigArray = nums2;
        smallArray = nums1;
    }
    // 创造滑动窗，从1头2尾交叉开始，到1尾2头交叉结束
    // 要注意两个的大小，有大的完全覆盖小的情况
    // 三种情况，1）window_size < small; j+window_size < small;
    //      2) window_size == small; j==0;
    //      3) j+window_size > small;
    int window_size = 1;
    int i = 0;
    int j = small -1;
    while (i <= big){
        if ( j > 0){
            max = maxlen(bigArray,&smallArray[j],window_size,max);
            j--;
            window_size++;
        }else if( i + window_size < big){
            max = maxlen(&bigArray[i],smallArray,window_size,max);
            i++;
        }else{
            max = maxlen(&bigArray[i],smallArray,window_size,max);
            i++;
            window_size --;
        }
    }
    // return max;
}



/**
 * TODO: 官方思路：1）动态规划 2）滑动窗口 3） 二分查找+哈希
 * */
void main(){
    int result;
    // int A[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // int B[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};
    int A[] = {0,1,1,1,1};
    int B[] = {1,0,1,0,1};
    result = findLength(A,sizeof(A)/sizeof(int),B,sizeof(B)/sizeof(int));
    return;
}