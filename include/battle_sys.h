#ifndef BATTLE_SYS_H_INCLUDED
#define BATTLE_SYS_H_INCLUDED

#include "fighters.h"
#include "quik_funcs.h"
#include <iostream>
#include <stdlib.h>
#include <string>

bool next_level (int, int);
void enemy_announce (std::string);
void battle (class Fighter&, class Enemy&);

#endif // BATTLE_SYS_H_INCLUDED
