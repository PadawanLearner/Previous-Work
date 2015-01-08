#include "DungeonLevel.h"
#include <cmath>  
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;


Dungeon::Dungeon(bool create, mt19937 mt1) //vector <vector<Tile> > level
{
	if( create == true)
	{

		for (int i=0; i < 20; i++)
		{
			vector<Tile> myvec;
			for (int j=0; j < 79; j++)
			{
				myvec.push_back(Tile());
				myvec[j].set_tile_char(' ');
			}

			grid.push_back(myvec);
		}

		mt = mt1;
		room_tile_count =0;
	}


}

int Dungeon::get_room_tile_count()
{
	return room_tile_count;
}

int Dungeon::get_level_wideness()
{
	return grid.size();
}

int Dungeon::get_level_tallness()
{
	return grid[0].size();
}


vector <vector<Tile> > Dungeon::getGrid()
{
	return grid;
}


void Dungeon::get_stairs_loc()
{
	for (int i=0; i < 20; i++)
	{
		for (int j=0; j < 79; j++)
		{
			if (grid[i][j].get_tile_char() == '>' )
			{
				cout << endl << "Downstairs located at: " << j+1 << ',' << i+1 << endl;
				xPosDownstairs = j+1;
				yPosDownstairs = i+1;
			}

			if (grid[i][j].get_tile_char() == '<')
			{
				cout << endl << "Upstairs located at: " << j+1 << ',' << i+1 << endl;
				xPosUpstairs = j+1;
				yPosUpstairs = i+1;
			}
		}

	}

}

int Dungeon::getxPosDownstairs()
{
	return xPosDownstairs;
}
int Dungeon::getyPosDownstairs()
{
	return yPosDownstairs;
}
int Dungeon::getxPosUpstairs()
{
	return xPosUpstairs;
}
int Dungeon::getyPosUpstairs()
{
	return yPosUpstairs;
}

vector<string> Dungeon::get_grid_image()
{

	vector<string> myVec;

	for (int i=0; i < 20; i++)
	{
		string myString = "";
		for (int j=0; j < 79; j++)
		{
			myString = myString + grid[i][j].get_tile_char();
		}
		myVec.push_back(myString);
	}

	return myVec;
}

void Dungeon::reset_grid()
{
	for (int i=0; i < 20; i++)
	{
		for (int j=0; j < 79; j++)
		{
			grid[i][j].set_tile_char(' ');
		}

	}
}

bool Dungeon::check_build_path(int room_w, int room_h, int x_pos, int y_pos)
{
	//build room in (-,-) direction, up and left
	if ( room_w < 0 && room_h < 0 )	
	{
		for (int i=0; i > room_h; i--)
		{
			for (int j=0; j > room_w; j--)
			{
					if (grid[y_pos+i][x_pos+j].get_tile_char() == '.' || 
						grid[y_pos+i-1][x_pos+j-1].get_tile_char() == '.' )
						return false;	                
			}
		}
	}

	//build room in (+,-) direction, down and left
	else if ( room_w < 0 && room_h > 0 )	
	{
		for (int i=0; i < room_h; i++)
		{
			for (int j=0; j > room_w; j--)
			{
					if (grid[y_pos+i][x_pos+j].get_tile_char() == '.' ||
						grid[y_pos+i+1][x_pos+j-1].get_tile_char() == '.')
						return false;	            
			}
		}
	}

	//build room in (-,+) direction, up and right
	else if ( room_w > 0 && room_h < 0 )	
	{
		for (int i=0; i > room_h; i--)
		{
			for (int j=0; j < room_w; j++)
			{
				
					if (grid[y_pos+i][x_pos+j].get_tile_char() == '.' ||
						grid[y_pos+i-1][x_pos+j+1].get_tile_char() == '.' )
						return false;
					              
			}
		}
	}

	//build room in (+,+) direction, down and right
	else 	
	{
		for (int i=0; i < room_h; i++)
		{
			for (int j=0; j < room_w; j++)
			{
					if (grid[y_pos+i][x_pos+j].get_tile_char() == '.' ||
						grid[y_pos+i+1][x_pos+j+1].get_tile_char() == '.')
						return false;
					
			}
		}
	}

	return true;
}

