// Source : https://leetcode.com/problems/print-in-order
// Author : Siwei Xu
// Date   : 2019-10-07
/*

Print In Order
==============

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().



Example 1:

Input: [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.


Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
*/
package main

import "fmt"

type Foo struct {
    c12 chan bool
    c23 chan bool
}

func NewFoo() *Foo {
    return &Foo {
        c12: make(chan bool, 1),
        c23: make(chan bool, 1),
    }
}


func (self *Foo) first(printFirst func()) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    self.c12 <- true
}

func (self *Foo) second(printSecond func()) {
    <- self.c12
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    self.c23 <- true
}

func (self *Foo) third(printThird func()) {
    <- self.c23
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}


func main()  {
    foo := NewFoo()
    done := make(chan bool, 1)

    go foo.first(func() { fmt.Printf("first") })
    go foo.second(func () { fmt.Printf("second") })
    go func() {
        foo.third(func () { fmt.Printf("third") })
        done <- true
    }()

    <- done
}