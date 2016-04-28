#include <iostream>//cout 
#include <cmath> //pow abs
#include <vector> //vector
#include "Signed_Addition.h"

using namespace std; 

//********************************************************************
// Signed_Addition class function definitions below
//
///*******************************************************************

//signed_number_addition class Constructor defined
Signed_Addition::Signed_Addition(int a, int b, int c){
	
	
	dec_num_1 = a; 
	dec_num_2 = b; 
	num_of_bits = c; 
	
	
	//If both numbers fit into the max bit size the program proceeds
	 if(check_bits_fit(dec_num_1) && check_bits_fit(dec_num_2)){
	 	
	 	//Call to class function that converts the absolute value of the numbers to their positive binary representations
	 	convert_to_binary(dec_num_1,dec_num_2);
		
		//Call to class function that converts binary number to ones complement representation
		ones_complement(binary_num_1,binary_num_2);
		
		//Call to class function that converts binary number to twos complement representation
		twos_complement(ones_comp_num_1,ones_comp_num_2);
		
		//Call to class function that adds the twos complements of each integer together
		sum_of_bits(twos_comp_num_1,twos_comp_num_2);
		
		//Function call to convert binary sum into integer value
		convert_sum_to_dec(sum);
		
		//Call to class that prints out all the values of the two numbers which calls the function to check for overflow and calculates the sum in decimal form
		print_results(); 
		
		

		
		
	 	return; 
	 	
	 	
	 }
	 //If either number exceed the alotted bit size then an error message is output and the program returns to main
	 else{
	 	
	 	cout << endl;
	 	cout << "Error! Your numbers are a bit off! Please be sure to select the appropriate bit size or number corresponding to its limits!" << endl << endl; 
	 	return; 
	 }

	
	
}

//Class function that validates whether numerical values are in range of selected bit size
bool Signed_Addition::check_bits_fit(int a){
	
	//Variables that hold the limits of negative and positive signed numbers based on bit size
	long long int positive_limit = pow(2,num_of_bits-1)-1; 
	long long int negative_limit = pow((int)-2,(int)num_of_bits-1); 
	

	
	if(a >= 0){
		//Checks to see if positive values fall into range given max bit size
		if(a <= positive_limit && a >= 0 ){
			
			return true; 
			
		}
		else{
			
			return false; 
		}
		
	}
	else{
		//Checks to see if negative values fall into range given max bit size
		if(a >= negative_limit && a < 0 ){
			
			return true; 
		}
		else{
			
			return false; 
		}
	}
}

//Class function that turns decimal number into binary number
void Signed_Addition::convert_to_binary(int a,int b){
	
	vector<int> temp_1; 
	vector<int> temp_2;
	
	
	int dividend; 
	int remainder; 
	int divisor = 2; 
	
	
	
	if(a != 0){
		
		//Stores the absolute value of user's input into the dividend variable
		dividend = abs(a); 
		
	
		//While loop divides number then quotients by 2 and pushes remainder into vector for binary conversion in MSB form
		while(dividend != 0){
		
		remainder = dividend%divisor; 
		temp_1.push_back(remainder); 
		dividend = dividend/divisor; 
		}
		
		//If conversion does not fill max number of bits 0's are added to make it max number of bits
		while(temp_1.size() < num_of_bits){
			
				temp_1.push_back(0);
			
		}
	
		int reverse_count = 0; 
		//Loop reads temp vector backwards into binary number vector variable to get LSB bit order 
		for(int x = temp_1.size()-1; x >= 0 ;x--){
		
			binary_num_1.push_back(temp_1[x]); 
			reverse_count++; 
		}
		
	}
	//These else if's consider if the number being converted is 0 and simply pushes in the appropriate amount of 0's. 
	else if(a == 0){
		
		for(int t = 0; t < num_of_bits; t++){
	
				binary_num_1.push_back(0);
			
		}
		
	}
	
	//Same steps as above except this is used to fill the vector pertaining to the second number
	if(b != 0){
		
		dividend = abs(b);
		
		while(dividend != 0){
		
		remainder = dividend%divisor; 
		temp_2.push_back(remainder); 
		dividend = dividend/divisor; 
		}
		
		while(temp_2.size() < num_of_bits){
			
				temp_2.push_back(0);
			
		}
	
		int reverse_count = 0; 
	
		for(int x = temp_2.size()-1; x >= 0 ;x--){
		
			binary_num_2.push_back(temp_2[x]); 
			reverse_count++; 
		}
		
		
	}
	else if(b == 0){
		
		for(int w = 0; w < num_of_bits; w++){
				binary_num_2.push_back(0);
			
		}
		
		
		
	}
	
	

	return;
	
	
		
}

