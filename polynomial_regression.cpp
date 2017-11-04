#include "polynomial_regression.h"

#include <cassert>


/// Constructs a polynomial regression of the given model complexity M.
ann::polynomial_regression
::
polynomial_regression
(
  size_t M_a
)
// task: You can try the constructor syntax here to initialize member variables
// (see the constuctor of ann::matrix). Or initialize your members in the
// function body. Just make sure all members have the right size (or value).
/*
: M_m(M_a), ... and the other members
*/
{
}

// Trains this regressor with the given training data as demanded in exercise
// 1.1c (and used in d and e).
// The matrix object holding training data is organized as in main:
// The first column shall contain input values xp and the second shall hold
// corresponding output variables tp. Corresponding values must be in the same
// row, of course.
void
ann::polynomial_regression
::
train
(
  const matrix& training_set_a
)
{
  // task: Implement training by creating the system of linear equations in the
  // form A * w = b as stated in exercise 1.1c; so fill the corresponding
  // members. Then solve the system elegantly, thus compute weights w.
}


// Predicts the output for a given input; using the trained weights.
ann::polynomial_regression::real_t
ann::polynomial_regression
::
y
(
  real_t x_a
) const
{
  // task: Use given input x and trained weights w to compute output y, as
  // stated by the first formula on the exercise sheet..
}
