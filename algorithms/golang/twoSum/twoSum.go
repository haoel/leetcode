package twoSum

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	for index, num := range nums {
		if i, ok := numMap[target-num]; ok {
			return []int{i, index}
		}
		numMap[num] = index
	}
	return nil
}