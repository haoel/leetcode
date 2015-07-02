package excelSheetColumnTitle

func convertToTitle(n int) string {
	var title string
	for ; n > 0; n /= 26 {
		c := string(n%26 + 'A' - 1)
		title = c + title
	}
	return title
}
