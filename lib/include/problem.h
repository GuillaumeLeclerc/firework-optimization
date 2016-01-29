#pragma once

#include <functional>
#include <vector>
#include <tuple>

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

    std::tuple<double, S> solve(std::vector<S> startingPoints) const;
};
