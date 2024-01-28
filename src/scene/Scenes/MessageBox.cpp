/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** MessageBox
*/

#include "MessageBox.hpp"

#define POINTS 10
sf::Shape& RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius, const sf::Color& Col, float Outline, const sf::Color& OutlineCol)
{
	sf::Shape* rrect=new sf::Shape();
	rrect->SetOutlineWidth(Outline);
	float X=0,Y=0;
	for(int i=0; i<POINTS; i++)
	{
		X+=radius/POINTS;
		Y=sqrt(radius*radius-X*X);
		rrect->AddPoint(X+x+rectWidth-radius,y-Y+radius,Col,OutlineCol);
	}
	Y=0;
	for(int i=0; i<POINTS; i++)
	{
		Y+=radius/POINTS;
		X=sqrt(radius*radius-Y*Y);
		rrect->AddPoint(x+rectWidth+X-radius,y+rectHeight-radius+Y,Col,OutlineCol);
	}
	X=0;
	for(int i=0; i<POINTS; i++)
	{
		X+=radius/POINTS;
		Y=sqrt(radius*radius-X*X);
		rrect->AddPoint(x+radius-X,y+rectHeight-radius+Y,Col,OutlineCol);
	}
	Y=0;
	for(int i=0; i<POINTS; i++)
	{
		Y+=radius/POINTS;
		X=sqrt(radius*radius-Y*Y);
		rrect->AddPoint(x-X+radius,y+radius-Y,Col,OutlineCol);
	}
	return *rrect;
}

MessageBox::MessageBox(sf::RenderWindow &window,
    const std::string title, const std::string message, const sf::Vector2f &position,
    const sf::Vector2i &size): _window(window), _position(position), _size(size)
{
    const sf::Vector2f pos = sf::Vector2f(position.x + size.x / 2, position.y + size.y / 2);
    const int textSize = (20 * message.size()) / 2;
    const sf::Vector2f textPos = sf::Vector2f(pos.x - textSize / 2, pos.y - 20 / 2);

    // Topbar
    _topBar.setSize(sf::Vector2f(size.x, 30));
    _topBar.setFillColor(sf::Color(36, 93, 218)); // Adjust color
    _topBar.setOutlineColor(sf::Color(0, 0, 0)); // Adjust color
    _topBar.setOutlineThickness(2);
    _topBar.setPosition(position);

    sf::Texture texture;
    sf::Texture textureCopy = texture;

    // Body
    _body.setSize(sf::Vector2f(size.x, size.y));
    _body.setFillColor(sf::Color(240, 240, 240)); // Adjust color
    _body.setOutlineColor(sf::Color(0, 0, 0)); // Adjust color
    _body.setOutlineThickness(2);
    _body.setPosition(position);

    _title = new Text(title, sf::Vector2f(pos.x - (title.size() * 20) / 2, position.y + 10), 20, sf::Color::Black); // Adjust color
    _text = new Text(message, textPos, 20, sf::Color::Black); // Adjust color

    sf::Rect _topBarRect = _topBar.getGlobalBounds();
    sf::Rect _titleRect = _title->getText().getGlobalBounds();
    _title->setPosition(sf::Vector2f(_topBarRect.left + _topBarRect.width / 2, _topBarRect.top + _topBarRect.height / 2 - _titleRect.height / 2));


    // Icon
    // _icon = new Icon("assets/icons/Icon.png", sf::Vector2f(position.x + 10, position.y + 10), sf::Vector2f(20, 20));
}

MessageBox::~MessageBox()
{
}

void MessageBox::render(sf::RenderWindow &window)
{
    window.draw(_body);
    window.draw(_topBar);
    _text->draw(window);
    _title->draw(window);
}

void MessageBox::processEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
            _window.close();
    }
}
