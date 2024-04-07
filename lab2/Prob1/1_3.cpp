#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


map<int, int>mp[150005];//mp[i]表示i号点相连的所有点及其距离


void my_dij()
{
	int n, m;
	cin >> n >> m;

	vector<ll>dis(n + 1, 1e18);//起点到每个点的距离
	vector<ll>yes(n + 1);//表示最短路是否已经确定
	priority_queue<pll, vector<pll>, greater<pll>>q;
	for (int i = 0; i <= n; i++)
		mp[i].clear();

	int tmp1, tmp2, tmp3;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		if (mp[tmp1].count(tmp2))//对重边保留最小费用
			mp[tmp1][tmp2] = min(mp[tmp1][tmp2], tmp3);
		else
			mp[tmp1][tmp2] = tmp3;
	}

	dis[1] = 0;
	q.push({ 0,1 });//花费0，在1号点
	while (!q.empty())
	{
		auto now = q.top();
		q.pop();
		if (yes[now.second])continue;
		yes[now.second] = 1;
		dis[now.second] = now.first;
		if (yes[n])
		{
			printf("%lld\n", dis[n]);
			return;
		}
		for (auto x : mp[now.second])
		{
			if (!yes[x.first] && now.first + x.second < dis[x.first])
			{
				q.push({ now.first + x.second ,x.first });
				dis[x.first] = now.first + x.second;
			}
		}
	}
	printf("-1\n");
}

signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	my_dij();

	return 0;
}