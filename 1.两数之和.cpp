/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.43%)
 * Likes:    7555
 * Dislikes: 0
 * Total Accepted:    802.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值
 * target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 *
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 *
 * 示例:
 *
 * 给定 nums = [2, 7, 11, 15], target = 9
 *
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 *
 *
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v(2);
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = 0; j < nums.size() - 1; j++) {
        if (nums[i] + nums[j] == target) {
          v.at(0) = i;
          v.at(1) = j;
          return v;
        }
      }
    }
    return v;
  }
};
// @lc code=end
