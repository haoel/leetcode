package excelSheetColumnNumber

import (
	"testing"
)

func TestTitleToNumber(t *testing.T) {
	if titleToNumber("AAA") != 703 {
		t.Error("fail")
	}
}
