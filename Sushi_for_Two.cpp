#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100003];
	int t;
	cin>>t;
	for(int i = 0 ; i < t ; i++)
		cin>>a[i];
	int one = 0;
	int two = 0;
	int flag = 0;
	int ans = 0;

	if(a[0]==1)
		one++;
	else
		two++;

	for(int i = 1 ; i <t ; i++)
	{
		if(a[i-1] != a[i])	//this is the code to check if there is any change in the sequencw
			flag++;
		if(flag==2)	//if the flag is 2 it means there one set of 11111222222 completed
		{
			ans = max(ans, min(one, two));
			if(a[i]==1)	//we are selectively putting the counter to 0 since 2211 is also valid
				one = 0;
			else
				two = 0;
			flag = 1;
		}	
		if(a[i]==1)
			one++;
		else 
			two++;
	}
	ans = max(ans, min(one, two)); //this has been added so that it can update ans is new ans is found int he last run throught array.
	cout<<ans*2;
	return 0;
}

