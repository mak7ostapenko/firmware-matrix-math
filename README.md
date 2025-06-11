# Firmware 3d math library


The library provides a set of mathematical types and operations for 3D applications, including matrices, vectors, quaternions, and more. It is designed to be lightweight and efficient, suitable for use in embedded systems and robotics.


Matrix lib mainly based on [Px4](https://github.com/PX4/PX4-Autopilot/tree/main/src/lib/matrix) with minor custom changes. 
**NOTE:** License and copyrights are preserved from the original Px4 library.

It was created using these [instructions](https://stackoverflow.com/questions/24577084/forking-a-sub-directory-of-a-repository-on-github-and-making-it-part-of-my-own-r)

## Installation

Install test libraries:
```bash
sudo apt update
sudo apt install libgtest-dev libgmock-dev
```

## Usage Examples

Below are examples for the main types in the library. After reading these, you can start using the library effectively.


### Creating and Initialising Matrices

```cpp
#include "matrix/Matrix.hpp"

using matrix::Matrix;

// Create a 3x3 float matrix initialized to zero
Matrix<float, 3, 3> mat1;
mat1.setZero();

// Create a 3x3 matrix initialized to ones
Matrix<float, 3, 3> mat2;
mat2.setOne();

// Create a 3x3 identity matrix
Matrix<float, 3, 3> mat3;
mat3.setIdentity();
```

### Matrix Operations

```cpp
// Matrix addition, subtraction, and multiplication
Matrix<float, 3, 3> A;
Matrix<float, 3, 3> B;
A.setAll(2.0f);
B.setAll(3.0f);

Matrix<float, 3, 3> C = A + B; // element-wise addition
Matrix<float, 3, 3> D = A - B; // element-wise subtraction
Matrix<float, 3, 3> E = A * 2.0f; // scalar multiplication

// Matrix multiplication (dimensions must match)
Matrix<float, 3, 2> F;
F.setAll(1.0f);
Matrix<float, 2, 3> G;
G.setAll(2.0f);

Matrix<float, 3, 3> H = F * G;
```

### Accessing and Modifying Elements

```cpp
A(0, 0) = 5.0f;           // Set element at row 0, column 0
float val = A(0, 0);      // Get element at row 0, column 0

// Set entire row or column
A.setRow(1, 1.0f);        // Set all elements in row 1 to 1.0
A.setCol(2, 2.0f);        // Set all elements in column 2 to 2.0
```

### Transpose and Slicing

```cpp
auto At = A.transpose();  // Transpose matrix
auto row0 = A.row(0);     // Get first row as a ConstSlice
auto col1 = A.col(1);     // Get second column as a ConstSlice
```

### Utility Functions

```cpp
A.print();                // Print matrix to stdout
float max_val = A.max();  // Get the maximum element
float min_val = A.min();  // Get the minimum element
bool all_finite = A.isAllFinite();
```

---

### Vector

```cpp
#include "matrix/Vector.hpp"
using matrix::Vector;

// Create a 3-element float vector
Vector<float, 3> v1;
v1(0) = 1.0f; v1(1) = 2.0f; v1(2) = 3.0f;

// Construct from array
float data[3] = {4.0f, 5.0f, 6.0f};
Vector<float, 3> v2(data);

// Dot product, norm, normalization
float dot = v1 * v2;
float length = v1.norm();
v1.normalize();
```

---

### Vector3

```cpp
#include "matrix/Vector3.hpp"
using matrix::Vector3f;

// Create with components
Vector3f a(1.0f, 2.0f, 3.0f);
Vector3f b(2.0f, 1.0f, 0.0f);

// Cross product
Vector3f c = a.cross(b);

// Accessing xy components
auto xy = a.xy();

// Overloaded operators
Vector3f d = a + b;
float dp = a * b; // dot product
```

---

### Quaternion

```cpp
#include "matrix/Quaternion.hpp"
using matrix::Quatf;
using matrix::Vector3f;

// Default = identity quaternion
Quatf q1;

// From array
float arr[4] = {1, 0, 0, 0};
Quatf q2(arr);

// From axis-angle
Vector3f axis(1, 0, 0);
float angle = 3.14159f;
matrix::AxisAnglef aa(axis, angle);
Quatf q3(aa);

// Rotate vector
Vector3f v(1, 0, 0);
Vector3f v_rot = q3.rotateVector(v);

// Quaternion multiplication and inversion
Quatf q4 = q1 * q2;
Quatf q_inv = q1.inversed();
```

---

### SquareMatrix

```cpp
#include "matrix/SquareMatrix.hpp"
using matrix::SquareMatrix3f;
using matrix::Vector3f;

// Create identity, diagonal, or invert matrix
SquareMatrix3f I = matrix::eye<float, 3>();
SquareMatrix3f A;
A.setAll(2.0f);

// Set diagonals
Vector3f diag(4.f, 5.f, 6.f);
SquareMatrix3f D = matrix::diag<float, 3>(diag);

// Inverse
SquareMatrix3f invA = matrix::inv(A);

// Extract diagonal, trace
auto diagVec = A.diag();
float tr = A.trace();
```

---

### AxisAngle

```cpp
#include "matrix/AxisAngle.hpp"
using matrix::AxisAnglef;
using matrix::Vector3f;

// From vector (angle = norm, axis = direction)
Vector3f vec(0.1f, 0.2f, 0.3f);
AxisAnglef aa1(vec);

// From axis and angle
AxisAnglef aa2(Vector3f(1, 0, 0), 1.57f);

// Get axis and angle
Vector3f axis = aa2.axis();
float angle = aa2.angle();
```

---

### Euler

```cpp
#include "matrix/Euler.hpp"
using matrix::Eulerf;

// Default (all angles zero)
Eulerf e1;

// From angles
Eulerf e2(0.1f, 0.2f, 0.3f);

// From rotation matrix or quaternion
// Dcmf R; // Assume R is defined
// Eulerf e3(R);
// Quatf q; // Assume q is defined
// Eulerf e4(q);

// Access angles
float roll = e2.phi();
float pitch = e2.theta();
float yaw = e2.psi();
```

---

For more, see the source of each type in the [matrix directory](https://github.com/mak7ostapenko/firmware-3d-math-library/tree/main/matrix).


## License
This library is licensed under the BSD 3-Clause License as original Px4 library. See the [LICENSE](LICENSE) file for details.