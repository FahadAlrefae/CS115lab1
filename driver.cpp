//
//  driver.cpp
//  csci115lab1
//
//  Created by Fahad alrefae on 1/27/17.
//  Copyright © 2017 Fahad alrefae. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "relation.h"

using namespace std;

int main()
{
    int n, e1, e2;
    cout << "Enter your number of elements in the relation: ";
    cin >> n;
    if (n <= 0) // The number of relation should be positive
    {
        cerr << "Error: number of elements must be positive" << endl;
        cout << endl;
        main(); //recursive call
    }
    
    cout << endl;
    Relation *rel= new Relation(n);

    
    while (1)
    {
        int input;
        cout << "1 - print relation information" << endl;
        cout << "2 - insert a pair into the relation" << endl;
        cout << "3 - list all pairs in the relation" << endl;
        cout << "4 - list all successors of a particular element" << endl;
        cout << "5 - list all predecessors of a particular element" << endl;
        cout << "6 - quit" << endl << endl;
        cout << "Choose a function (1 - 6): ";
        cin  >>  input;
        cout << endl << endl;
        
        switch (input)
        {
            case 1:
                cout << "Relation has " << rel->num_elts() << " element and " << rel->num_pairs() << " pairs " << endl << endl;
                break;
                
            case 2:
                cout << "Enter two elements, separated by a space: ";
                cin >> e1 >> e2;
                cout << endl;
                rel->insert_pair(e1, e2);
                break;
                
            case 3:
                rel->list_pairs();
                cout << endl;
                cout << endl;
                break;
                
            case 4:
                cout << "Enter the element to list all of the successors of: ";
                cin >> e1;
                cout << endl << endl;
                rel->list_succs(e1);
                break;
                
            case 5:
                cout << "Enter the element to list all of the predecessors of: ";
                cin  >> e2;
                cout << endl << endl;
                rel->list_preds(e2);
                break;
                
            case 6:
                exit(0);
        }
    }
}
