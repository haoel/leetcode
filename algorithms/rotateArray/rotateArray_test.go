package rotateArray

import (
	"testing"
)

func TestRotate(t *testing.T) {
	array := []int{1, 2, 3, 4, 5, 6, 7}
	narray := []int{5, 6, 7, 1, 2, 3, 4}
	result := rotate(array, 3)
	for k, v := range result {
		if v != narray[k] {
			t.Error("fail")
		}
	}
}
