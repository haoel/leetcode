package factorialTrailingZeroes

import (
	"testing"
)

func TestTrailingZeroes(t *testing.T) {
	if trailingZeroes(4617) != 1151 {
		t.Error("fail")
	}
}
