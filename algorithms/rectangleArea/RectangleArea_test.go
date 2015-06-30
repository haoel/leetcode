package rectangleArea

import (
	"testing"
)

func TestRectangleArea(t *testing.T) {
	if computeArea(-1, -1, 1, 1, -2, -2, 2, 2) != 16 {
		t.Error("fail")
	}

	if computeArea(-2, -2, 2, 2, -1, -1, 1, 1) != 16 {
		t.Error("fail")
	}

	if computeArea(-2, -2, 2, 2, -4, 3, -3, 4) != 17 {
		t.Error("fail")
	}

	if computeArea(-3, -0, 3, 4, 0, -1, 9, 2) != 45 {
		t.Error("fail")
	}

	if computeArea(-2, -2, 2, 2, -3, -3, 3, -1) != 24 {
		t.Error("fail")
	}
}
