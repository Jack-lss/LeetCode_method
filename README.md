# LeetCode_method

**算法无性能可言，仅仅只是实现！**

**use C++ and Python!**

----

- [001Sum_of_two_numbers](#001)
- [002Sum_of_three_numbers](#002)
- [003after_array_closest_target](#003)
- [004longest_common_prefix](#004)
- [005Serialization_and_deserialization_of_binary_trees](#005)
- [006Best_sightseeing_combination](#006)
- [007Restore_Binary_Tree_from_Preorder_Traversal](#007)
- [008Verify_palindrome](#008)
- [009Regular_expression_matching](#009)
- [010The_maximum_path_sum_in_the_binary_tree](#010)
- [011Different_paths_2](#011)
- [012Sum_of_paths](#012)
- [013Best_stock_trading_period_including_freezing_period](#013)
- [014Lntersection_of_two_arrays_2](#14)

----

## <span id="001">001Sum_of_two_numbers</span>

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

----

## <span id="002">002Sum_of_three_numbers</span>

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

**注意：答案中不可以包含重复的三元组。**

示例：

    给定数组 nums = [-1, 0, 1, 2, -1, -4]，

    满足要求的三元组集合为：
    [
        [-1, 0, 1],
        [-1, -1, 2]
    ]

----

## <span id="003">003after_array_closest_target</span>

给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

**请注意，答案不一定是 arr 中的数字。**

示例 1：

    输入：arr = [4,9,3], target = 10
    输出：3
    解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。

示例 2：

    输入：arr = [2,3,5], target = 10
    输出：5

示例 3：

    输入：arr = [60864,25176,27249,21296,20204], target = 56803
    输出：11361

提示：

    1 <= arr.length <= 10^4
    1 <= arr[i], target <= 10^5

----

## <span id="004">004longest_common_prefix</span>

编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:

    输入: ["flower","flow","flight"]
    输出: "fl"

示例 2:

    输入: ["dog","racecar","car"]
    输出: ""
    解释: 输入不存在公共前缀。

**说明:** 所有输入只包含小写字母 a-z。

----

## <span id="005">005Serialization_and_deserialization_of_binary_trees</span>

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例:

    你可以将以下二叉树：

        1
       / \
      2   3
         / \
        4   5

    序列化为 "[1,2,3,null,null,4,5]"

**提示**: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

**说明**: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

----

## <span id='006'>006Best_sightseeing_combination</span>

给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。

一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。

返回一对观光景点能取得的最高分。

示例：

    输入：[8,1,5,2,6]
    输出：11
    解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11

**提示：**

    2 <= A.length <= 50000
    1 <= A[i] <= 1000

----

## <span id='007'>007Restore_Binary_Tree_from_Preorder_Traversal</span>

我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

示例 1：

!['1-2--3--4-5--6--7'](https://github.com/Jack-lss/LeetCode_method/raw/master/007Restore_Binary_Tree_from_Preorder_Traversal/recover-a-tree-from-preorder-traversal01.png "007")

    输入："1-2--3--4-5--6--7"
    输出：[1,2,5,3,4,6,7]

示例 2：

!['1-2--3---4-5--6---7'](https://github.com/Jack-lss/LeetCode_method/raw/master/007Restore_Binary_Tree_from_Preorder_Traversal/screen-shot-2019-04-10-at-114101-pm.png "008")

    输入："1-2--3---4-5--6---7"
    输出：[1,2,5,3,null,6,null,4,null,7]

示例 3：

!['1-401--349---90--88'](https://github.com/Jack-lss/LeetCode_method/raw/master/007Restore_Binary_Tree_from_Preorder_Traversal/screen-shot-2019-04-10-at-114955-pm.png "009")

    输入："1-401--349---90--88"
    输出：[1,401,null,349,88,90]

提示：

- 原始树中的节点数介于 1 和 1000 之间。
- 每个节点的值介于 1 和 10 ^ 9 之间。

----

## <span id='008'>008Verify_palindrome</span>

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

**说明**：本题中，我们将空字符串定义为有效的回文串。

示例 1:

    输入: "A man, a plan, a canal: Panama"
    输出: true

示例 2:

    输入: "race a car"
    输出: false

----

## <span id='009'>009Regular_expression_matching</span>

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符

'*' 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

**说明**:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:

    输入:
    s = "aa"
    p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:

    输入:
    s = "aa"
    p = "a*"
    输出: true
    解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:

    输入:
    s = "ab"
    p = ".*"
    输出: true
    解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:

    输入:
    s = "aab"
    p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:

    输入:
    s = "mississippi"
    p = "mis*is*p*."
    输出: false

----

## <span id='010'>010The_maximum_path_sum_in_the_binary_tree</span>

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

    输入: [1,2,3]

               1
              / \
             2   3
    输出: 6

示例 2:

    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7

输出: 42

----

## <span id="011">011Different_paths_2</span>

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

!["robot"](https://github.com/Jack-lss/LeetCode_method/raw/master/011Different_paths_2/robot_maze.png "011")

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

    输入:
    [
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ]
    输出: 2
    解释:
    3x3 网格的正中间有一个障碍物。
    从左上角到右下角一共有 2 条不同的路径：
    1. 向右 -> 向右 -> 向下 -> 向下
    2. 向下 -> 向下 -> 向右 -> 向右

----

## <span id="012">012Sum_of_paths</span>

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:

    给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
    返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

----

## <span id="013">013Best_stock_trading_period_including_freezing_period</span>

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

- 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

示例:

    输入: [1,2,3,0,2]
    输出: 3
    解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

----

## <span id="014">014Lntersection_of_two_arrays_2</span>

给定两个数组，编写一个函数来计算它们的交集。

示例 1：

    输入：nums1 = [1,2,2,1], nums2 = [2,2]
    输出：[2,2]

示例 2:

    输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出：[4,9]

说明：

- 输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
- 我们可以不考虑输出结果的顺序。

进阶：

- 如果给定的数组已经排好序呢？你将如何优化你的算法？
- 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
- 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

----
