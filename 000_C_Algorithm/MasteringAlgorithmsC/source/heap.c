//
//  heap.c
//  Algorithms - Heap
//
//  Created by YourtionGuo on 05/05/2017.
//  Copyright © 2017 Yourtion. All rights reserved.
//

#include <stdlib.h>
#include <string.h>

#include "heap.h"

#pragma mark - Private


/**
 获取父结点位置 (i-1)/2

 @param npos 当前结点位置
 @return 父结点位置
 */
#define heap_parent(npos) ((int)(((npos) - 1) / 2))


/**
 获取左子结点位置 i*2+1

 @param npos 当前结点位置
 @return 左子结点位置
 */
#define heap_left(npos) (((npos) * 2) + 1)


/**
 获取右子结点位置 i*2+2

 @param npos 当前结点位置
 @return 右子结点位置
 */
#define heap_right(npos) (((npos) * 2) + 2)


#pragma mark - Public


void heap_init(Heap *heap,
               int (*compare)(const void *key1, const void *key2),
               void (*destroy)(void *data))
{
  /// 初始化堆
  heap->size = 0;
  heap->compare = compare;
  heap->destroy = destroy;
  heap->tree = NULL;

  return;
}


void heap_destroy(Heap *heap) {

  int     i;

  /// 删除所有节点
  if (heap->destroy != NULL) {

    for (i = 0; i < heap_size(heap); i++) {
      /// 执行用户指定的 destroy 函数
      heap->destroy(heap->tree[i]);
    }
  }

  /// 删除堆数据
  free(heap->tree);
  /// 清理堆数据结构
  memset(heap, 0, sizeof(Heap));

  return;
}


int heap_insert(Heap *heap, const void *data)
{
  void      *temp;
  int       ipos, ppos;

  /// 创建结点空间. 扩大原有的数组
  if ((temp = (void **)realloc(heap->tree, (heap_size(heap) + 1) * sizeof (void *))) == NULL) return -1;

  heap->tree = temp;

  /// 将结点插入到最后位置
  heap->tree[heap_size(heap)] = (void *)data;

  /// 通过将节点上推保障树的平衡
  ipos = heap_size(heap);
  ppos = heap_parent(ipos);
  // 检查堆是不是平衡：比较当前节点和父节点，如果比父节点大，往前移动
  while (ipos > 0 && heap->compare(heap->tree[ppos], heap->tree[ipos]) < 0) {

    /// 交换当前结点与父结点内容
    temp = heap->tree[ppos];
    heap->tree[ppos] = heap->tree[ipos];
    heap->tree[ipos] = temp;

    /// 将结点向上移动一层保障树的平衡。 更新新的节点ID.
    ipos = ppos;
    ppos = heap_parent(ipos);

  }

  /// 更新堆的 size
  heap->size++;

  return 0;
}

/**
 *  从堆 heap 中释放堆顶部的结点 - O(lg n)
 * */
int heap_extract(Heap *heap, void **data)
{
  void      *save, *temp;
  int       ipos, lpos, rpos, mpos;

  /// 不允许在空堆中释放
  if (heap_size(heap) == 0) return -1;

  /// 释放堆中的顶部节点
  *data = heap->tree[0];

  /// 调整堆的存储空间
  save = heap->tree[heap_size(heap) - 1]; // 保存末端节点

  if (heap_size(heap) - 1 > 0) {

    if ((temp = (void **)realloc(heap->tree, (heap_size(heap) - 1) * sizeof(void *))) == NULL) return -1;

    heap->tree = temp;

    /// 更新堆的 size
    heap->size--;

  } else {

    /// 当释放最后一个结点

    free(heap->tree);
    heap->tree = NULL;
    heap->size = 0;
    return 0;
  }

  /// 保存最后一个结点（末端）的内容到树顶端

  heap->tree[0] = save;

  /// 通过将顶部节点逐层下移保障树的平衡
  ipos = 0;
  lpos = heap_left(ipos);
  rpos = heap_right(ipos);

  while (1) {

    /// 选择与当前结点交换的子结点
    lpos = heap_left(ipos);
    rpos = heap_right(ipos);
    // 检查左树是否需要调整
    if (lpos < heap_size(heap) && heap->compare(heap->tree[lpos], heap->tree[ipos]) > 0) {

      mpos = lpos;  // mark需要更新的点

    } else {

      mpos = ipos;
    }
    // 检查右树是否需要调整
    if (rpos < heap_size(heap) && heap->compare(heap->tree[rpos], heap->tree[mpos]) > 0) {

      mpos = rpos;  // mark需要更新的点,放在后面，优先更新右树
    }

    /// 当 mpos 就是 ipos 时，堆已经完成调整
    if (mpos == ipos) {

      break;

    } else {

      /// 交换当前结点与选择的子结点内容
      temp = heap->tree[mpos];
      heap->tree[mpos] = heap->tree[ipos];
      heap->tree[ipos] = temp;
      
      /// 将结点向下移动一层保障树的平衡
      ipos = mpos;
    }
  }
  
  return 0;
}
