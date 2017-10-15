#ifndef __GRAPH_H_INCLUDED__
#define __GRAPH_H_INCLUDED__

#include<armadillo>
#include<string>

arma::mat build_adj_matrix(std::string);
void display(arma::mat);
arma::mat laplacian(arma::mat);

#endif
