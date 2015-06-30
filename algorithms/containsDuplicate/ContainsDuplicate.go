package containsDuplicate

func containsDuplicate(nums []int) bool {
	m := map[int]int{}
	for _, v := range nums {
		if _, ok := m[v]; ok {
			return true
		}
		m[v] += 1
	}
	return false
}

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
