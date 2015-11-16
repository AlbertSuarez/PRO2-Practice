pro2.exe: pro2.o
	g++ -o pro2.exe *.o

pro2.o: pro2.cpp
	g++ -c *.cpp -D_GLIBCXX_DEBUG -I$(INCLUDES_CPP)


# Aquesta última opció serverix per netejar el directori de fitxers
# innecesaris; s'executa mitjançant el comandament "make clean"
	
	
clean:
	rm *.o
	rm *.exe