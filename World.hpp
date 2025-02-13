#pragma once
#include "Ball.hpp"
#include "Physics.hpp"
#include <string>
#include <vector>

class Painter;

class World
{
  public:
    World(const std::string &worldFilePath);
    void show(Painter &painter) const;
    void update(double time);

  private:
    void readFromStream(std::istream &in, Point &point);
    void readFromStream(std::istream &in, Velocity &velocity);
    void readFromStream(std::istream &in, Color &color);
    // Границы мира заданы углами прямоугольника
    Point topLeft;
    Point bottomRight;
    // Объект физического движка
    Physics physics;
    // Контейнер с шарами
    std::vector<Ball> balls;
    std::vector<Particle> particles;
    // Длина отрезка времени, который не был
    // учтен при прошлой симуляции. См. реализацию update
    double restTime = 0.;
};
