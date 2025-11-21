#include "WordDictionary.h"
#include <iostream>

enum Operation { INSERT, SEARCH };

int main() {
	WordDictionary* wd;
	std::vector<std::pair<Operation, string>> actions = {
		std::make_pair(INSERT, "bad"),
		std::make_pair(INSERT, "dad"),
		std::make_pair(INSERT, "mad"),
		std::make_pair(SEARCH, "pad"),
		std::make_pair(SEARCH, "bad"),
		std::make_pair(SEARCH, ".ad"),
		std::make_pair(SEARCH, "b.."),
	};

	wd = new WordDictionary();
	for (auto [op, word] : actions) {
		switch (op) {
		case INSERT:
			wd->addWord(word);
			std::cout << "null,";
			break; 
		case SEARCH:
			string result = wd->search(word) ? "true," : "false,";
			std::cout << result;
		}
	}
	std::cin.get();
}