package isomorphicStrings

import (
	"testing"
)

func TestIsomorphicStrings(t *testing.T) {
	source, target := "egg", "add"
	if !isomorphicStrings(source, target) {
		t.Error("fail")
	}
	source, target = "foo", "bar"
	if isomorphicStrings(source, target) {
		t.Error("fail")
	}
	source, target = "paper", "title"
	if !isomorphicStrings(source, target) {
		t.Error("fail")
	}
}
