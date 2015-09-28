#ifndef BATTLE_SYS_H_INCLUDED
#define BATTLE_SYS_H_INCLUDED

#include "fighters.h"

bool level_up (int, int);
void enemy_announce (std::string);
void battle (Fighter, Enemy);

#endif // BATTLE_SYS_H_INCLUDED
