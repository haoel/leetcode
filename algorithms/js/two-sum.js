/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  var map = {}
  for (var i = 0; i < nums.length; i++) {
    const com = target - nums[i]
    if (map[com] !== undefined) {
      const j = map[com]
      if (j !== i) return [j, i]
    }
    map[nums[i]] = i
  }
  return []
}