void Dungeon::create_room( int min_width, int max_width, int min_tall, int max_tall, int starting_x, int starting_y)
{
	//assign random room dimensions within our parameter specs
	
	int random_width = mt() % (max_width - min_width +1) + min_width; //wide

	int random_length = mt() % (max_tall - min_tall +1) + min_tall; //tall  //still getting errors here
	
	
	//area of room must be 16 square units atleast, if not re-do random dimensions
	while(  ( abs(random_length*random_width) < 16 ) ) 
	{
		random_width = mt() % (max_width - min_width +1) + min_width; //wide

		random_length = mt() % (max_tall - min_tall +1) + min_tall; //tall 
	}
	
	if(check_build_path(random_width, random_length, starting_x, starting_y))
	{
		//record starting x and y
		vector <int> myVec;
		myVec.push_back(starting_y);
		myVec.push_back(starting_x);
		random_coordinates.push_back(myVec);

		//build room in (-,-) direction, up and left
		if ( random_width < 0 && random_length < 0)	
		{
			for (int i=0; i > random_length; i--)
			{
				for (int j=0; j > random_width; j--)
				{
						grid[starting_y+i][starting_x+j].set_tile_char('.');
						room_tile_count++;
				}
			}
		}

		//build room in (+,-) direction, down and left
		else if ( random_width < 0 && random_length > 0 )	
		{
			for (int i=0; i < random_length; i++)
			{
				for (int j=0; j > random_width; j--)
				{
				
						grid[starting_y+i][starting_x+j].set_tile_char('.');
						room_tile_count++;
				}
			}
		}

		//build room in (-,+) direction, up and right
		else if ( random_width > 0 && random_length < 0 )	
		{
			for (int i=0; i > random_length; i--)
			{
				for (int j=0; j < random_width; j++)
				{
						grid[starting_y+i][starting_x+j].set_tile_char('.');
						room_tile_count++;
				}
			}
		}

		//build room in (+,+) direction, down and right
		else 	
		{
			for (int i=0; i < random_length; i++)
			{
				for (int j=0; j < random_width; j++)
				{
				
						grid[starting_y+i][starting_x+j].set_tile_char('.');
						room_tile_count++;
				}
			}
		}
	
	}

		
}

void Dungeon::pick_random_coords(int rand_num) 
{
	vector <int> myVec;
	//RANGE: 8 to 12 tall and 20 to 50 wide
	
	myVec.push_back( mt()  % (11 - 8 +1) + 8 ); //y-coord or TALLNESS

	myVec.push_back( mt() % (50 - 20 +1) + 20 ); //x-coord or WIDTH

	random_coordinates.push_back(myVec);

	/*
	---The below range picks coordinates towards the edges more frequently. Ideal for smaller levels
	//RANGE: 4 to 16 and 4 to 75 
	random_coordinates[0] = mt()  % (15 - 4 +1) + 4; //y-coord or TALLNESS
	random_coordinates[1] = mt() % (74 - 4 +1) + 4; //x-coord or WIDTH

	---The below range picks truely random coordinates from the entire map (weird rooms possibly)
	RANGE: 0 to 20 and 0 to 79 
	random_coordinates[0] = mt()  % (19 - 0 +1) + 0; //y-coord or TALLNESS
	random_coordinates[1] = mt() % (78 - 0 +1) + 0; //x-coord or WIDTH
	*/

}

bool Dungeon::assign_layout()
{
	//edge cases
	//THIS IS NOT ANCHORING.  this merely ensures we get a dimensionally randomized room on the edge
	//again, the room dimensions will be randomized rectangularly (between 4-10 units wide, and 4-8units tall) 
	create_room(4,10,4,8,(mt() % (68 - 10 +1) + 10),0);
	create_room(4,10, 4,8,0, (mt() % (11 - 4 +1) + 4));
	create_room(-10,-4,4,8, 78, (mt() % (11 - 4 +1) + 4));
	create_room( 4,10,-8,-4, (mt() % (68 - 10 +1) + 10), 19);
	

	//general cases -- all of these CAN become rooms, but may not
	pick_random_coords(mt());
	pick_random_coords(mt());
	pick_random_coords(mt());
	pick_random_coords(mt());
	pick_random_coords(mt());
	pick_random_coords(mt());

	//create the rooms above (assuming the path is clear, which is called in create room)
	for (int i=4; i < random_coordinates.size(); i++)
	{
		create_room(4,20,4,8,random_coordinates[i][1],random_coordinates[i][0]);
	}
	
	
	bool flag;

	//do we have enough tiles?
	if (get_room_tile_count() < 200)
	{
		reset_grid();
		return false;
	}

	//this ascending-sorts the random_coordinates that our rooms/tunnels are built off of
	sort_vector(); //used bc it makes tunnel paths look nicer. if not used, our tunnels may look crazy

	//create tunnels
	for (int i=0; i < random_coordinates.size(); i++)
	{
		if (!( i == random_coordinates.size()-1))
		{
			create_path(random_coordinates[i][1],random_coordinates[i][0],
				random_coordinates[i+1][1],random_coordinates[i+1][0]);
		}
	}

	//create upstairs
	flag = assign_upstairs();
	while (!(flag))
	{
		flag = assign_upstairs();
	}

	//create downstairs
	mt();
	flag = assign_downstairs();
	while (!(flag))
	{
		flag = assign_downstairs();
	}


	return true;
}

