// Source : https://leetcode.com/problems/print-zero-even-odd
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print Zero Even Odd
===================

Suppose you are given the following code:

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // constructor
  public void zero(printNumber) { ... }  // only output 0's
  public void even(printNumber) { ... }  // only output even numbers
  public void odd(printNumber) { ... }   // only output odd numbers
}
The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A will call zero() which should only output 0's.
Thread B will call even() which should only ouput even numbers.
Thread C will call odd() which should only output odd numbers.
Each of the threads is given a printNumber method to output an integer. Modify the given program to output the series 010203040506... where the length of the series must be 2n.



Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously. One of them calls zero(), the other calls even(), and the last one calls odd(). "0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
*/
package main

import "fmt"
import "os"
import "strconv"

type ZeroEvenOdd struct {
	n int
	odd_in chan int
	zero_in chan int
	even_in chan int
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	self := new(ZeroEvenOdd)
	self.n = n
	self.odd_in = make(chan int, 1)
	self.zero_in = make(chan int, 1)
	self.even_in = make(chan int, 1)
	self.zero_in <- 1 // tricky for zero routine start
	return self
}

// message transfers between routines:
// zero -> odd -> zero -> even -> zero ...

// printNumber(x) outputs "x", where x is an integer.
func (self *ZeroEvenOdd) zero(printNumber func(int)) {
	for i := 0; i < self.n; i++ {
		x := <-self.zero_in
		printNumber(0)
		if x % 2 == 1 {
			self.odd_in <- x
		} else {
			self.even_in <- x
		}
	}
}

func (self *ZeroEvenOdd) odd(printNumber func(int)) {
	for i := 1; i <= self.n; i += 2 {
		x := <-self.odd_in
		printNumber(x)
		self.zero_in <- x+1
	}
}

func (self *ZeroEvenOdd) even(printNumber func(int)) {
	for i := 2; i <= self.n; i += 2 {
		x := <-self.even_in
		printNumber(x)
		self.zero_in <- x+1
	}
}

func main() {
	n := 10
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}

	z := NewZeroEvenOdd(n)
	done := make(chan bool, 1)
	printNumber := func (n int) {
		fmt.Printf("%d", n)
	}

	go z.zero(printNumber)
	go func() {
		z.even(printNumber)
		if n % 2 == 0 {
			done <- true
		}
	}()
	go func() {
		z.odd(printNumber)
		if n % 2 != 0 {
			done <- true
		}
	}()

	<-done
}