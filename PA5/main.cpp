/*
* Name: Ben Kaufmann
* PA4
* CS 223
* This program parses data from a csv file and inserts it into a Red Black Tree
*
* 1.) Since red-black trees are balanced and don't need full traversal to insert, the big O to insert is O(logn)
* 2.) The remove function's big O is also O(logn) because it also does not need to traverse through the whole tree since it is balanced.
* 3.) Clear has a big O of O(n) since it does need to individually access each node.
*/






#include "RedBlackTree.h"
#include "RedBlackNode.h"
#include "InventoryRecord.h"
#include "fstream"
#include "sstream"

void parseIntoTree(RedBlackTree<InventoryRecord>* tree, fstream& input) {
    InventoryRecord* temp = new InventoryRecord();
    string line, idStr, numStr, type;
    int num, id;
    while (getline(input, line)) {
        istringstream buffer(line);
        getline(buffer, idStr, ',');
        getline(buffer, type, ',');
        getline(buffer, numStr);
        id = stof(idStr);
        num = stof(numStr);
        temp->setId(id);
        temp->setType(type);
        temp->setNumItems(num);
        tree->insert(*temp);
    }
}

int main() {
	RedBlackTree<InventoryRecord>* tree = new RedBlackTree<InventoryRecord>();
    InventoryRecord* temp = new InventoryRecord();
    fstream input;
    input.open("InventoryRecord.csv");
    parseIntoTree(tree, input);
    int response = 0, answerInt;
    string answerString;


    while (response != 4) {
        cout << "1. Add an item" << endl;
        cout << "2. Update an item" << endl;
        cout << "3. Display Tree" << endl;
        cout << "4. Exit" << endl;


        cin >> response;
        switch (response) {
        case 1:
            cout << "Adding new item to inventory..." << endl;
            cout << "Enter item name: ";
            cin >> answerString;
            temp->setType(answerString);
            cout << "\nEnter number of items: ";
            cin >> answerInt;
            temp->setNumItems(answerInt);
            cout << "\nEnter item ID: ";
            cin >> answerInt;
            temp->setId(answerInt);
            tree->insert(*temp);
            cout << "\n Your item has been added" << endl;
            break;

        case 2:
            cout << "What is the ID of the item you want to update? " << endl;
            cin >> answerInt;
            tree->update(tree->getRoot(), answerInt);
            break;
        case 3:
            tree->inOrder(tree->getRoot());
            break;
        }



    }

    input.close();
	return 0;
}