package containsDuplicate

func containsDuplicate2(nums []int, step int) bool {
	m := map[int]int{}
	for k, v := range nums {
		if i, ok := m[v]; ok {
			if k-i <= step {
				return true
			}
		}
		m[v] = k
	}
	return false
}
