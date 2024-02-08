// Online C++ compiler to run C++ program online
 #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateRandomNumber(int game[4][4]) {
    int upper = 3;
    int lower = 0;
    int arr[2];
    
    while (true) {
        for (int i = 0; i < 2; i++) {
            arr[i] = (rand() % (upper - lower + 1)) + lower;
        }

        if (game[arr[0]][arr[1]] == 0) {
            game[arr[0]][arr[1]] = 2;
            return;
        }
    }
}

int checkWinLoss(int game[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game[i][j] == 2048) {
                return 1; // Win
            }
            else if (game[i][j] == 0) {
                return 0; // Continue playing
            }
        }
    }
    return -1; // Loss
}

void moveUp(int game[4][4]) {
    for (int j = 0; j < 4; j++)
{
for (int i = 0; i < 3; i++)
{
int swap = -1;
int m = game[i][j];
if (m != 0)
{
for (int k = i + 1; k < 4; k++)
{
if (game[k][j] != 0)
{
swap = k;
break;
}
}
if (swap != -1)
{
if (game[swap][j] == m)
{
game[i][j] = 2 * m;
game[swap][j] = 0;
break;
}
}
}
}
}
}
for (int j = 0; j < 4; j++)
{
for (int i = 0; i < 3; i++)
{
int idx = i;
if (game[i][j] == 0)
{
for (int k = i + 1; k < 4; k++)
{
if (game[k][j] != 0)
{
idx = k;
break;
}
}
game[i][j] = game[idx][j];
game[idx][j] = 0;
}
}
}
}

void moveLeft(int game[4][4]) {
    for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 3; j++)
{
int swap = -1;
int m = game[i][j];
if (m != 0)
{
for (int k = j + 1; k < 4; k++)
{
if (game[i][k] != 0)
{
swap = k;
break;
}
}
if (swap != -1)
{
if (game[i][swap] == m)
{
game[i][j] = 2 * m;
game[i][swap] = 0;
break;
}
}
}
}
}
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 3; j++)
{
int idx = j;
if (game[i][j] == 0)
{
for (int k = j + 1; k < 4; k++)
{
if (game[i][k] != 0)
{
idx = k;
break;
}
}
game[i][j] = game[i][idx];
game[i][idx] = 0;
}
}
}
}
}
}
void moveRight(int game[4][4]) {
    {
for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 3; j++)
{
int swap = -1;
int m = game[i][j];
if (m != 0)
{
for (int k = j + 1; k < 4; k++)
{
if (game[i][k] != 0)
{
swap = k;
break;
}
}
if (swap != -1)
{
if (game[i][swap] == m)
{
game[i][j] = 2 * m;
game[i][swap] = 0;
break;
}
}
}
}
}
for (int i = 0; i < 4; i++)
{
for (int j = 3; j > 0; j--)
{
int idx = j;
if (game[i][j] == 0)
{
for (int k = j - 1; k >= 0; k--)
{
if (game[i][k] != 0)
{
idx = k;
break;
}
}
game[i][j] = game[i][idx];
game[i][idx] = 0;
}
}
}
}
}

void moveDown(int game[4][4]) {
  for (int j = 0; j < 4; j++)
{
for (int i = 0; i < 3; i++)
{
int swap = -1;
int m = game[i][j];
if (m != 0)
{
for (int k = i + 1; k < 4; k++)
{
if (game[k][j] != 0)
{
swap = k;
break;
}
}
if (swap != -1)
{
if (game[swap][j] == m)
{
game[i][j] = 2 * m;
game[swap][j] = 0;
break;
}
}
}
}
}
for (int j = 0; j < 4; j++)
{
for (int i = 3; i > 0; i--)
{
int idx = i;
if (game[i][j] == 0)
{
for (int k = i - 1; k >= 0; k--)
{
if (game[k][j] != 0)
{
idx = k;
break;
}
}
game[i][j] = game[idx][j];
game[idx][j] = 0;
}
}
}
}

void displayBoard(int game[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << game[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random numbers
    
    const int n = 4;
    int game[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            game[i][j] = 0;
        }
    }

    generateRandomNumber(game);

    int userInput;
    
    while (true) {
        cout << endl;
        displayBoard(game);

        int gameStatus = checkWinLoss(game);

        if (gameStatus == 1) {
            cout << "You won!!\n";
            break;
        }
        else if (gameStatus == -1) {
            cout << "You lost!!\n";
            break;
        }
        else {
            generateRandomNumber(game);

            cout << "Enter 4 for left\n6 for right\n5 for down\n8 for up\n";
            cin >> userInput;

            switch (userInput) {
                case 4:
                    moveLeft(game);
                    break;
                case 6:
                    moveRight(game);
                    break;
                case 5:
                    moveDown(game);
                    break;
                case 8:
                    moveUp(game);
                    break;
                default:
                    cout << "Wrong input, try again\n";
                    return 0;
            }
        }
    }

    cout << "Thanks for playing\n";
    return 0;
}

