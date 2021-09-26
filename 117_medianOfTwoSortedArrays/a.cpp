#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
// #include <cstdlib>
// #include <ctime>
#include <climits>
using namespace std;
/** 
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这
 *  两个正序数组的 中位数 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：
输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：
输入：nums1 = [2], nums2 = []
输出：2.00000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */
/**
 * 最终难点：时间复杂度优化到log(m+n)
*/
/**
 * 常规方法：排序，排到一半直接输出
 * 时间复杂度O((m+n)/2) == O(m+n)
 * 时间 40ms. memory 86.9MB.
 * 优化，直接从中间开始找。难点，如何确认是中值，顺序怎么拍？ -- 见下方官方思路。
*/
// class Solution {
// public:
//   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     int middleLoc1 = (nums1.size() + nums2.size())/2;
//     int middleLoc2 = middleLoc1 + 1;
//     int middleV1 = 0,middleV2 =0;
//     vector<int>::const_iterator it1 = nums1.begin(),it2=nums2.begin();
//     // vector<int>::iterator it0 = nums1.begin(),it1=nums2.begin();
//     for (int i = 0; i < middleLoc2; i++){
//       middleV1 = middleV2;
//       if (it1 == nums1.end()){
//         middleV2 = *it2++;
//       }else if (it2 == nums2.end()){
//         middleV2 = *it1++;
//       }else{
//         if (*it1 > *it2){
//           middleV2 = *it2++;
//         }else{
//           middleV2 = *it1++;
//         }
//       }
//     }
//     if ((nums1.size() + nums2.size())%2) return (double)middleV2;
//     else return ((double)middleV1 + middleV2) /2;
//   }
// };
/**
 * 官方解法一，感觉没有解法二简单。可以大概了解一下。
 * 作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
*/
// class Solution {
// public:
//   int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
//     /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
//       * 这里的 "/" 表示整除
//       * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
//       * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
//       * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
//       * 这样 pivot 本身最大也只能是第 k-1 小的元素
//       * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
//       * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
//       * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
//       */

//     int m = nums1.size();
//     int n = nums2.size();
//     int index1 = 0, index2 = 0;

//     while (true) {
//       // 边界情况
//       if (index1 == m) {
//         return nums2[index2 + k - 1];
//       }
//       if (index2 == n) {
//         return nums1[index1 + k - 1];
//       }
//       if (k == 1) {
//         return min(nums1[index1], nums2[index2]);
//       }

//       // 正常情况
//       int newIndex1 = min(index1 + k / 2 - 1, m - 1);
//       int newIndex2 = min(index2 + k / 2 - 1, n - 1);
//       int pivot1 = nums1[newIndex1];
//       int pivot2 = nums2[newIndex2];
//       if (pivot1 <= pivot2) {
//         k -= newIndex1 - index1 + 1;
//         index1 = newIndex1 + 1;
//       }
//       else {
//         k -= newIndex2 - index2 + 1;
//         index2 = newIndex2 + 1;
//       }
//     }
//   }

//   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     int totalLength = nums1.size() + nums2.size();
//     if (totalLength % 2 == 1) {
//       return getKthElement(nums1, nums2, (totalLength + 1) / 2);
//     }
//     else {
//       return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
//     }
//   }
// };

/**
 * leetcode官方解法二. 从中间开始查找。
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
 * */
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // always keep nums1.size <= nums2.size
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size();
    int n = nums2.size();
    int left = 0, right = m;
    // median1：前一部分的最大值
    // median2：后一部分的最小值
    int median1 = 0, median2 = 0;

    while (left <= right) { // 叠加left =, right =的操作，保证i是满足<=的最大值。
        // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
        // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
        int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
        int nums_i = (i == m ? INT_MAX : nums1[i]);
        int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
        int nums_j = (j == n ? INT_MAX : nums2[j]);

        if (nums_im1 <= nums_j) { 
            median1 = max(nums_im1, nums_jm1);
            median2 = min(nums_i, nums_j);
            left = i + 1;
        } else {
            right = i - 1;
        }
    }

    return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
  }
};

int main(){
  // vector<int> nums1 = {1,2},nums2 = {3,4};
  vector<int> nums1 = {1,3},nums2 = {2};
  Solution sl;
  float result = sl.findMedianSortedArrays(nums1,nums2);
  cout << result << endl;
  return 0;
}