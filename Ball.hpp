#pragma once

#include "Color.hpp"
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

#ifndef _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#endif

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
    bool isCollidable;
};
