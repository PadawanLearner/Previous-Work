#ifndef _Enemy_included_
#define _Enemy_included_

#include "Unit.h"
#include <vector>
#include "Player.h"

class Enemy :
	public Unit
{
public:
	Enemy(void);
	Enemy(const Enemy & copied_enemy);
	virtual ~Enemy(void);

	virtual void dumpObject();
	virtual void dumpObjectData();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, std::string sValue);


	virtual bool isHostile();
	virtual void setHostile(bool bHostile);
	virtual void attack(Player & target);
	virtual void takeTurn();


	bool move(Unit user, std::vector <std::vector<Tile*> >  game);

private:
	bool m_bHostile;


};

#endif

