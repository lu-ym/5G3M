#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/** 
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"
示例 3：
输入：s = "a"
输出："a"
示例 4：
输入：s = "ac"
输出："a"

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * 思路一：一正一反两个方向找，区别是找到后要校验一下子串的首尾是不是原来的同一位置，
 * 有可能是中间的反向相同，但是不是回文
 * 
根据回文串的定义，正着和反着读一样，那我们是不是把原来的字符串倒置了，然后找最长的
    公共子串就可以了。例如 S = "caba" ，S = "abac"，最长公共子串是 "aba"，所以原字符串的最长回文串就是 "aba"。

关于求最长公共子串（不是公共子序列），有很多方法，这里用动态规划的方法，
整体思想就是，申请一个二维的数组初始化为 0，然后判断对应的字符是否相等，相等的话

arr [ i ][ j ] = arr [ i - 1 ][ j - 1] + 1 。

当 i = 0 或者 j = 0 的时候单独分析，字符相等的话 arr [ i ][ j ] 就赋为 1 。

arr [ i ][ j ] 保存的就是公共子串的长度。

再看一个例子，S="abc435cba"，S="abc534cba"，最长公共子串是 "abc" 和 "cba"，但很明显
    这两个字符串都不是回文串。

所以我们求出最长公共子串后，并不一定是回文串，我们还需要判断该字符串倒置前的下标和当前的
    字符串下标是不是匹配。

比如 S="caba"，S'="abac" ，S’ 中 aba 的下标是 0 1 2 ，倒置前是 3 2 1，和 S 中 aba 
    的下标符合，所以 aba 就是我们需要找的。当然我们不需要每个字符都判断，我们只需要判断末尾字符就可以。

首先 i，j 始终指向子串的末尾字符。所以 j 指向的红色的 a 倒置前的下标是 beforeRev = 
    length-1-j=4-1-2=1，对应的是字符串首位的下标，我们还需要加上字符串的长度才是
    末尾字符的下标，也就是 beforeRev+arr\[i][j]-1=1+3-1=3，因为 arr\[i][j] 保存的
    就是当前子串的长度，也就是图中的数字 3。此时再和它与 i 比较，如果相等，则说明它是我们要找的回文串。

之前的 S="abc435cba"，S'="abc534cba"，可以看一下图示，为什么不符合。

当前 j 指向的 c，倒置前的下标是 beforeRev=length-1-j=9-1-2=6，对应的末尾下标是
    beforeRev+arr\[i][j]-1=6+3-1=8，而此时 i=2，所以当前的子串不是回文串。

代码的话，在上边的基础上，保存 maxLen 前判断一下下标匹不匹配就可以了。
时间复杂度：两层循环 O(n²)。

空间复杂度：一个二维数组 O(n²)。

空间复杂度其实可以再优化一下。
我们分析一下循环，i=0，j=0，1，2...8 更新一列，然后 i=1，再更新一列，而更新的时候我们其实
    只需要上一列的信息，更新第 3 列的时候，第 1 列的信息是没有用的。所以我们只需要一个一维数组
    就可以了。但是更新 arr [i] 的时候我们需要 arr[i-1] 的信息，假设 a[3]=a[2]]+1，更新 a[4] 
    的时候， 我们需要 a[3] 的信息，但是 a[3] 在之前已经被更新了，所以 j 不能从0到 8，
    应该倒过来，a[8]=a[7]+1，a[7]=a[6]+1, 这样更新 a[8] 的时候用 a[7]，用完后才去更新 a[7]，保证了不会出错。

时间复杂度 O(n²)。
空间复杂度降为 O(n)。

作者：windliang
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */
// char * longestPalindrome(char * s){
//     if (s == NULL)  return NULL;
//     // 思路：两个指针，一头一尾（没有尾？）开始查找
//     char *head,*tail;
//     int len = 1;
//     int max_len = 0;
//     head = s;
//     tail = s;
//     while(++s != NULL){ 
//         tail = s;   // get tail
//         len++;
//     }

    

