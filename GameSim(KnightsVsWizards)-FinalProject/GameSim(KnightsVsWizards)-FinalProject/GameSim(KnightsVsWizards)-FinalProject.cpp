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

void showStats(const Character& player, const Character& enemy)/* This'll be to display the stats after each round and beginning. Using "&" we pass by reference,
ensuring that the "player" and "enemy" aren't changed.*/
{
    cout << "___STATUS___" << endl << endl; // I did this in order to make it look organized 
    cout << player.type << "HP: " << player.health << "/" << player.maxHealth << endl;// This prints the "character" your using and its current hp vs its max health.'
    cout << enemy.type << "HP: " << enemy.health << "/" << enemy.maxHealth << endl;// This does the same, however its for your enemy.
    cout << "____________" << endl;
}

int main()// The main part of the code!!!!!!!!!!!!
{
    srand(static_cast<unsigned int>(time(0)));
    Character player, enemy;

    cout << "Choose your character (Knight/Wizard): ";// Iconic
    string choice;// We make it type string since we expect the user to type the actual word.
    cin >> choice;// This just takes it in.

    if (choice == "Knight" || choice == "knight")
    {
        player = { "Knight ", 120, 120, 15 };
        enemy = { "Wizard", 80, 80, 25 };
    }
    else
    {
        player = { "Wizard", 80, 80, 25 };
        enemy = { "Knight", 120, 120, 15 };
    }
    
    cout << "Battle begins: " << player.type << " vs " << enemy.type << "!" << endl;
    
    while (player.health > 0 && enemy.health > 0)
    {
        showStats(player, enemy);

        cout << endl << "Choose your action: " << endl << "1.Attack" << endl << "2.Heal " << endl << "3.Flee" << endl;
        int action;
        cin >> action;
        system("cls");

        if (action == 1)
        {
            attack(player, enemy);
        }
        else if(action ==2)
        {
            heal(player);
        }
        else if (action == 3)
        {
            if (flee(player))
                break;
        }
        else
        {
            cout << "Invalid option. Try Again!" << endl;
        }

        if (enemy.health > 0)
        {
            cout << "Enemy's turn..." << endl;
            int enemyAction = rand() % 2;// 0 = attack, 1 = heal
            if (enemyAction == 0) attack(enemy, player);
            else heal(enemy);

        }
    }

    if (player.health <= 0)
        cout << "You were defeated by the " << enemy.type << "!";
    else if (enemy.health <= 0)
        cout << " Victory! You defeated the " << enemy.type << "!";
    else
        cout << " The battle ended ";

    return 0;
}

