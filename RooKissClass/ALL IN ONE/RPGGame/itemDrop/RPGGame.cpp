#include <iostream>
#include "Item.h"
#include "Inventory.h"
using namespace std;

// [시스템] 몬스터를 잡을 때, 아이템을 떨군다.
Item* DropItem()
{
    if (rand() % 2 == 0)
    {
        Weapon* weapon = new Weapon();
        return weapon;
    }
    else
    {
        Armor* armor = new Armor();
        return armor;
    }
}

int main()
{
    srand((unsigned)time(0));

    // 몬스터 처치
    for (int i = 0; i < 100; i++)
    {
        Item* item = DropItem();
        item->PrintInfo();

        if (Inventory::Getinstance()->AddItem(item))
        {
            cout << "Added item to Inven" << endl;
        }
        else
        {
            cout << "Failed to add Item" << endl;
            delete item;
        }

        

        /*ItemType itemType = item->GetItemType();
        if (itemType == IT_Weapon)
        {
            Weapon* weapon = (Weapon*)item;
            weapon->GetDamage();
        }
        else if (itemType == IT_Armor)
        {
            Armor* armor = (Armor*)item;
            armor->GetDefence();
        }*/

        // delete item
    }

    // PK 당해서 랜덤으로 일부 아이템 드랍
    for (int i = 0; i < 20; i++)
    {
        int randIndex = rand() % MAX_SLOT;
        Item* item = Inventory::Getinstance()->GetItemAtSlot(randIndex);
        if (item && Inventory::Getinstance()->RemoveItem(item))
        {
            cout << "Removed Item" << endl;
        }
    }
}