Some Scripts
============

`comments.sh` - use to generate a cpp file with some comments


1) Create a file named largestNumber.cpp, and add Copyright & Problem description
```
./comments.sh https://oj.leetcode.com/problems/largest-number/
```

2) Add Copyright & Problem description into existed file
```
./comments.sh https://oj.leetcode.com/problems/largest-number/ largestNumber.cpp
```


the cpp source file's comment will be like blow:

```
// Source : https://oj.leetcode.com/problems/largest-number/
// Author : Hao Chen
// Date   : 2015-01-25

/**********************************************************************************
 *
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 *
 **********************************************************************************/


```
