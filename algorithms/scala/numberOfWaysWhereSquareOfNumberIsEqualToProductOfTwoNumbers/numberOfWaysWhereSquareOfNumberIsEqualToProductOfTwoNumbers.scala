// Source : https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
// Author : Phuong Lam
// Date   : 2020-11-04

/**
 * 1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
 *
 * Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2)
 * under the following rules:
 *
 * Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k]
 *                           where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
 * Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k]
 *                           where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
 */
object Solution {
  def numTriplets(nums1: Array[Int], nums2: Array[Int]): Int = {
    val s1 = nums1.map(x => 1L * x * x).groupBy(identity).mapValues(_.length)
    val s2 = nums2.map(x => 1L * x * x).groupBy(identity).mapValues(_.length)
    var count = 0

    for (i <- 0 until nums1.length - 1) {
      for (j <- i + 1 until nums1.length) {
        val v = 1L * nums1(i) * nums1(j)
        if (s2.contains(v)) count += s2(v)
      }
    }

    for (i <- 0 until nums2.length - 1) {
      for (j <- i + 1 until nums2.length) {
        val v = 1L * nums2(i) * nums2(j)
        if (s1.contains(v)) count += s1(v)
      }
    }

    count
  }
}