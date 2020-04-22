#include "FamilyTree.hpp"
#include <stdexcept>
#define COUNT 10

using namespace family;

// Node class
void Node::setFather(Node *father) {
    this->father = father;
}
void Node::setMother(Node *mother) {
    this->mother = mother;
}
void Node::setRelation() {
    if (this->level == 1)
        this->relation = this->type;
    else if (this->level == 2)
        this->relation = "grand" + this->type;
    else if (this->level > 2) {
        string temp = "grand" + this->type;
        for (int i = 0; i < this->level - 2; i++) {
            temp = "great-" + temp;
        }
        this->relation = temp;
    }
}
Node *Node::getFather() {
    return this->father;
}
Node *Node::getMother() {
    return this->mother;
}
int Node::getLevel() {
    return this->level;
}
string Node::getName() {
    return this->name;
}
string Node::getRelation() {
    return this->relation;
}
string Node::getType() {
    return this->type;
}

// Tree class

//public
Tree &Tree::addFather(string child, string father) {
    Node *c = findChild(root, child, "name");
    if (c == NULL)
        throw runtime_error("Child was not found");

    if (c->getFather() != NULL)
        throw runtime_error("Child already got father");

    Node *f = new Node(father, c->getLevel() + 1, "father");
    f->setRelation();
    c->setFather(f);
    return *this;
}
Tree &Tree::addMother(string child, string mother) {
    Node *c = findChild(root, child, "name");
    if (c == NULL)
        throw runtime_error("Child was not found");

    if (c->getMother() != NULL)
        throw runtime_error("Child already got mother");

    Node *m = new Node(mother, c->getLevel() + 1, "mother");
    m->setRelation();
    c->setMother(m);
    return *this;
}
void Tree::display() {
    display(this->root);
}
void Tree::display(Node *r) {
    if (r == NULL)
        return;
    cout << r->getName() << ":" << r->getRelation() << ",";
    display(r->getFather());
    display(r->getMother());
}

string Tree::relation(string name) {
    Node *c = findChild(root, name, "name");
    if (c == NULL)
        return "unrelated";
    return c->getRelation();
}
string Tree::find(string relation) {
    Node *c = findChild(root, relation, "relation");
    if (c == NULL)
        throw runtime_error("Child was not found");
    return c->getName();
}
void Tree::remove(string name) {
    Node *c = findChild(root, name, "name");
    if (c == NULL) {
        throw runtime_error("Child was not found");
    }
    if (c->getLevel() == 0) {
        throw runtime_error("Child is the root , can't remove");
    }
    Node *children = findByParent(root, c->getName());
    if (c->getType() == "father") {
        children->setFather(NULL);
    } else if (c->getType() == "mother") {
        children->setMother(NULL);
    }
    remove(c);
};
void Tree::remove(Node *r) {
    if (r == NULL)
        return;

    remove(r->getFather());
    remove(r->getMother());

    delete r;
}

Node *Tree::findChild(Node *root, string child, string searchType) {
    if (root == NULL)
        return NULL;

    string field = root->getName(); // default search by name
    if (searchType == string("relation"))
        field = root->getRelation();

    if (field == child)
        return root;

    Node *father = findChild(root->getFather(), child, searchType);

    if (father != NULL) {
        return father;
    }

    return findChild(root->getMother(), child, searchType);
    // return findChild(root->getFather(), child, searchType) ?: findChild(root->getMother(), child, searchType);
}

Node *Tree::findByParent(Node *root, string child) {
    if (root == NULL)
        return NULL;

    if (root->getFather() != NULL && root->getFather()->getName() == child)
        return root;

    else if (root->getMother() != NULL && root->getMother()->getName() == child)
        return root;

    Node *father = findByParent(root->getFather(), child);

    if (father != NULL) {
        return father;
    }

    return findByParent(root->getMother(), child);
    // return findByParent(root->getFather(), child) ?: findByParent(root->getMother(), child);
}