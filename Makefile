a.out : main.cpp
	g++ main.cpp -std=c++11

clean:
	rm -f ./*.o a.out

