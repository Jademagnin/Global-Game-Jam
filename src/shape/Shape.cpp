#include "Shape.hpp"

void Circle::draw(sf::RenderWindow& window, const sf::Color& color, const sf::Vector2f& position)
{
    sf::CircleShape circle(this->_radius);
    circle.setFillColor(color);
    circle.setPosition(position);
    window.draw(circle);
}


void Rectangle::draw(sf::RenderWindow& window, const sf::Color& color, const sf::Vector2f& position)
{
    sf::RectangleShape rectangle(this->_size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    window.draw(rectangle);
}

std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType type, float size)
{
    switch (type) {
        case ShapeType::Circle:
            return std::make_unique<Circle>(size);
        case ShapeType::Rectangle:
            return std::make_unique<Rectangle>(sf::Vector2f(size, size));
        default:
            throw std::invalid_argument("Invalid shape type");
    }
    return nullptr;
}
