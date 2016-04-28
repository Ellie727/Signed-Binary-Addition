#include <iostream>//cout, cin
#include <limits> //numeric_limits

#include "UI.h"
#include "Signed_Addition.h"
#include "Signed_Addition.cpp"

using namespace std; 

//UI class const
Ui::Ui(){
	
	cout << "==========Let's add some binary numbers!=========" << endl << endl;  
	
	do{
		
		cout << "Please enter your first integer value" << endl; 
		cin >> num_1; 
		
		if(!cin.fail()){
			
			cout << "Great! Now please enter your second integer value" << endl; 
			cin >> num_2; 
			
			if(!cin.fail()){
				
				cout << "Please, enter the max number of bits of your sum" << endl; 
				cin >> max_bits; 
				
				if (!cin.fail() && max_bits > 0){
					
						
					//Creates Signed_Addition Object to calculate values based on user input
					Signed_Addition calculate_user_input(num_1,num_2,max_bits);
					
					cout << "Would you try another calulation? Enter 'y' for yes and 'n' for no" << endl;
					cin >> response; 
								
								if(validate_response(response)){
		
									if(response == 'n' || response == 'N'){
								
										cout << "Goodbye!";
									}
		
								}	
								else{
									
									cin.clear(); 
									cin.ignore(numeric_limits<streamsize>::max(),'\n');
									cout << endl;  
									cout <<"Sorry your input is input is invalid, let's try that again!" << endl << endl;
									response = 'Y';  
								}
									
				}
				else{
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << endl;  
					cout << "Wrong input but, stay positive and let's try that again!" << endl << endl; 
					response = 'Y';
						
				}
				
				
					
					
					
			}
			else{
					
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << endl;  
				cout << "Please stick to numbers and try that again!" << endl << endl;
				response = 'y'; 
				}
			
		}
		else{
				
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << endl;  
			cout << "Oops! Numbers only please! Let's try that again" << endl << endl;
			response = 'y'; 
				
		}
		
	}while(response == 'y' || response == 'Y');
	
	
}



//Function that validates user's response as 'Y' or 'N' 
bool Ui::validate_response(char i){
	
	
	char input; 
	input = i; 
	
	if((int)input == 89 || (int)input == 121 || (int)input == 78 || (int)input == 110 ){
		return true; 
	}
	else{
		return false; 
	}
}
