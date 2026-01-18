#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Knight.h"
#include "Mage.h"
#include "Enemy.h"
#include "Potion.h"
using namespace std;

int main() {
    srand((unsigned)time(nullptr));

    cout << "Choose your character:\n1. Knight (Bilbo)\n2. Mage (Frodo)\n";
    string choice;
    cin >> choice;

    Character* player;
    if (choice == "1")
        player = new Knight("Bilbo");
    else
        player = new Mage("Frodo");

    player->Inventory.AddItem(new Potion("HP", 30));
    player->Inventory.AddItem(new Potion("Mana", 50));

    vector<Enemy> enemies;
    string enemyNames[] = { "Dwarf", "Orc", "Elf", "Man", "Wizard" };

    for (int i = 0; i < 5; i++) {
        enemies.emplace_back(
            enemyNames[rand() % 5],
            rand() % 40 + 40,
            rand() % 10 + 20
        );
    }

    for (auto& enemy : enemies) {
        cout << "\n" << enemy << " appears!\n";

        while (enemy.HP > 0 && player->HP > 0) {

            cout << *player << endl;

            cout << "1. Basic Attack\n2. Special Attack\n3. Use Item\n";
            string action;
            cin >> action;

            int dmg = 0;

            if (action == "1")
                dmg = player->BasicAttack(player->BasicAtk());
            else if (action == "2")
                dmg = player->UseAbility(player->SpecialAtk(), player->ManaCost());
            else if (action == "3") {
                player->Inventory.ListItems();
                cout << "Enter item name: ";
                string itemName;
                cin >> itemName;

                for (auto item : player->Inventory.items) {
                    if (item->Name == itemName) {
                        player->Inventory.UseItem(item, *player);
                        break;
                    }
                }
                continue;
            }

            if (dmg > 0)
                enemy.TakeDamage(dmg);

            player->RegenerateMana();

            if (enemy.HP > 0)
                enemy.Attack(*player);
        }

        double gainedExp = rand() % 50 + 50 + 10 * player->lvl;
        player->GainExp(gainedExp);
    }

    cout << "\nCongratulations. You defeated all enemies!\n";
    delete player;
    return 0;
}
