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

  private:
    Color color;
    Velocity velocity;
    Point center;
    double radius;
    double mass;
    bool isCollidable;
};
