//
//  traverse.c
//  Algorithms - bitree traverse
//
//  Created by YourtionGuo on 03/05/2017.
//  Copyright © 2017 Yourtion. All rights reserved.
//

#include "list.h"
#include "traverse.h"

#pragma mark - Public


/**
 * 前序搜索：递归调用，知道寻找到末端
 * @param node 树的根节点
 * @param list 是遍历后的结果，做成了一个list
 * */
int bitree_preorder(const BiTreeNode *node, List *list)
{
  if (!bitree_is_eob(node)) {
    
    if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
    
    if (!bitree_is_eob(bitree_left(node))) {
      if (bitree_preorder(bitree_left(node), list) != 0) return -1;
    }
    
    if (!bitree_is_eob(bitree_right(node))) {
      if (bitree_preorder(bitree_right(node), list) != 0) return -1;
    }
    
  }
  
  return 0;
}

// 中序
int bitree_inorder(const BiTreeNode *node, List *list)
{
  if (!bitree_is_eob(node)) {
    
    if (!bitree_is_eob(bitree_left(node))) {
      if (bitree_inorder(bitree_left(node), list) != 0) return -1;
    }
    // 找到左树的末端（叶子）再开始往list插入数据。但是要在右树之前
    if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
    
    if (!bitree_is_eob(bitree_right(node))) {
      if (bitree_inorder(bitree_right(node), list) != 0) return -1;
    }
    
  }
  
  return 0;
}

// 后序
int bitree_postorder(const BiTreeNode *node, List *list)
{
  if (!bitree_is_eob(node)) {
    
    if (!bitree_is_eob(bitree_left(node))) {
      if (bitree_postorder(bitree_left(node), list) != 0) return -1;
    }
    
    if (!bitree_is_eob(bitree_right(node))) {
      if (bitree_postorder(bitree_right(node), list) != 0) return -1;
    }
    // 找到右的末端（叶子）再开始往list插入数据
    if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
    
  }
  
  return 0;
}
