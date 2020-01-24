
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

static int wayPoints[4][2] = 
{
	295, 184,
	1038, 210,
	751,620,
	315,559

};


class Plane{

	public:

		sf::Texture planeText;
		
		sf::Sprite plane;
		

	int x,y;
	float speed;
	float angle;
	float accel;
	int CurrentWaypoint;

	Plane() {
		
		speed = 0; 
		angle = 0;
		accel = 0.08;
		CurrentWaypoint = 0;
		
		planeText.loadFromFile("plane.png");
		plane.setTexture(planeText);
		plane.setOrigin(plane.getGlobalBounds().width / 2, plane.getGlobalBounds().height / 2);
		plane.setScale(0.2, 0.2);
		
	
	}
	//in order for the cars to move too waypoint.
	void MoveWayPoint()
	{
		int Xwp =  wayPoints[CurrentWaypoint][0]; //sets waypoint of x
		int Ywp =  wayPoints[CurrentWaypoint][1]; // sets waypoint of y

		float beta = angle-atan2(Xwp - x, -Ywp+y); 
		// makes for smoother turning 
		
		if(sin(beta)<0) angle+=0.017*speed;
		else angle -=0.017*speed;
	
		if((x - Xwp)*(x-Xwp)+(y- Ywp)*(y - Ywp) < 60*60) CurrentWaypoint=(CurrentWaypoint+1)%4; // the xy values of the cars will move towards the current waypoint

	}
	void move(){
	//allows the cars to move
	x = x + sin(angle)*speed;
	y = y - cos(angle)*speed;
	
	
	}

};