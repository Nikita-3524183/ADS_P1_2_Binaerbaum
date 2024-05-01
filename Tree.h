/*************************************************
 * ADS Praktikum 1.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>
#include <queue>

using namespace std;

class Tree
{

private:
    TreeNode* m_anker;
    int m_CurrentNodeChronologicalID;

    void printPreOrder();
    void printInOrder();
    void printPostOrder();

    
public:
    Tree();
    ~Tree();

    void addNode(string name, int age, double income, int postcode);
    bool deleteNode(int nordeOrderID);
    bool searchNode(string name);
    void printAll();
    void levelOrder();

    
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