//Class one's complement conversion function 
void Signed_Addition::ones_complement(vector<int> &a, vector<int> &b){
	
	binary_num_1 = a; 
	binary_num_2 = b; 
	
	
		//Checks to see if the number is positive if so the one's complement is the same as its binary
		if(dec_num_1 >= 0){
			
			ones_comp_num_1 = binary_num_1;
		}
		//If the number is negative the for loop, loops through and replaces each bit with its inverse
		else{
			
			ones_comp_num_1 = binary_num_1;
			for(int x = 0; x < ones_comp_num_1.size(); x++){
		
				if(ones_comp_num_1[x] == 0){
					ones_comp_num_1[x] = 1; 
				}
				else{
					ones_comp_num_1[x] = 0; 
				}
			
			
			}
		
		
		}
	
	
	
		//If number is positive it doesn't change
		if(dec_num_2 >= 0){
			
			ones_comp_num_2 = b;
		}
		//If the number is negative the for loop, loops through and replaces each bit with its inverse
		else{
			ones_comp_num_2 = b;
			for(int x = 0; x < ones_comp_num_2.size(); x++){
		
				if(ones_comp_num_2[x] == 0){
					
					ones_comp_num_2[x] = 1; 
				}
				else{
					ones_comp_num_2[x] = 0; 
				}
			
			
			}
		
		
			
		}
	
	
	return; 
}


//Class two's complement function definition
void Signed_Addition::twos_complement(vector<int> &b,vector<int> &c){
		
		
		if(dec_num_1 >= 0){
			//Nothing changes if number is positive
			twos_comp_num_1 = b; 
		}
		
		else{
			
			twos_comp_num_1 = b; 
			
			//the last item of the array is found and if it is equal to 0 it is changed to a 1 to represent a 1 being added.
			if(twos_comp_num_1[twos_comp_num_1.size()-1] == 0){
				
				twos_comp_num_1[twos_comp_num_1.size()-1] = 1; 
			}
			else{
				
				int count = twos_comp_num_1.size()-1;
			
				//if a one is found in the end the program loops backwards through the program until it hits a zero
				while(twos_comp_num_1[count] == 1){
		
					twos_comp_num_1[count] = 0;
					count--; 
				}
				//Adds 1 to the first zero found
				if(count >= 0){
		
					twos_comp_num_1[count] = 1; 
				}
		
			}
		
			
			
		}
		
			
	//A mirror of the above for the second value 
		if(dec_num_2 >= 0){
		
			twos_comp_num_2 = c; 
		}
		
		else{
			twos_comp_num_2 = c; 
			//the last item of the array is found and if it is equal to 0 it is changed to a 1 to represent a 1 being added.
			if(twos_comp_num_2[twos_comp_num_2.size()-1] == 0){
				
				twos_comp_num_2[twos_comp_num_1.size()-1] = 1; 
			}
			else{
				
				int count = twos_comp_num_2.size()-1;
				
				//if a one is found in the end the program loops backwards through the program until it hits a zero
				while(twos_comp_num_2[count] == 1){
		
					twos_comp_num_2[count] = 0;
					count--; 
				}
				//Adds 1 to the first zero found
				if(count >= 0){
		
					twos_comp_num_2[count] = 1; 
				}
		
			}
	
			
			
		}
	
	return;
	
};


