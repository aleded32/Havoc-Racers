#include <iostream>
#include <SFMl/Graphics.hpp>

using namespace std;


	class Wall{

public:
	
	sf::RectangleShape wall;

	Wall(){

		wall.setSize(sf::Vector2f(50,90));
		wall.setFillColor(sf::Color::Blue);
		wall.setPosition(400,300);
		
		
	}
	void drawTo(sf::RenderWindow &TheGameWindow){
	
		TheGameWindow.draw(wall);
	
	}



	
private:





}; 