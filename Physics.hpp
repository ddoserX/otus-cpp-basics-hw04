#pragma once
#include "Ball.hpp"
#include <vector>

class Physics
{
  public:
    Physics(double timePerTick = 0.001);
    void setWorldBox(const Point &topLeft, const Point &bottomRight);
    void setGlobalParticles(std::vector<Particle> &articles);
    void update(std::vector<Ball> &balls, size_t ticks) const;

  private:
    void collideBalls(std::vector<Ball> &balls) const;
    void collideWithBox(std::vector<Ball> &balls) const;
    void move(std::vector<Ball> &balls) const;
    void move(std::vector<Particle> &particles) const;
    void processCollision(Ball &a, Ball &b, double distanceBetweenCenters2) const;

  private:
    std::vector<Particle> *globalParticles;
    Point topLeft;
    Point bottomRight;
    double timePerTick;
};
