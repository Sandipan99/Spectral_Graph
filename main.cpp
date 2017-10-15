#include<iostream>
#include "graph.h"
#include "common.h"

int main(int argc, char *argv[]){
	arma::mat adj_matrix = build_adj_matrix("graph_1");
	display(adj_matrix);
	arma::mat L_G = laplacian(adj_matrix);
	display(L_G);
	arma::vec eigval;
	arma::mat eigvec;
	eig_sym(eigval,eigvec,L_G);
	std::cout << matrix_dot(eigvec,1,2) << std::endl;
	//std::cout << eigval(1) << std::endl;
	return 0;
}
