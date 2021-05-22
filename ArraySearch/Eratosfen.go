package main

import "fmt"

const arrSize = 100

func EratosthenesSieve() []int {
	fmt.Println("Решето Эратосфена: ")
	var arr [arrSize]int
	var a []int

	//Все числа от 0 до arrSize
	for i := 0; i < len(arr); i++ {
		arr[i] = i
	}

	//идем от 2 до arrSize зануляя числа кратные 2, потом 3 и тд
	for i := 2; i*i < len(arr); i++ {
		if arr[i] != 0 {
			for j := i * i; j < len(arr); j += i {
				arr[j] = 0
			}
		}
	}
	//все незачеркнутые числа заносим в наш массив
	for i := 0; i < len(arr); i++ {
		if arr[i] != 0 {
			a = append(a, arr[i])
		}
	}
	return a
}

func main() {
	fmt.Println(EratosthenesSieve())
}