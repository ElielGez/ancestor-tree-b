#include "FamilyTree.hpp"
#include <stdexcept>

using namespace family;

// Node class
void Node::setFather(Node *father)
{
    this->father = father;
}
void Node::setMother(Node *mother)
{
    this->mother = mother;
}
void Node::setRelation(string gender)
{
    if (this->level == 1)
        this->relation = gender;
    else if (this->level == 2)
        this->relation = "grand" + gender;
    else if (this->level > 2)
    {
        string temp = "grand" + gender;
        for (int i = 0; i < this->level - 2; i++)
        {
            temp = "great-" + temp;
        }
        this->relation = temp;
    }
}
Node *Node::getFather()
{
    return this->father;
}
Node *Node::getMother()
{
    return this->mother;
}
int Node::getLevel()
{
    return this->level;
}
string Node::getName()
{
    return this->name;
}
string Node::getRelation()
{
    return this->relation;
}

// Tree class

//public
Tree &Tree::addFather(string child, string father)
{
    Node *c = findChild(root, child, "name");
    if (c == NULL)
        throw runtime_error("Child was not found");

    if (c->getFather() != NULL)
        throw runtime_error("Child already got father");

    Node *f = new Node(father, c->getLevel() + 1);
    f->setRelation("father");
    c->setFather(f);
    return *this;
}
Tree &Tree::addMother(string child, string mother)
{
    Node *c = findChild(root, child, "name");
    if (c == NULL)
        throw runtime_error("Child was not found");

    if (c->getMother() != NULL)
        throw runtime_error("Child already got mother");

    Node *m = new Node(mother, c->getLevel() + 1);
    m->setRelation("mother");
    c->setMother(m);
    return *this;
}
void Tree::display()
{
    display(this->root);
    cout << endl;
}
void Tree::display(Node *r)
{
    if (r == NULL)
        return;
    cout << r->getName() << ":" << r->getLevel() << ":" << r->getRelation() << ",";
    display(r->getFather());
    display(r->getMother());
}

string Tree::relation(string name)
{
    Node *c = findChild(root, name, "name");
    if (c == NULL)
        return "unrelated";
    return c->getRelation();
}
string Tree::find(string relation)
{
    Node *c = findChild(root, relation, "relation");
    if (c == NULL)
        throw runtime_error("Child was not found");
    return c->getName();
}
void Tree::remove(string name)
{
    Node *c = findChild(root, name, "name");
    if (c == NULL)
    {
        throw runtime_error("Child was not found");
    }
    if (c->getLevel() == 0)
    {
        throw runtime_error("Child is the root , can't remove");
    }
    Node *children = findByParent(root, c->getName());
    if (c->getRelation().find("father") != std::string::npos)
    {
        children->setFather(NULL);
    }
    else if (c->getRelation().find("mother") != std::string::npos)
    {
        children->setMother(NULL);
    }
    remove(c);
};
void Tree::remove(Node *r)
{
    if (r->getFather() != NULL)
        remove(r->getFather());
    if (r->getMother() != NULL)
        remove(r->getMother());
    else if (r != NULL)
    {
        delete r;
    }
}

Node *Tree::findChild(Node *root, string child, string searchType)
{
    if (root == NULL)
        return NULL;

    string field = root->getName(); // default search by name
    if (searchType == string("relation"))
        field = root->getRelation();

    if (field == child)
        return root;

    return findChild(root->getFather(), child, searchType) ?: findChild(root->getMother(), child, searchType);
}

Node *Tree::findByParent(Node *root, string child)
{
    if (root == NULL)
        return NULL;

    if (root->getFather() != NULL && root->getFather()->getName() == child)
        return root;

    else if (root->getMother() != NULL && root->getMother()->getName() == child)
        return root;

    return findByParent(root->getFather(), child) ?: findByParent(root->getMother(), child);
}