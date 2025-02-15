#include "Ball.hpp"
#include <cmath>

Ball::Ball(Velocity velocity, Point center, Color color, double radius, bool isCollidable)
{
    this->velocity = velocity;
    this->center = center;
    this->color = color;
    this->radius = radius;
    this->mass = M_PI * std::pow(radius, 3) * 3 / 4;
    this->isCollidable = isCollidable;
}

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity &velocity)
{
    this->velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const
{
    return velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter &painter) const
{
    painter.draw(getCenter(), getRadius(), color);
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point &center)
{
    this->center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const
{
    return center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const
{
    return radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const
{
    return mass;
}

bool Ball::getCollisionState() const
{
    return isCollidable;
}

Color Ball::getColor() const
{
    return color;
}

Particle::Particle(Velocity velocity_, Point center_, Color color_, double radius_, bool isCollidable_)
    : Ball(velocity_, center_, color_, radius_, isCollidable_)
{
    timeToLive = 1000;
}

Particle::Particle(const Ball &ball)
    : Ball(ball.getVelocity().vector() * -1, ball.getCenter(), ball.getColor(), ball.getRadius() / 2., false)
{
    timeToLive = 1;
}

void Particle::decreaseTTL(double time)
{
    timeToLive -= time;
}

bool Particle::isLive() const
{
    return (timeToLive <= 0) ? false : true;
}
