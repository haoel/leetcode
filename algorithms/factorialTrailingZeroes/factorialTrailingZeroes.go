package factorialTrailingZeroes

func trailingZeroes(n int) int {
	count := 0
	for i := 5; ; i *= 5 {
		m := n / i
		if m > 0 {
			count += m
			continue
		}
		return count
	}
	return count
}
