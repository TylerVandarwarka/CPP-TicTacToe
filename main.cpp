#include <iostream>

//Sets up the board
void botBoardSetup();
void pvpBoardSetup();

//The turn methods
void playerTurn();
void botTurn();
void player1Turn();
void player2Turn();

//initializing the rng values
int generateRandomValue(int, int);
void SeedRNGToSystemClock();

//the methods to check if someone wins
void PlayercheckWin();
void BotcheckWin();
void Player1checkWin();
void Player2checkWin();

// This is so that I don't have to use std:: before every cout and cin line
using namespace std;

//initializes the board as a 2d array
string board[3][3] = {{ "", "",""},{ "", "", ""},
                      { "", "", ""}};

//initializes the names for the 1v1 gamemode
string name1 = "";
string name2 = "";

//this is initialized to check whether or not it is ran once
bool firstTime = true;
bool secondTime = true;

//initializes the inputs used for the move
int input;
int input2;

//initilized to check whos turn it is
int turn = 1;

//checks if tie
int checkTie = 0;

//main method
int main() {
    //SeedRNGToSystemClock method
    SeedRNGToSystemClock();

    //printing the introduction as well as asking if you would like to play against a bot or another person
    cout << "Welcome to C++ TicTacToe!!!" << "\nStarting Off, would you like to play against a bot or another player?"
         << endl;
    cout << "1: Against A Bot" << "\n2: Against Another Player" << endl;
    //gets the input of your answer as a 1 or 2
    cin >> input;

    // This checks for validation to see if the option was valid using cin.clear and rewind(stdin)
    while(input != 1 && input != 2){
        cout << "Please Choose A Valid Option" << endl;
        cout << "1: Against A Bot" << "\n2: Against Another Player" << endl;
        cin.clear();
        rewind(stdin);
        cin >> input;
    }
    //this checks if the input is 1 and sends you to bot game if it is
    if (input == 1) {
        cout << "\nWelcome to the Bot Game!!!" << endl;
        botBoardSetup();
    //this checks if the input is 2 and sends you to the 1v1 gamemode
    } else if (input == 2) {

        cout << "\nWelcome to the Player VS Player Game!!!" << endl;
        cout << "\nPlease enter Player 1's Name!" << endl;
        cin >> name1;
        cout << "\n" << "Welcome: " <<name1 << endl;
        cout << "\nPlease enter Player 2's Name!" << endl;
        cin >> name2;
        cout << "\n" << "Welcome: " << name2 << "\n" << endl;
        pvpBoardSetup();
    }
}

void botBoardSetup() {
    //sets the board up for the start of the game
    board[0][0] = "1";
    board[0][1] = "2";
    board[0][2] = "3";
    board[1][0] = "4";
    board[1][1] = "5";
    board[1][2] = "6";
    board[2][0] = "7";
    board[2][1] = "8";
    board[2][2] = "9";

    cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
    cout << "----------" << endl;
    cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
    cout << "----------" << endl;
    cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;

    playerTurn();
}

void pvpBoardSetup(){
    //sets the board up for the start of the game
    board[0][0] = "1";
    board[0][1] = "2";
    board[0][2] = "3";
    board[1][0] = "4";
    board[1][1] = "5";
    board[1][2] = "6";
    board[2][0] = "7";
    board[2][1] = "8";
    board[2][2] = "9";

    cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
    cout << "----------" << endl;
    cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
    cout << "----------" << endl;
    cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;

    player1Turn();
}

