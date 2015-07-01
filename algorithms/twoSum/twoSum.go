package twoSum

type twoSum3 struct {
	m map[int]bool
}

func newTwoSum3() *twoSum3 {
	return &twoSum3{m: map[int]bool{}}
}

func (p *twoSum3) add(n int) {
	p.m[n] = true
}

func (p *twoSum3) find(m int) bool {
	for k, _ := range p.m {
		delta := m - k
		if _, ok := p.m[delta]; ok {
			return true
		}
	}
	return false
}
