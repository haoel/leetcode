package rotateArray

func rotate(array []int, k int) []int {
	k = k % len(array)
	return append(array[len(array)-k:], array[:len(array)-k]...)
}
