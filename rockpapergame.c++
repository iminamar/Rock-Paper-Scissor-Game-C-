#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int winner(string guess[], int p1, int p2, int *p1_score, int *p2_score, int *end)
{
    int player1_score = *p1_score;
    int player2_score = *p2_score;
    if (guess[p1] == guess[p2])
    {
        player1_score += 1;
        player2_score += 1;
        (*end)++;
    }
    else if ((guess[p1] == "rock" && guess[p2] == "scissor") || (guess[p1] == "paper" && guess[p2] == "rock") || (guess[p1] == "scissor" && guess[p2] == "paper"))
    {
        player1_score += 1;
    }
    else
    {
        player2_score += 1;
    }

    *p1_score = player1_score;
    *p2_score = player2_score;
}
int main()
{
    //--------changing the output window color---------//
    //  https://www.geeksforgeeks.org/colorizing-text-and-console-background-in-c/
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_color, rand() % 15);
    //-----------------------------------------------//

    //-----------------------------------------------//
    string guess[3] = {"rock", "paper", "scissor"};
    int player1_score = 0, player2_score = 0;
    int start = 0, end = 3;
    string player1, player2;
    cout << "player1: enter name: ";
    cin >> player1;
    cout << "player2: enter name: ";
    cin >> player2;
    //-----------------------------------------------//

    system("CLS");
    srand(time(NULL));
    while (start < end)
    {
        system("CLS");
        int p1, p2;
        p1 = rand() % 3;
        p2 = rand() % 3;
        cout << player1 << ": " << guess[p1] << endl;
        cout << player2 << ": " << guess[p2] << endl;
        winner(guess, p1, p2, &player1_score, &player2_score, &end);
        start++;
        system("pause");
    }
    if (player1_score > player2_score)
    {
        cout << player1 << " wins!!!\n\n\n";
    }
    else
    {
        cout << player2 << " wins!!!\n\n\n";
    }

    system("pause");
    return 0;
}
