/*
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
  ]
  示例 2:

  输入:
  beginWord = "hit"
  endWord = "cog"
  wordList = ["hot","dot","dog","lot","log"]

  输出: []

  解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/word-ladder-ii
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> myqueue;
		minLen = wordList.size() + 2;
		myqueue.push(beginWord);
		vector<vector<string>> myres;
		DFS(beginWord, endWord, wordList, myqueue);
		for (int i = 0; i < res.size(); i++) {
			if (res[i].size() == minLen) {
				myres.emplace_back(res[i]);
			}
		}
		return myres;
	}

private:
	void DFS(string beginword, string endWord, vector<string> & wordList, queue<string> & myqueue) {
		if (myqueue.size() == 0)
			return;
		string front = myqueue.front();
		myqueue.pop();
		path.emplace_back(front);
		if (checkLen(endWord, front)) {
			path.emplace_back(endWord);
			res.emplace_back(path);
			minLen = min(minLen, (int)path.size());
			path.pop_back();
			path.pop_back();
			return;
		}
		vector<string> wordlistback(wordList.begin(), wordList.end());
		for (string item : wordList) {			
			if (checkLen(item, front)) {
				myqueue.push(item);
				for (auto it = wordlistback.begin(); it != wordlistback.end(); it++) {
					if (*it == item) {
						wordlistback.erase(it);
						break;
					}
				}
				DFS(beginword, endWord, wordlistback, myqueue);
				wordlistback.push_back(item);
			}	
		}		
		path.pop_back();
	}

	bool checkLen(string & item, string & ref) {
		int diff = 0;
		for (int i = 0; i < item.size(); i++) {
			if (item[i] == ref[i])
				continue;
			diff++;
		}
		return diff == 1;
	}

private:
	int minLen;
	vector<string> path;
	vector<vector<string>> res;
};

int main(int argc, const char** argv) {
	Solution s;
	vector<string> input{ "hot","dot","dog","lot","log","cog" };
	auto res = s.findLadders("hit", "cog", input);
	for (auto item : res) {
		for (auto it : item) {
			cout << it << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
