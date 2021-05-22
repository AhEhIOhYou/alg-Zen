package main

import "fmt"

//Вершина - значение + указатель на следующую вершину
type Node struct {
	data int
	next *Node
}

//Стэк - число вершин + указатель на вершину
type Stack struct {
	top *Node
}

//Добавление числа назад
func (s *Stack) Push(i int) {
	data := &Node{data: i}
	if s.top != nil {
		data.next = s.top
	}
	s.top = data
}

//Удаление последнего числа
func (s *Stack) Pop() (int, bool) {
	if s.top == nil {
		return 0, false
	}
	i := s.top.data
	s.top = s.top.next
	return i, true
}

//Вернет веришну
func (s *Stack) Peek() (int, bool) {
	if s.top == nil {
		return 0, false
	}
	return s.top.data, true
}

//Вернет значения стека в массиве
func (s *Stack) GetList() []int {

	var items []int

	current := s.top
	for current != nil {
		items = append(items, current.data)
		current = current.next
	}
	return items
}

//Проверка на пустоту
func (s *Stack) IsEmpty() bool {
	return s.top == nil
}

//Очищает стек
func (s *Stack) Empty() {
	s.top = nil
}

func main() {
	var s = Stack{
		top: nil,
	}

	fmt.Print("Стэк пустой: ")
	fmt.Println(s.IsEmpty())

	s.Push(2)
	s.Push(12)
	s.Push(22)

	fmt.Print("Стэк: ")
	fmt.Println(s.GetList())

	fmt.Print("Вершина: ")
	fmt.Println(s.Peek())

	fmt.Print("Стэк пустой: ")
	fmt.Println(s.IsEmpty())
}