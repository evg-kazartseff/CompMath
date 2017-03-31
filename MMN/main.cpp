#include <iostream>
#include <cmath>
#include <iomanip>
#include "MMN.h"
#include "Gays.h"

#define Number_of_equtions 2
#define Number_of_variables 2
#define eps 0.1

int main() {
    equation F1([] (std::vector<double> v) { return pow(v[0], 3) + pow(v[1], 2);});

    equation F2([] (std::vector<double> v) { return v[0] / v[1] + 1 ;});

   // equation F3([] (std::vector<double> v) { return 3 * pow(v[0], 2) - 4 * v[1] + pow(v[2], 2);});

    std::vector<equation> pool_equation;
    pool_equation.push_back(F1);
    pool_equation.push_back(F2);
   // pool_equation.push_back(F3);

    equation D00([] (std::vector<double> v) { return 3 * pow(v[0], 2); });
    equation D01([] (std::vector<double> v) { return 2 * v[1]; });
    //equation D02([] (std::vector<double> v) { return 2 * v[2]; });

    equation D10([] (std::vector<double> v) { return 1 / v[1]; });
    equation D11([] (std::vector<double> v) { return - (v[0] / pow(v[1], 2)); });
    //equation D12([] (std::vector<double> v) { return -4.0; });
/*
    equation D20([] (std::vector<double> v) { return 6 * v[0]; });
    equation D21([] (std::vector<double> v) { return -4.0 ; });
    equation D22([] (std::vector<double> v) { return 2 * v[2]; });
*/
    std::vector<std::vector<equation>> derivatives;
    derivatives.resize(Number_of_equtions);
    std::vector<equation> line0;
    line0.push_back(D00);
    line0.push_back(D01);
    //line0.push_back(D02);

    std::vector<equation> line1;
    line1.push_back(D10);
    line1.push_back(D11);
   // line1.push_back(D12);
/*
    std::vector<equation> line2;
    line2.push_back(D20);
    line2.push_back(D21);
    line2.push_back(D22);*/
    derivatives[0] = line0;
    derivatives[1] = line1;
    //derivatives[2] = line2;

    MMN mmn(pool_equation, derivatives);

    std::vector<double> var;
    var.resize(Number_of_variables);
    var[0] = -0.6;
    var[1] = 0.5;
    //var[2] = 0.5;

    std::vector<std::vector<double>> result_derivatives;
    result_derivatives.resize(Number_of_equtions);
    for (unsigned long i = 0; i < Number_of_equtions; ++i) {
        result_derivatives.at(i).resize(Number_of_variables);
    }

    std::vector<double> result_system;
    result_system.resize(Number_of_variables);

    std::vector<double> result_Gays;
    result_Gays.resize(Number_of_variables);
    double norm = 1.0;
    std::vector<double> res;
    res.resize(Number_of_variables);
    int iter = 0;
    for (iter = 0; norm > eps; ++iter) {
        for (unsigned long i = 0; i < Number_of_equtions; ++i) {
            for (unsigned long j = 0; j < Number_of_equtions; ++j) {
                result_derivatives[i][j] = mmn.MD->get_cell(i, j).func(var);
            }
        }

        for (unsigned int i = 0; i < Number_of_variables; ++i) {
            result_system[i] = mmn.System->get_equation(i).func(var);
        }

        int flg = gays(result_derivatives, result_system, result_Gays, Number_of_variables);
        if (flg != 0) {
            std::cout << "Err Gays" << std::endl;
            return -1;
        }

        for (int k = 0; k < Number_of_variables; ++k) {
            res[k] = var[k];
        }

        mmn.difference_vector(var, var, result_Gays);
        mmn.difference_vector(res, var, res);

        norm = mmn.vector_norm(res);

        std::cout << std::fixed << std::setprecision(12) <<  var[0] << " " << var[1] << std::endl;
    }

    std::cout << "Number of iteration: " << iter << std::endl;
}