bool Dungeon::create_path( int start_x, int start_y, int start_x2, int start_y2)
{
	int x_diff = abs(start_x - start_x2);
	int y_diff = abs(start_y - start_y2);


	//build x tunnel in (+) ,right
	if (start_x < start_x2)
	{
		int i=0;
		for (i=0; i<x_diff; i++)
		{
			if (grid[start_y][start_x+i].get_tile_char() == ' ')
				grid[start_y][start_x+i].set_tile_char('#');
		}

		//now build y from here
		if (start_y < start_y2)
		{
			for (int j=0; j<y_diff; j++)  //build y tunnel  down(+)
			{
				if (grid[start_y+j][start_x+i].get_tile_char() == ' ')
					grid[start_y+j][start_x+i].set_tile_char('#');
			}
		}
		else // start_y > start_2
		{
			for (int j=0; j<y_diff; j++)  //build y tunnel  up(-)
			{
				if (grid[start_y-j][start_x+i].get_tile_char() == ' ')
					grid[start_y-j][start_x+i].set_tile_char('#');
			}
		}
	}

	else // start_x > start_x2
	{
		int i=0;
		for ( i=0; i<x_diff; i++) //build x in (-) direction, left
		{
			if (grid[start_y][start_x-i].get_tile_char() == ' ')
				grid[start_y][start_x-i].set_tile_char('#');
		}

		//now build y from here
		if (start_y < start_y2)
		{
			for (int j=0; j<y_diff; j++)  //build y tunnel  down(+)
			{
				if (grid[start_y+j][start_x-i].get_tile_char() == ' ')
					grid[start_y+j][start_x-i].set_tile_char('#');
			}
		}
		else // start_y > start_2
		{
			for (int j=0; j<y_diff; j++)  //build y tunnel  up(-)
			{
				if (grid[start_y-j][start_x-i].get_tile_char() == ' ')
					grid[start_y-j][start_x-i].set_tile_char('#');
			}
		}
	}


	return true;
}

void Dungeon::print_dungeon()
{

	//print lvl
	cout << endl;

	for (int i=0; i < grid.size(); i++) //tallness
	{
		for (int j=0; j < grid[i].size() ; j++) //width
		{
			cout << grid[i][j].get_tile_char();
		}

		cout << endl;
	}
	

}

bool Dungeon::assign_upstairs()
{
	int r_y=mt()  % (19 - 0 +1) + 0;
	

	int r_x=mt() % (78 - 0 +1) + 0;

	if (grid[r_y][r_x].get_tile_char() == '.')
	{
		grid[r_y][r_x].set_tile_char('<');
		xPosUpstairs = r_x;
		yPosUpstairs = r_y;
		return true;

	}
	else
		return false;

}

bool Dungeon::assign_downstairs()
{

	int r_y=mt()  % (19 - 0 +1) + 0;
	
	int r_x=mt() % (78 - 0 +1) + 0;

	if (grid[r_y][r_x].get_tile_char() == '.')
	{
		grid[r_y][r_x].set_tile_char('>');
		xPosDownstairs = r_x;
		yPosDownstairs = r_y;
		return true;

	}
	else
		return false;

}

void Dungeon::sort_vector()
{
	int i,j,flag=1;
	vector <int> temp;

	//sorted via area
	for (i=0; i < random_coordinates.size() && flag; i++)
	{
		flag=0;

		 for (j=0; j < (random_coordinates.size() -1); j++)
		 {
			 if (  random_coordinates[j+1][1]*random_coordinates[j+1][0]
			 < random_coordinates[j][1]*random_coordinates[j][0]  )
					{
						temp = random_coordinates[j];
						random_coordinates[j] = random_coordinates[j+1];
						random_coordinates[j+1]=temp;
						flag=1;
					}
		 }
	}
}