//     return max_len;
// }
/**
 * 方法二：中心扩展算法
思路与算法

我们仔细观察一下方法一中的状态转移方程：

找出其中的状态转移链：

可以发现，所有的状态在转移的时候的可能性都是唯一的。也就是说，我们可以从每一种边界情况
    开始「扩展」，也可以得出所有的状态对应的答案。

边界情况即为子串长度为 11 或 22 的情况。我们枚举每一种边界情况，并从对应的子串开始不断
    地向两边扩展。如果两边的字母相同，我们就可以继续扩展，例如从 P(i+1,j-1)P(i+1,j−1) 
    扩展到 P(i,j)P(i,j)；如果两边的字母不同，我们就可以停止扩展，因为在这之后的子串都不能是回文串了。

聪明的读者此时应该可以发现，「边界情况」对应的子串实际上就是我们「扩展」出的回文串的
    「回文中心」。方法二的本质即为：我们枚举所有的「回文中心」并尝试「扩展」，直到无法
    扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度。我们对所有的长度
    求出最大值，即可得到最终的答案。

复杂度分析
时间复杂度：O(n^2)，其中 n 是字符串的长度。长度为 1 和 2 的回文中心分别有 n和 n-1个，
    每个回文中心最多会向外扩展 O(n)次。
空间复杂度：O(1)。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */
// pass. Time 16ms. Memory:6.2MB.
/**
 * @param left 左边的字符
 * @param right 右边的字符
 * @param leftIndex 目前left的索引，用来检查整个string头
 * @return >0:回文串长度. At least 1.
 * */
int expandAroundCenter(const char *left,const char *right,int leftIndex){
  int length = 0;
    while ((leftIndex >= 0) &&(*right != '\0') && (*left)==(*right)) {
        length += 2;
        leftIndex--;
        left--;
        right++;
    }
    if (length > 0){
        left++;
        right--;
    }
    return length;
}
char * longestPalindrome(char * s){
    if (s == NULL || *(s+1) == '\0')  return s;
    char *head = s;
    char *left,*right;
    int curIndex = 0;
    char *palindromeHead = s;   // at least 1
    int maxPalindrome = 1;
    int tempLength = 1; // at least 1.
    while(*(s+1) != '\0'){   // check char rather than pointer
        // 以当前位置和下一位置的pair组合为中心点
        left = s;
        right = s+1;
        tempLength = expandAroundCenter(left,right,curIndex);
        if (tempLength > maxPalindrome)
        {
            maxPalindrome = tempLength;
            palindromeHead = left+1 -(tempLength/2);
        }
        s++;
        curIndex++;
    }
    s = head;
    curIndex = 0;   
    if (strlen(s) > 2 ){  // there should be at least 3 letters.
        while(*(s+2) != '\0'){   // check char rather than pointer
            left = s;
            right = s+2;
            // 以当前位置的下一个点为中心点
            tempLength = expandAroundCenter(left,right,curIndex);
            tempLength++;   // 必须加上中心的这个
            if (tempLength > maxPalindrome)
            {
                maxPalindrome = tempLength;
                palindromeHead = left + 1 - (tempLength/2);
            }
            s++;
            curIndex++;
        }
    }
    char *palindrome = malloc(maxPalindrome+1); // should include NULL as end
    if (palindrome == NULL) return NULL;
    memset(palindrome,0,maxPalindrome+1);   // confirm ends w/ NULL
    if (palindromeHead == NULL) return NULL;
    strncpy(palindrome,palindromeHead,maxPalindrome);
    return palindrome;
} 

/**
 * 动态规划，题解参见one note or leetcode.
 * https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/
 * */

void main(){
  int result;
    // char testString[] = "babad";
    char testString[] = "aaaa";
    // char *testString;
    // testString = malloc(6*sizeof(char));
    // if(testString == NULL) return;
    // strcpy(testString,"babad");
    char *palindrome;
    palindrome  = longestPalindrome(testString);
    // free(testString);
    free(palindrome);
    return;
}