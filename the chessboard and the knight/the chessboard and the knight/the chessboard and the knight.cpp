#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 6;
int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

bool isValid(int x, int y, vector<vector<int>>& board) 
{
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == -1;
}

bool solve(int x, int y, int move, vector<vector<int>>& board) 
{
    if (move == SIZE * SIZE) 
    {
        return true;
    }

    for (int i = 0; i < 8; i++) 
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(nextX, nextY, board)) 
        {
            board[nextX][nextY] = move;
            if (solve(nextX, nextY, move + 1, board)) 
            {
                return true;
            }
            board[nextX][nextY] = -1;
        }
    }

    return false;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int startX, startY;
    cout << "Начальная позиция коня (x y): ";
    cin >> startX >> startY;

    vector<vector<int>> board(SIZE, vector<int>(SIZE, -1));
    board[startX][startY] = 0;

    if (solve(startX, startY, 1, board)) 
    {
        cout << "Маршрут коня:" << endl;
        for (int i = 0; i < SIZE; i++) 
        {
            for (int j = 0; j < SIZE; j++) 
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else 
    {
        cout << "No solution found." << endl;
    }

    return 0;
}
