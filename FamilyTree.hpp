#include <iostream>
#include <string>
#define P_DEBUG(msg) cout << "\033[1;31m"                                                                                \
                          << "-DEBUG- File: " << __FILE__ << " Line: " << __LINE__ << " Message: " << msg << "\033[0m\n" \
                          << endl;
#define P_INFO(msg) cout << "\033[1;36m"                                                                               \
                         << "-INFO- File: " << __FILE__ << " Line: " << __LINE__ << " Message: " << msg << "\033[0m\n" \
                         << endl;

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
    Node *findChild(Node *root, string child, string searchType);
    Node *findByParent(Node *root, string child);
    void remove(Node *r);
    void display(Node *r);

public:
    Tree(string name) : root(new Node(name, 0, "root")){};
    ~Tree() {
        remove(root);
    }

    Tree &addFather(string, string);
    Tree &addMother(string, string);
    void display();
    string relation(string);
    string find(string);
    void remove(string);
};
}; // namespace family