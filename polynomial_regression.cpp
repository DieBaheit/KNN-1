#include "polynomial_regression.h"

#include <cassert>


/// Constructs a polynomial regression of the given model complexity M.
ann::polynomial_regression
::
polynomial_regression
(
  size M_a
):M_m(M_a)
// @task: You can try the constructor syntax here to initialize member variables
// (see the constuctor of ann::matrix). Or initialize your members in the
// function body. Just make sure all members have the right size (or value).
/*
: M_m(M_a), ... and the other members
*/
{
	A_m = matrix(M_m+1,M_m+1);
	b_m = matrix(M_m+1,1);
	w_m = matrix(M_m+1,1);
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
  // @task: Implement training by creating the system of linear equations in the
  // form A * w = b as stated in exercise 1.1c; so fill the corresponding
  // members. Then solve the system elegantly, thus compute weights w.
    for (size i = 0; i <= M_m; i++) {
        for (size j = 0; j <= M_m; j++) {
            real accumulator_for_A = 0;
            for (size p = 1; p <= training_set_a.rows(); p++) {
                accumulator_for_A += pow(training_set_a.get(p - 1, 0), i + j);
            }
            A_m.set(i, j, accumulator_for_A);
        }
        real accumulator_for_b = 0;
        for (size p = 1; p <= training_set_a.rows(); p++){
            accumulator_for_b += pow(training_set_a.get(p - 1, 0), i)*training_set_a.get(p-1,1);
        }
        b_m.set(i,0,accumulator_for_b);
    }
    w_m = A_m.inverse()*b_m;

}


// Predicts the output for a given input; using the trained weights.
ann::polynomial_regression::real
ann::polynomial_regression
::
y
(
  real x_a
) const
{
  // @task: Use given input x and trained weights w to compute output y, as
  // stated by the first formula on the exercise sheet..
    size y = 0;
    for(size m = 0; m <= M_m; m++){
        y += w_m.get(m,0) * pow(x_a,m);
    }
    return y;
}
