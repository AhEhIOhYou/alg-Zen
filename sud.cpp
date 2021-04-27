
#include <iostream>
 

using namespace std;
 
// N is the size of the 2D matrix   N*N
#define N 9
 
/* A utility function to print grid */

void print(int arr[N][N])
{

    for (int i = 0; i < N; i++) 

    {

        for (int j = 0; j < N; j++)

            cout << arr[i][j] << " ";

        cout << endl;

    }
}
 
// Checks whether it will be 
// legal to assign num to the
// given row, col

bool isSafe(int grid[N][N], int row, 

                       int col, int num)
{

     

    // Check if we find the same num 

    // in the similar row , we

    // return false

    for (int x = 0; x <= 8; x++)

        if (grid[row][x] == num)

            return false;
 

    // Check if we find the same num in 

    // the similar column , we

    // return false

    for (int x = 0; x <= 8; x++)

        if (grid[x][col] == num)

            return false;
 

    //Проверка кубика
    int startRow = row - row % 3, 

            startCol = col - col % 3;


    for (int i = 0; i < 3; i++)

        for (int j = 0; j < 3; j++)

            if (grid[i + startRow][j + 

                            startCol] == num)

                return false;
 

    return true;
}
 
bool solveSuduko(int grid[N][N], int row, int col)
{

    //когда придём к концу (8 строка, 9 столбец) - вернуть истину
    if (row == N - 1 && col == N)

        return true;
 

    //если дошли до конца ряда - переходим на новую строку
    if (col == N) {

        row++;

        col = 0;

    }

   

    //если что-то уже лежит, идём дальше

    if (grid[row][col] > 0)

        return solveSuduko(grid, row, col + 1);
 

    for (int num = 1; num <= N; num++) 

    {
        // идём по числа от 1 до 9, проверяем подходит ли оно на текущее место
        if (isSafe(grid, row, col, num)) 
        {
         
           //Ставим число, в текущей строке-столбце, предполагаем, что оно верно

            grid[row][col] = num;

           

            //рекурсивно идём дальше

            if (solveSuduko(grid, row, col + 1))
                //когда последняя рекурсия вернёт true - все рекурсии вернут true
                return true;

        }

       

        //Удаляем присвоенное число, т.к. ошиблись

        grid[row][col] = 0;

    }

    return false;
}

int main()
{

    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },

                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },

                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },

                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },

                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },

                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },

                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },

                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },

                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
 

    if (solveSuduko(grid, 0, 0))

        print(grid);

    else

        cout << "Решения не существует!" << endl;
 

    return 0;
