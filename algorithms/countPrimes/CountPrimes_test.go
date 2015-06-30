package countPrimes

import (
	"testing"
)

func TestCountPrimes(t *testing.T) {
	if countPrimes(100) != 25 {
		t.Error("fail")
	}
}
