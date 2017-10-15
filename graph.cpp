#include<fstream>
#include "graph.h"
#include<map>
#include<iostream>
#include "common.h"

arma::mat build_adj_matrix(std::string fname){
	int u,v;
	std::map<int,int> node;
	std::ifstream in;
	in.open(fname);
	while(in>>u>>v){
		node[u] = 1;
		node[v] = 1;
	}
	in.close();
	int n = node.size();
	arma::mat adj_mat = fill_zero(n,n);
	in.open(fname);
	while(in>>u>>v){
		adj_mat(u,v) = 1;
		adj_mat(v,u) = 1;
	}
	in.close();
	return adj_mat;	
}


arma::mat laplacian(arma::mat m){
	int n =m.n_rows;
	arma::mat D = fill_zero(n,n);
	arma::mat L_G = fill_zero(n,n);
	arma::vec dia = col_sum(m,0);
	for(int i=0;i<n;i++)
		D(i,i) = dia(i);
	L_G = D - m;
	return L_G;
}	
