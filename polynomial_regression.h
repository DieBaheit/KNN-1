#ifndef ANN_POLYNOMIAL_REGRESSION_H
#define ANN_POLYNOMIAL_REGRESSION_H

#include "matrix.h"

#include <vector>

namespace ann
{

/// Implemnts polynomial regression with arbitrary model complexity.
class polynomial_regression
{
 public:
  // Declare some types used by this class.
  typedef matrix::real real;
  typedef matrix::size size;

  /// Constructs a polynomial regression of the given model complexity M.
  polynomial_regression(size M_a);

  /// Trains this regressor with the given training data as demanded in exercise
  /// 1.1c (and used in d and e).
  /// The matrix object holding training data is organized as in main:
  /// The first column shall contain input values xp and the second shall hold
  /// corresponding output variables tp. Corresponding values must be in the same
  /// row, of course.
  void train (const matrix& training_set_a);

  /// Predicts the output for a given input; using the trained weights.
  real y (real x_a) const;

 private:
  // Member variables known from the exercise sheet.
  /// Model complexity
  size M_m;
  /// Matrix component of the system of linear equations solved to train this model
  matrix A_m;
  /// Vector component of the system of linear equations solved to train this model
  matrix b_m;
  /// Trainable weights of this model
  matrix w_m;
};

}

#endif // ANN_POLYNOMIAL_REGRESSION_H
