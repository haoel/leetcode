package majorityElement

import (
	"testing"
)

func TestMajorityElement(t *testing.T) {
	var nums = []int{1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1}
	if majorityElement(nums) != 1 {
		t.Error("fail")
	}
}
