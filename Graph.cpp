#include "Graph.h"

Tree::Node::Node(int _number, std::string _name, Node* _parent) :
    number(_number),
    name(_name),
    parent(_parent),
    childCount(0) {
    for (int i = 0; i < SIZE; i++) {
        children[i] = nullptr;
    }

}
//
Tree::Node::~Node() {
    for (int i = 0; i < childCount; i++)
    {
        delete children[i];
    }
}
//
void Tree::Node::addChild(Node* newChild) {
    children[childCount++] = newChild;
}
//
Tree::Tree() {
    root = nullptr;
}
//
Tree::~Tree() {
    if (root != nullptr)
    {
        delete root;
    }
}
//
void Tree::setRoot(int number, std::string name) {
    if (root != nullptr)
    {
        delete root;
        root = nullptr;
    }
    root = new Node(number, name);
}
//
void Tree::addNode(int parentNumber, int newNodeNumber, std::string newNodeName)
{
    Node* parentNode = getNodeByNumber(parentNumber, root);
    Node* newNode = new Node(newNodeNumber, newNodeName, parentNode);
    parentNode->addChild(newNode);
}
//
Tree::Node* Tree::getNodeByNumber(int number, Node* current) {
    if (current->number == number)
        return current;
    for (int i = 0; i < current->childCount; i++)
    {
        Node* found = getNodeByNumber(number, current->children[i]);
        if (found)
            return found;
    }
    return nullptr;
}

Tree::Node* Tree::getNodeByName(std::string& name, Node* current) {
    if (current->name == name)
        return current;
    for (int i = 0; i < current->childCount; i++)
    {
        Node* found = getNodeByName(name, current->children[i]);
        if (found)
            return found;
    }
    return nullptr;
}

void Tree::possibleFriends(std::string& name, int k)
{
    
    std::vector<std::string> friends;
    std::stack<Node*> goUp;
    Node* current = getNodeByName(name, root);
    Node* next = nullptr;
    int x = 0;
    while (x < k && current->parent != nullptr) {
        x++;
        goUp.push(current);
        current = current->parent;
    }
    if (current->parent != nullptr && k != x)
        friends.push_back(current->parent->name);
    while (current->name != name && !goUp.empty()) {
        friends.push_back(current->name);
        next = goUp.top();
        int depht = k - x;
        if (depht > 0) {
            for (int i = 0; i < SIZE; i++) {
                if (current->children[i] != nullptr)
                    if (current->children[i]->name != name && current->children[i]->name != next->name) {
                        friends.push_back(current->children[i]->name);
                        if (depht > 1) {
                            innerDown(current->children[i], &friends, depht);
                        }
                    }
            }
        }
        current = next;
        goUp.pop();
        x--;
    }
    innerDown(current, &friends, k);
    std::cout << "Список возможных друзей " << name << ":\n";
    for (int i = 0; i < friends.size(); ++i)
    {
        std::cout << friends[i] << std::endl;
    }
}

std::vector<std::string> Tree::innerDown(Node* start, std::vector<std::string>* spisok, int d)
{
    
    if (d > 1) {
        for (int i = 0; i < SIZE; i++) {
            if (start->children[i] != nullptr) {
                spisok->push_back(start->children[i]->name);
                d--;
                innerDown(start->children[i], spisok, d);
            }
        }
    }
    return *spisok;
}



void Tree::delNode(int number) {
    // Ваш код должен быть здесь
    Node* node = getNodeByNumber(number, root); // нашли вершину для удаления
    Node* parent = node->parent; // нашли ее родителя
    // перебросили всех детей удаляемой вершины её родителю
    for (int i = 0; i < node->childCount; i++)
    {
        parent->addChild(node->children[i]);
    }
    // указали, что у  удаляемой вершины, больше нет детей
    node->childCount = 0;
    // удалили вершину
    parent->delChild(node);
}







void Tree::Node::delChild(Node* child) {
    int foundIndex = -1;
    for (int i = 0; i < childCount; i++)
        if (children[i] == child)
            foundIndex = i; // нашли индекс удаляемой вершины в массиве
    delete children[foundIndex]; // удалили вершину
    childCount--; // удалили ее из массива
    for (int i = foundIndex; i < childCount; i++)
        children[i] = children[i + 1];
}

