/* Game Sim Knights vs Wizard: This is the final project of the semester using C++ 
Name: Marcos Rodriguez
*/
#include <iostream>// The typical input output stream header.
#include <cstdlib>// I implemented this one because of the use of rand.
#include <ctime>// Since later on we will be using a lot of time, since its a turn based
#include <string>// For the characters and structs.

using namespace std;

struct Character // My struct for each character. It contains the repetive core functions such as health,max health and damage.
{
    string type;
    int health;
    int maxHealth;
    int damage;
};

int luckRoll() //Your luck, this will generate a random number between 0 to 99, if that number is below 20, your attack will miss.
{
    return rand() % 100; // returns a value between 0 and 99
}

void attack(Character& attacker, Character& defender) // We use void in order to not get a value back
{
    int luck = luckRoll();// This means that luck will recieve that random number value.
    if (luck < 20) // Refer to line 19
    {
        cout << "Missed! Luck wasn't on your side." << endl;// Refer to line 19 for info on this
    }
    else // This is what happens if you're actually succesful with your attack.
    {
        int actualDamage = attacker.damage + (luck % 5); // small luck boost
        defender.health -= actualDamage;
        cout << attacker.type << " attacks for " << actualDamage << " damage!" << endl;
    }
}

void heal(Character& player)
{
    int luck = luckRoll();
    int healAmount = (player.maxHealth / 5) + (luck % 10);// Base heal + luck
    player.health += healAmount;
    if (player.health > player.maxHealth)player.health = player.maxHealth;
    cout << player.type << " heals for " << healAmount << "HP" << endl;
}

bool flee(Character& player)
{
    int luck = luckRoll();
    if (luck > 70)
    {
        cout << player.type << " successfully fled the battle!" << endl;
        return true;
    }
    else
    {
        cout << " Failed to flee! You're still in this fight! " << endl;
        return false;
    }
}



// THis is a test for git
int main()
{
    
}

