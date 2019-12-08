
/*
230. 二叉搜索树中第K小的元素

    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

    说明： 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    示例 1 :

    输入
    : root = [ 3, 1, 4, null, 2 ],
      k = 1
            3
           / \
          1   4
           \
            2
输出 : 1

示例 2 :

    输入 : root = [ 5, 3, 6, 2, 4, null, null, 1 ],
      k = 3
            5
           / \
          3   6
         / \
        2   4
       /
      1
输出 : 3

进阶： 如果二叉搜索树经常被修改（插入 /删除操作）并且你需要频繁地查找第 k小的值，你将如何优化 kthSmallest 函数？
来源：力扣（LeetCode） 链接：
https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
      著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 */

#define NULL 0
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == nullptr)
            return 0;

        int leftNum = _kthSmallest(root->left, k);
        if (k > leftNum + 1) {
          k = k - 1 - leftNum;
          return kthSmallest(root->right, k);
        } else if (leftNum + 1 == k) {
          return root->val;
        }
        return kthSmallest(root->left, k);
    }

private:
    int _kthSmallest(TreeNode *root, int k) {
        if (root == nullptr)
            return 0;

        int leftNum = _kthSmallest(root->left, k);
        int rightNum = _kthSmallest(root->right, k);
        return leftNum + rightNum + 1;        
    }
};

/*
思路解析：

https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/di-gui-yu-fei-di-gui-xie-fa-tong-li-wan-cheng-di-1/
可以采用递归、栈操作的方法， 利用中序遍历获取第k个值

https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/czhong-xu-bian-li-by-xiaoneng/
*/