#include <stdio.h>
#include "matplotlibcpp.h"
#include "Eigen/Core"

namespace plt = matplotlibcpp;

using namespace Eigen;

// Euler based integrator
MatrixXf transition(MatrixXf A, MatrixXf x, MatrixXf B, double u, double delta_t)
{
    MatrixXf x_dot = A * x + B * u;
    MatrixXf x_new = x + x_dot*delta_t;
    return x_new;
}

int main()
{
    double t = 0.0;
    double t_final = 10.0f;
    double delta_t = 0.01f;
    int n = t_final/delta_t;
    double u = 1.0;

    MatrixXf A(3,3);
    A.setZero();
    A(0,0) = 0;
    A(0,1) = 0;
    A(0,2) = -1;
    A(1,0) = 1;
    A(1,1) = 0;
    A(1,2) = -3;
    A(2,0) = 0;
    A(2,1) = 1;
    A(2,2) = -3;

    MatrixXf B(3,1);
    B.setZero();
    B(0,0) = 1;
    B(1,0) = -5;
    B(2,0) = 1;

    // Single output matrix. Can be more if needed.
    MatrixXf y(1,1);
    y.setZero();

    // State matrix
    MatrixXf x(3,1);
    x.setZero();
    
    MatrixXf C(1,3);
    C.setZero();
    C(2) = 1;

    // for plotting
    std::vector<double> t_array(n), output_array(n);

    for (int i = 0; i < n; i++) {
        t_array.at(i) = t;
        
        // Select specifically the Y row you need.
        output_array.at(i) = y(0,0);

        x = transition(A, x, B, u, delta_t);
        y = (C*x);

        // printf("x_dot(0): %f, x_dot(1)=%f, x_dot(2)=%f\n", x_dot(0,0), x_dot(1,0), x_dot(2,0));
        // printf("x(0): %f, x(1)=%f, x(2)=%f\n", x(0,0), x(1,0), x(2,0));

        t = t + delta_t; 
    }

    plt::figure();
    plt::plot(t_array, output_array);
    plt::show();

    return 0;
}
