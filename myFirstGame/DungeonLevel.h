#ifndef DUNGEON_LEVEL_H
#define DUNGEON_LEVEL_H

#include <random>
#include "Tile.h"
#include <vector>
#include <iostream>
#include <functional>
#include <ctime>
#include <chrono>
#include <string>


using namespace std;

class Dungeon
{
public:

	Dungeon(bool create, mt19937 mt1); //vector <vector<Tile> > level


	void print_dungeon();

	void create_room(int min_width, int max_width, int min_tall, int max_tall, int starting_x, int starting_y);

	//void pick_random_coords(mt19937 mt);
	void pick_random_coords(int rand_num);

	bool assign_layout();

	bool check_build_path(int room_w, int room_h, int x_pos, int y_pos);

	bool create_path( int start_x, int start_y, int start_x2, int start_y2);

	int get_room_tile_count();

	int get_level_wideness();

	int get_level_tallness();

	//bool assign_upstairs(mt19937 mt);
	bool assign_upstairs();

	void sort_vector();

	bool assign_downstairs();

	void reset_grid();

	void get_stairs_loc();

	vector<string> get_grid_image();

	int getxPosDownstairs();
	int getyPosDownstairs();
	int getxPosUpstairs();
	int getyPosUpstairs();

	vector <vector<Tile> > getGrid();


private:

	vector <vector<Tile> > grid; //coordinates

	int room_tile_count;

	mt19937 mt;
	
	vector <vector<int> > random_coordinates; //randomized points for room building
	
	int xPosDownstairs;
	int yPosDownstairs;
	int xPosUpstairs;
	int yPosUpstairs;


};





#endif