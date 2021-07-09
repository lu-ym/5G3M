#include <stdint.h>
#include <string.h>



/**
 * 归并有序数组。个人实现，简单，但是效率一般。
 * @param A int整型一维数组 
 * @param ALen int A数组长度
 * @param B int整型一维数组 
 * @param BLen int B数组长度
 * @return void
 */
void merge(int* A, int ALen, int m, int* B, int BLen, int n) {
    // write code here
    int i,j,k;
    int temp[m];
    memcpy((int*)temp, (int*)A, m*sizeof(int));   
    i=0;
    j=0;
    for(k=0;k<(m+n);k++)
    {
        if(i == m ){
            A[k] = B[j];
            j++;
        }else if(j == n){
            A[k] = temp[i];
            i++;
        }else if(temp[i]<B[j]){
            A[k] = temp[i];
            i++;
        }else{
            A[k] = B[j];
            j++;
        }
    }
    
}

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



void main(){
    int A[6] = {4,5,6};
    int B[3] = {1,2,3};
    merge(A,6,3,B,3,3);
}