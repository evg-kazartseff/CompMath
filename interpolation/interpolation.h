//
// Created by evgenii on 28.03.17.
//

#ifndef INTERPOLATION_INTERPOLATION_H
#define INTERPOLATION_INTERPOLATION_H

#include <cmath>
#include <vector>

typedef struct {
    double x;
    double y;
} point;

class interpolation {
private:
    unsigned int polynomial_degree;
    unsigned int number_of_nodes;
    double left;
    double right;
    std::vector<double> nodes_iterpolation;
    std::vector<double> value_nodes;
public:
    interpolation(double left, double right, unsigned int number_of_nodes, unsigned int polynomial_degree);
    void set_left(double left);
    double get_left();
    void set_right(double right);
    double get_right();
    void set_number_of_nodes(unsigned int NON);
    unsigned int get_number_of_nodes();
    void set_polynomial_degree(unsigned int PD);
    unsigned int get_polynomial_degree();
    void set_nodes_interpolation();
    void set_nodes_interpolation(std::vector<double> nodes);
    double get_node_interation(unsigned int number);

};

#endif //INTERPOLATION_INTERPOLATION_H
