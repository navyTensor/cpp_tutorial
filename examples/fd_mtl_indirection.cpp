/* program to illustrate the use of mtl
 *
 * example taken from mtl document
 *
 * Rajeev Singh
 * 2013-04-17
 *
 */

// Filename: matrix_indirect.cpp (part of MTL4) #include <iostream>
#include <boost/numeric/mtl/mtl.hpp>

using namespace std;  

int main(int, char**)
{
    typedef mtl::dense2D<double> matrix;
    matrix A(5, 3);
    hessian_setup(A, 1.0);

    mtl::iset rows, cols;
    rows= 2, 0, 3; cols= 2, 1;

    cout << "rows = " << rows << ", cols = " << cols << "\n"   
         << "The sub-matrix A[{2, 0, 3}][{2, 1}] is\n" << A[rows][cols];

    mtl::matrix::indirect<matrix> B(A[rows][cols]);
    //B[0][0] = 10;
    cout << "B is\n" << B;
    cout << "A is\n" << A;

    return 0;
}
