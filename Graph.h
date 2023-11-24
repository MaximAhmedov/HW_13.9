#pragma once
#include <iostream>
#include <vector>
#include <stack>

#define SIZE 10

class Tree { // класс дерева
public:
    struct Node { // структура узла
        Node(int _number, std::string _name, Node* _parent = nullptr);
        ~Node();

        int number; // номер мершины
        std::string name;

        Node* parent; // родительская вершина
        Node* children[SIZE]; // список дочерних вершин
        int childCount; // количество детей

        void addChild(Node* newChild);
        void delChild(Node* child);

    };
    Tree();
    ~Tree();

    void setRoot(int number, std::string name);
    void addNode(int parentNumber, int newNodeNumber, std::string newNodeName);
    void possibleFriends(std::string& name, int k);
    std::vector<std::string> innerDown(Node* start, std::vector<std::string>* spisok,int d);
    
    
    void delNode(int nodeNumber);
private:
    Node* getNodeByNumber(int number, Node* current);
    Node* getNodeByName(std::string& name, Node* current);
    Node* root;
};
