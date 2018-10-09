//
//  Dice.h
//  Assignment_1
//
//  Created by mushfiqur anik on 2018-10-09.
//  Copyright © 2018 mushfiqur anik. All rights reserved.
//

#ifndef Dice_h
#define Dice_h

class Dice {
    int *values; // This is a pointer to point to the values of dice.
    int size; // This int is initialised to the number of rolls of dice.
    
public:
    Dice(int numberOfRolls); // Signature Constructor
    void rolls(); // This method performs the rolls
    void sort(); // This method sorts the values in ascending order
    void displayValues(); // Displays all the values of rolls
    double percentage(); // Calculates the percentage
};


#endif /* Dice_h */
