#include <iostream>
#include <vector>

#include <functional>
#include <map>
#include <fstream>


#include "EnemyFactory.h"
#include "DungeonLevel.h"
#include "Unit.h"
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Consumable.h"
#include "Enemy.h"
#include "XMLSerializable.h"
#include "parser.h"
#include "EnemyFactory.h"
#include "Entity.h"
#include "Player.h"
#include "ItemFactory.h"
#include "Tile.h"





/*	NOTES:



My game scales best with number_of_levels = 12.  End game bosses occur on the last level: OverlordBlagg, OverlordBrown, 
and a dragon, in which case the user should have atleast 70 health (approx. lvl 40ish) before facing them, 
or make sure you have Thunderfury.

My combat is fairly straight-forward, where as this is more of a grinding game.  You need to obtain certain items before 
facing the bosses.  The game seems easy until you face them.  Make sure you grind out enough good gear and a good potion.

My game takes approximately 5 seconds to load.  I do have random enemy generation within the levels, but I also 
initially load them into their respective positions before the game starts.  5 second loading screens ftl =(

The coolest part of my game is the dynamic experience required to level (Line#380ish).  Leveling up (which increases damage/health) is
largely based upon the total turns taken.  This means that the longer you just walk around without doing combat will make
it harder for you to level up.  The solution to this requires the player to constantly
seek combat (while watching their health of course) in order to keep up with the ever increasing experience cap.


*/








using namespace std;

