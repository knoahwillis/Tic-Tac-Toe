#include <iostream>
#include <stdlib.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
bool checkValidMove = true;
bool checkWon = false;

void printBoard(){
    std::cout << "\t\t    Tic-Tac-Toe\n\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  "<<board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    std::cout << "\t\t_____|_____|_____\n";
    std::cout << "\t\t     |     |     \n";
    std::cout << "\t\t  "<<board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    std::cout << "\t\t     |     |     \n\n";
    std::cout << "PLAYER 1 IS X's \t\t  PLAYER 2 IS O's\n";

}



 void player1Move(char boardPos){
    int checker = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j] == boardPos){
                board[i][j] = 'X';
                checkValidMove = true;
                checker = 1;
            }
            
        }
    }
    if(checker == 0){checkValidMove = false;}
}

void player2Move(char boardPos){
    int checker = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j] == boardPos){
                board[i][j] = 'O';
                checkValidMove = true;
                checker = 1;
            }
            
        }
    }
    if(checker == 0) {checkValidMove = false;}
}

void checkIfGameWon(char gameBoard[3][3]){
    if(((gameBoard[0][0] == gameBoard[0][1]) && gameBoard[0][1] == gameBoard[0][2])
    ||((gameBoard[1][0] == gameBoard[1][1]) && gameBoard[1][1] == gameBoard[1][2])
    ||((gameBoard[2][0] == gameBoard[2][1]) && gameBoard[2][1] == gameBoard[2][2])
    ||((gameBoard[0][0] == gameBoard[1][1]) && gameBoard[1][1] == gameBoard[2][2])
    ||((gameBoard[0][2] == gameBoard[1][1]) && gameBoard[1][1] == gameBoard[2][0])
    ||((gameBoard[0][0] == gameBoard[1][0]) && gameBoard[1][0] == gameBoard[2][0])
    ||((gameBoard[0][1] == gameBoard[1][1]) && gameBoard[1][1] == gameBoard[2][1])
    ||((gameBoard[0][2] == gameBoard[1][2]) && gameBoard[1][2] == gameBoard[2][2])){
        checkWon = true;
    }
}

int main(){
    int turnCount = 0;
    char playPos;
    int winner = 1;
    while(!checkWon && turnCount < 9){
        if(turnCount % 2 == 0){
            printBoard();
            std::cout << "Player 1's Turn. Please choose a spot on the board to play (1 - 9):\n";
            std::cin >> playPos;
            player1Move(playPos);
            while(checkValidMove == false){
                std::cout << "Invalid move! Pick again:\n";
                std::cin >> playPos;
                player1Move(playPos);
                }
            checkIfGameWon(board);
            ++turnCount;
        }
        else{
            printBoard();
            std::cout << "Player 2's Turn. Please choose a spot on the board to play (1 - 9):\n";
            std::cin >> playPos;
            player2Move(playPos);
            while(checkValidMove == false){
                std::cout << "Invalid move! Pick again:\n";
                std::cin >> playPos;
                player2Move(playPos);
                }
            checkIfGameWon(board);
            ++turnCount;
        }
    }
    printBoard();
    if(turnCount == 9){
        std::cout << "\t\t    Game Over!\n\t\t    Tie Game!";
    }
    else if(turnCount % 2 == 0) {
        winner = 2;
        std::cout << "\t\t    Game Over!\n\t\t  Player " << winner << " wins!";
    }else{
        std::cout << "\t\t    Game Over!\n\t\t  Player " << winner << " wins!";
    }

}