package numberOf1Bits

import (
	"testing"
)

func TestHammingWeight(t *testing.T) {
	if hammingWeight(11) != 3 {
		t.Error("fail")
	}
}
