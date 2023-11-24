#include <iostream>
#include "Graph.h"

int main() {
    setlocale(LC_ALL, "");
    Tree tree;

    tree.setRoot(2, "Ostin");
    tree.addNode(2, 4, "Nik");
    tree.addNode(2, 0, "Any");
    tree.addNode(2, 3, "Dan");
    tree.addNode(4, 1, "Violik");
    tree.addNode(1, 5, "Max");
    tree.addNode(1, 6, "Tayvin");
    tree.addNode(3, 7, "Kris");
    tree.addNode(0, 8, "Bob");
    tree.addNode(3, 9, "Kek");
    tree.addNode(7, 10, "Pepe");
    tree.addNode(4, 11, "Lol");
    tree.addNode(4, 12, "Alex");
    tree.addNode(12, 13, "Dima");
    tree.addNode(5, 14, "Pupa");
    tree.addNode(11, 15, "Lupa");
    std::string name;
    std::cin >> name;

    tree.possibleFriends(name, 3);

    tree.delNode(4);


	return 0;
 }