package main

import "fmt"

func main() {
	var a = [...]string{1: "hello", 2: "tung", "deptrai"}
	for value := range a {
		fmt.Println(a[value])
	}
	// fmt.Println("hello")
}
