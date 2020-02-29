#include "activationFunctions.hpp"

double AktFunc::sigmoid(const double &x) {
    return 1 / (1 + pow(M_E, -x));
}

double AktFunc::ReLU(const double &x) {
    if(x < 0) return 0;
    return x;
}

double AktFunc::binary(const double &x) {
    if (x < 0) return 0;
    return 1;
}

double AktFunc::linear(const double &x) { return x; }

double AktFunc::BipolarSigmoid(const double &x) {
    return (1 - pow(M_E, -x)) / (1 + pow(M_E, -x));
}

double AktFunc::absolute(const double &x) {
    return abs(x);
}

double AktFunc::LeCunTan(const double &x) {
    return 1.7159 * tanh((2 / 3 * x));
}

double AktFunc::gaussian(const double &x) {
    return pow(M_E, (-0.5 * x * x));
}