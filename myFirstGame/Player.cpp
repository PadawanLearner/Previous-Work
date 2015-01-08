#include "Player.h"

#include <cstdlib>

using namespace std;

Player::Player(void)
{
	m_iExperience = 0;

	//inventoryWeapon = NULL;
	//myPtr = &Armor();
	inventoryArmour = NULL;

	//myPtr2 = &Weapon();
	inventoryWeapon = NULL;
}




//important function for user gameplay
bool Player::move(char & input,vector <vector<Tile*> >  game)
{



	if (input == 'w' && isMoveValid(0,-1, game))
	{
		
		game[getyPos()][getxPos()]->setUnitHere(false);
		setyPos(-1);
		return true;
	}
	if (input == 's'&& isMoveValid(0,1, game))	
	{
		game[getyPos()][getxPos()]->setUnitHere(false);
		setyPos(1);
		return true;
	}
	if (input == 'a'&& isMoveValid(-1,0, game))
	{
		game[getyPos()][getxPos()]->setUnitHere(false);
		setxPos(-1);
		return true;
	}
	if (input == 'd'&& isMoveValid(1,0, game))
	{
		game[getyPos()][getxPos()]->setUnitHere(false);
		setxPos(1);
		return true;
	}


	return false;
}





Weapon* Player::getInventoryWeapon()
{
	return inventoryWeapon;
}
Armor* Player::getInventoryArmour() 
{

	if (!(inventoryArmour == NULL)) 
		return inventoryArmour;
	else
	{
		//return myPtr; //stub
		return NULL;
	}
}
void Player::setInventoryWeapon(Weapon* newWeapon)
{
	inventoryWeapon = newWeapon;
	return;
}

void Player::setInventoryArmour(Armor* newArmour)
{
		inventoryArmour = newArmour;
		return;
	
}




Player::~Player(void)
{
}


void Player::dumpObject()
{
	cout << "Player:" << endl;
	dumpObjectData();
}

void Player::dumpObjectData()
{
	Unit::dumpObjectData();

	cout << "    [Experience] " << getExperience() << endl;
}

void Player::writeFragment(ostream & output)
{
	output << "   <Player>" << endl;
	writeDataAsFragment(output);
	output << "   </Player>" << endl;
}

void Player::writeDataAsFragment(ostream & output)
{
	Unit::writeDataAsFragment(output);

	output << "      <experience>" << getExperience() << "</experience>" << endl;

}

void Player::setElementData(string sElementName, string sValue)
{
	Unit::setElementData(sElementName, sValue);

	if( sElementName == "experience" )
	{
		setExperience(atoi(sValue.c_str()));
	}

}

int Player::getExperience()
{
	return m_iExperience;
}

void Player::setExperience(int iExperience)
{
	m_iExperience = iExperience;
}

void Player::attack(Unit & target)
{
	int dmg;


	if (getLevel() == 1)
		dmg = 2;
	else
		dmg = getLevel()/2 + getInventoryWeapon()->getDamage()/2;

	target.setHealth(target.getHealth()-dmg);
	cout << endl <<"Level " << getLevel() << " " << getName() << " hit "
		<< target.getName() << " for " << dmg << " damage"; 
}


