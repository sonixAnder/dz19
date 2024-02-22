#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 4;

int board[SIZE][SIZE];

void init_board() 
{
    int num = 1;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (num == SIZE * SIZE) 
            {
                board[i][j] = 0;
            }
            else 
            {
                board[i][j] = num++;
            }
        }
    }
}

void shuffle_board() 
{
    srand(time(0));
    for (int k = 0; k < 1000; k++) 
    {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        int di = rand() % SIZE;
        int dj = rand() % SIZE;

        swap(board[i][j], board[di][dj]);
    }
}

void print_board() 
{
    cout << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == 0) 
            {
                cout << "    ";
            }
            else {
                cout << board[i][j];
                if (board[i][j] < 10) 
                {
                    cout << "   ";
                }
                else {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool is_solved() 
{
    int num = 1;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] != num && !(num == SIZE * SIZE && board[i][j] == 0)) 
            {
                return false;
            }
            num++;
        }
    }
    return true;
}

void move_tile(int tile) 
{
    int row, column;
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == tile) 
            {
                row = i;
                column = j;
                break;
            }
        }
    }

    if (row > 0 && board[row - 1][column] == 0) 
    {
        swap(board[row][column], board[row - 1][column]);
    }
    else if (row < SIZE - 1 && board[row + 1][column] == 0) 
    {
        swap(board[row][column], board[row + 1][column]);
    }
    else if (column > 0 && board[row][column - 1] == 0) 
    {
        swap(board[row][column], board[row][column - 1]);
    }
    else if (column < SIZE - 1 && board[row][column + 1] == 0) 
    {
        swap(board[row][column], board[row][column + 1]);
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    init_board();
    shuffle_board();

    cout << "Вэлком ту зе 'Пятнашки'" << endl;

    while (!is_solved()) 
    {
        print_board();

        int tile;
        cout << "Введите номер плитки, которую вы хотите переместить (0 для выхода): ";
        cin >> tile;

        if (tile == 0) 
        {
            cout << "Ты вышел из игры." << endl;
            break;
        }
        else 
        {
            move_tile(tile);
        }
    }

    if (is_solved()) 
    {
        cout << "Поздравляю! Вы разгадали головоломку!" << endl;
        print_board();
    }

    return 0;
}