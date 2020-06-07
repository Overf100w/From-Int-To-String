#include "pch.h"
#include <iostream>

// arrays of name of numbers (spread in names)

const char *name0_9[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" }; 
const char *name10_19[10] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
const char *name20_90[10] = { "","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
const char *name100_900[10] = { "one hundred","two hundred","three hundred","four hundred","five hundred","six hundred","seven hundred","eight hundred","nine hundred" };
const char *name1f_9f[10] = { "one thousand","two thousand","three thousand","four thousand","five thousand","six thousand","seven thousand","eight thousand","nine thousand" };

char num[] = "";	// input num (string)

int main() {
	std::cout << "enter a num (to 9999): ";
	std::cin >> num;

	int num_int;		// intput num (integer)
	num_int = atoi(num);

	size_t length;		// length of inputed num
	length = strlen(num);

	// the main loop
	for (int i = 0;; i++) {
		if (length == 1) {		// one char nums
			if (num[i] == *"0") {	// checking for 0 
				length--;
				continue;
			}
			std::cout << name0_9[(int)num[i] - 48] << std::endl;
			break;
		}
		else if (length == 2) {		// two char nums
			if (num_int < 20 && num_int > 9) {	// 10 - 19 nums
				std::cout << name10_19[(int)num[i + 1] - 48] << " ";
			}
			else {		//20 - 99
				if (num[i] == *"0") {	// checking for 0 
					length--;
					continue;
				}
				std::cout << name20_90[(int)num[i] - 48] << " ";
			}
		}
		else if (length == 3) {		// three char nums
			if (num[i] == *"0") {	// checking for 0 
				length--;
				continue;
			} 	
			std::cout << name100_900[(int)num[i] - 49] << " and ";
		}
		else if (length == 4) {		// four char nums
			if (num[i] == *"0") {	// checking for 0 
				length--;
				continue;
			}
			std::cout << name1f_9f[(int)num[i] - 49] << ", ";
		}

		length--;
	}

	system("pause");
	return 0;
}