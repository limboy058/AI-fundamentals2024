#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


set<int>st[150005];//st[i]表示i号点相连的所有点

void my_bfs()
{
	int n, m;
	cin >> n >> m;

	vector<int>vis(n + 1);//vis[i]表示i是否被访问过
	for (int i = 1; i <= n; i++)
		st[i].clear();

	int tmp1, tmp2;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2;
		st[tmp1].insert(tmp2);
	}

	pii s = { 1,0 };//我在1号点，移动距离为0
	vis[1] = 0;
	queue<pii> q;
	q.push(s);
	int ans = -1;

	while (!q.empty())
	{
		auto tmp = q.front();
		q.pop();
		if (vis[tmp.first])continue;
		if (tmp.first == n)
		{
			ans = tmp.second;
			break;
		}
		vis[tmp.first] = 1;
		for (auto x : st[tmp.first])
		{
			if (vis[x])continue;
			q.push({ x,tmp.second + 1 });
		}
	}
	printf("%d\n", ans);
}

signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	my_bfs();

	return 0;
}