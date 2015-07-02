package compareVersionNumbers

func compareVersion(v1, v2 string) int {
	vi1 := split(v1)
	vi2 := split(v2)

	vi1 = rightTrimZero(vi1)
	vi2 = rightTrimZero(vi2)

	for i := 0; i < len(vi1) && i < len(vi2); i++ {
		if vi1[i] > vi2[i] {
			return 1
		} else if vi1[i] < vi2[i] {
			return -1
		}
	}

	if len(vi1) > len(vi2) {
		return 1
	} else if len(vi1) < len(vi2) {
		return -1
	}

	return 0
}

func split(s string) []int {
	var p string
	var q []string
	var d []int
	for k, v := range s {
		if v <= '9' && v >= '0' {
			p = p + string(v)
			if k == len(s)-1 {
				q = append(q, p)
			}
		} else {
			q = append(q, p)
			p = ""
		}
	}
	for _, v := range q {
		c := atoi(v)
		d = append(d, c)
	}
	return d
}

func atoi(s string) int {
	var c int
	var j int = 1
	for i := len(s) - 1; i >= 0; i-- {
		c += int(s[i]-'0') * j
		j *= 10
	}
	return c
}

func rightTrimZero(d []int) []int {
	for i := len(d) - 1; i >= 0; i-- {
		if d[i] == 0 {
			d = d[:i]
		} else {
			return d
		}
	}
	return nil
}
