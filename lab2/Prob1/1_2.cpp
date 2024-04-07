#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


map<int, int>mp[150005];//mp[i]表示i号点相连的所有点及其距离

void my_low_dij()
{
	int n, m;
	cin >> n >> m;

	vector<ll>dis(n + 1, 1e18);//起点到每个点的距离
	vector<ll>yes(n + 1);//表示最短路是否已经确定
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
	for (int i = 1; i <= n; i++)
	{
		int now = 0;//当前的最短路可达点
		for (int j = 1; j <= n; j++)
		{
			if (yes[j] == 0 && dis[j] < dis[now])
				now = j;
		}
		if (now == 0)//存在点不可达
		{
			if (dis[n] < 1e17)printf("%lld\n", dis[n]);
			else printf("-1\n");
			return;
		}
		yes[now] = 1;
		for (auto x : mp[now])
			dis[x.first] = min(dis[x.first], dis[now] + x.second);
	}
	printf("%lld\n", dis[n]);
}


signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	my_low_dij();

	return 0;
}