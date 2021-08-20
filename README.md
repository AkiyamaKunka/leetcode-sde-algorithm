# Akiyama \'s LeetCode Note

This is AkiyamaKunka's Repository, stored his record on work of Algorithms.





#### Two Pointers



#### [611. Valid Triangle Number](https://leetcode-cn.com/problems/valid-triangle-number/) 21.8.4 Using the condition to judge the valid triangle.

**2 pointers, but assign an upper boundary **. Make sure to optimize the answers, just using minus, not traver all solutions...

#### [202. Happy Number](https://leetcode-cn.com/problems/happy-number/)  快慢指针 21.8.20

#### [15. 3sum](https://leetcode-cn.com/problems/3sum/) 双指针 21.8.20

#### [160. Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) 用长度的结论恰好得到两个链表的交点，同样使用了双指针



#### 字典树

#### [208. Implement Trie (Prefix Tree) ](https://leetcode-cn.com/problems/implement-trie-prefix-tree/) 21.7.13

每个节点都有一个 ```HashMap<String, Node>```

既储存了全部Son ```Node```拥有的Char(stored in ```String```) ，又能用```Map```映射到Son Node获得对象，进行下一步操作

#### 7.11 两次使用单调栈

确定未排序子序列的左右边界位置

#### [581. Shortest Unsorted Continuous Subarray](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)



#### 7.10 树的递归遍历

#### [98. Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

用recursion就能做出来，只需要return树的种类即可，并不是BackTracking



#### 7.9 Floyd 判圈算法

两个数学公式，一个结论 可以推出直线长度的一个关系。复习下面这道题就足以了

#### [287. Find the Duplicate Number](https://leetcode-cn.com/problems/find-the-duplicate-number/)



#### 7.3 PreSum + Frequency的技巧

#### [560. Subarray Sum Equals K](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

HashMap储存Sum Frequencies PreSum + Linear Scanning 优化到O(N)


