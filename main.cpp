#include<iostream>
#include "graph.h"
#include "common.h"

int main(int argc, char *argv[]){
	arma::mat adj_matrix = build_adj_matrix("graph_1");
	arma::mat L_G = laplacian(adj_matrix);
	display(L_G);
	arma::mat T;
	arma::mat lambda;
	diagonalize(L_G,T,lambda);
	arma::mat C = T * lambda * T.t();
	display(C);
	return 0;
}
