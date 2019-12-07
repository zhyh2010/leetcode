/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
public:
    // 采用并查集实现
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> tmp;
        int maxlen = 0;
        for (auto it : nums) {
            int len = -1;
            if (tmp.count(it) > 0){
                continue;
            }
            tmp[it] = len;
            if (tmp.count(it - 1) > 0){
                len += tmp[it - 1];
                tmp[it - 1] = it;
                tmp[it] = len;
            }
            if (tmp.count(it + 1) > 0){
                int i = it + 1;
                while (tmp.count(i)){
                    i++;
                }
                len += tmp[i - 1];
                tmp[it] = it + 1;
                tmp[i - 1] = len;
            }
            if (len < maxlen){
                maxlen = len;
            }            
        }
        return -maxlen;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> arr{100, 4, 200, 1, 3, 2};
    cout << "sss" << endl;
    cout << s.longestConsecutive(arr) << endl;
    system("pause");
    return 0;
<<<<<<< HEAD
}

/*
官方解法：
https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode/

自己的思路： 并查集
构建并查集前后联系
*/
=======
}
>>>>>>> 96fa501de80fb65d307b1c2821ece8d1aa0fad44
