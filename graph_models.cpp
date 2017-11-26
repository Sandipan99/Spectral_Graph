#include<iostream>
#include "math.h"
#include "common.h"

arma::mat RecurPopulate(arma::mat, arma::mat, int);

arma::mat DeterministicKronecker(arma::mat P, int k){

	int m = P.n_rows;
	int n = P.n_cols;
	int r = pow(m,k);
	int c = pow(n,k);
	int k_p = k;
	arma::mat K_G = RecurPopulate(P,P,k_p);
	return K_G;
}

arma::mat RecurPopulate(arma::mat P,arma::mat P_1, int k_p){
	int val;
	if(k_p==0)
		return P_1;
	else{
		//display(P_1);
		int r = P_1.n_rows * P.n_rows;
		int c = P_1.n_cols * P.n_cols;
		int m = P.n_rows;
		int n = P.n_cols;
		arma::mat P_n = fill_zero(r,c);
		for(int i=0;i<P_1.n_rows;i++){
			for(int j=0;j<P_1.n_cols;j++){
				std::cout << i << "," << j << std::endl;
				val = P_1(i,j);
				//P = mul_scalar(P,val);
				//display(P);
				for(int k=0;k<P.n_rows;k++){
					for(int l=0;l<P.n_cols;l++){
						P_n(k+m*i,l+n*j) = P(k,l)*val;
						std::cout << k+m*i << "," << l+n*j << ": " << P(k,l) << std::endl;
					}
				}
			}
		}
		std::cout << "----------------------" << std::endl;
		arma::mat P_n1 = RecurPopulate(P, P_n, k_p-1);
		return P_n1;				
	}	
}
