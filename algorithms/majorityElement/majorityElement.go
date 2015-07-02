package majorityElement

func majorityElement(nums []int) int {
	vote := nums[0]
	count := 1
	for k, v := range nums {
		if count == 0 {
			vote = nums[k]
			count = 1
			continue
		}
		if vote == v {
			count++
		} else {
			count--
		}
	}
	return vote
}
