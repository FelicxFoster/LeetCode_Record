/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 *
 * https://leetcode-cn.com/problems/reduce-array-size-to-the-half/description/
 *
 * algorithms
 * Medium (60.99%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 6.9K
 * Testcase Example:  '[3,3,3,3,5,5,5,2,2,7]'
 *
 * 给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。
 *
 * 返回 至少 能删除数组中的一半整数的整数集合的最小大小。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [3,3,3,3,5,5,5,2,2,7]
 * 输出：2
 * 解释：选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
 * 大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
 * 选择 {2,7} 是不可行的，它的结果数组为
 * [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
 *
 *
 * 示例 2：
 *
 * 输入：arr = [7,7,7,7,7,7]
 * 输出：1
 * 解释：我们只能选择集合 {7}，结果数组为空。
 *
 *
 * 示例 3：
 *
 * 输入：arr = [1,9]
 * 输出：1
 *
 *
 * 示例 4：
 *
 * 输入：arr = [1000,1000,3,7]
 * 输出：1
 *
 *
 * 示例 5：
 *
 * 输入：arr = [1,2,3,4,5,6,7,8,9,10]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^5
 * arr.length 为偶数
 * 1 <= arr[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr) {
      ++freq[num];
    }
    vector<int> occ;
    for (pair<int, int> m : freq) {
      occ.push_back(m.second);
    }
    sort(occ.begin(), occ.end(), greater<int>());
    int cnt = 0, ans = 0;
    for (int c : occ) {
      cnt += c;
      ans += 1;
      if (cnt * 2 >= arr.size()) {
        break;
      }
    }
    return ans;
  }
};
// @lc code=end
