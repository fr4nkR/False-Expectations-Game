#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <conio.h>
#include <time.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
using namespace std;

class gameGraph
{
private:
	class vertex
	{
	public:
		string name;
		//bool dead;

		//List of all edges leaving this vertex
		vector<vertex*> neighbors;

		vertex(string x)
		{
			//dead = false;
			name = x;
		}
	};

	//For faster vertex lookups,
	//Replace this with a binary search tree (or hash table)
	vector<vertex*> vertexList;

	//Return the vertex with x as it's data field.
	//Return null if it doesn't exist.
	//O( n )  -- oooh slow, use a bst to make this faster 
	vertex * findVertex(string x)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->name == x)
				return vertexList[i];
		}
		return nullptr;
	}

	///////////Game specific stuff////////////////
	vertex * playerLocation;

	int lives = 3;
	int score = 0;

public:


	void addVertex(string x)
	{
		vertex * newVertex = new vertex(x);
		vertexList.push_back(newVertex);
	}

	void addDirectedEdge(string x, string y)
	{
		vertex * vertexX = findVertex(x);
		vertex * vertexY = findVertex(y);

		if (vertexX == nullptr || vertexY == nullptr)
		{
			cout << "Oh no!  You've hosed up!" << endl;
		}
		else
		{
			vertexX->neighbors.push_back(vertexY);
		}
	}

	void addEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	/////////////Game specific methods///////////////

	void setPlayerLocation(string x)
	{
		playerLocation = findVertex(x);
	}

	string getPlayerLocation()
	{
		return playerLocation->name;
	}


	int getRandom()
	{
		srand(static_cast<int>(time(NULL)));

		return rand() % 3;

	}

	bool dead() {
		if (lives == 0) {
			return true;
		}
		else return false;

	}

	void moving(string x) {
		vertex* p = findVertex(x);
		int c = 0;
		while (dead() == false)
		{
			c = 0;

			switch ((c = _getch())) {
			case KEY_UP:
				if (p->name == "north") {
					lives--;
					if (lives == 2)
					{
						if (getRandom() == 0)
						{
							cout << "You trip over some pieces of concrete that fell, you made some noice, you hear steps comming towards you, watch out!" << endl;
						}
						else if (getRandom() == 1)
						{
							cout << "You step over broken glass and make some noice, you can hear a maniac laugh at a distance " << endl;//case 2 1 life
						}
						else
						{
							cout << "You step over some electrified water from the broken pipelines, fortunatelly, nothing happened to you, but your reflexes made you jump and you made noise, you hear a 'SHHHH' at the distance" << endl;//case 3 1 life
						}
					}
					else if (lives == 1)
					{
						if (getRandom() == 0)
						{
							cout << "A small rock fall over your head, you say 'AUCH' because of the pain, KEEP IT QUIET!" << endl; //case 1 2 life
						}
						else if (getRandom() == 1)
						{
							cout << "You received a text message from the government declaring the city as a disaster-zone, it makes your phone vibrate, it emmits sound, you hear steps this time even closer!" << endl;//case 2 2 life
						}
						else
						{
							cout << "You ran into a wall and made noise, someone yells out loud 'Where #$%#$ are you?!?' " << endl;//case 3 2 life
						}
					}
					else
					{
						if (getRandom() == 0)
						{
							cout << "You tripped on your shoelaces, you fell and made noise. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 1 3 life;
						}
						else if (getRandom() == 1)
						{
							cout << "There is a lot of dust, so you cough. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 2 3 life;
						}
						else
						{
							cout << "You sneeze because of your allergies. TOO MUCH NOICE! THEY FIND YOU! " << endl;
						}
					}
					cout << "You only have " << lives << " injures left" << endl << endl;
					p = p->neighbors[getRandom()];
					move(p->name);

					if (lives != 0)
					{
						cout << "Choose which direction to go next" << endl;
					}
				}
				else {
					p = p->neighbors[getRandom()];
					score++;
					if (score != 0 && score % 5 == 0)
					{
						cout << endl << "The distance you travled so far is " << score << " floors down" << endl << endl;
					}
					cout << "Choose which direction to go next" << endl;
					moving(p->name);
				}
				break;
			case KEY_DOWN:
				if (p->name == "south") {
					lives--;
					if (lives == 2)
					{
						if (getRandom() == 0)
						{
							cout << "You trip over some pieces of concrete that fell, you made some noice, you hear steps comming towards you, watch out!" << endl;
						}
						else if (getRandom() == 1)
						{
							cout << "You step over broken glass and make some noice, you can hear a maniac laugh at a distance " << endl;//case 2 1 life
						}
						else
						{
							cout << "You step over some electrified water from the broken pipelines, fortunatelly, nothing happened to you, but your reflexes made you jump and you made noise, you hear a 'SHHHH' at the distance" << endl;//case 3 1 life
						}
					}
					else if (lives == 1)
					{
						if (getRandom() == 0)
						{
							cout << "A small rock fall over your head, you say 'AUCH' because of the pain, KEEP IT QUIET!" << endl; //case 1 2 life
						}
						else if (getRandom() == 1)
						{
							cout << "You received a text message from the government declaring the city as a disaster-zone, it makes your phone vibrate, it emmits sound, you hear steps this time even closer!" << endl;//case 2 2 life
						}
						else
						{
							cout << "You ran into a wall and made noise, someone yells out loud 'Where #$%#$ are you?!?' " << endl;//case 3 2 life
						}
					}
					else
					{
						if (getRandom() == 0)
						{
							cout << "You tripped on your shoelaces, you fell and made noise. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 1 3 life;
						}
						else if (getRandom() == 1)
						{
							cout << "There is a lot of dust, so you cough. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 2 3 life;
						}
						else
						{
							cout << "You sneeze because of your allergies. TOO MUCH NOICE! THEY FIND YOU! " << endl;
						}
					}
					cout << "You only have " << lives << " chances left" << endl << endl;
					p = p->neighbors[getRandom()];
					move(p->name);

					if (lives != 0)
					{
						cout << "Choose which direction to go next" << endl;
					}
				}
				else {
					p = p->neighbors[getRandom()];
					score++;
					if (score != 0 && score % 5 == 0)
					{
						cout << endl << "The distance you travled so far is " << score << " floors down" << endl << endl;
					}
					cout << "Choose which direction to go next." << endl;
					moving(p->name);
				}
				break;
			case KEY_LEFT:
				if (p->name == "west") {
					lives--;
					if (lives == 2)
					{
						if (getRandom() == 0)
						{
							cout << "You trip over some pieces of concrete that fell, you made some noice, you hear steps comming towards you, watch out!" << endl;
						}
						else if (getRandom() == 1)
						{
							cout << "You step over broken glass and make some noice, you can hear a maniac laugh at a distance " << endl;//case 2 1 life
						}
						else
						{
							cout << "You step over some electrified water from the broken pipelines, fortunatelly, nothing happened to you, but your reflexes made you jump and you made noise, you hear a 'SHHHH' at the distance" << endl;//case 3 1 life
						}
					}
					else if (lives == 1)
					{
						if (getRandom() == 0)
						{
							cout << "A small rock fall over your head, you say 'AUCH' because of the pain, KEEP IT QUIET!" << endl; //case 1 2 life
						}
						else if (getRandom() == 1)
						{
							cout << "You received a text message from the government declaring the city as a disaster-zone, it makes your phone vibrate, it emmits sound, you hear steps this time even closer!" << endl;//case 2 2 life
						}
						else
						{
							cout << "You ran into a wall and made noise, someone yells out loud 'Where #$%#$ are you?!?' " << endl;//case 3 2 life
						}
					}
					else
					{
						if (getRandom() == 0)
						{
							cout << "You tripped on your shoelaces, you fell and made noise. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 1 3 life;
						}
						else if (getRandom() == 1)
						{
							cout << "There is a lot of dust, so you cough. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 2 3 life;
						}
						else
						{
							cout << "You sneeze because of your allergies. TOO MUCH NOICE! THEY FIND YOU! " << endl;
						}
					}
					cout << "You only have " << lives << " chances left" << endl << endl;
					p = p->neighbors[getRandom()];
					move(p->name);
					if (lives != 0)
					{
						cout << "Choose which direction to go next" << endl;
					}
				}
				else {
					p = p->neighbors[getRandom()];
					score++;
					if (score != 0 && score % 5 == 0)
					{
						cout << endl << "The distance you travled so far is " << score << " floors down" << endl << endl;
					}
					cout << "Choose which direction to go next." << endl;
					moving(p->name);
				}
				break;
			case KEY_RIGHT:
				if (p->name == "east") {
		
					lives--;
					if (lives == 2)
					{
						if (getRandom() == 0)
						{
							cout << "You trip over some pieces of concrete that fell, you made some noice, you hear steps comming towards you, watch out!" << endl;
						}
						else if (getRandom() == 1)
						{
							cout << "You step over broken glass and make some noice, you can hear a maniac laugh at a distance " << endl;//case 2 1 life
						}
						else
						{
							cout << "You step over some electrified water from the broken pipelines, fortunatelly, nothing happened to you, but your reflexes made you jump and you made noise, you hear a 'SHHHH' at the distance" << endl;//case 3 1 life
						}
					}
					else if (lives == 1)
					{
						if (getRandom() == 0)
						{
							cout << "A small rock fall over your head, you say 'AUCH' because of the pain, KEEP IT QUIET!" << endl; //case 1 2 life
						}
						else if (getRandom() == 1)
						{
							cout << "You received a text message from the government declaring the city as a disaster-zone, it makes your phone vibrate, it emmits sound, you hear steps this time even closer!" << endl;//case 2 2 life
						}
						else
						{
							cout << "You ran into a wall and made noise, someone yells out loud 'Where #$%#$ are you?!?' " << endl;//case 3 2 life
						}
					}
					else
					{
						if (getRandom() == 0)
						{
							cout << "You tripped on your shoelaces, you fell and made noise. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 1 3 life;
						}
						else if (getRandom() == 1)
						{
							cout << "There is a lot of dust, so you cough. TOO MUCH NOICE! THEY FIND YOU! " << endl;// case 2 3 life;
						}
						else
						{
							cout << "You sneeze because of your allergies. TOO MUCH NOICE! THEY FIND YOU! " << endl;
						}
					}
					cout << "You only have " << lives << " chances left" << endl << endl;
					p = p->neighbors[getRandom()];
					move(p->name);
					if (lives != 0)
					{
						cout << "Choose which direction to go next" << endl;
					}
				}
				else {
					p = p->neighbors[getRandom()];
					score++;
					if (score != 0 && score % 5 == 0)
					{
						cout << endl << "The distance you travled so far is " << score << " floors down" << endl << endl;
					}
					cout << "Choose which direction to go next." << endl;
					moving(p->name);
				}
				break;
			default:
				moving(p->name); // not arrow
				//break;
			}
		}
	}


	void finalScore()
	{
		cout << "The cannibal from the mental hospital you work at finds you, eats your face, opens you up with a piece of glass and eats your intestines" << endl;
		cout << "YOU DIE! But don't worry, if you were to have gotten out of the building, you would've realized that your family had died when the earthquake happened, the apartments where you live collapsed" << endl;
		cout << "Sometimes is better to actually die than to loose your will to live, so be thankful for having been devored by the cannibal" << endl << endl;

		cout << "You walked down " << score << " floors" << endl << endl;
	}
};