# **二叉树**

- 快速排序：二叉树的前序遍历；归并排序：二叉树的后序遍历

  ```java
  //快速排序的代码框架如下
  void sort(int[] nums, int lo, int hi) {
      /****** 前序遍历位置 ******/
      // 通过交换元素构建分界点 p
      int p = partition(nums, lo, hi);
      /************************/
  
      sort(nums, lo, p - 1);
      sort(nums, p + 1, hi);
  }
  
  // 定义：排序 nums[lo..hi]
  void sort(int[] nums, int lo, int hi) {
      int mid = (lo + hi) / 2;
      // 排序 nums[lo..mid]
      sort(nums, lo, mid);
      // 排序 nums[mid+1..hi]
      sort(nums, mid + 1, hi);
  
      /****** 后序位置 ******/
      // 合并 nums[lo..mid] 和 nums[mid+1..hi]
      merge(nums, lo, mid, hi);
      /*********************/
  }
  ```

- 前序位置的代码执行是自顶向下的，而后序位置的代码执行是自底向上的 --> 语法制导翻译

  - 意味着前序位置的代码只能从函数参数中获取父节点传递来的数据，而后序位置的代码不仅可以获取参数数据，还可以获取到子树通过函数返回值传递回来的数据

  - 举具体的例子，现在给你一棵二叉树，两个简单的问题：

    1、如果把根节点看做第 1 层，如何打印出每一个节点所在的层数？（子层数 = 父层数+1，继承属性，使用L-属性定义，自顶向下分析，先序遍历）

    2、如何打印出每个节点的左右子树各有多少节点？（节点数=左子树节点数+右子树节点数，综合属性，使用S-属性定义，自底向上分析，后序遍历）

- 层次遍历

  - ````java
    // 输入一棵二叉树的根节点，层序遍历这棵二叉树
    void levelTraverse(TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
    
        // 从上到下遍历二叉树的每一层
        while (!q.isEmpty()) {
            int sz = q.size();
            // 从左到右遍历每一层的每个节点
            for (int i = 0; i < sz; i++) {
                TreeNode cur = q.poll();
                // 将下一层节点放入队列
                if (cur.left != null) {
                    q.offer(cur.left);
                }
                if (cur.right != null) {
                    q.offer(cur.right);
                }
            }
        }
    }
    
    ````

- 