int main(int argc, char * argv[])
{

	//game creation values:
	Player user;
	bool gameOver = false;

	//arbitrary game values:
	int number_of_levels= 12;
	int currentUserLevel = number_of_levels - number_of_levels;
	int number_of_enemies_per_level = 5;
	int number_of_items_per_level = 5;
	
	//needed initializations
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	mt19937 generate_num( seed );
	generate_num();

	





	//create game via triple vector of Tiles:
	vector<vector <vector<Tile*> > > theGame;
	for (int i=0; i<number_of_levels; i++)
	{
		vector<vector<Tile*>> myVec;
		for(int j=0;j< 20; j++) 
		{
			vector <Tile*>  aVec;
			for (int k=0; k<79; k++)
			{
				aVec.push_back(new Tile);
			}
			myVec.push_back(aVec);
		}
		theGame.push_back(myVec);
	}









	//generate the dungeon and its sub-levels:
	vector <Dungeon> complete_dungeon;

	for (int i=0;i<number_of_levels;i++)
	{   
		generate_num();
		Dungeon new_lvl(true, generate_num); //new lvl

		bool level_created = new_lvl.assign_layout();

		while (!(level_created))
			level_created = new_lvl.assign_layout();
		complete_dungeon.push_back(new_lvl);
	}








	

	
	//convert dungeon level image into Tile layout
	vector<string> dungeon_image;
	vector<vector<char>> preGameImage; //use tiles here

	for(int h=0;h<number_of_levels;h++)
	{
		dungeon_image = complete_dungeon[currentUserLevel+h].get_grid_image();
		
		for(int i=0;i< 20; i++) 
		{
			vector <char> myVec;
			for (int j=0; j<79; j++)
			{
				myVec.push_back(dungeon_image[i][j]);
				theGame[currentUserLevel+h][i][j]->setMapChar(dungeon_image[i][j]); //USE setMapChar
			}
			preGameImage.push_back(myVec);
		}
	}
	
	






	//user starting values
	user.setName("Rick James");
	user.setHealth(10);
	user.randomizePosition(complete_dungeon[0].get_grid_image());
	theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitChar('*');
	theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitHere(true);
	user.setDisplayChar('*'); //DELETE?





	//standard user equipment:
	Armor startingArmor;
	Weapon startingWeapon;
	Consumable userConsumable;

	Armor* userStartingArmour = &startingArmor;
	userStartingArmour->setDisplayChar('.');
	userStartingArmour->setName("rags");
	userStartingArmour->setProtection(2);
	user.setInventoryArmour(userStartingArmour);

	Weapon* userStartingWeapon = &startingWeapon;
	userStartingWeapon->setDisplayChar('.');
	userStartingWeapon->setName("stick");
	userStartingWeapon->setDamage(2);
	user.setInventoryWeapon(userStartingWeapon);

	Consumable* ricksMagic = &userConsumable;
	ricksMagic->setHealth(5);

	

	


	//generate enemies by level per level ; vec<vec>
	EnemyFactory::instance();
	vector <vector<Enemy*> > dungeon_enemies; //a vector of vector of enemies, each [i] holds a vector of the enemies for [i]'s level
		for (int i=0; i<number_of_levels;i++)
		{
			vector <Enemy*> myvec;
			for (int j=0; j < number_of_enemies_per_level; j++)
			{
				//the below enemyfactory call will scale the level of enemies relative to the level of the dungeon "i"
				if (i < 5)
					myvec.push_back(EnemyFactory::instance().generateEnemy(2+i, i));
				else
					myvec.push_back(EnemyFactory::instance().generateEnemy(2+i, 4));
				myvec[j]->randomizePosition(complete_dungeon[i].get_grid_image());

				//store enemies into Tiles:
				theGame[currentUserLevel+i][myvec[j]->getyPos()][myvec[j]->getxPos()]->setUnitChar(myvec[j]->getDisplayChar());
				theGame[currentUserLevel+i][myvec[j]->getyPos()][myvec[j]->getxPos()]->setUnitHere(true);
			}
			dungeon_enemies.push_back(myvec);
		}
	
	







	//generate items by level per level ; vec<vec>
	ItemFactory::instance();
	vector <vector<Item*> > dungeon_items; //a vector of vector of items, each [i] holds a vector of the enemies for [i]'s level

	for (int i=0; i<number_of_levels;i++)
	{
		vector <Item*> myvec;
		for (int j=0; j < number_of_items_per_level; j++)
		{
			//alternate between weapon/armor generation to achieve balance of item generation
			if(j%2 == 0)
				myvec.push_back(ItemFactory::instance().generateItem(20, "Armor")); //change to 3+i to increase level of monsters per level of dungeon
			else
				myvec.push_back(ItemFactory::instance().generateItem(20, "Weapon"));

			myvec[j]->randomizePosition(complete_dungeon[i].get_grid_image());

			theGame[currentUserLevel+i][myvec[j]->getyPos()][myvec[j]->getxPos()]->setItemChar(myvec[j]->getDisplayChar());
			theGame[currentUserLevel+i][myvec[j]->getyPos()][myvec[j]->getxPos()]->setItemHere(true);
			theGame[currentUserLevel+i][myvec[j]->getyPos()][myvec[j]->getxPos()]->addItemToTile(myvec[j]);
		}
		dungeon_items.push_back(myvec);
	}







	//items to be dropped from enemies (called within turn):
	vector<Item*>  enemy_items;

	//input initializations
	int score = 0;
	int turns = 0;
	char userInput = ' ';





	





///////////////////////////////////////////////  GAME PLAY LOOP  ///////////////////////////////////////////////////////////
	while (!gameOver) 
	{  
		bool traverse = false;
		vector<vector<char>> currentFrontEndGame; //holds current information of current iteration 



		//user +1 health regeneration every third turn
		if ( turns%2 == 0 && user.getHealth() <= user.getMaxHealth()) 
			user.setHealth(user.getHealth()+1); 




		//print user info per turn:
		cout << "Level " << user.getLevel() << " Rick James, Score: " << score << 
			", Experience: " << user.getExperience() << "/" << (50+turns  + user.getExperience()/2)
			<< " Health: " << user.getHealth();
		cout << endl << "User inventory: " << user.getInventoryArmour()->getName() << ", " <<
						user.getInventoryWeapon()->getName() << endl;
		


		


//COMBAT LOOP:
		//check for enemy combat by proximity before user makes move:
		for (int i=0; i<dungeon_enemies[currentUserLevel].size(); i++)
		{
			if( abs(dungeon_enemies[currentUserLevel][i]->getxPos() - user.getxPos()) <= 1 && 
				abs(dungeon_enemies[currentUserLevel][i]->getyPos() - user.getyPos()) <= 1	) 
			{
				cout << endl << "Combat!";

				//while both combatants are alive:
				while (user.getHealth() > 0 && dungeon_enemies[currentUserLevel][i]->getHealth() > 0 )
				{
					//combat:
					user.attack(*dungeon_enemies[currentUserLevel][i]);
					dungeon_enemies[currentUserLevel][i]->attack(user);
				}

				//enemy dies:
				if (dungeon_enemies[currentUserLevel][i]->getHealth() <= 0)
				{
					cout << endl << "Monster defeated!";

					

					//possible item drop:
					//droprate increases as enemy level increases, with level 20 bosses guaranteeing a drop:
					if (generate_num() % 20 <= dungeon_enemies[currentUserLevel][i]->getLevel())
					{
						cout << endl << "Item drop!" << endl;
						if (turns%2 ==0)
							enemy_items.push_back(ItemFactory::instance().generateItem(200, "Armor"));
						else
							enemy_items.push_back(ItemFactory::instance().generateItem(200, "Weapon"));

						//add enemy drop to floor:
						theGame[currentUserLevel][ dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->setItemHere(true);

						theGame[currentUserLevel][ dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->addItemToTile(enemy_items.back());

						theGame[currentUserLevel][ dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->setItemChar(
							enemy_items.back()->getDisplayChar() );
					}

					//static 50% drop rate for healing potion per enemy kill:
					if (generate_num() % 10 >= 5)
					{
						ricksMagic = new Consumable;
						//set strength of healing potion based on strength of killed enemy: 
						ricksMagic->setHealth(dungeon_enemies[currentUserLevel][i]->getLevel());
						cout << endl << "Potion drop! Restoration strength: " << ricksMagic->getHealth();

						theGame[currentUserLevel][dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->setItemHere(true);

						theGame[currentUserLevel][dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->addItemToTile(ricksMagic);

						theGame[currentUserLevel][ dungeon_enemies[currentUserLevel][i]->getyPos()]
						[dungeon_enemies[currentUserLevel][i]->getxPos()]->setItemChar(
							ricksMagic->getDisplayChar());

					}

					

					//pad user stats for killing enemy:
					user.setExperience(user.getExperience() + dungeon_enemies[currentUserLevel][i]->getLevel()*50);
					score = score + user.getExperience();



					//user has enough xp to level up :
					//each new level requires a certain amount more xp relative to total turns played
					if(user.getExperience() > 50+turns  + user.getExperience()/2)
					{
						user.setLevel(user.getLevel()+1);
						cout << endl << "						Level Up! New level : " << user.getLevel() << endl;
						user.setMaxHealth(user.getMaxHealth()+5); //new max health per level up
						user.setExperience(0); //reset xp
					}

					//remove enemy from Tile:
					theGame[currentUserLevel][dungeon_enemies[currentUserLevel][i]->getyPos()]
					[dungeon_enemies[currentUserLevel][i]->getxPos()]->setUnitHere(false);
					//delete particular enemy:
					dungeon_enemies[currentUserLevel].erase(dungeon_enemies[currentUserLevel].begin()+i);
				}
			}
		}

		//check for user death:
		if (user.getHealth() <= 0) //not ending correctly
		{
			cout << endl << "You died!" << endl;
			cout << "Score: " << score << endl;
			gameOver = true;
			break;
		}
		
		




//begin user input for turn:
		if (turns > 0) {
			cout << "Enter command: up,left,down,right = W,A,S,D ; list of commands = x ";
			cin >> userInput;

			while (userInput == 'x')
			{
				cout << endl << "up,left,down,right = W,A,S,D ; item pickup = p ; drop current item(s) = z ; c = use healing potion(cocaine is a hell of drug) ;"
				<< " ; get item stats = e ; quit = q " << endl;
				cout << endl << "You = *" << endl << "Enter command: up,left,down,right = W,A,S,D ; list of commands = x " << endl;
				cin >> userInput;
			}


			while(userInput == 'e')
			{
				cout << endl << user.getInventoryArmour()->getName() << " protection: " << user.getInventoryArmour()->getProtection();
				cout << endl << user.getInventoryWeapon()->getName() << " damage: " << user.getInventoryWeapon()->getDamage();
				cout << endl << "You = *" << endl << "Enter command: up,left,down,right = W,A,S,D ; list of commands = x " << endl;
				cin >> userInput;
			}

		
			while (userInput == 'c')
			{
				if (ricksMagic == NULL)
				{
					cout << endl << "No potion available!";
					cout << endl << "You = *" << endl << "Enter command: up,left,down,right = W,A,S,D " << endl;
					cin >> userInput;
				}
				else
				{
					ricksMagic->use(user);
					cout << endl << "New health: " << user.getHealth();
					ricksMagic = NULL;

					cout << endl << "You = *" << endl << "Enter command: up,left,down,right = W,A,S,D " << endl;
					cin >> userInput;
				}
			}

			if (userInput == 'q')
			{
				cout << "Score: " << score << endl;
				gameOver = true;
				break;
			}




//user drops items:
		while(userInput == 'z')
		{
			//drop Armor? :
			cout << endl <<"Drop " << user.getInventoryArmour()->getName() <<"? y/n ";
			cin >> userInput;
			if(userInput == 'y')
			{
				//drop current armor:
				if (!(user.getInventoryArmour()->getDisplayChar() == userStartingArmour->getDisplayChar()))
				{
					Armor * armorPtr = user.getInventoryArmour();

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->addItemToTile(
					armorPtr );

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemHere(true);

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
					user.getInventoryArmour()->getDisplayChar());
				}
				user.setInventoryArmour(userStartingArmour); //fallback on default armour "rags"
			}
					
			//drop weapon? :
			cout << endl <<"Drop " << user.getInventoryWeapon()->getName() <<"? y/n ";
			cin >> userInput;
			if(userInput == 'y')
			{

				if (!(user.getInventoryWeapon()->getDisplayChar() == userStartingWeapon->getDisplayChar()))
				{
					Weapon * weaponPtr = user.getInventoryWeapon();

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->addItemToTile(
					weaponPtr );

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemHere(true);

					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
							user.getInventoryWeapon()->getDisplayChar());
				}
				user.setInventoryWeapon(userStartingWeapon); //fallback on default weapon "stick"
			}	
			cout << endl << "Enter command: up,left,down,right = W,A,S,D ; item pickup = p ";
			cin >> userInput;
		}
		






//user picks up item :
			while (userInput == 'p')
			{
				if ( theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size()
					== 0 ) 
					cout << endl << "No items here "; //no items to pick up
				else
				{
					for (int i=0; i < theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size(); i++)
					{
						cout << endl << "Option " << i+1 << ": " << 
							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]->getName();
					}
					//user picks item to equip:
					cout << endl << "Choose the Option # you wish to carry as an item. Press 0 to decline. ";	
					int itemInput;
					cin >> userInput;
					itemInput = userInput - '0';

					//input validation:
					while ( (itemInput < 0 || itemInput > theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size())&& itemInput != 0)
					{
						cout << endl << "Choose the Option # you wish to carry as an item. Press 0 to decline. ";
						cin >> userInput;
						itemInput = userInput - '0';
					}

					//switch ground item with player's inventory item
					if (!(itemInput == 0 ))
					{
						//is armor exchange? :
						if (dynamic_cast<Armor*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[itemInput-1]))
						{
							//takes users armor, polymorphically add to tile that holds item*'s
							Armor * armorPtr = user.getInventoryArmour(); 

							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->addItemToTile(
								armorPtr );
							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemHere(true);

							//trickery here to always show armor that is a possible upgrade
							if(user.getInventoryArmour()->getName() == "rags" && theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size() > 2)
							{
								//use for loop to cycle through all armor on the ground, choose 1st good one
								for (int i=0 ;i<theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size();i++)
								{
									if (!(i == itemInput-1))
									{
										if (dynamic_cast<Armor*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]) && 
											theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]->getName() != "rags")
										{
											theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
												theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]->getDisplayChar());
										}
									}
								}
							}
							else
							{
								theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
									user.getInventoryArmour()->getDisplayChar()
									);
							}
							//now take tile's armor, add to user armor slot
							armorPtr = (dynamic_cast<Armor*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->pickupItem(itemInput-1)));
							Armor armorPtrSupport = *armorPtr;   
							user.setInventoryArmour(armorPtr);
						}


						//is weapon exchange? :
						if (dynamic_cast<Weapon*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[itemInput-1]))
						{
							//takes users armor, polymorphically add to tile that holds item*'s
							Weapon * WeaponPtr = user.getInventoryWeapon(); 
							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->addItemToTile(
								WeaponPtr );
							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemHere(true);

							//only display chooseable weapons:
							if(user.getInventoryWeapon()->getName() == "stick" && theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size() > 2)
							{
								for (int i=0 ;i<theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size();i++)
								{
									if (!(i == itemInput-1))
									{
										if (dynamic_cast<Weapon*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]) && 
											theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]->getName() != "stick")
										{
											theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
												theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[i]->getDisplayChar());
										}
									}
								}
							}

							else
							{
								theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
									user.getInventoryWeapon()->getDisplayChar()
									);
							}

							//now take tile's armor, add to user armor slot
							WeaponPtr = (dynamic_cast<Weapon*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->pickupItem(itemInput-1)));
							Weapon armorPtrSupport = *WeaponPtr;   
							user.setInventoryWeapon(WeaponPtr);

						}

						
						//pick up consumable:
						if (dynamic_cast<Consumable*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList()[itemInput-1]))
							{
								if(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().size() == 1)
								{
									theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemHere(false);
									theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
										theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getMapChar());
								
									ricksMagic = (dynamic_cast<Consumable*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->pickupItem(itemInput-1)));
								}
								else
								{
									ricksMagic = (dynamic_cast<Consumable*>(theGame[currentUserLevel][user.getyPos()][user.getxPos()]->pickupItem(itemInput-1)));
									
									theGame[currentUserLevel][user.getyPos()][user.getxPos()]->deleteItem(itemInput-1);

									theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setItemChar(
										theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getItemList().back()->getDisplayChar());
								}
							}

						//else here
						//delete item picked up:
						else
							theGame[currentUserLevel][user.getyPos()][user.getxPos()]->deleteItem(itemInput-1);
					}
					cout << endl << "User inventory: " << user.getInventoryArmour()->getName() << ", " <<
						user.getInventoryWeapon()->getName();
				}
				cout << endl << "Enter command: up,left,down,right = W,A,S,D ; item pickup = p ";
				cin >> userInput;
			}












