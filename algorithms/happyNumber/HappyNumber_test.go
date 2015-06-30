package happyNumber

import (
	"testing"
)

func TestHappyNumber(t *testing.T) {
	if isHappyNumber(11) {
		t.Error("fail")
	}
	if !isHappyNumber(19) {
		t.Error("fail")
	}
}
