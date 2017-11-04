#ifndef ANN_MATRIX_H
#define ANN_MATRIX_H

#include <iostream>
#include <random>


/// namespace of this artificial neural networks course
namespace ann
{

/// Class ann::matrix implements a rectangular matrix.
/// Basic matrix operations are implemented, as well as pseudoinversion and
/// initialization with random values.
class matrix
{
  // - - - type definitions - - - - - - - - - - - - - - - - - - - - - - - - - - -

 public:
  /// Defines which ()floating point) type matrix elements shall be of.
  typedef long double real_t;

 private:
  /// This container type is used to internally store matrix elements.
  typedef std::vector<real_t> data_t;

 public:
  /// The type used for array access (ideally) fits the utilized container.
  typedef typename data_t::size_type size_t;
  /// The signed type used for array access fits the utilized container.
  typedef typename data_t::difference_type diff_t;

 private:
  /// The type of random engine used by matrix is defined here for convenience.
  /// This engine implemnts a 64-bit Mersenne Twister as suggested by Matsumoto
  /// and Nishimura in 2000.
  typedef std::mt19937_64 random_engine_t;

  // - - - member variables - - - - - - - - - - - - - - - - - - - - - - - - - - -

  /// number of rows
  size_t rows_m;
  /// number of columns
  size_t cols_m;

  /// data array holding matrix elements
  data_t data_m;

  /// This random device is used to seed the random engine.
  /// It is a non-deterministic uniform random number generator, if one is
  /// available on your system.
  std::random_device random_device_m;
  /// Each matrix object has its own (instance of the) random engine.
  random_engine_t random_engine_m;

 public:
  /// primary constructor
  /// Creates a matrix with the given number of columns and rows.
  /// All elements are initialized to the third parameter, which defaults to 0.
  /// This is also the default constructor, creating a matrix of size 0.
  matrix (size_t rows_a = 0, size_t cols_a = 0, real_t value_a = 0.0);

  /// copy constructor
  /// Constructs a matrix which is a copy of the given other matrix.
  matrix (const matrix& other_a);

  /// move constructor
  /// Constructs a matrix taking over resources of the given other matrix.
  matrix (matrix&& other_a);

  // There's no need to explicitly define a destructor. The implicitly defined
  // default is fine, because all member variables may be destroyed in a default
  // way (e.g. no explicit deallocation on the heap is needed).

  /// assignement operator
  /// Turns this matrix into a copies of the given other matrix.
  matrix& operator= (const matrix& other_a);

  /// move assignement operator
  /// Lets this matrix take over the resources of the given other matrix.
  matrix& operator= (matrix&& other_a);

  /// Returnes the number of rows in this matrix.
  size_t rows () const;
  /// Returnes the number of columns in this matrix.
  size_t cols () const;

  /// Accesses element (read/write) in the given row and column of the matrix.
  /// This version of the operator returns a non-const reference to allow
  /// modification of the matrix element.
  /// Warning: Parameters are considered indices starting at 0.
  /// E.g.: To access the element in the first row and second column use (0, 1).
  real_t& operator() (size_t row_a, size_t col_a);
  /// Accesses element (read only) in the given row and column of the matrix.
  /// This version of the operator returns a const reference to allow access to
  /// elements in case this matrix is const.
  /// Warning: Parameters are considered indices starting at 0.
  /// E.g.: To access the element in the first row and second column use (0, 1).
  const real_t& operator() (size_t row_a, size_t col_a) const;

  /// matrix addition
  /// Creates a new matrix as the sum of this and the given other matrix.
  matrix operator+ (const matrix& other_a) const;
  /// matrix addition, compound assignment
  /// Adds the given matrix to this matrix, storing the result in this.
  matrix& operator+= (const matrix& other_a);

  /// matrix multiplication
  /// Creates a new matrix as the product of this and the given other matrix.
  matrix operator* (const matrix& other_a) const;
  /// matrix multiplication, compound assignment
  /// Multiplies the given matrix with this matrix, storing the result in this.
  /// Warning: This may change the extents of this matrix.
  matrix& operator*= (const matrix& other_a);

  /// scalar multiplication
  /// Creates a copy of this matrix where all elements are scaled by the given
  /// factor.
  matrix operator* (real_t b_a) const;
  /// scalar multiplication, compound assignment
  /// Scales this matrix by the given factor.
  matrix& operator*= (real_t b_a);

  /// pseudoinverse
  /// Computes the pseudoinverse of this matrix using singular value decomposition.
  matrix inverse() const;

  /// Fills the matrix with pseudo-random values drawn from a uniform
  /// distribution over the interval defined by the given lower and upper bound,
  /// where the lower bound is inclusive and the upper is not.
  void fill_with_uniform_samples (real_t lower_bound_a, real_t upper_bound_a);

  /// Compares two matrices for equality.
  bool operator== (const matrix& other_a) const;

  /// Returns true, iff this is a Hermitian (or self-adjoint) matrix.
  bool is_hermitian () const;

 private:
  /// Computes the singular value decomposition of this matrix.
  /// This matrix is decomposed into U_a * W_a * Vc_a, where U and V* are unitary
  /// and W is a diagonal matrix.
  void singular_value_decomposition(matrix& U_a, matrix& Vc_a, data_t& W_a) const;

}; // class matrix

} // namespace ann

/// Overload of operator<< for writing matrices to output streams.
/// Must be declared outside of class matrix to achieve writing to stream in the
/// convenient fashion (stream << stuff).
std::ostream& operator<< (std::ostream& stream_a, const ann::matrix& matrix_a);

#endif //ANN_MATRIX_H