//Function that adds the twos complement of each number to create a vector containing the sum
void Signed_Addition::sum_of_bits(vector<int> &a,vector<int> &b){
	
	 int temp_bits_storage = num_of_bits; 
	vector<int> temp_sum; 
	
	//bool that detects if carry flag is set
	bool carry = false;
	
    	
	
	//While loops that goes through the number of bits in each vector which is the max size, adds last two number of both vectors then decrements
	while(num_of_bits >= 0){
			 
			 //if we're adding 0 and 0 and carry flag is set then push in 1 to the sum vector, set carry to false
			if(twos_comp_num_1[num_of_bits-1] == 0 && twos_comp_num_2[num_of_bits-1] == 0 && carry){
			
				temp_sum.push_back(1);
				carry = false; 
			}
			//otherwise if we're adding 0 and 0 and carry flag is not set then just push 0 into temporary sum vector, set carry to false
			else if(twos_comp_num_1[num_of_bits-1] == 0 && twos_comp_num_2[num_of_bits-1] == 0 && !carry){
				
				temp_sum.push_back(0);
				carry = false; 
			}
			//if we're adding 1 and 0 together if carry flag is set put in zero and set flag now to true otherwise push one and set flag to false
			else if(twos_comp_num_1[num_of_bits-1] == 1 && twos_comp_num_2[num_of_bits-1] == 0 || twos_comp_num_1[num_of_bits-1] == 0 && twos_comp_num_2[num_of_bits-1] == 1 ){
				if(carry){
					temp_sum.push_back(0); 
					carry = true; 
				}
				else{
					temp_sum.push_back(1); 
					carry = false; 
				}
				 
			}
			//if we're adding 1 and 1 and the carry flag is 1, push 1 into the temporary sum vector and set carry flag to true
			else if(twos_comp_num_1[num_of_bits-1] == 1 && twos_comp_num_2[num_of_bits-1] == 1 && carry){
				
				temp_sum.push_back(1); 
				carry = true; 
				
		
			}
			//if we're adding 1 and 1 and the carry flag is not set then push 0 into temporary sum vector and set carry flag true
			else if(twos_comp_num_1[num_of_bits-1] == 1 && twos_comp_num_2[num_of_bits-1] == 1 && !carry){
				
				temp_sum.push_back(0);
				carry = true; 
			}
			
			--num_of_bits; 
			
		}
		//If a carry flag is still set at the end of all this then just push a 1 into the temporary sum
		if(carry){
			temp_sum.push_back(1);
		}
		
		//Pushes the temporary sum into the sum vector in reverse so we get LSB bit order
		for(int z = temp_sum.size()-1; z >= 0; z--){
			
			sum.push_back(temp_sum[z]);
		}
		
		
		
		//restores original value of num_of_bits
		num_of_bits = temp_bits_storage; 
		
		//Removes any carry or excess values thus leaving the sign bit at index 0
		while(sum.size() > num_of_bits){
			sum.erase(sum.begin());
		}
		
		
	
	
	return;
}

//Function definition for detect_no_overflow that detects if Overflow is present or not
bool Signed_Addition::detect_no_overflow(vector<int> &a){
	
	int count = sum.size()-1; 

	//Checks to see if sign bit of a positive number is 0 if so no overflow
	if(dec_num_1 >= 0 && dec_num_2 >= 0){
	
		if(sum[0] == 0 && sum.size() == num_of_bits){
			return true; 
		}
		else{
			
			return false; 
		}
	}
					
	//If the number is negative it's sign bit is checked for a 1 if not then it's an overflow
	else{
		
		if(sum[0] == 1 && sum.size() == num_of_bits){
		
			return true; 
		}
		else{
			
			return false; 
		}
		
		
	}
	

	
}


