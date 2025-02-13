#pragma once

#include "Color.hpp"
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball
{
  public:
    Ball(Velocity velocity, Point center, Color color, double radius, bool isCollidable);
    void setVelocity(const Velocity &velocity);
    Velocity getVelocity() const;
    void draw(Painter &painter) const;
    void setCenter(const Point &center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    bool getCollisionState() const;
    Color getColor() const;

  protected:
    Color color;
    Velocity velocity;
    Point center;
    double radius;
    double mass;
    bool isCollidable;
};

class Particle : public Ball
{
  public:
    Particle(Velocity velocity, Point center, Color color, double radius, bool isCollidable);
    Particle(const Ball &ball);
    void decreaseTTL(double time);
    bool isLive() const;

  private:
    double timeToLive;
};
