#include "World.hpp"
#include "Painter.hpp"
#include <fstream>

// Длительность одного тика симуляции.
// Подробнее см. update()
// Изменять не следует
static constexpr double timePerTick = 0.001;

/**
 * Конструирует объект мира для симуляции
 * @param worldFilePath путь к файлу модели мира
 */
World::World(const std::string &worldFilePath)
{

    std::ifstream stream(worldFilePath);

    readFromStream(stream, topLeft);
    readFromStream(stream, bottomRight);
    physics.setWorldBox(topLeft, bottomRight);

    double radius;
    bool isCollidable;

    Point ballCenter;
    Velocity ballVelocity;
    Color ballColor;

    // Здесь не хватает обработки ошибок, но на текущем
    // уровне прохождения курса нас это устраивает
    while (stream.peek(), stream.good())
    {
        // Читаем координаты центра шара (x, y) и вектор
        // его скорости (vx, vy)
        readFromStream(stream, ballCenter);
        readFromStream(stream, ballVelocity);
        // Читаем три составляющие цвета шара
        readFromStream(stream, ballColor);
        // Читаем радиус шара
        stream >> radius;
        // Читаем свойство шара isCollidable, которое
        // указывает, требуется ли обрабатывать пересечение
        // шаров как столкновение. Если true - требуется.
        // В базовой части задания этот параметр
        stream >> std::boolalpha >> isCollidable;

        Ball ball{ballVelocity, ballCenter, ballColor, radius, isCollidable};
        balls.push_back(ball);
    }
}

/// @brief Отображает состояние мира
void World::show(Painter &painter) const
{
    // Рисуем белый прямоугольник, отображающий границу
    // мира
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    // Вызываем отрисовку каждого шара
    for (const Ball &ball : balls)
    {
        ball.draw(painter);
    }
}

/// @brief Обновляет состояние мира
void World::update(double time)
{
    /**
     * В реальном мире время течет непрерывно. Однако
     * компьютеры дискретны по своей природе. Поэтому
     * симуляцию взаимодействия шаров выполняем дискретными
     * "тиками". Т.е. если с момента прошлой симуляции
     * прошло time секунд, time / timePerTick раз обновляем
     * состояние мира. Каждое такое обновление - тик -
     * в physics.update() перемещаем шары и обрабатываем
     * коллизии - ситуации, когда в результате перемещения
     * один шар пересекается с другим или с границей мира.
     * В общем случае время не делится нацело на
     * длительность тика, сохраняем остаток в restTime
     * и обрабатываем на следующей итерации.
     */

    // учитываем остаток времени, который мы не "доработали" при прошлом update
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    physics.update(balls, ticks);
}

void World::readFromStream(std::istream &in, Point &point)
{
    in >> point.x >> point.y;
}

void World::readFromStream(std::istream &in, Velocity &velocity)
{
    Point vector;
    in >> vector.x >> vector.y;
    velocity.setVector(vector);
}

void World::readFromStream(std::istream &in, Color &color)
{
    double r, g, b;
    in >> r >> g >> b;
    color.setColor(r, g, b);
}
