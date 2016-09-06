#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M, S, E;
vector<int> v[100];

int cnt;
void check1(int no)
{
	if (no == E-1)
	{
		cnt++;
		return;
	}
	for (int i = no; i < N; i++)
	{
		if (v[no][i] >= M)
			check1(i);
	}
}

void check2(int no)
{
	if (no == S-1)
	{
		cnt++;
		return;
	}
	for (int i = no; i >= 0; i--)
	{
		if (v[no][i] >= M)
			check2(i);
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++)
	{
		scanf("%d %d %d %d", &N, &M, &S, &E);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int tmp;
				scanf("%d ", &tmp);
				v[i].push_back(tmp);
			}
			scanf("\n");
		}
		printf("%d ", t);
		check1(S - 1);
		printf("%d ", cnt);
		cnt = 0;
		check2(E - 1);
		printf("%d\n", cnt);		
	}
	
	return 0;
}