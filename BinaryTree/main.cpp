#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "BinaryTree: " << endl;
	BinaryTree tr(15);
	tr.insert(10);
	tr.insert(2);
	tr.insert(20);
	tr.insert(23);
	tr.insert(30);
	tr.print();
	tr.remove(20);
	cout << "1-if the tree has 23" << endl;
	cout << "0-if the tree hasn't 23" << endl;
	cout << "Result: " <<  tr.contains(23) << endl;
	cout << "New BinaryTree: " << endl;
	tr.print();

	cout << "dft_iterator: " << endl;
	Iterator* lst_iterator = tr.create_dft_iterator();
	while (lst_iterator->has_next()) {
		cout << lst_iterator->next() << ' ';
	}
	cout << "bft_iterator: " << endl;
	lst_iterator = tr.create_bft_iterator();
	while (lst_iterator->has_next()) {
		cout << lst_iterator->next() << ' ';
	}

	return 0;
}