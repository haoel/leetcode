package minStack

type stack struct {
	s   []int
	min int //index of min
}

func (p *stack) push(n int) {
	if len(p.s) == 0 {
		p.min = 0
	} else if n < p.s[p.min] {
		p.min = len(p.s)
	}
	p.s = append(p.s, n)
}

func (p *stack) pop() {
	if len(p.s) == 0 {
		return
	}
	p.s = p.s[:len(p.s)-1]
	if p.min == len(p.s) {
		if len(p.s) == 1 {
			p.min = 0
		} else {
			m := p.s[0]
			for i := 1; i < len(p.s); i++ {
				if p.s[i] < m {
					m = p.s[i]
					p.min = i
				}
			}
		}
	}
}

func (p *stack) top() int {
	if len(p.s) == 0 {
		return 0
	}
	return p.s[len(p.s)-1]
}

func (p *stack) getMin() int {
	if len(p.s) == 0 {
		return 0
	}
	return p.s[p.min]
}
