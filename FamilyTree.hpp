#include <iostream>
#include <string>
using namespace std;
namespace family {

class Node {
private:
    string name;
    Node *father;
    Node *mother;
    int level;
    string relation;
    string type;

public:
    Node(string name, int level, string type) : name(name), father(NULL), mother(NULL), level(level), relation("me"), type(type){};
    void setFather(Node *father);
    void setMother(Node *mother);
    void setRelation();
    Node *getFather();
    Node *getMother();
    int getLevel();
    string getName();
    string getRelation();
    string getType();
};
class Tree {
private:
    Node *root;

public:
    Tree(string name) : root(new Node(name, 0, "root")){};

    Tree &addFather(string, string);
    Tree &addMother(string, string);
    void display();
    void display(Node *r);
    void displayRec(Node *root, int space);
    string relation(string);
    string find(string);
    void remove(string);
    void remove(Node *r);
    Node *findChild(Node *root, string child, string searchType);
    Node *findByParent(Node *root, string child);
};
}; // namespace family