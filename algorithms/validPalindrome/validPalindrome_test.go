package validPalindrome

import (
	"testing"
)

func TestValidPalindrome(t *testing.T) {
	if !validPalindrome("A man, a plan, a canal: Panama") {
		t.Error("fail")
	}
	if validPalindrome("race a car") {
		t.Error("fail")
	}
	if !validPalindrome("") {
		t.Error("fail")
	}
}
