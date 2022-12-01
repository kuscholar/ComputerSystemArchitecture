// CudaTestRun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include "./test_cuda_kernel.cuh"
//
//int main()
//{
//    // Initialize arrays A, B, and C.
//    double A[3], B[3], C[3];
//
//    // Populate arrays A and B.
//    A[0] = 5; A[1] = 8; A[2] = 3;
//    B[0] = 7; B[1] = 6; B[2] = 4;
//
//    // Sum array elements across ( C[0] = A[0] + B[0] ) into array C using CUDA.
//    kernel(A, B, C, 3);
//
//    // Print out result.
//    std::cout << "C = " << C[0] << ", " << C[1] << ", " << C[2] << std::endl;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <conio.h>
#include <stdio.h>
#include "calculate.h"
#include "cuda_helper.h"
#include "matrix.h"
#include "timer.h"
#include <iostream>

void ShowMatrix(const char* name, Matrix* data)
{
    fprintf(stdout, "[%s]\n", name);
    data->Show();
    fprintf(stdout, "\n");
}

int main(int argc, char** argv)
{
    int matrixSize = 16;
    printf("\n----------------------------------------\n");
    CudaDeviceList();
    printf("\n----------------------------------------\n");
    // prepare
    Timer timer = Timer();
    printf("size = %dx%d\n\n", matrixSize, matrixSize);
    Matrix m(matrixSize, 1);
    Matrix n(matrixSize, 2);
    Matrix r_cpu(matrixSize, 0);
    Matrix r_gpu(matrixSize, 0);
    // CPU
    timer.start();
    DotProductByCPU(&m, &n, &r_cpu);
    timer.stop();
    printf("[CPU]\n");
    timer.show();
    // GPU
    timer.start();
    DotProductByGPU(&m, &n, &r_gpu);
    timer.stop();
    printf("[GPU]\n");
    timer.show();
    // show data
    ShowMatrix("m", &m);
    ShowMatrix("n", &n);
    ShowMatrix("r_cpu", &r_cpu);
    ShowMatrix("r_gpu", &r_gpu);
    printf("\n----------------------------------------\n");
    fflush(stdout);
    printf("Press any key to continue.\n");
    _getch();
    //cin.get();
    return 0;
}