//user movement
			while (!user.move(userInput, theGame[currentUserLevel])) // && userInput != 'p' && userInput != 'c'
				//&& userInput != 'z' && userInput != 'q')
			{
				cout << endl << "You cannot move there!  " << endl << "Enter MOVEMENT command: ";
				cin >> userInput;
			}

			
			










//traverse levels
			if (theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getMapChar() == '<'
				&& traverse == false)
			{
				if(currentUserLevel == 0)
				{
					cout << endl << "You have given up and gone back into your own prison...Game Over!" << endl;
					cout << "Score: " << score << endl;
					gameOver = true;
					break;
				}
				else
				{
					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitHere(false);
					currentUserLevel--;

					user.setxPos(-user.getxPos());
					user.setxPos(complete_dungeon[currentUserLevel].getxPosDownstairs());

					user.setyPos(-user.getyPos());
					user.setyPos(complete_dungeon[currentUserLevel].getyPosDownstairs());
		
					traverse = true;
					cout << endl << "Upstairs found " << endl;
				}
			}

			if (theGame[currentUserLevel][user.getyPos()][user.getxPos()]->getMapChar() == '>'
				&& traverse == false)
			{
				//user wins game by getting out of all dungeon levels:
				if (currentUserLevel == number_of_levels-1)
				{
					cout << endl << "You have made it out of The Dungeon. Game Over: You ESCAPED, well done!" << endl;
					cout << "Score: " << score << endl;
					gameOver = true;
					break;
				}
				else
				{
					theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitHere(false);
					currentUserLevel++;
				
					user.setxPos(-user.getxPos());
					user.setxPos(complete_dungeon[currentUserLevel].getxPosUpstairs());
			
					user.setyPos(-user.getyPos());
					user.setyPos(complete_dungeon[currentUserLevel].getyPosUpstairs());
					
					traverse = true;
					cout << endl << "Downstairs found " << endl; 
				}
			}
		//user completed move successfully:
		theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitHere(true); 
		theGame[currentUserLevel][user.getyPos()][user.getxPos()]->setUnitChar(user.getDisplayChar()); 













