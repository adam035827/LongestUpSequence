#include "ListOfStacks.h"

void ListOfStacks::processData(){
	clock_t t1, t2;

	//get file from user
	string infile;
	string outfile;

	cout << "What is the name of your input file? " << endl;
	cin >> infile;

	//check if file exists
	ifstream fin(infile);
	if (!fin)
	{
		cout << "file not found" << endl;
		system("pause");
	}

	cout << "What is the name of your output file? " << endl;
	cin >> outfile;

	//check if file exists
	ofstream fout(outfile,ios::app);
	if (!fout)
	{
		cout << "file not found" << endl;
		system("pause");
	}

	int input;

	while (fin.good())
	{
		while (fin.good())
		{
			fin >> input;
			Node* temp = new Node;
			temp->num = input;

			if (input == 0)
				break;
			if (stackCount == 0)
			{
				stacks.push_back(temp);
				stackCount++;
			}
			else
			{
				bool added = false;
				for (int i = 0; i < stackCount; i++)
				{
					if (stacks[i]->num > input)
					{
						if (i > 0)
						{ 
							temp->prevTop = stacks[i - 1];
						}
						temp->below = stacks[i];
						stacks[i] = temp;
						added = true;
						break;
					}
				}
				if (added == false)
				{
					temp->prevTop = stacks[stackCount - 1];
					stacks.push_back(temp);
					stackCount++;
				}
			}
		}
		findLongestUpSequence();
		findLargestUpSequence();
		outputLongestUpsequnce(fout);
		outputLargestUpSequence(fout);
		clearStacks();
	}
}

void ListOfStacks::findLongestUpSequence(){

	int total = 0;
	Node* next = stacks[stackCount -1];
	while (next != nullptr)
	{
		longestUpSequence.push(next->num);
		total += next->num;
		next = next->prevTop;
	}
	longestUpSequence.push(total);//add total to top of stack
}

void ListOfStacks::findLargestUpSequence(){
	
	int total = 0;
	Node* sequence = new Node;
	Node* temp = stacks[stackCount - 1];

	//find item at bottom of last stack
	while (temp != nullptr)
	{
		sequence = temp;
		temp = temp->below;
	}

	largestUpSequence.push(sequence->num);
	total += sequence->num;

	while (sequence->prevTop != nullptr)
	{
		sequence = sequence->prevTop;
		temp = sequence;
		while (temp->below != nullptr)
		{
			temp = sequence->below;
			if (temp->num < largestUpSequence.top()){
				sequence = temp;
			}
			if (temp->num >= largestUpSequence.top()){
				break;
			}
		}
		largestUpSequence.push(sequence->num);
		total += sequence->num;
	}
	largestUpSequence.push(total);//add total value to top of stack 
}

void ListOfStacks::outputLargestUpSequence(ofstream& out){
	out << "Total LargestUpSequence = " << largestUpSequence.top() << endl;
	largestUpSequence.pop();

	while (!largestUpSequence.empty())
	{
		out << largestUpSequence.top() << " ";
		largestUpSequence.pop();
	}
	out << "= Largest Upsequence" << endl;
	out << "LUS= " << stackCount << endl;
}

void ListOfStacks::outputLongestUpsequnce(ofstream& out){
	out << "Total LongestUpSequence = " << longestUpSequence.top() << endl;
	longestUpSequence.pop();

	while (!longestUpSequence.empty())
	{
		out << longestUpSequence.top() << " ";
		longestUpSequence.pop();
	}
	out << "= Longest Upsequence" << endl;
}

void ListOfStacks::clearStacks(){
	while(stackCount > 0)
	{
		delete stacks[stackCount - 1];
		stackCount--;
		stacks.pop_back();
	}
}