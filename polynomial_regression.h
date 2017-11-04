#ifndef ANN_POLYNOMIAL_REGRESSION_H
#define ANN_POLYNOMIAL_REGRESSION_H

#include "matrix.h"

#include <vector>

namespace ann
{

// Implemnts polynomial regression with arbitrary model complexity.
class polynomial_regression
{
 public:
  // Declare some types used by this class.
  typedef matrix::real_t real_t;
  typedef matrix::size_t size_t;
  typedef std::vector<real_t> data_t;

  /// Constructs a polynomial regression of the given model complexity M.
  polynomial_regression(size_t M_a);

  // Trains this regressor with the given training data as demanded in exercise
  // 1.1c (and used in d and e).
  // The matrix object holding training data is organized as in main:
  // The first column shall contain input values xp and the second shall hold
  // corresponding output variables tp. Corresponding values must be in the same
  // row, of course.
  void train (const matrix& training_set_a);

  // Predicts the output for a given input; using the trained weights.
  real_t y (real_t x_a) const;

 private:
  // Member variables known form the exercise sheet.
  size_t M_m;
  matrix A_m;
  matrix b_m;
  matrix w_m;
};

}

#endif // ANN_POLYNOMIAL_REGRESSION_H
