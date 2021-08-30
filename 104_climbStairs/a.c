#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/** 
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * 暴力解法:只x+2*y==n不对，要考虑顺序，先2再1，和先1再2。用排列组合的思想。
 * 耗时0ms, memory 5.2MB.
 * 时间复杂度分析：O(min(x,y)*n^2)
 * */
// 算x和y有多少种排列。递归算组合数  -- 纯数学方法A(m+n)n的方式，一边计算分母，一边计算分子，效果非常好
int cal(int x,int y, long accum,long div){
    if(x != 0 && y != 0){
        if(!(accum%div)){   // avoid integer overflow
            accum = accum/div;
            div = 1;
        }
        accum *= (x+y);
        if (x > y)  // 只需要用小的当分母
        {
            div *= y--;
        }else{
            div *= x--;
        }
        return cal(x,y,accum,div);
    }else{
        return (accum/div);
    }
}

int climbStairs(int n){
    int x=0;
    int y=0;
    int count = 0;
    for(x=0;x<=n;x++){
        for(y=0;y<=n;y++){
            if(x + (2*y) == n) {
                count += cal(x,y,1,1);
            }
        }
    }
    return count;
}

// TODO: Leetcode上用了动态规划、矩阵乘法、递推公式等方法来解这道题，复杂度会比这个低，可以试试。
// 算到最后，实际就是斐波那切数列，的计算方法
/*
总结
这里形成的数列正好是斐波那契数列，答案要求的 f(n) 即是斐波那契数列的第n项（下标从 0 开始）。
我们来总结一下斐波那契数列第 n 项的求解方法：

n 比较小的时候，可以直接使用过递归法求解，不做任何记忆化操作，时间复杂度是 O(2^n)O，存在很多冗余计算。
一般情况下，我们使用「记忆化搜索」或者「迭代」的方法，实现这个转移方程，时间复杂度和空间复杂度都可以做到 O(n)。
为了优化空间复杂度，我们可以不用保存 f(x−2) 之前的项，我们只用三个变量来维护 f(x)、f(x−1) 和 f(x−2)，
可以理解成是把「滚动数组思想」应用在了动态规划中，也可以理解成是一种递推，这样把空间复杂度优化到了 O(1)。
随着 n 的不断增大 O(n) 可能已经不能满足我们的需要了，我们可以用「矩阵快速幂」的方法把算法加速到 O(\log n)。
我们也可以把 n 代入斐波那契数列的通项公式计算结果，但是如果我们用浮点数计算来实现，可能会产生精度误差。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

void main(){
    int result;
    result = climbStairs(35);
    return;
}