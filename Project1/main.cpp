#include "sequence.h"
#include <string>
using std::endl;
using std::cout;
using std::string;

int main()
{  

    // TESTING MERGE FROM REPORT //
    Sequence<int, int> SequenceFirst;
    Sequence<int, int> SequenceSecond;
    for(int i = 1; i < 10; i++)
        {
            SequenceFirst.pushBack(i, i);
        }
    for(int i = 10; i < 130; i+=10)
        {
            SequenceSecond.pushBack(i, i);
        }
    cout << "First Sequence: " << endl;
    SequenceFirst.print();
    cout << endl << "Second Sequence" << endl;
    SequenceSecond.print();
    Sequence<int, int> SequenceResult = merge(SequenceFirst, 2, 3, SequenceSecond, 1, 2, 4);
    cout << endl << "AFTER MERGE" << endl;
    SequenceResult.print();
    
    // EMPTY TEST //
    Sequence<char, int> List1; // list which consist of char key and int Info
    if(List1.isEmpty())
        cout << "List is empty" << endl;
    
    // ADDING TEST FOR LIST 1 AND LIST 2 //

    // LIST1 //
    List1.insert('d', 10, 0); // occurence cannot be 0, so we dont add this element
    List1.pushFront('a', 14); // adding at front, also as first element
    List1.pushBack('b', 69); // adding at the end
    List1.pushFront('c', 20); // again, we add at the beginning 
    List1.insert('a', 47, 1); // adding repeated key after that repeated key, occurence means after what repetition  
    List1.insert('b', 32, 4); // would add after 4th the same key but we dont have so many 'b' key so it will add nothing
    List1.insert('a', 32, 1); // again adding correctly key 'a' after first occurence so it will go between first and second 'a'
    List1.insert('c', 17, 1); // again but now after first occurence of c
    
    // FIND TEST //
    if(List1.findElement('a', 2))
        cout << "Element found on List1!" << endl;
    if(List1.findElement('b', 1))
        cout << "Element found on List1!" << endl;
    if(List1.findElement('d', 1))
        cout << "Element found on List1!" << endl << endl;


    // PRINT TEST //
    cout << endl << "List1" << endl << endl;
    List1.print(); // printing all added element
    
    // "=" OPERATOR AND COPY CONSTRUCTOR //
    cout << endl << endl <<endl;
    Sequence<char, int> List2(List1); // static new sequence
    Sequence<char, int> *List3 = &List1; //mdynamic new sequence
    
    // EQUALITY TEST //
    if(List1 == List2)
        cout <<"List1 and List2 are equal" << endl << endl; // will execute if list are equal
    
    // PRINTING TEST TO TEST COPYING // 
    //checking if List are equal at the moment //
    cout << endl << "List1" << endl << endl;
    List1.print(); 
    cout << endl << "List2" << endl << endl;
    List2.print(); 
    cout << endl << "List3" << endl << endl;
    List3->print(); 
    cout << endl << endl;

    // REMOVING TEST //
    List1.popBack(); // removing last element 
    List1.popFront(); // removing first element
    List1.remove('a', 2); // removing second occurence of 'a', so number 3232
    List1.removeAllKey('d'); // 'd' is not present on List so will remove nothing
    

    // CONTROL PRINTING TEST // 
    cout << endl << "List1" << endl << endl;
    List1.print(); // we shorten function by some elements 
    cout << endl << "List2" << endl << endl;
    List2.print(); // consist of element of List1 but is independent so didnt change
    cout << endl << "List3" << endl << endl; 
    List3->print(); // base on List1 so by removing some elements it  is shortened also
    cout << endl << endl;

    // LAST REMOVING TEST //
    List1.removeAllKey('a'); //removing all left 'a' occurences
    
    // CONTROL PRINTING TEST // 
    cout << endl << "List1" << endl << endl;    
    List1.print(); //checking if removing works 
    cout << endl << endl;
    List1.popBack();

    // DIFFERENT TYPE OF DATA //
    Sequence<int, string> List6;
    Sequence<int, string> List7;
    Sequence<int, string> List8;
    List6.pushFront(1, "James");
    List6.pushBack(2, "Martin");
    List6.pushFront(3, "Jerome");
    List6.insert(2, "Kevin", 1);
    List6.pushFront(4, "Mike");
    List6.insert(2, "William", 2);
    
    List7.pushBack(10, "Klara");
    List7.pushFront(11, "Franca");
    List7.insert(11, "Denisse", 1);
    List7.pushFront(13, "Tara");

    Sequence<int, string> List9 = List6;

    if(List9 == List6)
        cout << "List6 and List9 are equal" << endl << endl;
    
    cout << endl << "List6" << endl << endl;   
    List6.print();
    cout << endl << "List7" << endl << endl;   
    List7.print();
    List8 = merge(List6, 1, 2, List7, 1, 1, 3);
    cout << endl << "List8 (merged)" << endl << endl;   
    List8.print(); 
    if(List6 != List7)
        cout << endl << "List6 and List7 are not equal!" << endl;
    List7.removeAll();
    if(List7.isEmpty())
        cout << endl << "List7 is empty" << endl;

    return 0;
}
