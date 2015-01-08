#include "Enemy.h"

#include <cstdlib>

using namespace std;

Enemy::Enemy(void)
{
	m_bHostile = true;
}

Enemy::Enemy(const Enemy & copied_enemy)
{

	*this = copied_enemy;


}




Enemy::~Enemy(void)
{
}


void Enemy::dumpObject()
{
	cout << "Enemy:" << endl;
	dumpObjectData();
}

void Enemy::dumpObjectData()
{
	Unit::dumpObjectData();

	cout << "       [Hostile] " << (isHostile() ? "true" : "false") << endl;
}

void Enemy::writeFragment(ostream & output)
{
	output << "   <Enemy>" << endl;
	writeDataAsFragment(output);
	output << "   </Enemy>" << endl;
}

void Enemy::writeDataAsFragment(ostream & output)
{
	Unit::writeDataAsFragment(output);

	output << "      <hostile>" << (isHostile() ? "true" : "false") << "</hostile>" << endl;

}

void Enemy::setElementData(string sElementName, string sValue)
{
	Unit::setElementData(sElementName, sValue);

	if( sElementName == "hostile" )
	{
		if( sValue == "true" )
		{
			setHostile(true);
		}
		else if( sValue == "false" )
		{
			setHostile(false);
		}
	}

}

bool Enemy::isHostile()
{
	return m_bHostile;
}

void Enemy::setHostile(bool bHostile)
{
	m_bHostile = bHostile;
}

void Enemy::attack(Player & target)
{
	int dmg;

	//easy mobs on lower levels:
	if (getLevel() == 1 || getLevel() == 2)
		dmg =1;
	else
	{
		dmg = (getLevel()) - target.getInventoryArmour()->getProtection()/2;

		while (dmg <= 0)
		{
			dmg = dmg + getLevel();
		}
	}

	target.setHealth(target.getHealth()-dmg);
	cout << endl << "Level " << getLevel()<< " " << getName() << " hit " << target.getName() << " for " << dmg; 

}


bool Enemy::move(Unit user,vector <vector<Tile*> >  game)
{
	
	int slopeX;
	int slopeY;
	
	if (user.getxPos() - getxPos() < 0)
		slopeX = -1;
	else if (user.getxPos() - getxPos() > 0)
		slopeX = 1;
	else
		slopeX = 0;


	if(user.getyPos() - getyPos() < 0)
		slopeY = -1;
	
	else if(user.getyPos() - getyPos() > 0)
		slopeY = 1;
	else
		slopeY = 0;


	if (!(slopeX == 0 || slopeY == 0 )) 
	{
		if (isMoveValid(0,slopeY, game))
		{
			game[getyPos()][getxPos()]->setUnitHere(false);
			setyPos(slopeY);
			return true;
			
		}
		
		if (isMoveValid(slopeX,0, game)	)
		{
			game[getyPos()][getxPos()]->setUnitHere(false);
			setxPos(slopeX);
			return true;
		}
	
	}

	else
	{
		if(slopeX == 0)
		{
			if (isMoveValid(0,slopeY, game))
			{
				game[getyPos()][getxPos()]->setUnitHere(false);
				setyPos(slopeY);
				return true;
			}
		
		}
		if(slopeY == 0)
		{
			if (isMoveValid(slopeX,0, game)) //and user is not 1 unit away
			{
				game[getyPos()][getxPos()]->setUnitHere(false);
				setxPos(slopeX);
				return true;
			}
		
		}
	}
	
	return false;
}


void Enemy::takeTurn()
{
}


