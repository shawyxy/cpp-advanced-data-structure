.PHONTY : all
all : BST main
BST : BinarySearchTree.h
	g++ -std=c++11 -o $@ $^
main : main.cpp
	g++ -std=c++11 -o $@ $^
# BST : BinarySearchTree.h
# 	g++ BinarySearchTree.h -std=c++11 -o BST
# main : main.cpp
# 	g++ main.cpp -std=c++11 -o main
.PHONY : clean
clean : 
	rm -rf main BST