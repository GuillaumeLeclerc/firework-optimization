#include "../include/problem.h"

#include <exception>

template <class S>
Problem<S>::Problem(
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
void Problem<S>::initDimension(size_t dim, std::function<S(S, int)> mover) {
  if (dim > this->dimension) {
    throw std::exception();
  } else {
    this->movers[dim] = mover;
  }
}


template <class S>
std::tuple<double, S>  Problem<S>::solve(std::vector<S> startingPoints) const {
  if (startingPoints.size() == 0) {
    throw std::exception();
  }
  std::tuple<double, S> result;
  result[0] = 0.0;
  return result;
}
