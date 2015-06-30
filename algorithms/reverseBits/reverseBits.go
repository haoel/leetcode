package reverseBits

func reverseBits(n uint32) uint32 {
	var m uint32
	for i := 0; i < 32; i++ {
		m <<= 1
		m += n & 1
		n /= 2
	}
	return m
}
