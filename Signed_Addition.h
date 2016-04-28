#include <vector> //vector

#ifndef SIGNED_ADDITION_H
#define SIGNED_ADDITION_H

using namespace std; 

//Class declaration for signed_number_addition 
class Signed_Addition{
	
	public: 
	
	//Class constructor which takes the two number to be added and bit size as arguments
	Signed_Addition(int,int,int);
	
	//Boolean to check if initial values entered are possible to calculate given bit size
	bool check_bits_fit(int);
	
	//Function that converts numbers to binary
	void convert_to_binary(int,int);
	
	//Function that uses binary vector to create a ones complement vector
	void ones_complement(vector<int> &a, vector<int> &b);
	
	//Function that takes ones complement vector to create a twos complement 
	void twos_complement(vector<int> &b,vector<int> &c);
	
	//Adds vectors of twos complement to create sum vector
	void sum_of_bits(vector<int> &a,vector<int> &b);
	
	//Checks to see if there's no overflow based on values in the sum vector
	bool detect_no_overflow(vector<int> &a);
	
	//Uses sum vector to convert to decimal
	void convert_sum_to_dec(vector<int> &b);
	
	//Prints out results 
	void print_results(); 
	
	
	
	private:
		
	int num_of_bits; 
	int dec_num_1; 
	int dec_num_2; 
	int dec_sum; 
	vector<int> binary_num_1; 
	vector<int> binary_num_2; 
	vector<int> ones_comp_num_1; 
	vector<int> ones_comp_num_2; 
	vector<int> twos_comp_num_1; 
	vector<int> twos_comp_num_2; 
	vector<int> temp_sum; 
	vector<int> sum; 
	
	
};

#endif 
