a.out: main.cpp autoComplete.o fileRead.o getinput.o saveToFile.o toLower.o trie.o
	g++ -o a.out main.cpp autoComplete.o fileRead.o getinput.o saveToFile.o toLower.o trie.o

autoComplete.o: autoComplete.cpp functions.h node.h trie.h
	g++ -c autoComplete.cpp

fileRead.o: fileRead.cpp functions.h node.h trie.h
	g++ -c fileRead.cpp

getinput.o: getInput.cpp functions.h node.h trie.h
	g++ -c getInput.cpp

saveToFile.o: saveToFile.cpp functions.h node.h trie.h
	g++ -c saveToFile.cpp

toLower.o: toLower.cpp functions.h node.h trie.h
	g++ -c toLower.cpp

trie.o: trie.cpp functions.h node.h trie.h
	g++ -c trie.cpp

clean:
	rm -f *.o *.out