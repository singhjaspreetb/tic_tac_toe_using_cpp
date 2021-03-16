#include <iostream>
#include <string>
#include <cstdlib>
#include "unistd.h"
using namespace std;
class game
{
private:
    char dip[10];
    int choice;
    string player[3];
    char mark;
    int play;
    int position;
public:
    static int status;
    static int ext;
private:
    int check();
public:
    void reup();
    void display();
    void usr_inp();
    void update();
    void result();
    void reset(char[]);
};
int game::ext = 1;
int game::status = -1;
void game::display()
{
    system("cls");
    cout << "Tic Tac Toe \n\n";
    cout << " " << dip[1] << " | " << dip[2] << " | " << dip[3] << endl;
    cout << "-----------" << endl;
    cout << " " << dip[4] << " | " << dip[5] << " | " << dip[6] << endl;
    cout << "-----------" << endl;
    cout << " " << dip[7] << " | " << dip[8] << " | " << dip[9] << endl;
    cout << "\n\nPlayer 1 (X)  -  Player 2 (O)\n\n";
}
void game::usr_inp()
{
    cout << "\n1: Human Vs Human\n2: Human Vs Computer\nChoice : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter the details...........\nPlayer 1 : ";
        cin >> player[1];
        cout << "Player 2 : ";
        cin >> player[2];
    }
    else
    {
        cout << "Enter Your Name : ";
        cin >> player[1];
        player[2] = "Computer";
    }
}
void game::update()
{
    display();
    play = (play % 2) ? 1 : 2;
    if (choice == 1)
    {
        cout << " \nPlayer " << player[play] << ", Enter a number:  ";
        cin >> position;
    }
    else
    {
        if (play == 1)
        {
            cout << " \nPlayer " << player[play] << ", Enter a number:  ";
            cin >> position;
        }
        else
        {
            for (int i = 1; i < 11; i++)
            {
                position = (rand() % 10) + 1;
            }
        }
    }
    mark = (play == 1) ? 'X' : 'O';
    if (position == 1 && dip[1] == '1')
        dip[1] = mark;
    else if (position == 2 && dip[2] == '2')
        dip[2] = mark;
    else if (position == 3 && dip[3] == '3')
        dip[3] = mark;
    else if (position == 4 && dip[4] == '4')
        dip[4] = mark;
    else if (position == 5 && dip[5] == '5')
        dip[5] = mark;
    else if (position == 6 && dip[6] == '6')
        dip[6] = mark;
    else if (position == 7 && dip[7] == '7')
        dip[7] = mark;
    else if (position == 8 && dip[8] == '8')
        dip[8] = mark;
    else if (position == 9 && dip[9] == '9')
        dip[9] = mark;
    else
    {
        cout << "\nInvalid move ";
        sleep(3);
        play--;
    }
    game::status = check();
    play++;
}
int game::check()
{
    if (dip[1] == dip[2] && dip[2] == dip[3])
        return 1;
    else if (dip[4] == dip[5] && dip[5] == dip[6])
        return 1;
    else if (dip[7] == dip[8] && dip[8] == dip[9])
        return 1;
    else if (dip[1] == dip[4] && dip[4] == dip[7])
        return 1;
    else if (dip[2] == dip[5] && dip[5] == dip[8])
        return 1;
    else if (dip[3] == dip[6] && dip[6] == dip[9])
        return 1;
    else if (dip[1] == dip[5] && dip[5] == dip[9])
        return 1;
    else if (dip[3] == dip[5] && dip[5] == dip[7])
        return 1;
    else if (dip[1] != '1' && dip[2] != '2' && dip[3] != '3' && dip[4] != '4' && dip[5] != '5' && dip[6] != '6' && dip[7] != '7' && dip[8] != '8' && dip[9] != '9')
        return 0;
    else
        return -1;
}
void game::result()
{
    if (game::status == 0)
    {
        cout << "\nGame Draw\n";
    }
    else
    {
        cout << endl
             << player[--play] << " Win \n";
    }
}
void game::reup()
{
    dip[0] = ' ';
    char ip = '1';
    for (int i = 1; i < 11; i++)
    {
        dip[i] = ip++;
    }
    play = 1;
    status = -1;
}
int main()
{
    while (game::ext != 2)
    {
        game box;
        system("cls");
        box.usr_inp();
        cout << "##Game Starts##";
        box.reup();
        box.display();
        while (game::status != 0 && game::status != 1)
        {
            box.update();
        }
        system("cls");
        box.result();
        cout << "Do You Want to Play again............\n1: Yes\t\t2: No\nEnter : ";
        cin >> game::ext;
    }
    system("cls");
    cout << "##Game Ended##";
    cout << "\n\nCome Again to Play \nHave a good day :)";
    return 0;
}