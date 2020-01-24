#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;


	class Player{

public:
	
	sf::RectangleShape player;
	
	Player(){

		player.setSize(sf::Vector2f(10,20));
		player.setFillColor(sf::Color::Green);
		player.setPosition(50,200);
		
		
	}
	void drawTo(sf::RenderWindow &TheGameWindow){
	
		TheGameWindow.draw(player);
	
	}



	
private:





}; 