all: a.out oop1.class
	./a.out
	java oop1
a.out: oop1.cpp
		g++ oop1.cpp
oop1.class: oop1.java
		javac oop1.java
clean:
		rm -f oop1.class
		rm -f ./a.out
