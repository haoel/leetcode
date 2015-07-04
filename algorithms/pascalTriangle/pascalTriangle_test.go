package pascalTriangle

import (
	"testing"
)

func TestPascalTriangle(t *testing.T) {
	t.Log(pascalTriangle(5))
}

func TestPascalTriangle2(t *testing.T) {
	p10 := []int{1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}
	r := pascalTriangle2(10)
	for k, v := range r {
		if v != p10[k] {
			t.Error("fail")
		}
	}
}
