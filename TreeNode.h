/*************************************************
 * ADS Praktikum 1.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

#define lenID 5
#define lenName 20
#define lenAge 5
#define lenIncome 10
#define lenPostcode 10
#define lenLevel 5


using namespace std;

class TreeNode
{

private:
    int m_NodeOrderID;
    int m_NodeChronologicalID;
    string m_Name;
    int m_Age;
    double m_Income;
    int m_PostCode;

    TreeNode* m_left;
    TreeNode* m_right;

public:
    TreeNode(int nodeOrderID, int nodeChronologicalID, string name, int age, double income, int postcode);

    int getNodeOrderID();
    int getNodeChronologicalID();
    string getName();
    int getAge();
    double getIncome();
    int getPostCode();

    TreeNode* getLeft();
    TreeNode* getRight();

    void setNodeOrderID(int nodeOrderID);
    void setNodeChronologicalID(int nodeChronologicalID);
    void setName(string name);
    void setAge(int age);
    void setIncome(double income);
    void setPostCode(int postcode);

    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);

    void print();
};
