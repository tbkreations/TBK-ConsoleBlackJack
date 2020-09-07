// BlackJack Card Game Program
// By: Arthur L. Brown III
// Developed on MacOS using VSCode

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Card {
    int cVal;
    string cSuit;
    string cFaceVal;
};

//constant vars
const int DECK_SIZE = 52;
const int NUM_SUITS = 4;
const int FACECARD_VAL = 10;

//function protos
void initDeck(vector<Card>&, int, int);
void shuffleDeck(vector<Card>&, int);
void dealCard(vector<Card>&, vector<Card>&, int);
int getHandTotal(vector<Card>);
void printHand(vector<Card>);
//Deck, Player Hand, Computer Hand, Deck-Size
void startGame(vector<Card>&, vector<Card>&, vector<Card>&, int);
int runMainGame(vector<Card>&, vector<Card>&, vector<Card>&, int);
void runComputerAlg(vector<Card>&, vector<Card>&, vector<Card>&, int);
//deck, decksize, user-hand, dealer-hand
bool isLiveGame(vector<Card>, int, vector<Card>, vector<Card>);

int main() {
    cout << endl;

    //declares gamedeck vector of cards
    vector<Card> gameDeck;
    //vectors to hold player and computer cards
    vector<Card> playerDeck;
    vector<Card> computerDeck;
    //seed for rand func
    srand(time(NULL));

    //creates the card deck
    initDeck(gameDeck, DECK_SIZE, NUM_SUITS);
    shuffleDeck(gameDeck, DECK_SIZE);
    startGame(gameDeck, playerDeck, computerDeck, DECK_SIZE);
    //initialize player choice for if they want another card
    int pChoice = 1;

    //loop to let the user draw cards until they hold
    while (pChoice == 1) {
        pChoice = runMainGame(gameDeck, playerDeck, computerDeck, DECK_SIZE);
    }

    if (isLiveGame(gameDeck, DECK_SIZE, playerDeck, computerDeck)) {
        while (isLiveGame(gameDeck, DECK_SIZE, playerDeck, computerDeck)) {
            runComputerAlg(gameDeck, playerDeck, computerDeck, DECK_SIZE);
        }    
    } else {
        cout << endl;
        return 0;
    }
    cout << endl;
}

void initDeck(vector<Card> &deck, int deckSize, int numSuits) {
    //card count var
    int cardNum = 0;

    //outer loop to determine card suit, inner loop to determine card value
    //this generates all number value cards and adds them to the deck
    for (int suit = 1; suit <= numSuits; suit++) {
        for (int val = 1; val <= 13; val++) {
            if (suit == 1) {
                //generates face cards
                if (val == 1) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Hearts";
                    deck[cardNum].cVal = val;
                    deck[cardNum].cFaceVal = "Ace";
                    cardNum++;
                } else if (val == 11) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Hearts";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Jack";
                    cardNum++;
                } else if (val == 12) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Hearts";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Queen";
                    cardNum++;
                } else if (val == 13) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Hearts";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "King";
                    cardNum++;
                } else {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Hearts";
                    deck[cardNum].cVal = val;
                    cardNum++;
                }
            } else if (suit == 2) {
                //generates face cards
                if (val == 1) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Spades";
                    deck[cardNum].cVal = val;
                    deck[cardNum].cFaceVal = "Ace";
                    cardNum++;
                } else if (val == 11) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Spades";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Jack";
                    cardNum++;
                } else if (val == 12) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Spades";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Queen";
                    cardNum++;
                } else if (val == 13) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Spades";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "King";
                    cardNum++;
                } else {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Spades";
                    deck[cardNum].cVal = val;
                    cardNum++;
                }
            } else if (suit == 3) {
                //generates face cards
                if (val == 1) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Clubs";
                    deck[cardNum].cVal = val;
                    deck[cardNum].cFaceVal = "Ace";
                    cardNum++;
                } else if (val == 11) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Clubs";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Jack";
                    cardNum++;
                } else if (val == 12) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Clubs";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Queen";
                    cardNum++;
                } else if (val == 13) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Clubs";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "King";
                    cardNum++;
                } else {
                   deck.push_back(Card());
                   deck[cardNum].cSuit = "Clubs";
                   deck[cardNum].cVal = val;
                   cardNum++;
                }
            } else if (suit == 4) {
                 //generates face cards
                if (val == 1) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Diamonds";
                    deck[cardNum].cVal = val;
                    deck[cardNum].cFaceVal = "Ace";
                    cardNum++;
                } else if (val == 11) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Diamonds";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Jack";
                    cardNum++;
                } else if (val == 12) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Diamonds";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "Queen";
                    cardNum++;
                } else if (val == 13) {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Diamonds";
                    deck[cardNum].cVal = FACECARD_VAL;
                    deck[cardNum].cFaceVal = "King";
                    cardNum++;
                } else {
                    deck.push_back(Card());
                    deck[cardNum].cSuit = "Diamonds";
                    deck[cardNum].cVal = val;
                    cardNum++;
                }
            }
        }
    }


    // displays card deck unshuffled
    // for (int card = 0; card <= 51; card+=51) {
    //     if (deck[card].cVal == 1 || (deck[card].cVal == 10 && deck[card].cFaceVal != "")) {
    //         cout << deck[card].cFaceVal << " " << deck[card].cSuit << endl;
    //     } else {
    //         cout << deck[card].cVal << " " << deck[card].cSuit << endl;
    //     }
    // }

    // cout << cardNum << " Cards Created. Init Deck Function" << endl;
}

