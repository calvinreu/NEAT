#pragma once

#include <math.h>


namespace ActFunc{
    extern double sigmoid(const double &x);
    extern double ReLU(const double &x);
    extern double binary(const double &x);
    extern double linear(const double &x);
    extern double BipolarSigmoid(const double &x);
    extern double absolute(const double &x);
    extern double LeCunTan(const double &x);
    extern double gaussian(const double &x);

   // typedef double (TanH)(const double&) double tanh(); 
}