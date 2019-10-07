// Source : https://leetcode.com/problems/building-h2o
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Building H2O
============

There are two kinds of threads, oxygen and hydrogen. Your goal is to group these threads to form water molecules. There is a barrier where each thread has to wait_consumed until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must be able to immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it has to wait_consumed for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it has to wait_consumed for an oxygen thread and another hydrogen thread.
We don’t have to worry about matching the threads up explicitly; that is, the threads do not necessarily know which other threads they are paired up with. The key is just that threads pass the barrier in complete sets; thus, if we examine the sequence of threads that bond and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.



Example 1:

Input: "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.


Constraints:

Total length of input string will be 3n, where 1 ≤ n ≤ 20.
Total number of H will be 2n in the input string.
Total number of O will be n in the input string.

*/
package main

import "os"
import "fmt"
import "sync"

type H2O struct {
	H int
	O int
	m *sync.Mutex
	c *sync.Cond
}

func NewH2O() *H2O {
	h2o := new(H2O)
	h2o.H = 0
	h2o.O = 0
	h2o.m = &sync.Mutex{}
	h2o.c = sync.NewCond(h2o.m)
	return h2o
}

// H2
func (self *H2O) hydrogen(releaseHydrogen func()) {
	self.m.Lock()
	for self.H >= 2 {
		self.c.Wait()
	}

	// releaseHydrogen() outputs "H". Do not change or remove this line.
	releaseHydrogen()

	self.H += 1
	if self.H == 2 && self.O == 1 {
		self.H = 0
		self.O = 0
		self.c.Broadcast()
	}
	self.m.Unlock()

	// self.finish <- true
}

// O2
func (self *H2O) oxygen(releaseOxygen func()) {
	self.m.Lock()
	for self.O >= 1 {
		self.c.Wait()
	}

	// releaseOxygen() outputs "O". Do not change or remove this line.
	releaseOxygen()

	self.O += 1
	if self.H == 2 && self.O == 1 {
		self.H = 0
		self.O = 0
		self.c.Broadcast()
	}
	self.m.Unlock()
}

func main() {
	input := "OOOOHHHHHHHH"
	if len(os.Args) > 1 {
		input = os.Args[1]
	}

	h2o := NewH2O()
	output := ""
	waiter := &sync.WaitGroup{}
	mutex := &sync.Mutex{}
	putch := func(ch int) {
		mutex.Lock()
		output = output + string(ch)
		mutex.Unlock()
		waiter.Done()
	}

	waiter.Add(len(input))
	for _, ch := range input {
		if ch == 'H' {
			go h2o.hydrogen(func() { putch('H') })
		} else {
			go h2o.oxygen(func() { putch('O') })
		}
	}

	waiter.Wait()

	fmt.Println("input :", input, len(input))
	fmt.Println("output:", output, len(output))
}
