#include "polynomial_regression.h"

#include <cassert>


/// Constructs a polynomial regression of the given model complexity M.
ann::polynomial_regression
::
polynomial_regression
(
  size M_a
):M_m(M_a) //assign the M value
{
    //compute and assign the correct matrix-sizes
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
	// compute matrix A and vector b row by row (both in one loop)
    for (size i = 0; i <= M_m; i++) {
    	// compute the entries of matrix A in row i for every column
        for (size j = 0; j <= M_m; j++) {
        	//use an accumulator to realize the function that computes Ai,j 
            real accumulator_for_A = 0;
            for (size p = 1; p <= training_set_a.rows(); p++) {
                accumulator_for_A += pow(training_set_a.get(p - 1, 0), i + j);
            }
            A_m.set(i, j, accumulator_for_A);
        }
        // compute and assign the values for bi
        real accumulator_for_b = 0;
        for (size p = 1; p <= training_set_a.rows(); p++){
            accumulator_for_b += pow(training_set_a.get(p - 1, 0), i)*training_set_a.get(p-1,1);
        }
        b_m.set(i,0,accumulator_for_b);
    }
    // compute vector w (A*w = b => w = A^(-1)*b)
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
    // use an accumulator (y) to sum up w_m*x_a^(m) for all m's
    real y = 0;
    for(size m = 0; m <= M_m; m++){
        y += w_m.get(m,0) * pow(x_a,m);
    }
    return y;
}
