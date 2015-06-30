package containsDuplicate

import (
	"testing"
)

func TestContainsDuplicate(t *testing.T) {
	nums := []int{1, 2, 3, 4, 5}
	if containsDuplicate(nums) {
		t.Error("fail")
	}

	nums = []int{1, 2, 3, 4, 5, 1}
	if !containsDuplicate(nums) {
		t.Error("fail")
	}
}

func TestContainsDuplicate2(t *testing.T) {
	nums := []int{1, 2, 3, 4, 5, 1}
	if containsDuplicate2(nums, 4) {
		t.Error("fail")
	}

	if !containsDuplicate2(nums, 5) {
		t.Error("fail")
	}
}
