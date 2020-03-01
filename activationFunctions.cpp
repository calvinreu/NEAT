#include "activationFunctions.hpp"

double ActFunc::sigmoid(const double &x) {
    return 1 / (1 + pow(M_E, -x));
}

double ActFunc::ReLU(const double &x) {
    if(x < 0) return 0;
    return x;
}

double ActFunc::binary(const double &x) {
    if (x < 0) return 0;
    return 1;
}

double ActFunc::linear(const double &x) { return x; }

double ActFunc::BipolarSigmoid(const double &x) {
    return (1 - pow(M_E, -x)) / (1 + pow(M_E, -x));
}

double ActFunc::absolute(const double &x) {
    return abs(x);
}

double ActFunc::LeCunTan(const double &x) {
    return 1.7159 * tanh((2 / 3 * x));
}

double ActFunc::gaussian(const double &x) {
    return pow(M_E, (-0.5 * x * x));
}