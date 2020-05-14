#include "function.h"

using namespace oj;

Sphere::Sphere(double r, double p) : radius(r), pi(p)
{
  if (r <= 0 || p <= 0)
    setVolume(0);
  else
    setVolume(4.0 / 3.0 * p * r * r * r);
}

Cone::Cone(double r, double h, double p) : radius(r), height(h), pi(p)
{
  if (r <= 0 || h <= 0 || p <= 0)
    setVolume(0);
  else
    setVolume(1.0 / 3.0 * p * r * r * h);
}

Cuboid::Cuboid(double l, double w, double h) : length(l), width(w), height(h)
{
  if (l <= 0 || w <= 0 || h <= 0)
    setVolume(0);
  else
    setVolume(length * width * height);
}

Cube::Cube(double s) : Cuboid(s, s, s){};
