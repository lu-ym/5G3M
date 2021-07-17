#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/** 
 *给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。

进阶：
你能用 O(1)（即，常量）内存解决此问题吗？

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：
输入：head = [1], pos = -1
输出：false./a
解释：链表中没有环。
 

提示：
链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * 
 * */
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    struct ListNode *next;
};
/**
 * 常规思路，挨个检查，可以通过，时间240ms，内存7.9MB.
 * 几个例外，这个一个空链表，或者链表只有一个元素。还有就是链表里面的环是自己本身
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL){
        return false;
    } 
    struct ListNode *temp1;
    temp1 = head->next;
    for(;temp1->next != NULL;temp1 = temp1->next){
        struct ListNode *temp2;
        // check self circle
        if(temp1->next == temp1){
            return true;
        }
        // only check the previous Listnode. if there is a node equals current node, 
        // this is a circle
        for(temp2 = head;temp2 != temp1; temp2 = temp2->next){
            if(temp2 == temp1->next){
                return true;
            }
        }
    }
    return false;;
}

/**
 * 基于上面的改进优化版 -- 没有任何优化,memory没有变小，运行时间还变长了。
 * */
bool hasCycle(struct ListNode *head) {
    struct ListNode *temp1;
    temp1 = head->next;
    while (temp1 != NULL && temp1->next != NULL)
    {
         struct ListNode *temp2;
        // check self circle
        if(temp1->next == temp1){
            return true;
        }
        // only check the previous Listnode. if there is a node equals current node, 
        // this is a circle
        for(temp2 = head;temp2 != temp1; temp2 = temp2->next){
            if(temp2 == temp1->next){
                return true;
            }
        }
    }
    return false;
} 
/**
 * Leetcode 解题思路，快慢指针，因为有环，快慢指针总会相遇的
 * 耗时：12ms,果然很快。 -->因为少了很多cycle
 * memory: 7.8MB. 还好。
 * */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast;
    struct ListNode *slow;
    fast = head;
    slow = head;
    while(fast != NULL){
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        if(slow = fast){
            return true;
        }
        slow = slow->next;
    }
    return false;
} 
/**
 * TODO: 哈希表法：
 * */


void main(){
    struct ListNode *head = malloc(4*sizeof(struct ListNode));
    struct ListNode t1;
    struct ListNode t2;
    struct ListNode t3;
    struct ListNode t4;
    t1.val =3;
    t2.val =2;
    t3.val =0;
    t4.val =-4;
    head=&t1;
    t1.next=&t2;
    t2.next=&t3;
    t3.next=&t4;
    t4.next=&t2;
    hasCycle(head);
    return;
}