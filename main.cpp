#include<iostream>
#include "graph.h"
#include "graph_models.h"

int main(int argc, char *argv[]){
	arma::mat adj_matrix = build_adj_matrix("graph_1");
	display(adj_matrix);
	arma::mat K_G = DeterministicKronecker(adj_matrix,2);
	/*
	arma::mat L_G = laplacian(adj_matrix);
	display(L_G);
	arma::mat T;
	arma::mat lambda;
	diagonalize(L_G,T,lambda);
	arma::mat C = T * lambda * T.t();
	*/
	display(K_G);
	return 0;
}
