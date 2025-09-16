#include "PalindromeNumber.h"
#include <iostream>

int main() {
	Solution s;
	std::cout << s.isPalindrome(0) << std::endl;
	std::cout << s.isPalindrome(121) << std::endl;
	std::cout << s.isPalindrome(-121) << std::endl;
	std::cout << s.isPalindrome(10) << std::endl;
}