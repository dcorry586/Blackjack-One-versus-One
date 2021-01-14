// blackj2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// global vars
int card;
char choice; // s for stand // h for hit
std::string PlayerOneStand = "stand";
std::string PlayerTwoStand = "stand";
int PlayerOneCard;
int PlayerTwoCard;
std::string PlayerOneDecision = ""; // player 1 decision
std::string PlayerTwoDecision = ""; // player 2 decision
int ace = 1;
int J, Q, K = 10;

std::vector<int> Deck = { ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K,\
                        ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K ,\
                        ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, \
                        ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K}; // currently : unshuffled ; just phase 1, will make shuffling func and shuffledVector!

std::vector<int> PlayerOneHand;
std::vector<int> PlayerTwoHand;

void Init() { // give all players 2 cards each
    // give player one 2 cards 
    int CardOneForPlayerOne = Deck.back();
    PlayerOneHand.push_back(CardOneForPlayerOne);

    int CardTwoForPlayerOne = Deck.back();
    PlayerOneHand.push_back(CardTwoForPlayerOne);

    int CardOneForPlayerTwo = Deck.back();
    PlayerTwoHand.push_back(CardOneForPlayerTwo);

    int CardTwoForPlayerTwo = Deck.back();
    PlayerTwoHand.push_back(CardTwoForPlayerTwo);
}

void PullCardFromDeck() {
    // card  = last card of deck && popback vector too.
    // point to last element in vector and get index
    // make that element literal == card
    auto LastIdx = Deck.back();// find last element of Deck vector
    card = LastIdx;
}

void GiveCardToPlayer1(int card) {
    PlayerOneCard = card;
    // push_back card to PlayerOneHand
    PlayerOneHand.push_back(card);
}

void GiveCardToPlayer2(int card){
    PlayerTwoCard = card;
    // push_back card to PlayerTwoHand
    PlayerTwoHand.push_back(card);
}

void ViewPlayerOneHand(std::vector<int> PlayerOneHand) {
    for (int i = 0; i < PlayerOneHand.size(); i++) {
        std::cout << "Player One : "<< PlayerOneHand[i] << '\n';
    }
}

void ViewPlayerTwoHand(std::vector<int> PlayerTwoHand) {
    for (int i = 0; i < PlayerOneHand.size(); i++) {
        std::cout << "Player Two : " << PlayerTwoHand[i] << '\n';
    }
}


int main()
{
    // give both players 2 cards each
    Init();
    // view player one hand
    ViewPlayerOneHand(PlayerOneHand);

    // view player two hand
    ViewPlayerTwoHand(PlayerTwoHand);

    // Player 1
    while (PlayerOneDecision != PlayerOneStand) {
        cout << "init()...give all players 2 starting cards each." << '\n';

        cout << "Stand or hit?" << '\n';
        cin >> choice;
        cout << "You chose : " << choice << '\n';


        if (choice == 's')
        {
            cout << 0 << '\n'; // represents no card given and dealer will now ask next player in line
            PlayerOneDecision = PlayerOneStand;
            // allow player to view hand - print it !
            ViewPlayerOneHand(PlayerOneHand);
        }
        else {
            // pull card from deck
            PullCardFromDeck();
            // given card to player 2
            GiveCardToPlayer2(card);
        }
    }
   
    cout << "Now Player 2 turn..." << '\n';

    // Player 2
    while (PlayerTwoDecision != PlayerTwoStand) {
        cout << "init()...give all players 2 starting cards each." << '\n';

        cout << "Stand or hit?" << '\n';
        cin >> choice;
        cout << "You chose : " << choice << '\n';


        if (choice == 's')
        {
            cout << 0 << '\n'; // represents no card given and dealer will now ask next player in line
            PlayerTwoDecision = PlayerTwoStand;
            // allow player to view hand - print it !
            ViewPlayerTwoHand(PlayerTwoHand);
        }
        else {
            // pull card from deck
            PullCardFromDeck();
            // given card to player 2
            GiveCardToPlayer1(card);
        }
    }

    cout << "Game finished" << '\n';

    // total up score and see who won


    return 0;
}

// NEXT : PLAYER VIEW HAND!!!!!!!
// NEXT : DEALER TOTAL UP HANDS AND EVALUATE WINNER 
// PLAYER NEEDS TO CONSTANTLY VIEW HAND - NOT JUST ON STAND!