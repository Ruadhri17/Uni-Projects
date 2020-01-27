#include <iostream>
#include <string>
#include "tree.hpp"

using namespace std;

int main()
{
    Dictionary<int, int> Dic1;
    Dic1.print_tree();
    Dic1.insert(10, 10);
    Dic1.insert(20, 20);
    Dic1.insert(30, 30);
    Dic1.insert(40, 40);
    Dic1.insert(50, 50);
    Dic1.insert(25, 60);
    Dic1.insert(45, 70);
    Dic1.insert(5, 80);
    Dic1.insert(45,80);
    cout << "========== FIRST PRINT AFTER INSERTION ==========" << endl;
    Dic1.print_tree();
    cout << endl << endl << endl << endl;
    cout << endl << "Preorder: ";
    Dic1.print_preorder();
    cout << endl << "Inorder: ";
    Dic1.print_inorder();
    cout << endl << "Postorder: ";
    Dic1.print_postorder();
    cout << endl << endl << endl << endl;
    Dictionary<int, int> Dic2 = Dic1;
    if(Dic1 == Dic2)
        cout << "Dic1 and Dic2 are equal!" << endl;
    Dic1.remove(30); // deletion of root
    Dic1.remove(10); // deletion inside
    Dic1.insert(100, 100);
    Dic1.insert(15, 15);
    cout << "========== SECOND PRINT AFTER DELETION AND SECOND INSERTION ==========" << endl;
    Dic1.print_tree();
    cout << endl << "Preorder: ";
    Dic1.print_preorder();
    cout << endl << "Inorder: ";
    Dic1.print_inorder();
    cout << endl << "Postorder: ";
    Dic1.print_postorder();
    cout << endl << endl << endl << endl;
    if(Dic1 != Dic2)
        cout << "Dic1 and Dic2 are not equal!" << endl;
    Dic1.remove_all();
    if(Dic1.is_empty())
        cout << "Dic1 is empty!" << endl;    
    cout << "==========  PRINT OF SECOND TREE ==========" << endl;
    Dic2.print_tree();
    return 0;


}