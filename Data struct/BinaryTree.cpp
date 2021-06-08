#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
using namespace std;
struct BinTree {
    int value; //содержит значение
    BinTree* left;//адрес левого поддерева
    BinTree* right;//адрес правого поддерева
};
//Функция для создания дерева
//Вход: значение будущего узла,узел бинарного дерева
//Выход: упорядоченое бинарное деревоб,заполеное значениями
void newBinTree(int val, BinTree** Tree) {
    if ((*Tree) == NULL) 
    {
        (*Tree) = new BinTree; //Выделить память
        (*Tree)->value = val;  //Поместить в выделенное место аргумент
        (*Tree)->left = (*Tree)->right = NULL;
        return;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);//Если аргумент больше чем текущий элемент, поместить его вправо
    else newBinTree(val, &(*Tree)->left);//Иначе поместить его влево
}
//Для печати дерева
void Print(BinTree**Tree, int l)
{
    int i;
 
    if (*Tree != NULL)
    {
        Print(&((**Tree).right), l + 1);
        for (i = 1; i <= l; i++) cout << "   ";
        cout << (**Tree).value << endl;
        Print(&((**Tree).left), l + 1);
    }
}
 
void TreeTraversalAndPrint(BinTree* Root) {
    if (Root != NULL) {
        cout << Root->value << endl;
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);
 
    }
}
 
void TreeTraversalAndPrint2(BinTree* Root) {
    if (Root != NULL) {
        TreeTraversalAndPrint2(Root->left);
        TreeTraversalAndPrint2(Root->right);
        cout << Root->value << endl;
    }
}
void TreeTraversalAndPrint3(BinTree* Root) {
    if (Root != NULL) {
        TreeTraversalAndPrint2(Root->left);
        cout << Root->value << endl;
        TreeTraversalAndPrint2(Root->right);
    }
}
//Так как в бинарном дереве поиска для каждого узла справедливо, что left < right, 
//то соответственно для нахождения наименьшенго элемента 
//надо топать от корня по левым веткам до упора - там и будет наименьший.
BinTree* MinValue(BinTree* Tree)
{
    if (Tree->left != NULL) {
        return MinValue(Tree->left);
    }
    else {
        return Tree;
    }
}
//Так как в бинарном дереве поиска для каждого узла справедливо, что left < right, 
//то соответственно для нахождения наибольшего элемента 
//надо топать от корня по правым веткам до упора - там и будет наибольший.
BinTree* MaxValue(BinTree* Tree)
{
    if (Tree->right != NULL) {
        return  MaxValue(Tree->right);
    }
    else {
        return Tree;
    }
}
int NumberOfNodes(BinTree* Tree) {
    if (Tree == NULL) return 0;
    return NumberOfNodes(Tree->left) + 1+ NumberOfNodes(Tree->right);
}
 
int ListCount(BinTree* node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    return  ListCount(node->left) + ListCount(node->right);
}
 
//Высота(максимальная глубина) дерева определяется количеством уровней, 
//на которых располагаются его вершины.
//Высота пустого дерева равна нулю, высота дерева из одного корня – единице.
//На первом уровне дерева может быть только одна вершина – корень дерева, 
//на втором – потомки корня дерева, на третьем – потомки потомков корня дерева и т.д.
int HeightBTree(BinTree* Tree) {
    int x = 0, y = 0;
    if (Tree == NULL) return 0;     //пустое дерево или дошли до листа
    if(Tree->left) x = HeightBTree(Tree->left); //высота левого поддерева
    if (Tree->right) y = HeightBTree(Tree->right);  //высота правого поддерева
    if (x > y) return x + 1;    //+1 от корня к левому поддереву
    else return y + 1;   //+1 от корня к правому поддереву
}
//поиск элемента в бинарном дереве поиска
BinTree* Search(BinTree* Tree, int key) {
    if (Tree == NULL) return NULL;
    if  (Tree->value == key) return Tree;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}
 
 
void DestroyBTree(BinTree* Tree) {
    if (Tree != NULL) {
        DestroyBTree(Tree->left);
        DestroyBTree(Tree->right);
        delete(Tree);
    }
}
void MenuProc() {
    BinTree* Tree = NULL;
    char variant;
    int val;
    cout << "Для проверки дерева его необходимо создать" << endl;
    while (_getch() != 27) {
        cout << "ведите значение (для завершения ввода нажмите ESC) ";
        cin >> val;
        newBinTree(val, &Tree);
    }
    Print(&Tree, 0);
    cout << "Прямой обход дерева" << endl;
    TreeTraversalAndPrint(Tree);
    cout << "Обратный обход дерева" << endl;
    TreeTraversalAndPrint2(Tree);
    cout << "Cимметричный обход дерева" << endl;
    TreeTraversalAndPrint3(Tree);
    cout << "Минимальный элемент дерева-> ";
    BinTree* min = MinValue(Tree);
    cout << min->value;
    cout << endl << "Максимальный элемент дерева-> ";
    BinTree* max = MaxValue(Tree);
    cout << max->value;
    cout << endl;
    cout << "Высота дерева-> ";
    int Heigh = HeightBTree(Tree);
    cout << Heigh;
    cout << endl;
    cout<<"Количество элементов в дереве-> ";
    int a = NumberOfNodes(Tree);
    cout << a << endl;
    cout << "Количество листов в дереве-> ";
    int b = ListCount(Tree);
    cout << b<< endl;
    cout << "Поиск элемента" << endl;
    int key;
    cout << "Введите значение элемента для поиска-> ";
    cin >> key;
    BinTree* Tree1 = Search(Tree,key);
    if (Tree1 == NULL)
        cout << "Элемент не найден";
    else
        cout << "Ваш элемент->" << Tree1->value;
    cout << endl;
    DestroyBTree(Tree);
}
 
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MenuProc();
    system("pause");
    return 0;
}
