#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
bool player1_turn = true;

void draw_board() 
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << "| ";
        for (int j = 0; j < 3; j++) 
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool is_winner() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool is_full() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void play_game() 
{
    bool game_over = false;
    int choice;
    char mark;

    while (!game_over) 
    {
        draw_board();
        if (player1_turn) 
        {
            cout << "Очередь 1-ого игрока. Ваш ход: ";
            mark = 'X';
        }
        else 
        {
            cout << "Очередь 1-ого игрока. Ваш ход: ";
            mark = 'O';
        }
        cin >> choice;

        if (choice < 1 || choice > 9) 
        {
            cout << "Неверный ввод. По новой попробуй." << endl;
            continue;
        }

        if (board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') 
        {
            cout << "Эта клетка уже занята. Нужно другое выбрать." << endl;
            continue;
        }

        board[(choice - 1) / 3][(choice - 1) % 3] = mark;

        if (is_winner()) 
        {
            draw_board();
            if (player1_turn) 
            {
                cout << "Поздравление 1-ому игроку, он победил!" << endl;
            }
            else 
            {
                cout << "Поздравление 2-ому игроку, он победил!" << endl;
            }
            game_over = true;
        }
        else if (is_full()) 
        {
            draw_board();
            cout << "It's a tie!" << endl;
            game_over = true;
        }
        else 
        {
            player1_turn = !player1_turn;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "ru");
    play_game();

    return 0;
}