void playerTurn() {
    //this is the players turn for the bot game
    PlayercheckWin();
    checkTie++;
    //this only runs the first time through
    if(firstTime){
        cin >> input;
        firstTime = false;
    }
    else{
        cin >> input;
    }
//    else if(!firstTime)
//    {
//        cout << "" << endl;
//        cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
//        cin >> input;
//
//    }
    if(turn == 1) {
        while (input < 1 || input > 9) {
            //this validates whether the input is 1 - 9
            cout << "Please enter in a valid space" << endl;
            cin.clear();
            rewind(stdin);
            cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
            cin >> input;
        }

        if(input == 1) {
            //checks the input if its 1
            while(board[0][0] == "X" || board[0][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[0][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            botTurn();
        }
        else if(input == 2) {//checks the input if its 2
            while(board[0][1] == "X" || board[0][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[0][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 3) {
            //checks the input if its 3
            while(board[0][2] == "X" || board[0][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[0][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 4) {
            //checks the input if its 4
            while(board[1][0] == "X" || board[1][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[1][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 5) {
            //checks the input if its 5
            while(board[1][1] == "X" || board[1][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[1][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 6) {
            //checks the input if its 6
            while(board[1][2] == "X" || board[1][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[1][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 7) {
            //checks the input if its 7
            while(board[2][0] == "X" || board[2][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[2][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 8) {
            //checks the input if its 8
            while(board[2][1] == "X" || board[2][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[2][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
        else if(input == 9) {
            //checks the input if its 9
            while(board[2][2] == "X" || board[2][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                playerTurn();
            }
            board[2][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            botTurn();
        }
    }
}
//botTurn method
void botTurn() {
    PlayercheckWin();
    BotcheckWin();
    if(turn == 2){
        cout << "\nBot's Turn!!!" << endl;
        input = generateRandomValue(1,9);
        //cout << input;

        if(input == 1) {
            while ((board[0][0] == "X" && input == 1) || (board[0][0] == "O" && input == 1)) {
                input = 0;
                input = generateRandomValue(1,9);
                botTurn();

            }
            board[0][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 2) {
            while ((board[0][1] == "X" && input == 2) || (board[0][1] == "O" && input == 2)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[0][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 3) {
            while ((board[0][2] == "X" && input == 3) || (board[0][2] == "O" && input == 3)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[0][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 4) {
            while ((board[1][0] == "X" && input == 4) || (board[1][0] == "O" && input == 4)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[1][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 5) {
            while ((board[1][1] == "X" && input == 5) || (board[1][1] == "O" && input == 5)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[1][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 6) {
            while ((board[1][2] == "X" && input == 6) || (board[1][2] == "O" && input == 6)) {
                input = generateRandomValue(1, 9);
                botTurn();
            }
            board[1][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 7) {
            while ((board[2][0] == "X" && input == 7) || (board[2][0] == "O" && input == 7)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[2][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 8) {
            while ((board[2][1] == "X" && input == 8) || (board[2][1] == "O" && input == 8)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[2][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
        //input = generateRandomValue(1,9);
        if(input == 9) {
            while ((board[2][2] == "X" && input == 9) || (board[2][2] == "O" && input == 9)) {
                input = generateRandomValue(1,9);
                botTurn();
            }
            board[2][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            BotcheckWin();
            playerTurn();
        }
    }
}
//player1Turn method
void player1Turn(){
    checkTie++;
    Player1checkWin();
    Player2checkWin();
    if(firstTime){
        cin >> input;
        firstTime = false;
    }
    else{
        cin >> input;
    }
//    else if(!firstTime)
//    {
//        cout << "" << endl;
//        cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
//        cin >> input;
//
//    }
    if(turn == 1) {
        while (input < 1 || input > 9) {
            cout << "Please enter in a valid space" << endl;
            cin.clear();
            rewind(stdin);
            cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
            cin >> input;
        }

        if(input == 1) {
            while(board[0][0] == "X" || board[0][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[0][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            player2Turn();
        }
        else if(input == 2) {
            while(board[0][1] == "X" || board[0][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[0][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 3) {
            while(board[0][2] == "X" || board[0][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[0][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 4) {
            while(board[1][0] == "X" || board[1][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[1][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 5) {
            while(board[1][1] == "X" || board[1][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[1][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 6) {
            while(board[1][2] == "X" || board[1][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[1][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 7) {
            while(board[2][0] == "X" || board[2][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[2][0] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 8) {
            while(board[2][1] == "X" || board[2][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[2][1] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
        else if(input == 9) {
            while(board[2][2] == "X" || board[2][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player1Turn();
            }
            board[2][2] = "X";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 2;
            input = 0;
            player2Turn();
        }
    }
}
//player2Turn
void player2Turn(){
    Player1checkWin();
    Player2checkWin();
    if(secondTime){
        cin >> input2;
        firstTime = false;
    }
    else{
        cin >> input;
    }
//    else if(!firstTime)
//    {
//        cout << "" << endl;
//        cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
//        cin >> input2;
//
//    }
    if(turn == 2) {
        cin.clear();
        while (input2 < 1 || input2 > 9) {
            cout << "Please enter in a valid space" << endl;
            cin.clear();
            rewind(stdin);
            cout << "\nYour Turn!!!" << "\nPick a open square!!!" << endl;
            cin >> input2;
        }
        if(input2 == 1) {
            while(board[0][0] == "X" || board[0][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[0][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            input2 = 0;
            player1Turn();
        }
        else if(input2 == 2) {
            while(board[0][1] == "X" || board[0][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[0][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            input2 = 0;
            player1Turn();
        }
        else if(input2 == 3) {
            while(board[0][2] == "X" || board[0][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[0][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            checkTie++;
            input2 = 0;
            player1Turn();
        }
        else if(input2 == 4) {
            while(board[1][0] == "X" || board[1][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[1][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
        else if(input2 == 5) {
            while(board[1][1] == "X" || board[1][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[1][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
        else if(input2 == 6) {
            while(board[1][2] == "X" || board[1][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[1][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
        else if(input2 == 7) {
            while(board[2][0] == "X" || board[2][0] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[2][0] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
        else if(input2 == 8) {
            while(board[2][1] == "X" || board[2][1] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[2][1] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
        else if(input2 == 9) {
            while(board[2][2] == "X" || board[2][2] == "O") {
                cout << "This space is taken" << endl;
                cin.clear();
                rewind(stdin);
                player2Turn();
            }
            board[2][2] = "O";
            cout << "" << board[0][0] << "" << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[1][0] << "" << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
            cout << "----------" << endl;
            cout << "" << board[2][0] << "" << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;
            turn = 1;
            input2 = 0;
            checkTie++;
            player1Turn();
        }
    }
}
// This sets a random value to any uninitialized variables and is how we get random numbers
void SeedRNGToSystemClock()
{
    srand((unsigned int)time(NULL));
}
// this goes in part with the random setRNGSeed to make random values
int generateRandomValue(int lowerBound, int upperBound)
{
    int range = (upperBound - lowerBound) + 1;
    return rand() % range + lowerBound;
}
//PlayercheckWin
void PlayercheckWin(){
    if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "X" && board[2][1] == "X" && board[2][2] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X"){
        cout << "Player Wins" << endl;
        exit(0);
    }
    else if(checkTie == 9){
        cout << "Tie" << endl;
        exit(0);
    }
}
//BotcheckWin method
void BotcheckWin(){
    if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "O" && board[2][1] == "O" && board[2][2] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O"){
        cout << "Bot Wins" << endl;
        exit(0);
    }
    else if(checkTie == 9){
        cout << "Tie" << endl;
        exit(0);
    }
}
//Player1checkWin
void Player1checkWin(){
    if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "X" && board[2][1] == "X" && board[2][2] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X"){
        cout << name1 << " Wins" << endl;
        exit(0);
    }
    else if(checkTie == 9){
        cout << "Tie" << endl;
        exit(0);
    }
}
//Player2checkWin
void Player2checkWin(){
    if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "O" && board[2][1] == "O" && board[2][2] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O"){
        cout << name2 << " Wins" << endl;
        exit(0);
    }
    else if(checkTie == 9){
        cout << "Tie" << endl;
        exit(0);
    }
}//end file




























































































































































































































































































































//I will turn into a convertable
//yeah yeah
//-Dababy