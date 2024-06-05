hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Yigit.o -c ./src/Yigit.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp 
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp 
	g++ -I ./include/ -o ./bin/Test ./lib/Node.o ./lib/Yigit.o ./lib/Kisi.o ./lib/Dugum.o ./lib/AVL.o ./src/Test.cpp
	
calistir:
	./bin/Test