
/*给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

 

示例 1：

输入：[2,1,5]
输出：[5,5,0]
示例 2：

输入：[2,7,4,3,5]
输出：[7,0,5,5,0]
示例 3：

输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]
 

提示：

对于链表中的每个节点，1 <= node.val <= 10^9
给定列表的长度在 [0, 10000] 范围内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-node-in-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
  Definition for singly-linked list.
  */

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> mystack = reverse(head);
        stack<int> mainQue;
        vector<int> resRev;
        while (!mystack.empty()){
            int top = mystack.top();
            mystack.pop();
            if (mainQue.empty()){
                resRev.push_back(0);
                mainQue.push(top);
            }
            else{
                while (!mainQue.empty() && top >= mainQue.top()){
                    mainQue.pop();
                }
                if (mainQue.empty()){
                    resRev.push_back(0);
                }
                else{
                    resRev.push_back(mainQue.top());
                }
                mainQue.push(top);
            }
        }
        vector<int> res(resRev.crbegin(), resRev.crend());
        return res;
    }

private:
    stack<int> reverse(ListNode * head){
        stack<int> mystack;
        while (head){
            mystack.push(head->val);
            head = head->next;
        }
        return mystack;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    ListNode a(2), b(1), c(2), e(7), f(3);
    a.next = &c;
    b.next = &c;
    c.next = nullptr;
    auto re = s.nextLargerNodes(&a);
    for (auto it : re){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}


/**
 * https://leetcode-cn.com/problems/next-greater-node-in-linked-list/solution/cli-yong-zhan-shi-xian-by-yang-tian-lun/
 * 使用栈处理
*/