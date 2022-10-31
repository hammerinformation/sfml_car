#include <SFML/Graphics.hpp>

void draw_line(sf::RenderWindow& window, const sf::Vector2f& v1, const sf::Vector2f& v2, const float& a)
{
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(v1.x + a, v1.y)),
        sf::Vertex(sf::Vector2f(v2.x + a, v2.y)),
    };
    line[0].color = sf::Color::Green;
    line[1].color = sf::Color::Green;
    window.draw(line, 2, sf::Lines);
}
void draw_car(sf::RenderWindow& window, const float& a)
{
    draw_line(window, sf::Vector2f(300, 500), sf::Vector2f(700, 500), a);
    draw_line(window, sf::Vector2f(700, 500), sf::Vector2f(700, 600), a);
    draw_line(window, sf::Vector2f(700, 600), sf::Vector2f(850, 600), a);
    draw_line(window, sf::Vector2f(850, 600), sf::Vector2f(850, 700), a);
    draw_line(window, sf::Vector2f(700, 700), sf::Vector2f(850, 700), a);
    draw_line(window, sf::Vector2f(300, 700), sf::Vector2f(700, 700), a);
    draw_line(window, sf::Vector2f(300, 700), sf::Vector2f(300, 500), a);
    sf::CircleShape l_wheel(50);
    l_wheel.setFillColor(sf::Color::Transparent);
    l_wheel.setOutlineThickness(1.f);
    l_wheel.setOutlineColor(sf::Color::Green);
    l_wheel.setPosition(350 + a, 702);
    sf::CircleShape r_wheel(50);
    r_wheel.setFillColor(sf::Color::Transparent);
    r_wheel.setOutlineThickness(1.f);
    r_wheel.setOutlineColor(sf::Color::Green);
    r_wheel.setPosition(700 + a, 702);
    window.draw(l_wheel);
    window.draw(r_wheel);
}


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Car");

    sf::Clock clock;
    float a{};
    float speed{250.f};
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        const float delta_time = clock.getElapsedTime().asSeconds();
        clock.restart();


        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            a += delta_time * speed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {

            a -= delta_time * speed;
        }

        window.clear(sf::Color::Black);

        draw_car(window, a);
        window.display();
    }

    return 0;
}