//Function to convert binary number to decimal
void Signed_Addition::convert_sum_to_dec(vector<int> &b){
	
	vector<int> temp; 
	temp = b; 
	int power = 0; 
	int temp_dec = 0; 
	
	//If the result of the addition is positive is non-negative we convert to binary as normal
	if(dec_num_1 >= 0 && dec_num_2 >= 0 || dec_num_1 >= 0 && dec_num_2 < 0 && abs(dec_num_1) > abs(dec_num_2) || (dec_num_1 < 0 && dec_num_2 >= 0 && abs(dec_num_1) < abs(dec_num_2))){
		
		
		//loops through copy of sum vector and increments temp_dec by the appropriate power each time a 1 is encountered
		for(int x = temp.size()-1; x >= 0; x--){
		
			    if(temp[x] == 1){
			
				temp_dec += pow(2,power);
				
				
                }
                ++power; 
		}
		
	    
		dec_sum = temp_dec; 
	}
	//If the result of the addition is negative it uses this method of conversion
	else{
		
		
		
		
	
		
		//Invert the negative binary value
		for(int y = 0; y < temp.size(); y++){
                
                if(temp[y] == 0){
                          
                   temp[y] = 1; 
                }
                else{
                     
                     temp[y] = 0; 
                }
                
        }
        
        //Add 1 to inverted value
        
        if(temp[temp.size()-1] == 0){
				
				temp[temp.size()-1] = 1; 
				
		}
		else if (temp[temp.size()-1] == 1){
				
			int count = temp.size()-1;
			
			//if a one is found in the end the program loops backwards through the program until it hits a zero
			while(temp[count] == 1){
		
				temp[count] = 0;
				count--; 
			}
			//Adds 1 to the first zero found
			if(count >= 0){
		
					temp[count] = 1; 
             }
        	
		}
		
	
			//Calculates decimal value of binary number
		
			for(int x = temp.size()-1; x >= 0; x--){
		
				
				if(temp[x] == 1){
                      
                
					temp_dec += pow(2,power);
				
            	}
            	++power; 
			}
			
			//Multiplies the results by negative one to get negative value 
			temp_dec = temp_dec*-1; 
		
		dec_sum = temp_dec; 
   }
   
   
   
	
}


//Function definition for print function that prints results 
void Signed_Addition::print_results(){
	
	cout << endl; 
	 
	 	//If no overflow is detected between the two numbers print the results
	if( dec_num_1 < 0 && dec_num_2 < 0 && detect_no_overflow(sum) || dec_num_1 >= 0 && dec_num_2 >= 0 && detect_no_overflow(sum) || dec_num_1 < 0 && dec_num_2 >= 0 || dec_num_1 >= 0 && dec_num_2 < 0){
		
		cout << "The binary representation for " << dec_num_1 << " is : ";  
		
		for(int y = 0; y < twos_comp_num_1.size(); y++){
			
			cout << twos_comp_num_1[y]; 
		}
		cout << endl << endl; 
		
		cout << "The binary representation for " << dec_num_2 << " is : ";
		
			for(int z = 0; z < twos_comp_num_2.size(); z++){
				
				cout << twos_comp_num_2[z]; 
			}
		cout << endl << endl;  
		
		cout << "The sum of these numbers is : "; 
		
		for(int x = 0; x < sum.size(); x++){
			
			cout << sum[x];
		}
		
		cout << endl << endl; 
		
		cout << "This sum's decimal value is : " << dec_sum << endl; 
		cout << endl; 
		return; 
	}
	
	//If overflow is detected print error message
	else{
		cout << endl; 
		cout << "ERROR: Overflow detected! The number " << dec_num_1+dec_num_2 << " can not be represented with " << num_of_bits << " bits" <<  endl; 
		cout << endl; 
	
		return; 
	}
}

