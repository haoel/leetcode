package isomorphicStrings

func isomorphicStrings(s, t string) bool {
	const CAPACITY = 256
	maps, mapt := make([]byte, CAPACITY), make([]byte, CAPACITY)
	for i := 0; i < len(s); i++ {
		if maps[s[i]] == 0 && mapt[t[i]] == 0 {
			maps[s[i]] = t[i]
			mapt[t[i]] = s[i]
			continue
		}
		if maps[s[i]] == t[i] && mapt[t[i]] == s[i] {
			continue
		}
		return false
	}
	return true
}
