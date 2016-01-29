#include "../lib/include/problem.h"

#include <array>
#include <iostream>
#include <cmath>
#include <vector>

typedef std::array<double , 2> Point;

double fitness(const Point& p) {
  return std::sqrt(p[0] * p[0] + p[1] * p[1]);
}

double dispersion(size_t) {
  return 10;
}

double sparkFactor(size_t) {
  return 1;
}

int main(void) {
  Problem<Point> p(2, 0.000001, fitness, dispersion, sparkFactor);
  Point initialPoint;
  initialPoint[0] = 5;
  initialPoint[1] = 6;
  std::vector<Point> initialPoints;
  initialPoints.push_back(initialPoint);
  Point result = p.solve(initialPoints);
  std::cout << result[0] << " - " << result[1] << std::endl;
}
