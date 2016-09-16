#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include<string>
#include<list>
#include<ctime>

using namespace std;

struct Node{
	int num = 0;
	Node* prevTop = nullptr;
	Node* below = nullptr;
};

class ListOfStacks{
private:
	int stackCount = 0;
	vector<Node*> stacks;
	stack<int> longestUpSequence;
	stack<int> largestUpSequence;
public:
	void processData();
	void outputLargestUpSequence(ofstream&);
	void outputLongestUpsequnce(ofstream&);
	void findLongestUpSequence();
	void findLargestUpSequence();
	void clearStacks();
};