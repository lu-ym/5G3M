#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

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
bool exist(char** board, int boardSize, int* boardColSize, char* word){
  // KMP算法，做前缀转移表

  // 做hashtable来log所有包含的字母的位置。
  for (size_t i = 0; i < boardSize; i++)
  {
    /* code */
  }
  
}
void main(){
  int ColSize = 4;
  int matrix[][4] = {{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
  int length = sizeof(matrix)/sizeof(int);
  char *word = "ABCCED";
  bool result;
  result = exist(matrix,length,&ColSize,word);
  printf("%s ",result);
  printf("\r\n");
  return;
}