/**
 *Not yet implemented. This will have the leveling system and battle system.
 *They may have separate files in the future, as they become more complex
 **/

#include <math.h>

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
