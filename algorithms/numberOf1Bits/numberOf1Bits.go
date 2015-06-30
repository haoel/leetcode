package numberOf1Bits

func hammingWeight(n uint32) int {
	count := 0
	for ; n > 0; n /= 2 {
		if n&1 == 1 {
			count++
		}
	}
	return count
}
