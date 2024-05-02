/*************************************************
 * ADS Praktikum 1.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>

using namespace std;

Tree::Tree(): m_anker(nullptr), m_CurrentNodeChronologicalID(0){}

Tree::~Tree()
{
    queue<TreeNode*> q;

    if(m_anker != nullptr) q.push(m_anker);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        

        if (current->getLeft() != nullptr) q.push(current->getLeft());
        if (current->getRight() != nullptr) q.push(current->getRight());

        delete current;
    }
    
}

void Tree::addNode(string name, int age, double income, int postcode)
{
    int nodeOrderID = age + income + postcode;

    TreeNode* newNode = new TreeNode(nodeOrderID, m_CurrentNodeChronologicalID, name, age, income, postcode);
    m_CurrentNodeChronologicalID++;
    //Tree ist leer
    if (m_anker == nullptr) m_anker = newNode;
    //Tree ist nicht leer
    else
    {
        TreeNode* current = m_anker;
        
        while (true)
        {
            if (newNode->getNodeOrderID() < current->getNodeOrderID())
            {
                if (current->getLeft() == nullptr)
                {
                    current->setLeft(newNode);
                    break;
                }
                else current = current->getLeft();
            }
            else
            {
                if (current->getRight() == nullptr)
                {
                    current->setRight(newNode);
                    break;
                }
                else current = current->getRight();
            }
        }      
    }
}

bool Tree::deleteNode(int nodeOrderID){
    TreeNode* current = m_anker;
    TreeNode* parent = nullptr;
    bool deleted = false;

    while (current != nullptr)
    {
        if (current->getNodeOrderID() == nodeOrderID){
            //Node hat keine Kinder
            if (current->getLeft() == nullptr && current->getRight() == nullptr){
                if (parent == nullptr) m_anker = nullptr;
                else if (parent->getLeft() == current) parent->setLeft(nullptr);
                else parent->setRight(nullptr);
                                
                delete current;
                deleted = true;
                break;
            }
            //Node hat ein Kind
            else if(current->getLeft() == nullptr && current->getRight() != nullptr 
            || current->getRight() == nullptr && current->getLeft() != nullptr){
                //erstes element
                if (parent == nullptr){
                    m_anker = (current->getLeft() != nullptr) ? current->getLeft() : current->getRight();
                }
                //mitten in der Liste
                else{
                    //ist linkes Kind
                    if (parent->getLeft() == current){
                        parent->setLeft((current->getLeft() != nullptr) ? current->getLeft() : current->getRight());
                    }
                    //ist rechtes Kind
                    else{
                        parent->setRight((current->getLeft() != nullptr) ? current->getLeft() : current->getRight());
                    }
                }
                delete current;
                deleted = true;
                break;
            }
            //Node hat zwei Kinder
            else{
                //ermitteln das min rechter Teilbaum
                TreeNode* minNode = current->getRight();
                TreeNode* minParent = current;
                while (minNode->getLeft() != nullptr)
                {
                    minParent = minNode;
                    minNode = minNode->getLeft();
                }
                
                //nur Pointer umbiegen falls minNode nicht direktes Kind von min Parent
                if(minParent->getRight() != minNode){
                    minParent->setLeft((minNode->getRight() != nullptr) ? minNode->getRight() : nullptr);                  
                }

                minNode->setLeft(current->getLeft());
                //falls der zulöschende Node parent von minNode ist, keine schleife erzeugen
                if(minNode != current->getRight()) minNode->setRight(current->getRight());

                //wenn parent == nullptr sind wir anker
                if (parent == nullptr) m_anker = minNode;
                //seite von parent rausfinden und pointer auf den neun Node setzen
                else if (parent->getLeft() == current) parent->setLeft(minNode);
                else parent->setRight(minNode);

                delete current;
                deleted = true;
                break;
            }            
        }
        //weiter nach current suchen
        else{
            if (nodeOrderID > current->getNodeOrderID()){
                parent = current;
                current = current->getRight();
            }
            else{
                parent = current;
                current = current->getLeft();
            }        
        }
    }
    
    return deleted;
}

bool Tree::searchNode(string name){
    bool result = false;
    queue<TreeNode*> q;

    if(m_anker != nullptr) q.push(m_anker);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        if (current->getName() == name){
            result = true;
            break;
        }

        if (current->getLeft() != nullptr) q.push(current->getLeft());
        if (current->getRight() != nullptr) q.push(current->getRight());
    }
    
    return result;
}

void Tree::printAll(){
    cout << "Ausgabereihenfolge ?>";
    string in;
    

    while (true)
    {
        cin >> in;
    if (in == "pre"){ 
        printPreOrder();
        break;
    }
    else if (in == "in"){
        printInOrder();
        break;
    }
    
    else if (in == "post"){
        printPostOrder();
        break;
    }
    else cout << "Falsche Eingabe" << endl;    
    }
    
    
};
void Tree::levelOrder(){
    queue<TreeNode*> q;
    queue<int> level({0});
    cout << "id name age income postcode level" << endl;

    if(m_anker != nullptr) q.push(m_anker);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        cout << current->getNodeOrderID() << " " << current->getName() << " " << current->getAge() << " " << current->getIncome() << " " << current->getPostCode() << " " << level.front() <<endl;

        if (current->getLeft() != nullptr)
        {
            q.push(current->getLeft());
            level.push(level.front() + 1);
        } 
        if (current->getRight() != nullptr)
        {
            q.push(current->getRight());
            level.push(level.front() + 1);
        }
        level.pop();
    }
};

void Tree::printPreOrder(){
    cout << "id name age income postcode" << endl;
    preOrderHelper(m_anker);
}

void Tree::preOrderHelper(TreeNode* node){
    
    cout << node->getNodeOrderID() << " " << node->getName() << " " << node->getAge() << " " << node->getIncome() << " " << node->getPostCode() << endl;
    if (node->getLeft() != nullptr) preOrderHelper(node->getLeft());
    if (node->getRight() != nullptr) preOrderHelper(node->getRight());
}
void Tree::printInOrder(){
    cout << "id name age income postcode" << endl;
    inOrderHelper(m_anker);
};

void Tree::inOrderHelper(TreeNode* node){
    if (node->getLeft() != nullptr) inOrderHelper(node->getLeft());
    cout << node->getNodeOrderID() << " " << node->getName() << " " << node->getAge() << " " << node->getIncome() << " " << node->getPostCode() << endl;
    if (node->getRight() != nullptr) inOrderHelper(node->getRight());
}
void Tree::printPostOrder(){
    cout << "id name age income postcode" << endl;
    postOrderHelper(m_anker);
};

void Tree::postOrderHelper(TreeNode* node){
    if (node->getLeft() != nullptr) postOrderHelper(node->getLeft());
    if (node->getRight() != nullptr) postOrderHelper(node->getRight());
    cout << node->getNodeOrderID() << " " << node->getName() << " " << node->getAge() << " " << node->getIncome() << " " << node->getPostCode() << endl;
}

void Tree::printNode(string name){
    queue<TreeNode*> q;

    if(m_anker != nullptr) q.push(m_anker);

    while (!q.empty())
    {
        TreeNode* current = q.front();
        q.pop();

        if (current->getName() == name){
            cout << current->getNodeOrderID() << " " << current->getName() << " " << current->getAge() << " " << current->getIncome() << " " << current->getPostCode() << endl;
            break;
        }
        if (current->getLeft() != nullptr) q.push(current->getLeft());
        if (current->getRight() != nullptr) q.push(current->getRight());
    }
}