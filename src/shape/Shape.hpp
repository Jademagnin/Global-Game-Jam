/*
** EPITECH PROJECT, 2023
** Global-Game-Jam
** File description:
** Main.cpp
*/

#include <SFML/Graphics.hpp>
#include <iostream>

// Base class for all shapes
class Shape {
    public:
        virtual void draw(sf::RenderWindow& window, const sf::Color& color, const sf::Vector2f& position) = 0;
        virtual ~Shape() {}
};

// Implementation of Circle
class Circle : public Shape {
    public:
        Circle(float radius) : _radius(radius) {}
        void draw(sf::RenderWindow& window, const sf::Color& color, const sf::Vector2f& position) override;
    private:
        float _radius;
};

// Implementation of Rectangle
class Rectangle : public Shape {
    public:
        Rectangle(const sf::Vector2f& size) : _size(size) {}
        void draw(sf::RenderWindow& window, const sf::Color& color, const sf::Vector2f& position) override;
    private:
        sf::Vector2f _size;
};

// Factory Design to create shapes
class ShapeFactory {
    public:
        enum class ShapeType {
            Circle,
            Rectangle
        };

        static std::unique_ptr<Shape> createShape(ShapeType type, float size);
};
