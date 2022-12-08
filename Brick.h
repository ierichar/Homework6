#ifndef BRICK_H
#define BRICK_H

#include "GameObject.h"

namespace gm {
    const short BRICK_WIDTH = 50;
    const short BRICK_HEIGHT = 25;

    struct BrickType
    {
        int hp;
        sf::Color col;

    };

    class Brick :
        public GameObject
    {
    private:
        sf::RectangleShape body;
        const BrickType* type;
        int hp; // set max hp in game settings
        bool isAlive;
    public:
        Brick(BrickType* t, const sf::Vector2f& position, const sf::Vector2f& size);
        virtual void update(sf::RenderWindow& window);
        virtual void render(sf::RenderWindow& window);
        virtual void setPosition(const sf::Vector2f& position);
        //virtual void move(const sf::Vector2f& force) override;
        void setAlive(const bool isAlive);
        const bool getAlive();
        void setHealth(const int hp);
        const int getHealth();
        void reset();
        ~Brick();

    };
}

#endif
