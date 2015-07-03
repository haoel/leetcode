package validPalindrome

func validPalindrome(s string) bool {
	if s == "" {
		return true
	}
	r := trim(s)
	if r == "" {
		return false
	} else {
		for i := 0; i < len(r)/2; i++ {
			if r[i] != r[len(r)-i-1] {
				return false
			}
		}
	}
	return true
}

func trim(s string) string {
	var r string
	for i := 0; i < len(s); i++ {
		if (s[i] >= '0' && s[i] <= '9') ||
			(s[i] >= 'a' && s[i] <= 'z') {
			r = r + string(s[i])
		} else if s[i] >= 'A' && s[i] <= 'Z' {
			r = r + string(s[i]-'A'+'a')
		}
	}
	return r
}
