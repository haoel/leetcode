/*
 * @lc app=leetcode id=221 lang=golang
 *
 * [221] Maximal Square
 */
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 { return 0 }

	m := len(matrix)
	n := len(matrix[0])

	memo := make([][]int, m)
	maxEdge := 0
	for i := 0; i < m; i++ {
		memo[i] = make([]int, n)
		if string(matrix[i][0]) == "1" { 
			memo[i][0] = 1
			maxEdge = 1
		} else {
			memo[i][0] = 0
		}
	}

	for i := 0; i < n; i++ {
		if string(matrix[0][i]) == "1" {
			memo[0][i] = 1
			maxEdge = 1
		} else {
			memo[0][i] = 0
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if string(matrix[i][j]) == "0" {
				memo[i][j] = 0
			} else { // 1
				memo[i][j] = min(memo[i - 1][j], memo[i][j - 1], memo[i - 1][j - 1]) + 1
			}

			if int(memo[i][j]) > maxEdge {
				maxEdge = int(memo[i][j])
			}
		}
	}

	return maxEdge * maxEdge
}

func min(a ...int) int {
	m := math.MaxInt64
	for _, v := range(a) {
		if v < m {
			m = v
		}
	}

	return m
}

