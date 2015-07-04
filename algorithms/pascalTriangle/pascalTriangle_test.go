package pascalTriangle

import (
	"testing"
)

func TestPascalTriangle2(t *testing.T) {
	p10 := []int{1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}
	if pascalTriangle2(10) != p10 {
		t.Error("fail")
	}
}
