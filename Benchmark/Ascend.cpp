#include <iostream>
#include <assert.h>
#include <map>
using namespace std;
#include "uni10.hpp"
using namespace uni10;
const int CHI = 16;

int main(){
	vector<Bond> bonds;
	Bond bdi(BD_IN, CHI);
	Bond bdo(BD_OUT, CHI);
	bonds.push_back(bdi);
	bonds.push_back(bdi);
	bonds.push_back(bdo);
	bonds.push_back(bdo);

	/*
	UniTensor H0(bonds, "Ob");
	H0.orthoRand();
	H0.save("Ob.ut");
	*/
	UniTensor H0("Ob.ut");

	/*
	UniTensor U(bonds, "U");
	U.orthoRand();
	H0.save("U.ut");
	*/
	UniTensor U("U.ut");

	/*
	UniTensor Rho(bonds, "Rho");
	Rho.orthoRand();
	H0.save("Rho.ut");
	*/
	UniTensor Rho("Rho.ut");
	
	bonds.clear();
	bonds.push_back(bdi);
	bonds.push_back(bdo);
	bonds.push_back(bdo);
	bonds.push_back(bdo);
	/*
	UniTensor W1(bonds, "W1");
	W1.orthoRand();
	W1.save("W1.ut");
	*/
	UniTensor W1("W1.ut");

	/*
	UniTensor W2(bonds, "W2");
	W2.orthoRand();
	W2.save("W2.ut");
	*/
	UniTensor W2("W2.ut");

	Network asdL("AscendL");
	//H1 = asdL.launch();
	asdL.putTensor("W1", &W1);
	asdL.putTensor("W2", &W2);
	asdL.putTensor("U", &U);
	asdL.putTensor("Ob", &H0);
	asdL.putTensorT("UT", &U);
	asdL.putTensorT("W1T", &W1);
	asdL.putTensorT("W2T", &W2);
	asdL.putTensor("Rho", &Rho);
	UniTensor H1;
	for(int i = 0; i < 50; i++)
		H1 = asdL.launch();
	cout<<asdL;
	cout<<H1;
}

