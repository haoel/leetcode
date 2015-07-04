package pascalTriangle

/*
	   1
	  1 1
	 1 2 1
	1 3 3 1
   1 4 6 4 1
*/
func pascalTriangle2(n int) []int {
	if n == 0 {
		return []int{1}
	}
	s := make([]int, n+1)
	t := make([]int, n+1)
	t[0] = 1
	for i := 2; i <= n+1; i++ {
		s[0] = 1
		for j := 1; j < i; j++ {
			s[j] = t[j-1] + t[j]
		}
		t = s
		s = make([]int, n+1)
	}
	return t
}
