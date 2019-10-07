// Source : https://leetcode.com/problems/fizz-buzz-multithreaded/
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Fizz Buzz Multithreaded
=======================

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.
*/

package main

import "fmt"
import "sync"
import "os"
import "strconv"

type FizzBuzz struct {
	n int
	// tansfer numbers in the channels:
	fizz_in chan int
	buzz_in chan int
	fizzbuzz_in chan int
	number_in chan int
}

func NewFizzBuzz(n int) *FizzBuzz {
	fb := new(FizzBuzz)
	fb.n = n
	fb.fizz_in = make(chan int, 1)
	fb.buzz_in = make(chan int, 1)
	fb.fizzbuzz_in = make(chan int, 1)
	fb.number_in = make(chan int, 1)
	fb.number_in <- 1
	return fb
}

func (self *FizzBuzz) dispatch(nx int) {
	if nx % 15 == 0 {
		self.fizzbuzz_in <- nx
	} else if nx % 3 == 0 {
		self.fizz_in <- nx
	} else if nx % 5 == 0 {
		self.buzz_in <- nx
	} else {
		self.number_in <- nx
	}
}

// printFizz() outputs "fizz".
func (self *FizzBuzz) fizz(printFizz func()) {
	for x := range self.fizz_in {
		if x > self.n {
			close(self.buzz_in)
			close(self.fizzbuzz_in)
			close(self.number_in)
			break
		}

		printFizz()

		self.dispatch(x + 1)
	}
}

// printBuzz() outputs "buzz".
func (self *FizzBuzz) buzz(printBuzz func()) {
	for x := range self.buzz_in {
		if x > self.n {
			close(self.fizz_in)
			close(self.fizzbuzz_in)
			close(self.number_in)
			break
		}

		printBuzz()

		self.dispatch(x + 1)
	}
}

// printFizzBuzz() outputs "fizzbuzz".
func (self *FizzBuzz) fizzbuzz(printFizzBuzz func()) {
	for x := range self.fizzbuzz_in {
		if x > self.n {
			close(self.fizz_in)
			close(self.buzz_in)
			close(self.number_in)
			break
		}

		printFizzBuzz()

		self.dispatch(x + 1)
	}
}

// printNumber(x) outputs "x", where x is an integer.
func (self *FizzBuzz) number(printNumber func(int)) {
	for x := range self.number_in {
		if x > self.n {
			close(self.fizz_in)
			close(self.buzz_in)
			close(self.fizzbuzz_in)
			break
		}

		if x % 3 != 0 && x % 5 != 0 && x % 15 != 0 {
			printNumber(x)
		}

		self.dispatch(x + 1)
	}
}

func main() {
	n := 15
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}

	fb := NewFizzBuzz(n)
	waiter := &sync.WaitGroup{}

	waiter.Add(4)
	go func () {
		fb.fizz(func () { fmt.Printf("fizz,") })
		waiter.Done()
	}()
	go func () {
		fb.buzz(func () { fmt.Printf("buzz,") })
		waiter.Done()
	}()
	go func () {
		fb.fizzbuzz(func () { fmt.Printf("fizzbuzz,") })
		waiter.Done()
	}()
	go func () {
		fb.number(func (n int) { fmt.Printf("%d,", n) })
		waiter.Done()
	}()

	waiter.Wait()
}