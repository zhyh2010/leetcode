/*
给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：

p[0] = start
p[i] 和 p[i+1] 的二进制表示形式只有一位不同
p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
 

示例 1：

输入：n = 2, start = 3
输出：[3,2,0,1]
解释：这个排列的二进制表示是 (11,10,00,01)
     所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
示例 2：

输出：n = 3, start = 2
输出：[2,6,7,5,4,0,1,3]
解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
 

提示：

1 <= n <= 16
0 <= start < 2^n
在真实的面试中遇到过这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circular-permutation-in-binary-representation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> tmp = greyCode(n);
        for (int i = 0; i < tmp.size(); i++){
            if (tmp[i] == start){
                vector<int> res(tmp.begin() + i, tmp.end());
                for (auto it = tmp.begin(); it != tmp.begin() + i; it++){
                    res.emplace_back(*it);
                }
                return res;
            }
        }
        return tmp;
    }
private:
    vector<int> greyCode(int n){
        if (n == 1)
            return vector<int>{0, 1};
        vector<int> tmp = greyCode(n - 1);
        vector<int> res(tmp.begin(), tmp.end());
        for (auto it = tmp.crbegin(); it != tmp.crend(); it++){
            res.emplace_back(*it + pow(2, n - 1));
        }
        return res;
    }
};


/*
https://leetcode-cn.com/problems/circular-permutation-in-binary-representation/solution/c-yi-ci-xun-huan-zhi-jie-qiu-jie-wei-yun-suan-by-h/
采用格雷码求解
*/