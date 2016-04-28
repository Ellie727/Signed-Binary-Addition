#ifndef UI_H
#define UI_H

class Ui{
	
	public: 
		Ui();
		bool validate_response(char);
	
	private: 
		int num_1; 
		int num_2;
		int max_bits; 
		char response;
};

#endif 
