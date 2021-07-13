#include <stdint.h>
#include <string.h>
#include <stdio.h>


/**
 * https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665?tpId=117&&tqId=37727
 * 描述
    给出一个整数数组 和有序的整数数组 ，请将数组 合并到数组 中，变成一个有序的升序数组
    注意：
    1.可以假设 数组有足够的空间存放 数组的元素， 和 中初始的元素数目分别为 和 ，的数组空间大小为 + 
    2.不要返回合并的数组，返回是空的，将数组 的数据合并到里面就好了
    3.数组在[0,m-1]的范围也是有序的

    例1:
    A: [1,2,3,0,0,0]，m=3
    B: [2,5,6]，n=3
    合并过后A为:
    A: [1,2,2,3,5,6]
*/
/**
 * 3ms, 360K
 * 归并有序数组。个人实现，简单，但是效率一般。
 * @param A int整型一维数组 
 * @param ALen int A数组长度
 * @param B int整型一维数组 
 * @param BLen int B数组长度
 * @return void
 */
// void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
//     // write code here
//     int i,j,k;
//     int temp[m];
//     memcpy((int*)temp, (int*)A, m*sizeof(int));   
//     i=0;
//     j=0;
//     for(k=0;k<(m+n);k++)
//     {
//         if(i == m ){
//             A[k] = B[j];
//             j++;
//         }else if(j == n){
//             A[k] = temp[i];
//             i++;
//         }else if(temp[i]<B[j]){
//             A[k] = temp[i];
//             i++;
//         }else{
//             A[k] = B[j];
//             j++;
//         }
//     }
    
// }

// leetcode思路，因为数组内部也是有序的，就按顺序先倒着放大的，最后再剩余的小的。
// C++实现，不能直接用
// 作者：ikaruga
// 链接：https://leetcode-cn.com/problems/merge-sorted-array/solution/88-by-ikaruga/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     int i = nums1.size() - 1;
//     m--;
//     n--;
//     while (n >= 0) {
//         while (m >= 0 && nums1[m] > nums2[n]) {
//             swap(nums1[i--], nums1[m--]);
//         }
//         swap(nums1[i--], nums2[n--]);
//     }
// }
/**
 * 3ms, 364K
 * @param A int整型一维数组 
 * @param ALen int A数组长度
 * @param B int整型一维数组 
 * @param BLen int B数组长度
 * @return void
 */
void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    int i = ALen - 1;
    // int i = ALen+BLen - 1;  // 牛客网的input或者其他参数有问题
    m--;
    n--;
    while(n>=0){
        while (m>=0 && A[m]>B[n]){
            A[i--] = A[m--];
        }
        A[i--]=B[n--];
    }
}

//另外一个牛客网的思路，C++的。
// 3ms, 492K
// class Solution {
// public:
//     void merge(int A[], int m, int B[], int n) {
//          //因为题目明确说了A数组足够大，所以直接在A数组操作
//         int i = m - 1;
//         int j = n - 1;
//         int index = m + n - 1;//AB合并后最后一个元素所在位置
//         while(i >= 0 && j>= 0)//AB合并，谁大就先放谁
//             A[index --] = A[i] > B[j] ? A[i --] : B[j --];
//         while(j >= 0)//如果B没有遍历完，那么之间丢在A数组里面
//             A[index--] = B[j --];
//     }
// };
void main(){
    int i=0;
    int A[6] = {4,5,6};
    int B[3] = {1,2,3};
    merge(A,6,3,B,3,3);
    for ( i = 0; i < 6; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\r\n",A[i]);
    
}