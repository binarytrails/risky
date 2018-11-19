//! @file
//! @author Vsevolod Ivanov

#include "PhaseObserver.h"

PhaseObserver::PhaseObserver(int id): id(id)
{
}

PhaseObserver::~PhaseObserver()
{
}

int PhaseObserver::getId() const
{
    return this->id;
}

void PhaseObserver::update(Player *player)
{
   cout << "--------- PhaseObserver" << this->id <<
           " ----------" << endl;

   cout << "Method: Update" << endl;
   cout << "Player: " << player->getName() << endl;
   //cout << "Phase:  " << player->activePhase() << endl;

   cout << "-----------------------------------" << endl;
}
