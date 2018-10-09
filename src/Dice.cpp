//
//  Dice.cpp
//  Assignment_1
//
//  Created by mushfiqur anik on 2018-10-09.
//  Copyright © 2018 mushfiqur anik. All rights reserved.
//

// Includes and namespaces.
#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Sets the number of rolls
Dice:: Dice(int numOfRolls) {
    values = new int[numOfRolls];
    size = numOfRolls;
}

// Performs the rolls
void Dice:: rolls() {
    for(int i = 0; i < size; i++) {
        values[i] = (rand()%6)+1;
    }
}

// This sorts the values of dice in ascending order
void Dice:: sort()
{
    for(int i = 0; i < size-1; i++) {
        int temp;
        for(int j = i+1; j < size; j++) {
            if(values[i] > values[j]){
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

// Displays the values of the rolls
void Dice:: displayValues() {
    for(int i = 0; i < size; i++) {
        cout << "The values are: " << values[i] << endl;
    }
}

// Calculates the percentage of players
double Dice:: percentage() {
    double percent = 0;
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum += values[i];
    }
    
    percent =  ((sum / (6*size))*100);
    return percent;
    
}

int main() {
    // Variables
    int numOfRolls;
    double p1; // holds the percentage of player 1
    double p2; // holds the percentage of player 2
    
    
    // Prompting the players to enter number of rolls.
    cout << "Enter the number of rolls (from 1 to 3 dice): " << endl;
    cin >> numOfRolls;
    
    // Object that passes the number of rolls
    Dice player1(numOfRolls),player2(numOfRolls);
    
    srand(time(0));
    
    // Rolls the dice and sets all the value
    player1.rolls();
    player2.rolls();
    
    // Sorts the values
    player1.sort();
    player2.sort();
    
    // Displays all the values
    cout << "The values of player 1 are: " << endl;
    player1.displayValues();
    cout << "\n" << endl;
    
    //cout << "----------------------------" << endl;
    
    cout << "The values of player2 are: " << endl;
    player2.displayValues();
    cout << "\n" << endl;
    
    // Initialises the variables
    p1 = player1.percentage();
    p2 = player2.percentage();
    
    // Displays the percentage
    cout << "The percentage of player1 is " << p1 << "% " << endl;
    cout << "The percentage of player2 is " << p2 << "% " << endl;
    cout << "\n";
    
    
    // Decides the winner
    if (p1 > p2) {
        cout << "Player1 won this round. " << endl;
    }
    else if (p1 < p2) {
        cout << "Player2 won this round. " << endl;
    }
    else
        cout << "It was a tie" << endl;
    
}

