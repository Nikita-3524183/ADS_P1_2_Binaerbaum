/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

TreeNode::TreeNode(int    nNodePos,
                   int    id,
                   string name,
                   int    alter,
                   double einkommen,
                   int    plz)
{
    this->m_NodeOrderID	= nNodePos;
    this->m_NodeChronologicalID = id;
    this->m_Name = name;
    this->m_Age	= alter;
    this->m_Income = einkommen;
    this->m_PostCode = plz;
    this->m_left = nullptr;
    this->m_right = nullptr;
}

int TreeNode::getNodeOrderID() { return this->m_NodeOrderID; }
int TreeNode::getNodeChronologicalID() { return this->m_NodeChronologicalID; }
string TreeNode::getName() { return this->m_Name; }
int TreeNode::getAge() { return this->m_Age; }
double TreeNode::getIncome() { return this->m_Income; }
int TreeNode::getPostCode() { return this->m_PostCode; }
TreeNode* TreeNode::getLeft() { return this->m_left; }
TreeNode* TreeNode::getRight() { return this->m_right; }

void TreeNode::setNodeOrderID(int nodeOrderID) { this->m_NodeOrderID = nodeOrderID; }
void TreeNode::setNodeChronologicalID(int nodeChronologicalID) { this->m_NodeChronologicalID = nodeChronologicalID; }
void TreeNode::setName(string name) { this->m_Name = name; }
void TreeNode::setAge(int age) { this->m_Age = age; }
void TreeNode::setIncome(double income) { this->m_Income = income; }
void TreeNode::setPostCode(int postcode) { this->m_PostCode = postcode; }
void TreeNode::setLeft(TreeNode* left) { this->m_left = left; }
void TreeNode::setRight(TreeNode* right) { this->m_right = right; }

void TreeNode::print()
{
    cout << std::setw(lenID) << this->getNodeOrderID() << "|"
        << std::setw(lenName) << this->getName() << "|"
        << std::setw(lenAge) << this->getAge() << "|"
        << std::setw(lenIncome) << this->getIncome() << "|"
        << std::setw(lenPostcode) << this->getPostCode() << "|";
}