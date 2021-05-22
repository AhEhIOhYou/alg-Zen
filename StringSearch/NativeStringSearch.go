package main

import "fmt"

func NaiveStringSearch(text, pattern string) int {
	//Длина строки и длина паттерна
	textLength := len(text)
	patternLength := len(pattern)

	//Если паттерн больше строки - ошибка
	if patternLength > textLength {
		return -1
	}

	fmt.Println(textLength, patternLength, textLength-patternLength + 1)
	//Цикл идет до минимального кол-ва символов в строке (чтоб влез паттерн)
	for i := 0; i < textLength-patternLength + 1; i++ {
		matchesCount := 0
		for j := 0; j < patternLength; j++ {
			if text[i+j] != pattern[j] {
				break
			}
			matchesCount++
		}
		if matchesCount == patternLength {
			return i
		}
	}
	return -1
}

func main() {
	var text string = "hda lkjjpl hell hqdl hellod aa"

	key := NaiveStringSearch(text,"hello")

	fmt.Println(key)
}