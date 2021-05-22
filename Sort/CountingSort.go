package main

import (
	"fmt"
	"math/rand"
	"time"
)

func findMax(arr []int) int {
	var temp int

	temp = arr[0]

	for _, e := range arr {
		//if temp < e {
		//	temp = e
		//}
	}

	return temp
}

func makeRange(min, max int) []int {
	a := make([]int, max-min+1)

	for i := range a {
		a[i] = 0
	}
	return a
}

func СountingSort(arr []int) []int {
	//генерация
	counter := makeRange(0, findMax(arr))

	//число элементов
	for _, e := range arr {
		counter[e] += 1
	}

	//Сложить текущий и предыдущий
	for i := 1; i < len(counter); i++ {
		counter[i] += counter[i-1]
	}

	res := make([]int, len(arr))

	//for i := 0 ; i < len(arr) ; i++ {
	//	e := arr[i]
	//	t := counter[e] - 1 // target pos
	//

	//	res[t] = e
	//	counter[e] = counter[e] - 1
	//}

	return res
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10)
	for i := range array {
		array[i] = random.Intn(20)
	}
	fmt.Println(array)
	СountingSort(array)
	fmt.Println(array)
}