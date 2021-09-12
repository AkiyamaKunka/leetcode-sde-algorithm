# Akiyama \'s LeetCode Note

Akiyama's Repository, recorded of effort on Algorithms.



### 回文串

[5869. Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

21.9.11 没做出来的题，用dfs做，思路非常简单，建议重做



### 贪心

[179. Largest Number](https://leetcode-cn.com/problems/largest-number/)

21.9.10 涉及快排的比较器，StringBuilder的使用。经典的贪心问题，但是证明完备性比较复杂

[134. Gas Station](https://leetcode-cn.com/problems/gas-station/)

21.9.10直观地想到，前缀和最低点的后一个点是最佳起点，以它为起点的后半段一定是能走通的，再保证全程有盈余，就可以走完全程

### 链表

[328. Odd Even Linked List](https://leetcode-cn.com/problems/odd-even-linked-list/)

21.9.8 边界条件容易出错的链表题

#### 并查集

[695. Max Area of Island](https://leetcode-cn.com/problems/max-area-of-island/)

21.8.27 带Size的并查集



#### 分治算法

[395. Longest Substring with At Least K Repeating Characters](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)

21.8.23 比较难的一道题，我自己没有写出来。递归实现分治较易出错。

可以用滑动窗口做，但是代码写起来很麻烦。



#### 二分搜索

[162. Find Peak Element](https://leetcode-cn.com/problems/find-peak-element/) 

21.8.23 二分搜索减少寻找区域



#### 双指针

[38. Count and Say](https://leetcode-cn.com/problems/count-and-say/)

21.9.9 非常经典的双指针 + 递归思想的题，值得重做

[611. Valid Triangle Number](https://leetcode-cn.com/problems/valid-triangle-number/) 

21.8.4 Using the condition to judge the valid triangle.

**2 pointers, but assign an upper boundary **. Make sure to optimize the answers, just using minus, not traver all solutions...

[202. Happy Number](https://leetcode-cn.com/problems/happy-number/)  



#### 快慢指针

[15. 3sum](https://leetcode-cn.com/problems/3sum/)  21.8.20

[160. Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) 用长度的结论恰好得到两个链表的交点，同样使用了双指针



#### 字典树

[208. Implement Trie (Prefix Tree) ](https://leetcode-cn.com/problems/implement-trie-prefix-tree/) 21.7.13

每个节点都有一个 ```HashMap<String, Node>```

既储存了全部Son ```Node```拥有的Char(stored in ```String```) ，又能用```Map```映射到Son Node获得对象，进行下一步操作



#### 单调栈

21.7.11两次使用单调栈，确定未排序子序列的左右边界位置

[581. Shortest Unsorted Continuous Subarray](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)



#### 树的递归遍历

[98. Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

21.7.21用recursion就能做出来，只需要return树的种类即可，并不是BackTracking



#### Floyd判圈算法

21.7.9 两个数学公式，一个结论 可以推出直线长度的一个关系。复习下面这道题就足以了

[287. Find the Duplicate Number](https://leetcode-cn.com/problems/find-the-duplicate-number/)



#### PreSum + Frequency的技巧

[560. Subarray Sum Equals K](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

21.7.3 HashMap储存Sum Frequencies PreSum + Linear Scanning 优化到O(N)



### 哈希

[36. Valid Sudoku](https://leetcode-cn.com/problems/valid-sudoku/)

21.9.8 用二维数组实现数独的哈希去重查询

