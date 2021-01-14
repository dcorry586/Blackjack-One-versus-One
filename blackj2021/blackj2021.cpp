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

void PullCardFromDeck() {
    // card  = last card of deck && popback vector too.
    // point to last element in vector and get index
    // make that element literal == card
    auto LastIdx = Deck.back();// find last element of Deck vector
    card = LastIdx;
}

void GiveCardToPlayer1(int card) {
    PlayerOneCard = card;
}

void GiveCardToPlayer2(int card){
    PlayerTwoCard = card;
}

int main()
{

    while (PlayerOneDecision != PlayerOneStand) {
        cout << "init()...give all players 2 starting cards each." << '\n';

        cout << "Stand or hit?" << '\n';
        cin >> choice;
        cout << "You chose : " << choice << '\n';


        if (choice == 's')
        {
            cout << 0 << '\n'; // represents no card given and dealer will now ask next player in line
            PlayerOneDecision = PlayerOneStand;
        }
        else {
            // pull card from deck
            PullCardFromDeck();
            // given card to player 2
            GiveCardToPlayer2(card);
        }
    }
   
    cout << "Now Player 2 turn..." << '\n';


    while (PlayerTwoDecision != PlayerTwoStand) {
        cout << "init()...give all players 2 starting cards each." << '\n';

        cout << "Stand or hit?" << '\n';
        cin >> choice;
        cout << "You chose : " << choice << '\n';


        if (choice == 's')
        {
            cout << 0 << '\n'; // represents no card given and dealer will now ask next player in line
            PlayerTwoDecision = PlayerTwoStand;
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

// But first : Create repo on GHub for this, commit to master branch and push this!!
// NEXT : PLAYER VIEW HAND!!!!!!!