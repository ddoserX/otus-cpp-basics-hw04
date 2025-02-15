#pragma once

class Color
{
  public:
    Color();
    Color(double red, double green, double blue);
    double red() const;
    double green() const;
    double blue() const;
    void setColor(const double red, const double green, const double blue);

  private:
    double r{};
    double g{};
    double b{};
};
