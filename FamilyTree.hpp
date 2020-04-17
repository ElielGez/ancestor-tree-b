#include <iostream>
#include <string>
using namespace std;
namespace family
{

class Node
{
private:
    string name;
    Node *father;
    Node *mother;
    int level;
    string relation;

public:
    Node(string name, int level) : name(name), father(NULL), mother(NULL), level(level), relation("me"){};
    void setFather(Node *father);
    void setMother(Node *mother);
    void setRelation(string gender);
    Node *getFather();
    Node *getMother();
    int getLevel();
    string getName();
    string getRelation();
};
class Tree
{
private:
    Node *root;

public:
    Tree(string name) : root(new Node(name, 0)){};

    Tree &addFather(string, string);
    Tree &addMother(string, string);
    void display();
    void display(Node *r);
    string relation(string);
    string find(string);
    void remove(string);
    void remove(Node *r);
    Node *findChild(Node *root, string child, string searchType);
    Node *findByParent(Node *root, string child);
};
}; // namespace family