void shuffleDeck(vector<Card> &deck, int deckSize) {
    int randomPos = 0;
    Card tempCard;

    for (int card = 0; card < deck.size(); card++) {
        randomPos = card + (rand() % (52 - card));

        tempCard = deck[randomPos];
        deck[randomPos] = deck[card];
        deck[card] = tempCard;
    }

    // displays Top and Bottom Card (shuffled)
    // for (int cNum = 0; cNum < deck.size(); cNum+= 51) {
    //     if (cNum == 0) {
    //         if (deck[cNum].cVal == 1 || (deck[cNum].cVal == 10 && deck[cNum].cFaceVal != "")) {
    //             cout << deck[cNum].cFaceVal << " " << deck[cNum].cSuit << ", ";
    //         } else {
    //             cout << deck[cNum].cVal << " " << deck[cNum].cSuit << ", ";
    //         }
    //     } else {
    //         if (deck[cNum].cVal == 1 || (deck[cNum].cVal == 10 && deck[cNum].cFaceVal != "")) {
    //             cout << deck[cNum].cFaceVal << " " << deck[cNum].cSuit << ". Shuffle Deck Function" << endl;
    //         } else {
    //             cout << deck[cNum].cVal << " " << deck[cNum].cSuit << ". Shuffle Deck Function" << endl;
    //         }
    //     }
    // }
}

void dealCard(vector<Card> &deck, vector<Card> &playerHand, int deckSize) {
    Card tempDrawn;
    tempDrawn = deck[0];
    playerHand.push_back(tempDrawn);
    deck.push_back(tempDrawn);
    deck.erase(deck.begin());
    // cout << "Cards Dealt. Deal Cards Function" << endl;
}

void printHand(vector<Card> playerHand) {
    int handSize = playerHand.size();

    for (int card = 0; card < handSize; card++) {
        //prompt for second card
        if (card >= 1) {
            cout << ", ";
        }
        //determines if card is an ace or facecard to format output
        if (playerHand[card].cVal == 1 || (playerHand[card].cVal == 10 && playerHand[card].cFaceVal != "")) {
            cout << playerHand[card].cFaceVal << " " << playerHand[card].cSuit;
        } else {
            cout << playerHand[card].cVal << " " << playerHand[card].cSuit;
        }
    }
    cout << endl;
}

int getHandTotal(vector<Card> playerHand) {
    int handSize = playerHand.size();
    int handTotal = 0;

    for (int card = 0; card < handSize; card++) {
        handTotal += playerHand[card].cVal;
    }
    return handTotal;
}

void startGame(vector<Card> &deck, vector<Card> &userHand, vector<Card> &computerHand, int deckSize) {
    
    //Initial Card Deal, two per player with prompts in between each card deal
    cout << "The Dealer has a ";
    dealCard(deck, computerHand, deckSize);
    dealCard(deck, computerHand, deckSize);
    printHand(computerHand);
    cout << "Dealer Card Total: " << getHandTotal(computerHand) << endl;

    cout << "\nYou have a ";
    dealCard(deck, userHand, deckSize);
    dealCard(deck, userHand, deckSize);
    printHand(userHand);
    cout << "Player Card Total: " << getHandTotal(userHand) << endl;
}

void runComputerAlg(vector<Card> &deck, vector<Card> &userHand, vector<Card> &computerHand, int deckSize) {
    int dealerTotal = getHandTotal(computerHand);
    cout << "Now the Dealer Plays. Press enter to continue.";
    cin.ignore();
    
    while (dealerTotal <= 17) {
        cin.ignore();
        dealCard(deck, computerHand, deckSize);
        dealerTotal = getHandTotal(computerHand);
        cout << endl;
        cout << "The Dealer has a "; 
        printHand(computerHand);
        cout << "The Dealer's Total is: " << dealerTotal << endl;
    }
}

int runMainGame(vector<Card> &deck, vector<Card> &userHand, vector<Card> &computerHand, int deckSize) {
    int pTotal = 0;
    int userInput;
    //asks user if they want a hit, computes and displays new cards and total
    cout << "\nPress '1 for Another Card and '0' to hold. ";
    cin >> userInput;
    cout << endl;

    if (userInput == 1) {
        dealCard(deck, userHand, deckSize);
        pTotal = getHandTotal(userHand);
        cout << "You Have a ";
        printHand(userHand);
        cout << "Your Total is: " << pTotal << endl;
    } else {
        pTotal = getHandTotal(userHand);
        cout << "Your Total is: " << pTotal << endl;
    }

    return userInput;
}

bool isLiveGame(vector<Card> deck, int deckSize, vector<Card> playerHand, vector<Card> computerHand) {
    int playerTotal, computerTotal;
    playerTotal = getHandTotal(playerHand);
    computerTotal = getHandTotal(computerHand);

    if (playerTotal == 21) {
        cout << "\nGame Over: Player 1 Wins with " << playerTotal << endl;
        return false;
    } else if (computerTotal == 21) {
        cout << "\nGame Over: Dealer Wins with " << computerTotal << endl;
        return false;
    } else if (playerTotal > 21) {
        cout << "\nGame Over: Player Busts with " << playerTotal << endl;
        return false;
    } else if (computerTotal > 21) {
        cout << "\nGame Over: Dealer Busts with " << computerTotal << endl;
        return false;
    } else if (playerTotal > computerTotal) {
        cout << "\nGame Over: Player 1 Wins with " << playerTotal << endl;
        return false;
    } else if (playerTotal == computerTotal) {
        cout << "\nGame Over: Hand is a push" << endl;
        return false;
    }
    return true;
}