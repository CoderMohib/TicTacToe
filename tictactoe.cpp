#include <iostream>
#include <conio.h>

using namespace std;

char selectChoice[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char mark;
char tempMark;
char tempMark2;
int gameover;
void update_select_choice()
{
    char ch='0';
    for (int i = 0; i <= 9; i++)
    {
        selectChoice[i]= ch;
        ch++;
    }
    
}
void drawboard()
{
    system("cls");
    cout << "Player 1 (" << tempMark << ")      Player 2 (" << tempMark2 << ")\n";
    cout << endl
         << endl;
    cout << " ____________________" << endl;
    cout << "|      |      |      | " << endl;
    cout << "|  " << selectChoice[1] << "   |  " << selectChoice[4] << "   |  " << selectChoice[7] << "   |" << endl;
    cout << "|______|______|______|" << endl;
    cout << "|      |      |      |" << endl;
    cout << "|  " << selectChoice[2] << "   |  " << selectChoice[5] << "   |  " << selectChoice[8] << "   |" << endl;
    cout << "|______|______|______|" << endl;
    cout << "|      |      |      |" << endl;
    cout << "|  " << selectChoice[3] << "   |  " << selectChoice[6] << "   |  " << selectChoice[9] << "   |" << endl;
    cout << "|______|______|______|" << endl;
}

int check_game()
{
    if (selectChoice[1] == selectChoice[2] && selectChoice[2] == selectChoice[3])
    {
        return 1;
    }
    else if (selectChoice[4] == selectChoice[5] && selectChoice[5] == selectChoice[6])
    {
        return 1;
    }
    else if (selectChoice[7] == selectChoice[8] && selectChoice[8] == selectChoice[9])
    {
        return 1;
    }
    else if (selectChoice[1] == selectChoice[4] && selectChoice[4] == selectChoice[7])
    {
        return 1;
    }
    else if (selectChoice[2] == selectChoice[5] && selectChoice[5] == selectChoice[8])
    {
        return 1;
    }
    else if (selectChoice[3] == selectChoice[6] && selectChoice[6] == selectChoice[9])
    {
        return 1;
    }
    else if (selectChoice[1] == selectChoice[5] && selectChoice[5] == selectChoice[9])
    {
        return 1;
    }
    else if (selectChoice[7] == selectChoice[5] && selectChoice[5] == selectChoice[3])
    {
        return 1;
    }
    else if (selectChoice[1] != '1' && selectChoice[2] != '2' && selectChoice[3] != '3' &&
             selectChoice[4] != '4' && selectChoice[5] != '5' && selectChoice[6] != '6' &&
             selectChoice[7] != '7' && selectChoice[8] != '8' && selectChoice[9] != '9')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


int computer_move()
{
    int Spots[9];
    int numSpots = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (selectChoice[i] != 'X' && selectChoice[i] != 'O')
        {
            Spots[numSpots] = i;
            numSpots++;
        }
    }
    int randomIndex = rand() % numSpots;
    return Spots[randomIndex];
}

void game_start(bool vsComputer)
{
    char temp;
    do
    {
        
        cout << "*****************************************\n";
        cout << "Enter 1st Player Mark choice: \n";
        cout << "*****************************************\n";
        cout << "1-  X- Mark\n";
        cout << "2-  O- Mark\n";
        cout << "*****************************************\n";
        temp = getche();
        switch (temp)
        {
        case '1':
            system ("cls");
            tempMark = 'X';
            tempMark2 = 'O';
            break;
        case '2':
            system("cls");
            tempMark = 'O';
            tempMark2 = 'X';
            break;
        default:
            system("cls");
            cout << "Invalid input!\n";
            break;
        }
    } while (temp != '1' && temp != '2');

    int player = 1;
    do
    {
        drawboard();
        char choice;

        if (player % 2 == 1)
        {
            player = 1;
            mark = tempMark;
        }
        else
        {
            player = 2;
            mark = tempMark2;
        }

        if (vsComputer && player == 2)
        {
            int move = computer_move();
            selectChoice[move] = mark;
        }
        else
        {
            cout << "\nPlayer" << player << ", Enter your choice: ";
            cin >> choice;
            if (choice == selectChoice[1])
            {
                selectChoice[1] = mark;
            }
            else if (choice == selectChoice[2])
            {
                selectChoice[2] = mark;
            }
            else if (choice == selectChoice[3])
            {
                selectChoice[3] = mark;
            }
            else if (choice == selectChoice[4])
            {
                selectChoice[4] = mark;
            }
            else if (choice == selectChoice[5])
            {
                selectChoice[5] = mark;
            }
            else if (choice == selectChoice[6])
            {
                selectChoice[6] = mark;
            }
            else if (choice == selectChoice[7])
            {
                selectChoice[7] = mark;
            }
            else if (choice == selectChoice[8])
            {
                selectChoice[8] = mark;
            }
            else if (choice == selectChoice[9])
            {
                selectChoice[9] = mark;
            }
            else
            {
                cout << "Invalid Input.";
                player--;
                cin.clear();
                cin.ignore();
            }
        }

        gameover = check_game();
        player++;
    } while (gameover == 0);

    drawboard();
    if (gameover == 1)
    {
        cout << "Player " << --player << " Win!\n";
        update_select_choice();
    }
    if (gameover == 2)
    {
        cout << "It's a Tie!\n";
        update_select_choice();
    }
}

void instruction()
{

    cout << "*****************************************\n";
    cout << "\t     Instructions\n";
    cout << "*****************************************\n";
    cout << "1. Players take turns putting their marks in empty squares.\n"
            "2. The first player to get 3 of their marks in a row\n"
            "   (up, down, across, or diagonally) is the winner.\n"
            "3. When all 9 squares are full, the game is over.\n"
            "4. If no player has 3 marks in a row, the game ends in a tie.\n";
    cout << "*****************************************\n";
    cout << "Press Any key to go back!\n";
    cout << "*****************************************\n";
    getche();
}


//Main body
int main()
{

    char choice;
    bool vsComputer = false;
    char vsCompChoice;
    do
    {
        
        cout << "*****************************************\n";
        cout << "\t\tTIC-TAC-TOE GAME\n";
        cout << "*****************************************\n";
        cout << "1- START GAME\n";
        cout << "2- INSTRUCTIONS\n";
        cout << "3- Exit\n";
        cout << "*****************************************\n";
        choice = getche();
        switch (choice)
        {
        case '1':
            system("cls");
            do
            {
                
                cout << "*****************************************\n";
                cout << "1.Play against the computer. \n";
                cout << "2.Multiplayer.\n";
                cout << "*****************************************\n";
                cout << "Enter 1 to Play or Enter 2 to play with eachother!\n";
                cin >> vsCompChoice;
                system("cls");
            } while (vsCompChoice != '1' && vsCompChoice != '2');
            
            
            if (vsCompChoice == '1' )
                vsComputer = true;
            else
                vsComputer = false;
            game_start(vsComputer);
            break;
        case '2':
            system("cls");
            instruction();
            break;
        case '3':
            system("cls");
            cout << "*****************************************\n";
            cout << "\t\tThanks\n";
            cout << "*****************************************\n";
            break;
        default:
            system("cls");
            cout << "Invalid Input!.";
            break;
        }
    } while (choice != '3');

    return 0;
}
