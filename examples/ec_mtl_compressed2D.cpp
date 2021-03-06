/* program to illustrate the use of mtl
 *
 * example taken from mtl document
 *
 * Rajeev Singh
 * 2013-04-16
 *
 */

// File: compressed2D.cpp

#include <iostream>
#include <boost/numeric/mtl/mtl.hpp>

int main(int, char**)
{
    using namespace mtl;

    // CRS matrix
    compressed2D<double>   A(12, 12);

    // Laplace operator discretized on a 3x4 grid
    matrix::laplacian_setup(A, 3, 4);
    std::cout << "A is \n" << A;
    
    // Element access is allowed for reading
    std::cout << "A[3][2] is " << A[3][2] << "\n\n";
    std::cout << "A[3][1] is " << A[3][1] << "\n\n";
    
    // CCS matrix
    compressed2D<float, matrix::parameters<tag::col_major> > B(10, 10);

    // Assign the identity matrix times 3 to B
    B= 3;
    std::cout << "B is \n" << B << "\n";

    return 0;
}
