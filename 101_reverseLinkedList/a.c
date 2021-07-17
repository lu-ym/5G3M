#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/** 
 * 以前在数据结构课上，老师和我们说：涉及到链表的操作，一定要在纸上把过程先画出来，再写程序。
 * */

/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：

输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：

输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
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
 * 迭代法，简单有效。时间复杂度O(n),空间复杂度O(1)
 * 复杂度分析
时间复杂度：O(n)O(n)，其中 nn 是链表的长度。需要遍历链表一次。
空间复杂度：O(1)O(1)。
 * leetcode执行耗时：4ms
 *  memory:6.4MB
 * */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    struct ListNode * cur,*pre,*next;
    pre = head;
    cur = head->next;
    pre->next = NULL;
    while (cur!=NULL){
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

/**
 * 递归的方法，复杂度较高，但是代码比较简单
使用递归函数，一直递归到链表的最后一个结点，该结点就是反转后的头结点，记作 retret .
此后，每次函数在返回的过程中，让当前结点的下一个结点的 nextnext 指针指向当前节点。
同时让当前结点的 nextnext 指针指向 NULLNULL ，从而实现从链表尾部开始的局部反转
当递归函数全部出栈后，链表反转完成。
作者：huwt
链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-shuang-zhi-zhen-di-gui-yao-mo-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 * 复杂度分析
时间复杂度：O(n)，假设 n 是列表的长度，那么时间复杂度为 O(n)。
空间复杂度：O(n)，由于使用递归，将会使用隐式栈空间。递归深度可能会达到 n 层。
作者：LeetCode
链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
来源：力扣（LeetCode）

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
实际耗时：4ms
内存消耗：6.4MB
 * */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode * cur,*result;
    // head must be the first check item to avoid NULL linked list.
    if (head == NULL || head->next == NULL )
    {
        return head;
    }else{
        result = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return result;
    }
}

void main(){
    struct ListNode *head;
    struct ListNode *cur;
    struct ListNode *temp;
    struct ListNode *result;
    head = malloc(sizeof(struct ListNode ));
    head->val = 1;
    head->next = NULL;
    cur = head;
    for (int i = 2; i < 6; i++)
    {
        temp = malloc(sizeof(struct ListNode ));
        temp->next = NULL;
        temp->val = i;
        cur->next = temp;
        cur = cur->next;
    }
    result = reverseList(head);
    return;
}