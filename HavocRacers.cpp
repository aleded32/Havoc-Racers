#include <SFML\Graphics.hpp>
#include "stdafx.h"
#include <iostream>
#include "cars.h"
#include <sstream>
#include <cmath>

using namespace std;

//Global Variables
sf::RenderWindow TheGameWindow(sf::VideoMode(1280,720), "Havoc Racers");
sf::Color fillColour[4] = {sf::Color::Blue, sf::Color::Red, sf::Color::Yellow };

//sets i for all loops
int i;

	
//main

int main(){
	TheGameWindow.setFramerateLimit(60);

	//background sprite
	sf::Texture backText; 
	backText.loadFromFile("background.png");
	sf::Sprite background;
	background.setTexture(backText);
	background.setScale(0.7, 0.7);

	//healthpack sprite
	sf::Texture healthText; 
	healthText.loadFromFile("healthPack.png");
	sf::Sprite healthPack;
	healthPack.setTexture(healthText);
	healthPack.setScale(0.08f,0.08f);
	healthPack.setPosition(400,550);

	

	//plane sprite
	sf::Texture planeText;
	planeText.loadFromFile("plane.png");
	sf::Sprite player;
	player.setTexture(planeText);
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
	player.setScale(0.2f, 0.2f);

	
	

	

	
	
	

	

 
	sf::Event e;

	
	
	
	int x = 300, y = 500;
	float speed = 0, angle = 0; // current speed and angle of the plane
	float maxSpeed = 7; // max speed of plane
	float accel = 1, decel = 0.8; // accelatration and deccelaration of plane
	float Tspeed = 0.1; //turning speed of the plane
	int PlayerHealth = 300; // health of player


	
	

	
	
	
	//this set tbe x and y values for the planes
	Plane planes[3];
	
	for (i = 0; i < 3; i++)
	{
		planes[i].x = 300+i*100;
		planes[i].y = 500+i*80;
		planes[i].speed +=  accel *i;
		planes[i].speed += -accel * i;
		
	}
	

	//calling player class
	
	

	

	while(TheGameWindow.isOpen()){
		
		
		
	
		while(TheGameWindow.pollEvent(e)){
		
			switch (e.type)
			{
			case sf::Event::Closed:
				
				TheGameWindow.close();
				
			}
			//movement of player
			bool w = false, s = false, a = false, d =false;

			if(speed>=maxSpeed){

				speed = maxSpeed;
			}else if(speed<= -maxSpeed){
			
				speed = -maxSpeed;
			
			}else{
			
			speed = speed;
			
			}

			//if car moves foward and is less than the max speed accelatrate if less than 0 decelarate 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && speed<maxSpeed){

				w =true;
			
				
			
				
				speed += accel;
				
				
			
			}
			
			
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && speed>-maxSpeed){
					
			
					s = true;
					speed = speed - decel;
				
			}

			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			
			


					speed = 0;
				
			
			

			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && speed !=0){
			
				a = true;	
				angle = angle - Tspeed * speed/maxSpeed;
			
			}

			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && speed !=0){
			
				d=true;
				angle = angle + Tspeed *speed/maxSpeed;
			
			}

			//player and planes collision edge of wall
			
			

			if (x >= 1200)
			{

				speed = -2;
				x = 1200;
				PlayerHealth -= 2;


				//cout << "collision";

			}
			else if (x <= 150)
			{

				speed = -2;
				x = 150;
				PlayerHealth -= 2;

			}

			if (y >= 640)
			{

				speed = -2;
				y = 640;
				PlayerHealth -= 2;


				//cout << "collision";

			}
			else if (y <= 150)
			{

				speed = -2;
				y = 150;
				PlayerHealth -= 2;

			}

			for (i = 0; i < 3; i++) 
			{
				if (planes[i].x >= 1200)
				{

					planes[i].speed = -2;
					planes[i].x  = 1200;


					//cout << "collision";

				}
				else if (planes[i].x <= 150)
				{

					planes[i].speed = -2;
					planes[i].x = 150;

				}

				if (planes[i].y >= 910)
				{

					planes[i].speed = -2;
					planes[i].y = 910;


					//cout << "collision";

				}
				else if (planes[i].y <= 150)
				{

					planes[i]. speed = -2;
					planes[i].y = 150;

				}

			}

			//if player health reaches zero
			if(PlayerHealth <=0){
				TheGameWindow.close();
			}
				
			
			//cout << PlayerHealth;
			
			
			//collision with health pack
			if(PlayerHealth >= 300) PlayerHealth = 300;
			if(player.getGlobalBounds().intersects(healthPack.getGlobalBounds()))
			{
			
				healthPack.setPosition(-200,-200);
				PlayerHealth +=100;
			
			}

			//collision for planes
			for (int k = 0; k < 3; k++)
			{

				if (abs(player.getPosition().x - planes[k].plane.getPosition().x) < 35)
				{
					if (abs(player.getPosition().y - planes[k].plane.getPosition().y) < 115)
					{
						
						speed = 0;
						planes[k].speed = -1;
						PlayerHealth -= 2;
					
					}


				}
			
				
				//cout << sqrt((pow(planes[i].x, 2) - pow(x, 2)) + (pow(planes[i].y, 2) - pow(y, 2)));
			}
			
			
		
			
		}

		
		//health font
		sf::Font font;
		font.loadFromFile("BebasNeue-Regular.ttf");
		sf::Text HealthText;
		HealthText.setFont(font);
		HealthText.setCharacterSize(32);
		HealthText.setFillColor(sf::Color::White);
		HealthText.setString( "Health: " + to_string(PlayerHealth));
		

			
			for (i = 0; i < 3; i++)
			{
				planes[i].move();
				//cout << planes[i].CurrentWaypoint << "\n";
				
			}

		//sets the speed and new positon of the players car
			x = x + sin(angle) * speed; 
			y = y - cos(angle) * speed;
			
			player.setPosition(x,y);
			player.setRotation(angle*180/3.14592); // rotation will be set so that angle of direction will be * by 180/pi to postion the sprite rotation in coleration of direction of rotation.
			
			
			for (i = 0; i < 3; i++)
			{

				
				planes[i].plane.setPosition(planes[i].x, planes[i].y);
				planes[i].plane.setColor(fillColour[i]);
				planes[i].plane.setRotation(planes[i].angle * 180 / 3.14592);
				//cout << planes[i].x << " " << planes[i].y << "\n";			 


					if(planes[i].speed < maxSpeed)
				{
					planes[i].speed += planes[i].accel;		
					//cout << planes[i].speed << "\n";
				}
				
			}
			
			

			TheGameWindow.clear();
			
			TheGameWindow.draw(background);
			TheGameWindow.draw(player);
			
			

			for (i = 0; i < 3; i++) 
			{
				TheGameWindow.draw(planes[i].plane);
			planes[i].MoveWayPoint();
			
			
			}
			
			TheGameWindow.draw(healthPack);
			TheGameWindow.draw(HealthText);
			
			
			TheGameWindow.display();
	}

	return 0;
}
