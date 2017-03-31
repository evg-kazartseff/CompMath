//
// Created by evgenii on 22.03.17.
//

#ifndef MMN_MMN_H
#define MMN_MMN_H

#include <vector>
#include <cmath>


class equation {
public:
    double (*func) (std::vector<double>);
    equation(double (* function) (std::vector<double>));
};

class system_of_equations {
private:
    std::vector<equation> Pool_of_equations;
public:
    system_of_equations(std::vector<equation> pool);
    equation get_equation(unsigned int n);
};

class Partial_derivatives {
private:
    std::vector<std::vector<equation>> matrix_of_derivatives;
public:
    Partial_derivatives(std::vector<std::vector<equation>> matrix);
    equation get_cell(unsigned long i, unsigned long j);
};


class MMN {
public:
    system_of_equations *System;
    Partial_derivatives *MD;

    MMN(std::vector<equation> pool, std::vector<std::vector<equation>> matrix);
    ~MMN();
    int difference_vector(std::vector<double> &res, std::vector<double> &vector1, std::vector<double> &vector2);
    double vector_norm(std::vector<double> vec);
};

#endif //MMN_MMN_H
