//#include <iostream>
//#include <stack>
//#include <string>
//#include <queue>
//
//std::string makeNewString(std::string, int);
//int getNumber(char*&);
//std::string getNewString(char*&);
//bool isNextSymbolLetter(char*&);
//
//int main() {
//	//char* input = "2(GV2(AB)P)";
//	//char* input = "2(2(A)3(B))";
//	//char* input = "3(AB2(B))";
//	//char* input = "3(AB)";
//	//char* input = "2(3(AB)5(C))";
//	//char* input = "AB";
//
//	//char* input = "2(K2(G2(A)P)2(2(C)))";
//
//	//char* input = "2(K2(G2(A)P)C)";
//
//	//char* input = "2(K2(G2(A)P))";
//
//
//	char* input = "2(K2(G2(A)P)V)";
//
//
//	//char* input = "2(K 2(G 2(A) P) C)";
//
//	//char* input = "2(KV2(GAAP)C3(O))";
//
//
//	std::stack<int> numbers;
//	//std::queue<std::string> text;
//	std::stack<std::string> text;
//
//	bool toConcatenate = false;
//
//	for (char* c = input; *c; c++) {
//		bool toConcatenate = false;
//
//		if (*c >= '0' && *c <= '9') {
//			int cval = getNumber(c);
//			numbers.push(cval);
//			if (isNextSymbolLetter(c)) {
//				toConcatenate = true;
//				std::cout << "-c:> " << *c << std::endl;
//			}
//			else {
//				std::cout << "-!c:> " << *c << std::endl;
//			}
//		}
//		if (*c >= 'A' && *c <= 'Z') {
//			std::string str = getNewString(c);
//			std::cout << "--c:> " << *c << std::endl;
//			if (toConcatenate && *c == ')') {
//				str = makeNewString(str, numbers.top());
//				numbers.pop();
//				text.push(str);
//				std::cout << "-if-str:> " << text.top() << std::endl;
//				//c++;
//				//std::cout << "-if-c:> " << *c << std::endl;
//				continue;
//			}
//			else if (toConcatenate) {
//				std::cout << "-elseif-str:> " << str << std::endl;
//				text.push(str);
//				text.push("~");
//			}
//			else {
//				std::cout << "-else-str:> " << str << std::endl;
//				text.push(str);
//			}
//		}
//		if (*c == ')' && c) {
//			std::cout << "tuka sym" << std::endl;
//			std::string patka = "";
//			while (!text.empty() && text.top() != "~") {
//				patka += text.top();
//				text.pop();
//			}
//			if (!text.empty()) {
//				text.pop();
//			}
//			std::cout << "patka " << patka << std::endl;
//			std::string asan = makeNewString(patka, numbers.top());
//			std::cout << "asan " << asan << std::endl;
//
//			numbers.pop();
//			text.push(asan);
//		}
//
//	}
//
//	while (!text.empty()) {
//		std::cout << "text:> " << text.top() << std::endl;
//		text.pop();
//	}
//
//
//	//std::cout << "textSize: " << text.size() << std::endl;
//	//std::string result = "";
//	//while (!text.empty()) {
//	//	result += text.top();
//	//	text.pop();
//	//}
//	//std::cout << "result: " << result << std::endl;
//
//	//std::cout << "numbersSize: " << numbers.size() << std::endl;
//	//while (!numbers.empty()) {
//	//	result = makeNewString(result, numbers.top());
//	//	numbers.pop();
//	//}
//	//std::cout << "result: " << result << std::endl;
//
//	std::cout << std::endl;
//	return 0;
//}
//
//std::string makeNewString(std::string oldStr, int n) {
//	std::string newStr = "";
//	while (n > 0) {
//		newStr += oldStr;
//		n--;
//	}
//	return newStr;
//}
//
//int getNumber(char*& c) {
//	int cval = 0;
//	while (*c >= '0' && *c <= '9') {
//		cval = cval * 10 + *c - '0';
//		++c;
//	}
//	return cval;
//}
//
//std::string getNewString(char*& c) {
//	std::string str = "";
//	while (*c >= 'A' && *c <= 'Z') {
//		str += *c;
//		++c;
//	}
//	if (*c >= '0' && *c <= '9') {
//		c--;
//	}
//	return str;
//}
//
//bool isNextSymbolLetter(char*& c) {
//	if (*(c + 1) >= 'A' && *(c + 1) <= 'Z') {
//		c++;
//		return true;
//	}
//	else {
//		return false;
//	}
//}