//
// Created by evgenii on 22.03.17.
//

#include "MMN.h"


equation::equation(double (*function)(std::vector<double>)) {
    func = function;
}

equation system_of_equations::get_equation(unsigned int n) {
    return this->Pool_of_equations.at(n);
}

system_of_equations::system_of_equations(std::vector<equation> pool) {
    this->Pool_of_equations = pool;
}

Partial_derivatives::Partial_derivatives(std::vector<std::vector<equation>> matrix) {
    this->matrix_of_derivatives = matrix;
}

equation Partial_derivatives::get_cell(unsigned long i, unsigned long j) {
    return this->matrix_of_derivatives.at(i).at(j);
}

MMN::MMN(std::vector<equation> pool, std::vector<std::vector<equation>> matrix) {
    this->System = new system_of_equations(pool);
    this->MD = new Partial_derivatives(matrix);
}

MMN::~MMN() {
    delete this->System;
    delete this->MD;
}

int MMN::difference_vector(std::vector<double> &res, std::vector<double> &vector1,
                           std::vector<double> &vector2) {
        if (vector1.size() != vector2.size()) {
            return -1;
        }
        else if (vector1.size() != res.size()) {
            return -1;
        }
        for (int i = 0; i < vector1.size(); i++) {
            res[i] = vector1[i] - vector2[i];
        }
        return 0;
}

double MMN::vector_norm(std::vector<double> vec) {
        double maximum = 0.0;
        if (vec.size() > 0) {
            maximum = std::abs(vec[0]);
            for (int i = 1; i < vec.size(); ++i) {
                if (std::abs(vec[i]) > maximum) {
                    maximum = std::abs(vec[i]);
                }
            }
        }
        return maximum;
}
