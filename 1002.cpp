/*
给定仅有小写字母组成的字符串数组
A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现
3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
      array<int, 26> gref = {0};
      for (int i = 0; i < A.size(); i++) {
          if (i == 0){
              gref = generateCode(A[i]);
          }
          else{
              array<int, 26> tmp = generateCode(A[i]);
              for (int j = 0; j < tmp.size(); j++){
                  gref[j] = min(gref[j], tmp[j]);
              }
          }
      }
      vector<string> res;
      for (int i = 0; i < gref.size(); i++){
          for (int j = 0; j < gref[i]; j++) {
              res.push_back(string(1, 'a' + i));
          }
      }
      return res;
    }
private:
    array<int, 26> generateCode(string tmp){
        array<int, 26> tm = {0};
        for (auto it : tmp){
            tm[it - 'a'] += 1;
        }
        return tm;
    }
};

/*
https://leetcode-cn.com/problems/find-common-characters/solution/cjian-dan-zhi-guan-jie-fa-yong-shi-ji-bai-96-kong-/
same solution
*/