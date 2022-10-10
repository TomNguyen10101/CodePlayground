CC = g++
CFLAG = -g -std=c++11 -Wall 
#BUNDLE_ZIP_NAME = Calculator.zip

zipFile:
	rm -f $(BUNDLE_ZIP_NAME)
	zip -r $(BUNDLE_ZIP_NAME) *.cpp *.h Makefile 

test:
	./Calculator

Calculator: Calculator.o FrontCal.cpp
	$(CC) $(CFLAG) -o Calculator FrontCal.cpp Calculator.o

Calculator.o: Calculator.h Calculator.cpp
	$(CC) $(CFLAG) -c Calculator.cpp

clean: 
	del *.exe *.o