//
// Created by evgenii on 28.03.17.
//

#include "interpolation.h"


void interpolation::set_left(double left) {
    this->left = left;
}

double interpolation::get_left() {
    return this->left;
}

void interpolation::set_right(double right) {
    this->right = right;
}

double interpolation::get_right() {
    return this->right;
}

interpolation::interpolation(double left, double right, unsigned int number_of_nodes, unsigned int polynomial_degree) {
    this->set_polynomial_degree(polynomial_degree);
    this->set_number_of_nodes(number_of_nodes);
    this->set_left(left);
    this->set_right(right);
    this->set_nodes_interpolation();
}

void interpolation::set_number_of_nodes(unsigned int NON) {
    this->number_of_nodes = NON;
}

unsigned int interpolation::get_number_of_nodes() {
    return this->number_of_nodes;
}

void interpolation::set_polynomial_degree(unsigned int PD) {
    this->polynomial_degree = PD;
}

unsigned int interpolation::get_polynomial_degree() {
    return this->polynomial_degree;
}

void interpolation::set_nodes_interpolation() {
    this->nodes_iterpolation.resize(get_number_of_nodes());
    double difference = get_right() - get_left();
    double delta = difference / (get_number_of_nodes() - 1);
    for (int i = 0; i < get_number_of_nodes(); ++i) {
        this->nodes_iterpolation[i] = get_left() + i * delta;
    }
}

void interpolation::set_nodes_interpolation(std::vector<double> nodes) {
    this->nodes_iterpolation = nodes;
}

double interpolation::get_node_interation(unsigned int number) {
    return this->nodes_iterpolation.at(number);
}
