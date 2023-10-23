#pragma once

// item
// - Weapon
// - Armor
// - Consumable

#include "enums.h";

// *******************************
//				item
// *******************************

class Item
{
protected:
	//Item(); // 기본 생성자
	Item(ItemType itemType);
public:
	virtual ~Item();

public:
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Normal;
	ItemType _itemType = IT_None;
};

// *******************************
//			   Weapon
// *******************************

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo();

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }
private:
	int _damage = 0;
};

// *******************************
//			    Armor
// *******************************

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintInfo();

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence(){ return _defence; }

private:
	int _defence = 0;
};

