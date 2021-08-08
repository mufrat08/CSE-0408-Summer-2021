#include <bits/stdc++.h>
using namespace std;
int M,N;
int parent[100];
int cost [1000][10000];
int find(int i)
{

	while (parent[i] != i)
        i = parent[i];
    return i;
}


void union1(int i, int j)
{
	int s = find(i);
	int r = find(j);
	parent[s] = r;
}


void BFsMST()
{
	int mincost = 0;
	int edge_count = 0;
	while (edge_count < M - 1)
    {
		int min = INT_MAX, s = -1, r = -1;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++)
            {
				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					s = i;
					r = j;
				}
			}
		}

		union1(s, r);
        cout<<"Edge "<<edge_count++<<":("<<s<<" "<<r<<") cost:"<<min<<endl;
		mincost += min;
	}
	cout<<endl<<"Minimum cost= "<<mincost;
}


int main()
{



	M=8;
	N=9;
    for(int i=0;i<M;i++)
    {
        for(int j=0; j<M; j++)
        {
            cost[i][j]= INT_MAX;
        }
    }

   
cost[0][1]=1;
cost[0][2]=2;
cost[2][3]=3;
cost[3][4]=4;
cost[3][5]=5;
cost[5][4]=100;
cost[5][6]=7;
cost[6][7]=101;
cost[4][7]=8;
    for (int i = 0; i < M; i++)
        parent[i] = i;

	/// Print the solution
	BFsMST();
	return 0;
}
