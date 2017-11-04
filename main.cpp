// ANN_USE_MSVC was set by CMake to identify the Visual Studio compiler.
#ifdef ANN_USE_MSVC
// It needs this to be defined to make M_PI available when including cmath.
#define _USE_MATH_DEFINES
#endif //def ANN_USE_MSVC

#include "matrix.h"
#include "polynomial_regression.h"

#include <cmath>
#include <fstream>
#include <iostream>

// Declare short hands to the utilized types.
typedef ann::matrix matrix;
typedef ann::polynomial_regression regressor;
typedef regressor::real_t real_t;
typedef regressor::size_t size_t;


// This implements the function used to create training and test set for
// exercise 1.1c. This does not create the entire set. It merely computes t_p
// for a given x_p.
real_t unknown_function_1 (real_t x_a)
{
  // task: Return the properly computed value.
    return sin(x_a/2);
}

// This implements the function used to create training and test set for
// exercise 1.1e. This does not create the entire set. It merely computes t_p
// for a given x_p.
real_t unknown_function_2 (real_t x_a)
{
  // task: Return the properly computed value.
    if (x_a != 0){
        return sin(4*x_a/x_a);
    }
    return 0;

}

// Creates the training set demanded in exercise 1.1c.
// x_p and t_p are written in a single matrix to be able to return them handily.
matrix compute_training_set_1 (size_t P_a)
{
  // The first column shall contain input values xp and the second shall hold
  // corresponding output variables tp. Corresponding values must be in the same
  // row, of course.
  // Remember that p starts at 1, while indices start at 0.
  matrix set_l(P_a, 2);

  // task: Create the training set. Use unknown_function_1 for this.

  return set_l;
}

// Creates the test set demanded in exercise 1.1c.
// x_p and t_p are written in a single matrix to be able to return them handily.
matrix compute_test_set_1 (size_t P_a)
{
  // The first column shall contain input values xp and the second shall hold
  // corresponding output variables tp. Corresponding values must be in the same
  // row, of course.
  // Remember that p starts at 1, while indices start at 0.
  matrix set_l(P_a, 2);

  // task: Create the test set. Use unknown_function_1 for this.

  return set_l;
}


// Creates the training set demanded in exercise 1.1e.
// x_p and t_p are written in a single matrix to be able to return them handily.
matrix compute_training_set_2 (size_t P_a)
{
  // The first column shall contain input values xp and the second shall hold
  // corresponding output variables tp. Corresponding values must be in the same
  // row, of course.
  // Remember that p starts at 1, while indices start at 0.
  matrix set_l(P_a, 2);

  // task: Create the training set. Use unknown_function_2 for this.

  return set_l;
}

// Creates the test set demanded in exercise 1.1e.
// x_p and t_p are written in a single matrix to be able to return them handily.
matrix compute_test_set_2 (size_t P_a)
{
  // The first column shall contain input values xp and the second shall hold
  // corresponding output variables tp. Corresponding values must be in the same
  // row, of course.
  // Remember that p starts at 1, while indices start at 0.
  matrix set_l(P_a, 2);

  // task: Create the test set. Use unknown_function_2 for this.

  return set_l;
}


// Computes the error E(w) as defined in exercise 1.1.
// The weights w are part of the trained regressor given as first argument.
// The second argument is a set as returned by the compute_*_set_* functions above.
real_t compute_error (const regressor& regressor_a, const matrix& test_set_a)
{
  // task: Return the error for of the given regressor on the given test set.
}


// task: Nothing really, but you can look at the following code to see what it
// does before you execute it.
// You can also note than, that the value for M_max
// given on the exercise sheet was wrong - the correct one is used here as
// default.
// The files created here are compatible with gnuplot. Check what is in which
// column of the file to plot it properly.
int main(int argc, char** argv)
{
  // number of training examples: parameter 1, if given, else 11
  size_t P_l = argc > 1 ? (size_t)std::atoi(argv[1]) : 11;
  // maximum polynomal degree: parameter 2, if given, else 15
  size_t M_max_l = argc > 2 ? (size_t)std::atoi(argv[2]) : 15;

  // You can limit the scope of arbitrary code snippets with curly braces.
  {
    // Open a file stream to write errors to.
    std::ofstream function_1_error_out_l;
    function_1_error_out_l.open("function_1_error.txt", std::ios::out);

    // Iterate over all model complexities.
    for (size_t M_l = 0; M_l <= M_max_l; ++M_l)
    {
      // Create an object for polynomial regression with model complexity M.
      regressor regressor_l(M_l);
      // Create the training set.
      matrix training_set_l = compute_training_set_1(P_l);
      // Create the test set.
      matrix test_set_l = compute_test_set_1(P_l);

      // Train the regressor with the training set. Duh.
      regressor_l.train(training_set_l);

      // Compute error on training and test set and write to file.
      function_1_error_out_l
        << M_l << "\t"
        << compute_error(regressor_l, training_set_l) << "\t"
        << compute_error(regressor_l, test_set_l) << std::endl;
    }
  } // Everything inside is gone now.

  // Well, I'm sorry for having the almost same code here twice, it's bad, but I
  // didn't want to make this harder to read by passing functions as parameters.
  {
    std::ofstream function_2_error_out_l;
    function_2_error_out_l.open("function_2_error.txt", std::ios::out);

    for (size_t M_l = 0; M_l <= M_max_l; ++M_l)
    {
      regressor regressor_l(M_l);
      matrix training_set_l = compute_training_set_2(P_l);
      matrix test_set_l = compute_test_set_2(P_l);

      regressor_l.train(training_set_l);

      function_2_error_out_l
        << M_l << "\t"
        << compute_error(regressor_l, training_set_l) << "\t"
        << compute_error(regressor_l, test_set_l) << std::endl;
    }
  }

  // Return 0 to confirm that everything is fine.
  return 0;
}
