///Francisco Rangel
///Rolando Cepeda
#include<iostream>
#include<time.h>
#include "gameGraph.h"
using namespace std;

int getRandom()
{
	srand(static_cast<int>(time(NULL)));
	return rand() % 3;
}

void buildBoard(gameGraph &world)
{
	world.addVertex("polar");
	world.addVertex("north");
	world.addVertex("east");
	world.addVertex("south");
	world.addVertex("west");

	world.addDirectedEdge("polar", "north");
	world.addDirectedEdge("polar", "east");
	world.addDirectedEdge("polar", "south");
	world.addDirectedEdge("polar", "west");

	world.addEdge("north", "east");
	world.addEdge("north", "south");
	world.addEdge("north", "west");
	world.addEdge("east", "south");
	world.addEdge("east", "west");
	world.addEdge("south", "west");
}

int main()
{
	gameGraph world;
	buildBoard(world);	

		cout << "At what direction do you want to start of with?" << endl;
		world.moving("polar");
		world.finalScore();
		
		system("pause");
	return 0;
}
