package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	fmt.Println("what's your name")
	// var name string
	// fmt.Scan(&name)
	// fmt.Println("hello ,Mr. ",name)

 reader := bufio.NewReader(os.Stdin)
 name, _ := reader.ReadString('\n')

fmt.Println("Hello ,Mr.", name)


}
