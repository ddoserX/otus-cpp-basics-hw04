#pragma once

#include "Point.hpp"
#include "Velocity.hpp"
#include <vector>

class Particle
{
  private:
    std::vector<Velocity> velocityParticles;
    std::vector<Point> positionParticles;
    double timeToLive;

  public:
    Particle();
    std::vector<Velocity> getVelocityParticles() const;
    std::vector<Point> getPositionParticles() const;
    double getTTL() const;
};