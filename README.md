# Akiyama \'s LeetCode Note

Akiyama's Repository, recorded of effort on Algorithms.

### 动态规划

[1218. Longest Arithmetic Subsequence of Given Difference](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/)

入门动态规划，求最长子等差数列，基本题

[1048. Longest String Chain](https://leetcode-cn.com/problems/longest-string-chain/)

入门动态规划，求最长字符串链，基本题

[45. Jump Game II](https://leetcode-cn.com/problems/jump-game-ii/)

入门动态规划，队列中的跳跃 + 贪心

[1143. Longest Common Subsequence](https://leetcode-cn.com/problems/longest-common-subsequence/)

动态规划二维经典题

[120. Triangle](https://leetcode-cn.com/problems/triangle/)

动态规划二维神级经典题

[131. Palindrome Partitioning](https://leetcode-cn.com/problems/palindrome-partitioning/)

动态规划二维状态解决回文串问题

[647. Palindromic Substrings](https://leetcode-cn.com/problems/palindromic-substrings/)

动态规划一维状态解决字符串种类问题

[91. Decode Ways](https://leetcode-cn.com/problems/decode-ways/)



### 比较器的写法

[56. Merge Intervals](https://leetcode-cn.com/problems/merge-intervals/)

21.9.29 建议熟背

### 最大/小堆的写法

[692. Top K Frequent Words](https://leetcode-cn.com/problems/top-k-frequent-words/)

21.10.7建议熟背

### 单调栈
[316. Remove Duplicate Letters](https://leetcode-cn.com/problems/remove-duplicate-letters/)

有四道题和本题有相同思想。本题设计核心是字符串的字典序比较。较为套路。

21.10.7

### 桶思想

[621. Task Scheduler](https://leetcode-cn.com/problems/task-scheduler/)

我们设计桶的大小为 n+1，则相同的任务恰好不能放入同一个桶，最密也只能放入相邻的桶。

对于重复的任务，我们只能将每个都放入不同的桶中，因此桶的个数就是重复次数最多的任务的个数。

一个桶不管是否放满，其占用的时间均为 n+1，这是因为后面桶里的任务需要等待冷却时间。最后一个桶是个特例，由于其后没有其他任务需等待，所以占用的时间为桶中的任务个数。



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

### 并查集



[695. Max Area of Island](https://leetcode-cn.com/problems/max-area-of-island/)

21.8.27 带Size的并查集

### 分治



[395. Longest Substring with At Least K Repeating Characters](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)

21.8.23 比较难的一道题，我自己没有写出来。递归实现分治较易出错。

可以用滑动窗口做，但是代码写起来很麻烦。

### 二分搜索

[二分查找LeetCode神贴：可做参考](https://leetcode.cn/circle/discuss/ooxfo8/)

[162. Find Peak Element](https://leetcode-cn.com/problems/find-peak-element/) 

21.8.23 二分搜索减少寻找区域

[378. Kth Smallest Element in a Sorted Matrix](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)


[74. Search a 2D Matrix](https://leetcode-cn.com/problems/search-a-2d-matrix/)

在这道题，我想强调二分搜索的固定写法：如果array里找不到target，那么 r 就应该是 while循环退出之后，array[r] 恰好小于 target的位置


### 双指针



[38. Count and Say](https://leetcode-cn.com/problems/count-and-say/)

21.9.9 非常经典的双指针 + 递归思想的题，值得重做

[611. Valid Triangle Number](https://leetcode-cn.com/problems/valid-triangle-number/) 

21.8.4 Using the condition to judge the valid triangle.

**2 pointers, but assign an upper boundary **. Make sure to optimize the answers, just using minus, not traver all solutions...

[202. Happy Number](https://leetcode-cn.com/problems/happy-number/)  



### 快慢指针

[15. 3sum](https://leetcode-cn.com/problems/3sum/)  21.8.20

[160. Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) 用长度的结论恰好得到两个链表的交点，同样使用了双指针

Floyd 判圈算法 [287. Find the Duplicate Number](https://leetcode-cn.com/problems/find-the-duplicate-number/)

21.7.9 两个数学公式，一个结论 可以推出直线长度的一个关系。复习下面这道题就足以了



### 递归

[95. Unique Binary Search Trees II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

利用了BST性质的递归法，求所有可能的BST

[4. Median of Two Sorted Arrays](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

找中位数的题，思维难度较大，边界条件容易出错，很难debug

### 回溯

[46. Permutationsv](https://leetcode-cn.com/problems/permutations/)

回溯模板，建议背熟


### 字典树


[208. Implement Trie (Prefix Tree) ](https://leetcode-cn.com/problems/implement-trie-prefix-tree/) 21.7.13

每个节点都有一个 ```HashMap<String, Node>```

既储存了全部Son ```Node```拥有的Char(stored in ```String```) ，又能用```Map```映射到Son Node获得对象，进行下一步操作

[212. Word Search II](https://leetcode-cn.com/problems/word-search-ii/)

21.10.1 字典树 搜索图



### 单调栈



21.7.11两次使用单调栈，确定未排序子序列的左右边界位置

[581. Shortest Unsorted Continuous Subarray](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)



### 树的遍历



[98. Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

21.7.21用recursion就能做出来，只需要return树的种类即可，并不是BackTracking

[106. Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

21.9.24 post + in 求树，记住用HashMap做查询



### 前缀数组

[560. Subarray Sum Equals K](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

21.7.3 HashMap储存Sum Frequencies PreSum + Linear Scanning 优化到O(N)

[525. Contiguous Array](https://leetcode-cn.com/problems/contiguous-array/)

21.9.28 HashMap储存0,1数量数组的前缀的和，非常值得重做的题。

[1249. Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

21.9.30 美服LC高频题，用一个factor储存左右括号的数量，思想和Prefix如出一辙，比较套路，看了提示才做出来，建议重新做。



### 哈希

[36. Valid Sudoku](https://leetcode-cn.com/problems/valid-sudoku/)

21.9.8 用二维数组实现数独的哈希去重查询

[380. Insert Delete GetRandom O(1)](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

21.9.15 非常棒的时间复杂度的题目，用动袋数组和Hash表实现了增、删、随机抽取的O(1)算法

[454. 4Sum II](https://leetcode-cn.com/problems/4sum-ii/)

21.9.15 用哈希表完成了sum4（2）的计算，非常套路，可以想想dfs怎么做。


### 溢出

[166. Fraction to Recurring Decimal](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)

用long处理int，注意int的范围是-2^n ~ 2^n - 1，还会有一个非常隐秘的溢出

### 模拟

[6. ZigZag Conversion](https://leetcode-cn.com/problems/zigzag-conversion/)

实质就是模拟，不要硬追求数学公式

### 位运算

[318. Maximum Product of Word Lengths](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/)

位运算基础题，用26bit长的int来代表了a-z这26个字母是否出现，


### 记忆化搜索

[877. Stone Game](https://leetcode-cn.com/problems/stone-game/)

DFS+memo，题意简单

[1140. Stone Game II](https://leetcode-cn.com/problems/stone-game-ii/)

DFS + Memo，题意略微复杂，使用前缀和数组，建议重做

[494. Target Sum](https://leetcode-cn.com/problems/target-sum/)

使用了HashMap的记忆化搜索，用一个String记录两个状态

[576. Out of Boundary Paths](https://leetcode-cn.com/problems/out-of-boundary-paths/)

使用了int[][]的记忆化搜索，适合两个状态都是数量较小的证书的情况

change
