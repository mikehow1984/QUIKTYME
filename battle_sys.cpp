/**
 *Not yet implemented. This will have the leveling system and battle system.
 *They may have separate files in the future, as they become more complex
 **/

#include <iostream>
#include <math.h>
#include <string>
#include "battle_sys.h"

using std::string;          using std::cout;
using std::cin;

bool level_up (int lv, int ex) //"ex" is the player's experience after a battle
{
    /**experience formula: exp = ((50*(lv))*((9*(lv)-16)))-100;
     *derived from the Runescape formula (exp needed to raise a level:
     *exp = previous_level_exp + (previous_level_exp * 0.1))
     *constructed a formula for the experience for each level (in other words,
     *the experience points needed to jump from a certain level to the next level
     *and then integrated it (never thought I'd ever have to practically do that)
     *to come up with a formula for total experience needed to be at a
     *certain level.
     **/
    int nextlevel_ex = ((50*(lv))*((9*(lv)-16)))-100;

    return ex >= nextlevel_ex;
}

void enemy_announce (string enemy_name)
{
    cout << "The monster " << enemy_name << " randomly appeared!\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void battle (Fighter hero, Enemy villain)
{
        do{     //battle systevillain. needs to be split into functions
        cout << "Type 2 to dodge, Type 1 to kick her in the face, Type 0 to block: ";
            //simple for now. need to add movesets and more options
        int move_num;
        cin >> move_num;
        move_num = input_errorchk(move_num);

        int hit;
        if (move_num == 2)      //dodging an attack
        {
            int m_hit_chance = ((*villain.Spd)*(100))/((*hero.Spd)+(*villain.Spd));   //calculates the chances of monster's attack hitting
            if (rand()%100+1 > m_hit_chance)                //if a random number is greater than attack chance
            {                                               //you dodge
                cout << "You dodged the attack!\n";
                hit = rand()%10+1;
                *villain.HP = *villain.HP - hit;
                cout << villain.get_name() << " hit a wall and lost " << hit << " HP!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n" << villain.get_name() << "'s HP: " << *villain.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            //the advantage is that the monster wastes a turn while taking damage
            //great if the monster is stronger than you
                if(check_if_dead(villain.HP))
                    {
                        cout << "You have defeated " << villain.get_name() << "!\n";
                        break;
                    }
                    //always check if a fighter or monster is dead after an attack
            }
            else        //here's the risk of dodging: if it hits, not only do you lose a turn
            {           //but the monster does bonus damage to you!
                hit = move_power(villain.Atk, hero.Def, villain.Int, 5, .5, "Def");
                *hero.HP = *hero.HP - hit;
                cout << villain.get_name() << " is too fast!\n";
                cout << villain.get_name() << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(hero.HP))
                    {
                        cout << hero.get_name() << " NOOOOOOOO!\n" <<  villain.get_name() << " has defeated you!\n";
                        break;
                    }
            }
        }
        if (move_num == 1) //normal attack option. will add move options (moveset)
        {
            if (*hero.Spd > *villain.Spd)  //checks who is faster. monster has the advantage if they're equal
            {
                hit = move_power(hero.Atk, villain.Def, hero.Int, 5);
                *villain.HP = *villain.HP - hit;
                cout << "You did " << hit << " damage!\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(villain.HP))
                    {
                        cout << "You have defeated " << villain.get_name() << "!\n";
                        break;
                    }

                hit = move_power(villain.Atk, hero.Def, hero.Int, 5);
                *hero.HP = *hero.HP - hit;
                cout << villain.get_name() << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                if(check_if_dead(hero.HP))
                    {
                        cout << hero.get_name() << " NOOOOOOOO!\n" <<  villain.get_name() << " has defeated you!\n";
                        break;
                    }
            }
            else
            {
                hit = move_power(villain.Atk, hero.Def, villain.Int, 5);
                *hero.HP = *hero.HP - hit;
                cout << villain.get_name() << " did " << hit << " damage to you!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                 if(check_if_dead(hero.HP))
                    {
                        cout << hero.get_name() << " NOOOOOOOO!\n" <<  villain.get_name() << " has defeated you!\n";
                        break;
                    }
                hit = move_power(hero.Atk, villain.Def, hero.Int, 5);
                *villain.HP = *villain.HP - hit;
                cout << "You did " << hit << " damage!\n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";

                if(check_if_dead(villain.HP))
                    {
                        cout << "You have defeated " << villain.get_name() << "!\n";
                        break;
                    }
            }

        }
        if (move_num == 0)      //block the attack. the monster is guaranteed to hit you
        {                       //but does a decreased amount of damage
            hit = move_power(villain.Atk, hero.Def, villain.Int, 5, 2, "Def");
            *hero.HP = *hero.HP - hit;
            cout << villain.get_name() << " did " << hit << " damage to you!\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << hero.get_name() << "'s HP: " << *hero.HP << "\n"  << villain.get_name() << "'s HP: " << *villain.HP << "\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            if(check_if_dead(hero.HP))
            {
                cout << hero.get_name() << " NOOOOOOOO!\n" <<  villain.get_name() << " has defeated you!\n";
                break;
            }
        }                       //doesn't make sense strategically, but adding status effects or
                                //other battle tactics will make it feasible
    } while(*hero.HP > 0 && *villain.HP > 0); //redundancy; there are already breaks when either player dies

hero.exp_gain(hero.exp, villain.exp_given(), player_win(villain.HP), hero.get_name());
}
