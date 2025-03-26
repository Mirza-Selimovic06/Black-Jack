/* 
Project: blackjack.cpp 
Purpose: Make a blackjack game using c++ 
Author: Mirza Selimovic  
Date: 11/3/24 
*/ 
#include <iostream> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 

int main() 
{ 
    char game_start; 
    char startGame; 
    cout << "***********************************\n"; 
    cout << "*Welcome to Mirza's blackjack game*"; 
    cout << "\n***********************************\n"; 
    cout << "***********************\n"; 
    cout << "*To start game enter Y*"; 
    cout << "\n***********************\n"; 
    cin >> startGame; 

    while (startGame == 'y' || startGame == 'Y') 
    { 
        int playerPoints = 0; 
        int housePoints = 0; 
        srand(time(0)); 

        //randomly number generates the players cards from 1-10 
        int playerCard1 = 1 + rand() % 10; 
        int playerCard2 = 1 + rand() % 10;  

        //randomly number generates the housecards from 2-11 
        int houseCard1 = 2 + rand() % 10; 
        int houseCard2 = 2 + rand() % 10; 

        //calculates the houses points and the players points 
        housePoints = houseCard1 + houseCard2; 
        playerPoints = playerCard1 + playerCard2; 

        //shows player his hand and the total points he has 
        cout << "Your hand is, " << playerCard1 << " " << playerCard2 << endl; 
        cout << "And your total is " << playerPoints << endl; 
        cout << "The houses total is " << housePoints << endl; 

        if(playerCard1 == 1) 
        { 
            cout << "You got an ace would you like to have it be equal to 1 or 11?\n"; 
            cin >> playerCard1; 
        } 

        if (playerCard2 == 1) 
        { 
            cout << "You got an ace would you like to have it be equal to 1 or 11?\n"; 
            cin >> playerCard2; 
        } 

        while (playerPoints < 21) 
        { 
            char hit; 
            cout << "Do you want to hit(h) or stand(s)\n"; 
            cin >> hit; 

            if (hit =='h' || hit == 'H') 
            {  
                //gives a new card when a player wants to hit 
                int newCard = 1 + rand() % 10; 

                if (newCard == 1) 
                { 
                    cout << "You got an ace would you like its value to be 1 or 11\n"; 
                    cin >> newCard; 
                } 
                playerPoints += newCard; 
                cout << "You total right now is " << playerPoints << endl; 

                if (playerPoints > 21) 
                { 
                    cout << "Your total was " << playerPoints << endl; 
                    cout << "Thats a bust!\n"; 
                    cout << "You lose :(\n";    
                    cout << "Would you like to play again! If yes enter y or Y, if no enter any character than y or Y\n"; 
                    cin >> startGame; 
                } 
                else if ((housePoints > 21 && playerPoints <= 21)) 
                { 
                    cout << "The houses total was " << housePoints << endl; 
                    cout << "You win! House busts\n";
                    cout << "Would you like to play again. If yes enter y or Y, if no enter any other character than y or Y\n"; 
                    cin >> startGame; 
                } 
                else if (playerPoints > housePoints) 
                { 
                    cout << "You win!\n"; 
                    cout << "Would you like to play again! If yes enter y or Y, if no enter any other character than y or Y\n"; 
                    cin >> startGame; 
                } 
            //if they would like to stand
            } 
            else if (hit == 's' || hit == 'S') 
            { 
                cout << "Your points were " << playerPoints << endl; 
                cout << "The houses points were " << housePoints << endl; 
            
                if (housePoints > playerPoints) 
                { 
                    cout << "You lose!\n"; 
                    cout << "Would you like to play again! If yes enter y or Y, if no enter any character than y or Y\n"; 
                    cin >> startGame; 
                } 
                else if ((playerPoints == 21 && housePoints != 21) || (playerPoints > housePoints)) 
                { 
                    cout << "You win!\n"; 
                    cout << "Would you like to play again! If yes enter y or Y, if no enter any character than y or Y\n"; 
                    cin >> startGame; 
                
                    if(startGame != 'y' || startGame != 'Y') 
                    { 
                        break; 
                    } 
                } 
            } 
        }  
    } 
} 