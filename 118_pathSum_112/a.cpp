#include <iostream>
// #include <string>
#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <cstdio>
#include <cstdlib>
// #include <ctime>
#include <climits>
using namespace std;
/**
 * 经典题：最好牢记几种常规的算法实现,DFS,回溯，BFS,栈
 * */
/** 
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在根节点
 * 到叶子节点的路径，这条路径上所有节点值相加等于目标和 targetSum 。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
示例 2：
输入：root = [1,2,3], targetSum = 5
输出：false
示例 3：
输入：root = [1,2], targetSum = 0
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  // 下面三个是构造函数
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return false;
  }
};


int main(){
  TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode)) ;
  int a = 5;
  root->val = 5;
  TreeNode *curr,*left,*right;
  curr = root;
  int rootV[] = {5,4,8,11,null,13,4,7,2,null,null,null,1};
  
  for(int i = 0;i < 12,i++){
    left = (TreeNode*)malloc(sizeof(TreeNode)) ;
    right = (TreeNode*)malloc(sizeof(TreeNode)) ;
    curr.left = left;
    curr.right = right;
  }
  Solution sl;
  cout << sl.hasPathSum(root,a) << endl;
  return 0;
}