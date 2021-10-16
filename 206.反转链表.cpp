/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.34%)
 * Likes:    2019
 * Dislikes: 0
 * Total Accepted:    723.1K
 * Total Submissions: 999.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* // 使用swap()函数交换指针
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* temp;
    for (temp = nullptr; head != nullptr;) {
      swap(temp, head->next);
      swap(head, temp);
    }

    return temp;
  }
}; */

/* // 迭代法
// 假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3。
// 在遍历链表时，将当前节点的 next 指针改为指向前一个节点。
// 由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。
// 在更改引用之前，还需要存储后一个节点。最后返回新的头引用。
// 返回的是prev指针,不是cur指针,如果返回cur指针,head就是NULL
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *cur, *prev, *nextn;
    prev = nullptr;
    cur = head;
    while (cur != nullptr) {
      nextn = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nextn;
    }
    return prev;
  }
}; */

/* // 递归法
// 假设链表为：n1→…→nk−1→nk→nk+1→…→nm→∅
// 若从节点 nk+1 到 nm 已经被反转,而我们正处于 nk
// n1→…→nk−1→nk→nk+1←…←nm
// 我们希望 nk+1 的下一个节点指向 nk
// 所以, nk->next->next = nk
// 需要注意的是 n1 的下一个节点必须指向 ∅ ,否则链表中可能会产生环
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* temp = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
  }
}; */
// @lc code=end
