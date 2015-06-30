package reverseBits

import (
	"testing"
)

func TestReverseBits(t *testing.T) {
	if reverseBits(43261596) != 964176192 {
		t.Error("fail")
	}
}
