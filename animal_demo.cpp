#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include "binary_tree.h"
using namespace std;


void playGame(binary_tree &tree);

int main() {
	binary_tree tree; 
	char choice;
	string animal,wrngAnimal;
	string question;

	bool not_done = true;

	tree.addRoot("dog");
	tree.current = tree.getRoot();
	cout << "Think of an animal... press Enter (<-') when you are ready!";
	cin.ignore(numeric_limits<streamsize>::max(), '\n' );
	cout << "Is it a " << tree.get(tree.current) <<" (Y/N)? ";
	cin >> choice;
	
	if(choice == 'y' || choice == 'Y')	{
	cout << "Play again? (Y/N)? ";
	cin >> choice;
	if(choice == 'y' || choice == 'Y')		
	playGame(tree);
	else
	tree.print(cout);
	return 0;
	}
	else
	cout << "What animal is it?";
	cin >> animal;

	cout << "What Yes/No question could I have asked to identify your animal?\n";
	cin.ignore();
	getline(cin,question);
	wrngAnimal = tree.getRoot()->data;

	tree.addRoot(question);
	tree.current = tree.getRoot();
	tree.addRight(tree.current,wrngAnimal);
	tree.addLeft(tree.current,animal);
	
	cout << "Play again? (Y/N)? ";
	cin >> choice;
	if(choice == 'y' || choice == 'Y')		
	playGame(tree);
	else
	tree.print(cout);
	return 0;
}



void playGame(binary_tree &tree){
	char choice;
	string animal,wrngAnimal;
	string question;
	bool not_done = true;
	
	cout << "Think of an animal... press Enter (<-') when you are ready!";
	cin.ignore(numeric_limits<streamsize>::max(), '\n' );

	cout << endl << tree.get(tree.getRoot()) <<" (Y/N)? ";
	cin >> choice;

	if(choice == 'y' || choice == 'Y'){
	cout << "Is it a " << tree.get(tree.current->left) <<" (Y/N)? ";
	cin >> choice;
	
	if(choice == 'y' || choice == 'Y'){
		cout << " Animal Successfully Guessed!\n";
	cout << "Play again? (Y/N)? ";
	cin >> choice;
	if(choice == 'y' || choice == 'Y')		
	playGame(tree);
	else{
	tree.print(cout);
	return;}
	}
}

	else

	cout << "What animal is it?";
	cin >> animal;

	cout << "What Yes/No question could I have asked to identify your animal? \n";
	cin.ignore();
	getline(cin,question);
	wrngAnimal = tree.get(tree.current->right);
	tree.current = tree.current->right;

	tree.addRight(tree.current,wrngAnimal);
	tree.addLeft(tree.current,animal);
	tree.current->data = question;
	
	cout << "Play again? (Y/N)? ";
	cin >> choice;
	if(choice == 'y' || choice == 'Y')	
	playGame(tree);
	else
	tree.print(cout);
	return;

}
