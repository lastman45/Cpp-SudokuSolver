#include <iostream>

using namespace std;

#define UNASSIGNED 0
#define N 9

bool SEARCH(int BOX[N][N], int &Row, int &Column);
bool PROJECT(int BOX[N][N], int Row, int Column, int Number);
void PRINT_BOX(int BOX[N][N]);
bool SUDOKU_SOLUTION(int BOX[N][N]);
bool isValidInput(int BOX[N][N]);
void INPUT_BOX(int BOX[N][N]);
int COUNT_SOLUTIONS(int BOX[N][N]);

bool isValidInput(int BOX[N][N])
{
    for (int Row = 0; Row < N; Row++)
    {
        for (int Column = 0; Column < N; Column++)
        {
            if (BOX[Row][Column] < 0 || BOX[Row][Column] > 9)
            {
                return false;
            }
        }
    }
    return true;
}

void INPUT_BOX(int BOX[N][N])
{
    cout << "Enter the Sudoku puzzle (0 for empty cells):" << endl;
    for (int Row = 0; Row < N; Row++)
    {
        for (int Column = 0; Column < N; Column++)
        {
            cin >> BOX[Row][Column];
        }
    }
}

void PRINT_BOX(int BOX[N][N])
{
    for (int Row = 0; Row < N; Row++)
    {
        if (Row % 3 == 0 && Row != 0)
        {
            cout << "---------------------" << endl;
        }
        for (int Column = 0; Column < N; Column++)
        {
            if (Column % 3 == 0 && Column != 0)
            {
                cout << "| ";
            }
            cout << BOX[Row][Column] << " ";
        }
        cout << endl;
    }
}

bool SEARCH(int BOX[N][N], int &Row, int &Column)
{
    for (Row = 0; Row < N; Row++)
    {
        for (Column = 0; Column < N; Column++)
        {
            if (BOX[Row][Column] == UNASSIGNED)
            {
                return true;
            }
        }
    }
    return false;
}

bool PROJECT(int BOX[N][N], int Row, int Column, int Number)
{

    for (int x = 0; x < N; x++)
    {
        if (BOX[Row][x] == Number || BOX[x][Column] == Number)
        {
            return false;
        }
    }

    int startRow = Row - Row % 3, startCol = Column - Column % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (BOX[i + startRow][j + startCol] == Number)
            {
                return false;
            }
        }
    }
    return true;
}

int COUNT_SOLUTIONS(int BOX[N][N])
{
    int Row, Column;
    if (!SEARCH(BOX, Row, Column))
    {
        return 1;
    }

    int count = 0;
    for (int Number = 1; Number <= 9; Number++)
    {
        if (PROJECT(BOX, Row, Column, Number))
        {
            BOX[Row][Column] = Number;
            count += COUNT_SOLUTIONS(BOX);
            BOX[Row][Column] = UNASSIGNED;
        }
    }
    return count;
}

bool SUDOKU_SOLUTION(int BOX[N][N])
{
    int Row, Column;
    if (!SEARCH(BOX, Row, Column))
    {
        return true;
    }

    for (int Number = 1; Number <= 9; Number++)
    {
        if (PROJECT(BOX, Row, Column, Number))
        {
            BOX[Row][Column] = Number;
            if (SUDOKU_SOLUTION(BOX))
            {
                return true;
            }
            BOX[Row][Column] = UNASSIGNED;
        }
    }
    return false;
}

int main()
{
    int BOX[N][N] = {0};

    INPUT_BOX(BOX);
    if (!isValidInput(BOX))
    {
        cout << "Invalid input! Please enter numbers between 0 and 9." << endl;
        return 1;
    }

    if (SUDOKU_SOLUTION(BOX))
    {
        cout << "Solved Sudoku:" << endl;
        PRINT_BOX(BOX);
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    int solutionCount = COUNT_SOLUTIONS(BOX);
    cout << "Number of solutions: " << solutionCount << endl;

    return 0;
}
