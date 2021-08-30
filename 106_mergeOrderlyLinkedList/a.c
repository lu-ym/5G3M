#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/** 
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * c常规思路：迭代
 * 复杂度分析

时间复杂度：O(n + m)，其中 nn 和 mm 分别为两个链表的长度。因为每次循环迭代中，l1 和 l2 
    只有一个元素会被放进合并链表中， 因此 while 循环的次数不会超过两个链表的长度之和。
    所有其他操作的时间复杂度都是常数级别的，因此总的时间复杂度为 O(n+m)。

空间复杂度：O(1)。我们只需要常数的空间存放若干变量。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL)    return NULL;
    if(l1 == NULL )                 return l2;
    if(l2 == NULL)                  return l1;
    struct ListNode *temp,*head;
    if(l1->val < l2->val)   {
        temp = l1;
        l1 = l1->next;
    }    else   {
        temp = l2;
        l2 = l2->next;
    } 
    head = temp;
    while(1){
        
        if(l1 == NULL){
            temp->next = l2;
            break;
        }else if(l2 == NULL){
            temp->next = l1;
            break;
        }
        if(l1->val < l2->val)   {
            temp->next = l1;
            l1 = l1->next;
        }else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    return head;
}
/**
 * leetcode 思路，递归，更简化
 * 思路

我们可以如下递归地定义两个链表里的 merge 操作（忽略边界情况，比如空链表等）：

也就是说，两个链表头部值较小的一个节点与剩下元素的 merge 操作结果合并。

算法

我们直接将以上递归过程建模，同时需要考虑边界情况。

如果 l1 或者 l2 一开始就是空链表 ，那么没有任何操作需要合并，所以我们只需要返回非空链表。
否则，我们要判断 l1 和 l2 哪一个链表的头节点的值更小，然后递归地决定下一个添加到结果里的节点。
如果两个链表有一个为空，递归结束。

C++

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
复杂度分析

时间复杂度：O(n + m)O(n+m)，其中 nn 和 mm 分别为两个链表的长度。因为每次调用递归都会去掉 
    l1 或者 l2 的头节点（直到至少有一个链表为空），函数 mergeTwoList 至多只会递归调用每个节点一次。
    因此，时间复杂度取决于合并后的链表长度，即 O(n+m)O(n+m)。

空间复杂度：O(n + m)O(n+m)，其中 nn 和 mm 分别为两个链表的长度。递归调用 mergeTwoLists 
    函数时需要消耗栈空间，栈空间的大小取决于递归调用的深度。结束递归调用时 mergeTwoLists 
    函数最多调用 n+m 次，因此空间复杂度为 O(n+m)O(n+m)。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * */



void main(){
    int result;

    return;
}