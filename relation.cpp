//
//  main.cpp
//  csci115lab1
//
//  Created by Fahad alrefae on 1/27/17.
//  Copyright © 2017 Fahad alrefae. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "relation.h"


using namespace std;



    
List::List() //initilize members
{
    head = NULL;
    length = 0;
}


Relation::Relation (int n){ // constructing a new list of lists
    succs = (List*) malloc (n); // creating n number of elements by asking the user in the driver.cpp file to dynamically allocate the array
    int i = 0;
    this->nelts = 0;
    while (i < n)
    {
     succs[i] = *new List(); // creating lists inside of the sucss list
     i++;
    nelts++;
    succs->length++;
    }
};



int Relation::num_elts()
{
    return (nelts); //returns the number of elements
}



void Relation::insert_pair(int e1, int e2){
   
    if ((e1 >= (this->num_elts())) || (e2 >= (this->num_elts()))) // in case the pairs are larger than the elements
    {
        cerr << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    
    if (succs[e1].lookup(e2)) // using the lookup function to search through the list of e1 which is used as an index
    {
        return;
    }
    
    succs[e1].cons(e2); // adding to beggining of the list if new pair is added with conditions met
    succs[e1].length++; // incremening the length everytime a new pair added
    
    (this->npairs)++;
    
    return;
    
}

int Relation::num_pairs() //returns number of pairs
{
    return (this->npairs);
}

void Relation::list_pairs()
{
    Node* p;
    
    for (int i = 0; i < (num_elts()); i++)
    {
        p = succs[i].head;
        
        if (p == NULL)
        {
            continue; //ignore in case the list is empty
        }
        
        while (p->next != NULL) // print pairs every time it has nodes
        {
            cout << '(' << i << ',' << p->value << ") ";
            p  = p->next;
        }
        
        if (p->next == NULL)
        {
            cout << '(' << i << ',' << p->value << ") ";
        }
    }
    cout << endl << endl;
}

void Relation::list_succs(int e)
{
    
    if (e >= (this->num_elts()) || (e < 0)) // if the number entered is greater than the number of elements or less than 0 then it is not in the list
    {
        cerr << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    else
    {
        
    Node* p = succs[e].head;
    
    
    cout << "Successors: " ;
    if (p == NULL)
    {
        cout << endl << endl; // ignore if the list is empty
        return;
    }
    
    while (p->next != NULL) // if not empty
    {
        cout << p->value << " ";
        p = p->next;
    }
    
    if (p->next == NULL)
    {
        cout << p->value << " ";
    }
    }
    cout << endl << endl;
    
    return;
}

void Relation::list_preds(int e)
{
    if (e >= (this->num_elts()) || (e < 0)) // if the number entered is greater than the number of elements or less than 0 then it is not in the list
    {
        cerr << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    
    Node* p;
    
    cout << "Predecessors: ";
    
    for (int i = 0; i < (num_elts()); i++)
    {
        p = succs[i].head;
        
        if (p == NULL)
        {
            continue;
        }
        
        if (p->next == NULL)
        {
            if (p->value == e)
            {
                cout << i << " ";
            }
        }
        
        while (p->next != NULL)
        {
            if (p->value == e)
            {
                cout << i << " ";
            }
            p = p->next;
        }
 
    }
    
    cout << endl << endl;
    
    return;
}


void List::cons(int e)
{
    Node* nn = new Node();
    nn->value = e;
    
    if (this->head == NULL) // if the list is empty, set the new node as the head
    {
        this->head = nn;
        nn->next = NULL;
        return;
    }
    
    nn->next = this->head; // if the list is not empty, link to the head then add to the beggining to the new list
    this->head = nn;
    
    return;
}
bool List::lookup(int e) // searches through the list
{
    Node* p = head;
    if (head == NULL) // if it is empty then it is not in the list
    {
        return false;
    }
    
    while (p->next != NULL) // if not empty seach through the list and return true if it maches the target
    {
        if (p->value == e)
        {
            return true;
        }
        p = p->next;
    }
    
    if (p->value == e)
    {
        return true; // if the head has value then stop
    }
    
    return false;
}


int Relation::num_succs(int e)
{
    Node* p = succs[e].head;
    
    int count = 0; //counter
    
    if (p == NULL) 
    {
        return 0;
    }
    
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    
    if (p->next == NULL)
    {
        count++;
    }
    
    return count;
}
