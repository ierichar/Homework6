#ifndef BALL_H
#define BALL_H

#include <math.h>

#include "GameObject.h"

namespace gm {
    const float BALL_RADIUS = 20.f;
    const float BALL_SPEED = 5.f;

    class Ball :
        public GameObject
    {
    private:
        sf::CircleShape body;
        sf::Vector2f velocity;
        float speed_multiplier;
    public:
        Ball(const sf::Vector2f& position, const float radius);
        virtual void update(sf::RenderWindow& window);
        virtual void render(sf::RenderWindow& window);

        virtual const sf::Vector2f& getPosition() const;
        virtual void setPosition(const sf::Vector2f& position);

        virtual void move(const sf::Vector2f& force) override;

        const sf::Vector2f& getVelocity() const;
        void setVelocity(const sf::Vector2f& velocity);

        void bounce(const sf::Vector2f& normalVector);

        // Vector Math Helper Functions
        const float calcMagnitude(const sf::Vector2f& vector);
        sf::Vector2f vScalarProduct(const float c, const sf::Vector2f & vector);
        const float dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2);
        void increaseSpeed();
    };
}

#endif // !CIRCLE_H
