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

    void  printPreOrder();
    void  printInOrder();
    void  printPostOrder();

    void preOrderHelper(TreeNode* node);
    void inOrderHelper(TreeNode* node);
    void postOrderHelper(TreeNode* node);

    void printTHead(bool level);
public:
    Tree();
    ~Tree();

    void addNode(string name, int age, double income, int postcode);
    bool deleteNode(int nordeOrderID);
    bool searchNode(string name);
    void printAll();
    void levelOrder();
    void printNodes(string name);

    
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode* get_anker(Tree& TN);
};
