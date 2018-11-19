//! @file
//! @author Vsevolod Ivanov

#include "PhaseObserver.h"

PhaseObserver::PhaseObserver(int id, Game *subject):
    id(id), subject(subject)
{
    this->subject->attach(this);
}

PhaseObserver::~PhaseObserver()
{
}

int PhaseObserver::getId() const
{
    return this->id;
}

void PhaseObserver::update()
{
   string phaseName;
   Player& player = *this->subject->activePlayer;
   Player::Phase phase = player.getActivePhase();
   Country* sourceCountry;
   Country* targetCountry;

   switch (phase)
   {
        case Player::Phase::REINFORCE:
            phaseName = "Reinforcement";
            targetCountry = player.targetCountry;
            break;
        case Player::Phase::ATTACK:
            phaseName = "Attack";
            sourceCountry = player.sourceCountry;
            targetCountry = player.targetCountry;
            break;
        case Player::Phase::FORTIFY:
            phaseName = "Fortification";
            targetCountry = player.targetCountry;
            break;
        default:
            throw -1;
   }

   cout << "--------- PhaseObserver" << this->id <<
           " ----------" << endl;
   cout << "Player: " << player.getName() << endl;
   cout << "Phase:  " << phaseName << endl;
   if (sourceCountry != NULL)
        cout << "Source: " << sourceCountry->getName() << endl;
   cout << "Target: " << targetCountry->getName() << endl;
   cout << "Armies: " << player.phaseArmies << endl;
   cout << "-----------------------------------" << endl;
}
