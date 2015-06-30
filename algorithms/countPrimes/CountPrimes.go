package countPrimes

func countPrimes(n int) int {
	b := make([]bool, n)
	for i := 2; i*i < n; i++ {
		if !b[i] {
			for j := i * i; j < n; j += i {
				b[j] = true
			}
		}
	}
	count := 0
	for i := 2; i < n; i++ {
		if !b[i] {
			count++
		}
	}
	return count
}
