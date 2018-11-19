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
   string phaseName;
   Player::Phase phase = player->getActivePhase();

   switch (phase)
   {
        case Player::Phase::REINFORCE:
            phaseName = "Reinforcement";
            break;
        case Player::Phase::ATTACK:
            phaseName = "Attack";
            break;
        case Player::Phase::FORTIFY:
            phaseName = "Fortification";
            break;
        default:
            throw -1;
   }

   cout << "--------- PhaseObserver" << this->id <<
           " ----------" << endl;
   cout << "Player: " << player->getName() << endl;
   cout << "Phase:  " << phaseName << endl;
   cout << "-----------------------------------" << endl;
}
