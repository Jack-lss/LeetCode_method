# LeetCode_method

**算法无性能可言，仅仅只是实现！**

**use C++ and Python!**

----

- [001Sum_of_two_numbers](#1)

- [002Sum_of_three_numbers](#2)

- [003after_array_closest_target](#3)

- [004longest_common_prefix](#4)

- [005Serialization_and_deserialization_of_binary_trees](#5)

----

## <h2 id="1">001Sum_of_two_numbers</h2>

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

----

## <h2 id="2">002Sum_of_three_numbers</h2>

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

## <h2 id="3">003after_array_closest_target</h2>

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

- > 1 <= arr.length <= 10^4
- > 1 <= arr[i], target <= 10^5

----

## <h2 id="4">004longest_common_prefix</h2>

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

## <h2 id="5">005Serialization_and_deserialization_of_binary_trees</h2>

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
