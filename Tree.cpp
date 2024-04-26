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

Tree::Tree()
{
    m_anker = nullptr;
    m_CurrentNodeChronologicalID = 0;
}

Tree::~Tree()
{
    //TODO: Delete des ganzes Baumes
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