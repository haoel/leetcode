package compareVersionNumbers

import (
	"testing"
)

func TestCompare(t *testing.T) {
	if compareVersion("1.11.0.0", "1.11.0.0.0") != 0 {
		t.Error("fail")
	}
	if compareVersion("2.1", "1.2") != 1 {
		t.Error("fail")
	}
	if compareVersion("0.1", "1.2") != -1 {
		t.Error("fail")
	}
}
