#include "Particle.hpp"

Particle::Particle() = default;

std::vector<Velocity> Particle::getVelocityParticles() const
{
    return velocityParticles;
}

std::vector<Point> Particle::getPositionParticles() const
{
    return positionParticles;
}

double Particle::getTTL() const
{
    return timeToLive;
}
