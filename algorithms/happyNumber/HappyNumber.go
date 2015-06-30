package happyNumber

func isHappyNumber(n int) bool {
	m := map[int]bool{}
	for {
		sum := 0
		for n > 0 {
			sum += (n % 10) * (n % 10)
			n /= 10
		}
		if sum == 1 {
			return true
		}
		if _, ok := m[sum]; ok {
			return false
		}
		m[sum] = true
		n = sum
	}
	return false
}
