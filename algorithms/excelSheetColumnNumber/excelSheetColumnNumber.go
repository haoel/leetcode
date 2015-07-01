package excelSheetColumnNumber

func titleToNumber(title string) int {
	count := 0
	for i := len(title) - 1; i >= 0; i-- {
		m := 1
		for j := 0; j < i; j++ {
			m *= (26 * int(uint8(title[i])-'A'+1))
		}
		count += m
	}
	return count
}
