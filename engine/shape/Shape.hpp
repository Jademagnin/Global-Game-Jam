// Classe de base pour les formes
class Shape {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual ~Shape() {}
};

// Implémentation de la classe Circle
class Circle : public Shape {
public:
    void draw(sf::RenderWindow& window) override {
        sf::CircleShape circle(50);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(100, 100);
        window.draw(circle);
    }
};

// Implémentation de la classe Rectangle
class Rectangle : public Shape {
public:
    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape rectangle(sf::Vector2f(120, 50));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(200, 200);
        window.draw(rectangle);
    }
};

// Factory pour créer des formes
class ShapeFactory {
public:
    enum class ShapeType { Circle, Rectangle };

    static std::unique_ptr<Shape> createShape(ShapeType type) {
        switch (type) {
            case ShapeType::Circle:
                return std::make_unique<Circle>();
            case ShapeType::Rectangle:
                return std::make_unique<Rectangle>();
            default:
                throw std::invalid_argument("Invalid shape type");
        }
    }
};