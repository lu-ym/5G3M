#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
using namespace std;
/** 
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；
 *  否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或
  垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

提示：
1 <= board.length <= 200
1 <= board[i].length <= 200
board 和 word 仅由大小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

/**
 * 常规思路，str字符串查找+回溯算法，枚举所有路径(DFS搜索)。可以加上剪枝策略，去掉不需要的路径。
*/
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    // pre-processing. Generate PMT
    vector<int> pmt(word.size()) ; // Partial Match Table
    for (size_t i = 1; i < word.size(); i++){
      if (word[i] == word[pmt[i-1]]) pmt[i] = pmt[i-1]+1;
      else pmt[i] = 0;
    }
    // verify PMT
    // cout << word <<endl;
    // vector<int>::const_iterator ite = pmt.begin();
    // while(ite != pmt.end())
    //   cout << *ite++ << ' ';
    // cout << endl;
    // 
    // DFS. 普通的枚举所有可能。
    // 起点，矩阵中的字母和字符串中相同的.四个方向，相同的继续，否则停止。
    for (size_t i = 0; i < board.size(); i++){
      for (size_t j = 0; j < board[0].size(); j++){
        if(board[i][j] == word[0]) {
          if(dfs(board,word,i,j)) return true;
        }
      }
    }
    return false;
  }
private:
  bool dfs(vector<vector<char>>& board, string word,int startI,int startJ){
    vector<vector<char>> bcopy(board); // copy for modification
    // 查找+裁剪。
    while (true){
      
    }
    
    return true;
  }
};
// KMP + DFS
int main(){
  vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word = "ABCCED";
  // string word = "ABCDABD";
  Solution sl;
  cout << sl.exist(board,word) <<endl;
  return 0;
}