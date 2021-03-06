/* program to illustrate the use of mtl
 *
 * example taken from mtl document
 *
 * Rajeev Singh
 * 2013-04-17
 *
 */

#include <iostream>
#include <boost/numeric/mtl/mtl.hpp>

int main(int, char**)
{
    using namespace mtl;

    double           array[][3]= {{1., 0., 3.},
                                  {4., 0., 6.},
                                  {7., 0., 9.},
                                  {0., 0., 0.}};
    dense2D<double>  A(array), B2, B3;

    // Creating a compression (reordering) matrix from a vector
    // (or an array respectively)
    int non_zero_rows[]= {0, 1, 2}, non_zero_columns[]= {0, 2};
    // To be sure, we give the number of columns for a consistent size!
    matrix::traits::reorder<>::type RR= matrix::reorder(non_zero_rows, 4),
                                    RC= matrix::reorder(non_zero_columns);
    std::cout << "A =\n" << A << "\nRR =\n" << RR << "\nRC =\n" << RC;    

    // Compress rows
    B2= RR * A;
    std::cout << "\nRR * A, i.e. compress row of A =\n" << B2;
    
    // Compress columns
    B3= B2 * trans(RC);
    std::cout << "\nB2 * trans(RC), i.e. compress columns of B2 =\n" << B3;
    
    // Decompress rows
    dense2D<double>  C1(trans(RR) * B3);
    std::cout << "\ntrans(RR) * B3, i.e. row decompression of B3 =\n" << C1;

    // Decompress columns
    dense2D<double>  C2(C1 * RC);
    std::cout << "\nC1 * RC, i.e. column decompression of C1 (should be A) =\n"
              << C2;

    return 0;
}
