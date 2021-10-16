/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (54.91%)
 * Likes:    1048
 * Dislikes: 0
 * Total Accepted:    216.4K
 * Total Submissions: 394.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left 。请你反转从位置
 * left 到位置 right 的链表节点，返回 反转后的链表 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目为 n
 * 1
 * -500
 * 1
 *
 *
 *
 *
 * 进阶： 你可以使用一趟扫描完成反转吗？
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* // 穿针引线法
// 为了减少边界判断,我们可以建立一个虚拟头结点 dummy,
// 使其指向 head,最终返回 dummy.next
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 思路：先遍历到left处，翻转，再拼接后续，注意指针处理
    // 输入: 1->2->3->4->5->NULL, left = 2, right = 4
    if (head == NULL) {
      return head;
    }
    // 头部变化所以使用dummy node
    // ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    ListNode* dummyNode = new ListNode(0);  // new比malloc更有效
    // 不能ListNode* dummyNode = NULL,因为NULL后面是不能->next的
    dummyNode->next = head;
    ListNode* pre = dummyNode;
    // 这里pre：0->1->2->3->4->5->NULL
    int i = 0;
    for (int i = 1; i < left; i++) {
      pre = pre->next;
    }
    // 遍历之后： 1(pre)->2(head)->3->4->5->NULL
    ListNode* next;
    ListNode* mid = pre->next;  // 用于中间节点连接
    ListNode* cur = pre->next;
    for (int i = left; i < right + 1; i++) {
      // 第一次循环： 1(pre) NULL<-2(next) 3(cur)->4->5->NULL
      ListNode* temp = cur->next;
      cur->next = next;
      next = cur;
      cur = temp;
    }
    // 循环需要执行四次
    // 循环结束：1(pre) NULL<-2(mid)<-3<-4(next) 5(cur)->NULL
    pre->next = next;
    mid->next = cur;
    return dummyNode->next;
  }
}; */

// 一次遍历「穿针引线」
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 设置 dummyNode 是这一类问题的一般做法
    ListNode* dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode* pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }
    ListNode* cur = pre->next;
    ListNode* next;
    for (int i = 0; i < right - left; i++) {
      next = cur->next;
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
    }
    return dummyNode->next;
  }
};

// @lc code=end
