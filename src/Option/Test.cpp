#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc,char * argv[])
{
	vector<int> intVec;
	intVec.push_back(1);
	intVec.push_back(3);
	intVec.push_back(6);

	int firstNum = 3;
	int secondNum = 2;
    vector<int>::iterator it = std::find(intVec.begin(),intVec.end(),firstNum);
	cout<<*it<<endl;

	if( it!= intVec.end())
	{
		cout<<"Find Result "<<*it<<endl;
	}
    vector<int>::iterator it2 = std::find(intVec.begin(),intVec.end(),secondNum);
	cout<<*it2<<endl;

	if( it2 != intVec.end())
	{
		cout<<"Find Result "<<*it2<<endl;
	}
	return 0;
}
