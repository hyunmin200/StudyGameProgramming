﻿#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;
int board[MAX][MAX];
int N;

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }

        cout << endl;
    }
}

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3,
};

bool CanGo(int y, int x)
{
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;
    if (board[y][x] != 0)
        return false;
    return true;
}

void SetBoard()
{
    int dir = RIGHT;
    int num = 1;
    int y = 0;
    int x = 0;

    while (true)
    {
        board[y][x] = num;

        if (num == N * N)
            break;

        int nextY;
        int nextX;

        int dy[] = {0, 1, 0, -1};
        int dx[] = {1, 0, -1, 0};

        nextY = y + dy[dir];
        nextX = x + dx[dir];

        /*switch (dir)
        {
            case RIGHT:
                nextY = y;
                nextX = x + 1;
                break;
            case DOWN:
                nextY = y - 1;
                nextX = x;
                break;
            case LEFT:
                nextY = y;
                nextX = x - 1;
                break;
            case UP:
                nextY = y + 1;
                nextX = x;
                break;
        }*/

        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else
        {
            dir = (dir + 1) % 4;
            /*switch (dir)
            {
                case RIGHT:
                    dir = DOWN;
                    break;
                case DOWN:
                    dir = LEFT;
                    break;
                case LEFT:
                    dir = UP;
                    break;
                case UP:
                    dir = RIGHT;
                    break;
            }*/
        }
    }
}

// [1][2][3][4][5]
// [16][ ][ ][ ][6]
// [15][ ][ ][ ][7]
// [14][ ][ ][ ][8]
// [13][12][11][10][9]

int main()
{
    cin >> N;

    SetBoard();

    PrintBoard();
}
