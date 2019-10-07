// Source : https://leetcode.com/problems/print-foobar-alternately
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print Foobar Alternately
========================

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.



Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar(). "foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/
package main

import "fmt"
import "os"
import "strconv"

type FooBar struct {
	n int
	c1 chan bool
	c2 chan bool
}

func NewFooBar(n int) *FooBar {
	self := new(FooBar)
	self.n = n
	self.c1 = make(chan bool, 1)
	self.c2 = make(chan bool, 1)
	self.c1 <- true
	return self
}

func (self *FooBar) foo(printFoo func()) {
	for i := 0; i < self.n; i++ {
		<-self.c1
		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo();
		self.c2 <- true
	}
}

func (self *FooBar) bar(printBar func()) {
	for i := 0; i < self.n; i++ {
		<-self.c2
		// printBar() outputs "bar". Do not change or remove this line.
		printBar();
		self.c1 <- true
	}
}

func main() {
	n := 10
	if len(os.Args) > 1 {
		n, _ = strconv.Atoi(os.Args[1])
	}

	fb := NewFooBar(n)
	done := make(chan bool, 1)

	go fb.foo(func () { fmt.Printf("foo") })
	go func() {
		fb.bar(func () { fmt.Printf("bar")})
		done <- true
	}()

	<-done
}