a.out : main.cpp
	g++ main.cpp 

clean:
	rm -f ./*.o a.out

