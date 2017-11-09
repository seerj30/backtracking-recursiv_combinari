#include<iostream>
#include<fstream>
using namespace std;
int n,m;
ofstream g("out.txt");
void back(int st[], int k)
{
	int i,ev,j;
	if(k==m+1)
	{
		for(int i = 1; i < k; i++)
			g << st[i] << " ";
		g << endl;
	}
	else
		for(int i = 1; i <= n; i++)
		{
			st[k] = i;
			ev=1;
			for(j = 1; j < k; j++)
				if(st[j] == st[k])
					ev=0;
			if(k>1 && st[k]<st[k-1])
				ev=0;
			if(ev)
				back(st, k+1);
		}
}

int main()
{
	int st[50];
	cout << "n="; cin >> n;
	cout << "m="; cin >> m;
	back(st, 1);
	return 0;
}
