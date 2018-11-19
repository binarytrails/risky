#include "HumanPlayer.h"

// Uses the default reinforce controlled by a real human player.
void HumanPlayer::reinforcement(Player * player, Hand & h, int cont)
{
	Reinforcement::reinforcement(player, h, cont);
}

// Uses the default attack controlled by a real human player.
void HumanPlayer::attack(Player * player)
{
	// TODO add attack when available
}

// Uses the default fortify controlled by a real human player.
void HumanPlayer::fortify(Player * player)
{
	//TODO add fortify when available
}
