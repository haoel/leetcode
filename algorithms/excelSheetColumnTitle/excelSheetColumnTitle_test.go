package excelSheetColumnTitle

import (
	"testing"
)

func TestConvertToTitle(t *testing.T) {
	if convertToTitle(28) != "AB" {
		t.Error("fail")
	}
}
