#pragma once

#include <functional>
#include <vector>
#include <tuple>
#include <exception>

template <class S>
class Problem {
  private:
    const size_t dimension;
    const double epsilon;
    const std::function<double (const S&)> fitnessEvaluator;
    const std::function<double (size_t)> dispersion;
    const std::function<double (size_t)> sparkFactor;
    const std::vector<std::function<S(S, int)>> movers;

  public:

    Problem(
        size_t dimensions,
        double epsilon,
        std::function<double (const S&)> fitness,
        std::function<double (size_t)> dispersion,
        std::function<double (size_t)> sparklingFactor
    );
    void initDimension(size_t dim, std::function<S(S, int)> mover);

    S solve(std::vector<S> startingPoints) const;
};


template <class S>
inline Problem<S>::Problem(
    size_t i_dimensions,
    double i_epsion,
    std::function<double( const S&)> fitnessFunction,
    std::function<double (size_t)> dispersionFunction,
    std::function<double (size_t)> sparklinkFunction
):
  dimension(i_dimensions),
  epsilon(i_epsion),
  fitnessEvaluator(fitnessFunction),
  dispersion(dispersionFunction),
  sparkFactor(sparklinkFunction),
  movers(i_dimensions)
{ };

template <class S>
inline void Problem<S>::initDimension(size_t dim, std::function<S(S, int)> mover) {
  if (dim > this->dimension) {
    throw std::exception();
  } else {
    this->movers[dim] = mover;
  }
}

double computeDispersion(double A, double curFitness, const std::vector<double> fitnesses, double epsilon);
double computeSparks(double m, double curFitness, const std::vector<double> fitnesses, double epsilon);


template <class S>
inline S Problem<S>::solve(std::vector<S> startingPoints) const {
  if (startingPoints.size() == 0) {
    throw std::exception();
  }

  std::vector<S> points(startingPoints);
  std::vector<double> fitnesses(startingPoints.size());

  for (size_t i = 0; i < points.size(); ++i) {
    fitnesses[i] = fitnessEvaluator(points[i]);
  }

  for (size_t i = 0 ; i < 10; ++i) {
    double currentDispersion = dispersion(i);
    double currentNbSparks = sparkFactor(i);
    for (size_t k = 0; k < points.size(); ++k) {

    }
  }
  return startingPoints[0];
}