//enemy A.I. movement towards user:
		for (int i=0; i < dungeon_enemies[currentUserLevel].size(); i++)
		{
			if (dungeon_enemies[currentUserLevel][i]->move(user,theGame[currentUserLevel]))
			{

				theGame[currentUserLevel][dungeon_enemies[currentUserLevel][i]->getyPos()]
				[dungeon_enemies[currentUserLevel][i]->getxPos()]->setUnitHere(true);

				theGame[currentUserLevel][dungeon_enemies[currentUserLevel][i]->getyPos()]
				[dungeon_enemies[currentUserLevel][i]->getxPos()]->setUnitChar(
					dungeon_enemies[currentUserLevel][i]->getDisplayChar());
			}
		}
		}






//printing
		//if (!gameOver)
		{
			for(int i=0;i< 20; i++) 
			{
				for (int j=0; j<79; j++)
				{
					cout << theGame[currentUserLevel][i][j]->getTileChar();
				}
				cout << endl;
			}
			cout << endl << "Dungeon Level : " << currentUserLevel+1 << endl;
			cout << "You = *" << endl;
		}



		



		
		//random enemy generation every 15 moves:
		turns++;
		if(turns%15 ==0)
		{
			vector <Enemy*> myvec;
			for (int j=0; j < number_of_enemies_per_level/3; j++) 
			{
				//the below enemyfactory call will scale the level of enemies relative to the level of the dungeon "i"
				myvec.push_back(EnemyFactory::instance().generateEnemy(2+currentUserLevel, currentUserLevel));
				myvec[j]->randomizePosition(complete_dungeon[currentUserLevel].get_grid_image());

				//put into enemy vec
				dungeon_enemies[currentUserLevel].push_back(myvec[j]);

				//store enemies into Tiles:
				theGame[currentUserLevel][myvec[j]->getyPos()][myvec[j]->getxPos()]->setUnitChar(myvec[j]->getDisplayChar());
				theGame[currentUserLevel][myvec[j]->getyPos()][myvec[j]->getxPos()]->setUnitHere(true);
			}
		}
		
	}
	

	system ("PAUSE"); //remove this at the end
	system("PAUSE"); //remove this at the end
	return 0;
}
	






