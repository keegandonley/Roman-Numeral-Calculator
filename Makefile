
CFLAGS=-std=c++11 -Wall -g

project1.x: InfixToPostfix.o Token.o TokenIterator.o main.o Tokenizer.o symbolTable.o Number.o
	g++ $(CFLAGS) InfixToPostfix.o Token.o TokenIterator.o main.o Tokenizer.o symbolTable.o Number.o -o project1.x

InfixToPostfix.o: InfixToPostfix.hpp InfixToPostfix.cpp TokenIterator.hpp Token.hpp
	g++ $(CFLAGS) InfixToPostfix.cpp -o InfixToPostfix.o -c

TokenIterator.o: TokenIterator.hpp TokenIterator.cpp Token.hpp
	g++ $(CFLAGS) TokenIterator.cpp -o TokenIterator.o -c

Token.o: Token.hpp Token.cpp
	g++ $(CFLAGS) Token.cpp -o Token.o -c

main.o: main.cpp Token.hpp InfixToPostfix.hpp TokenIterator.hpp
	g++ $(CFLAGS) main.cpp -o main.o -c

Number.o: Number.hpp Number.cpp
	g++ $(CFLAGS) Number.cpp -o Number.o -c

Tokenizer.o: Tokenizer.hpp Tokenizer.cpp Token.hpp
	g++ $(CFLAGS) Tokenizer.cpp -o Tokenizer.o -c

symbolTable.o: symbolTable.hpp symbolTable.cpp Number.hpp
	g++ $(CFLAGS) symbolTable.cpp -o symbolTable.o -c


clean:
	rm -f *.o *~ *.x

run:
	make
	./project1.x
