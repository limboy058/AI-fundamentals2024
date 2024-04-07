#include<bits/stdc++.h>//DFS ∞À ˝¬ÎŒ Ã‚ 
using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>


void solve()
{
	string s = "";
	for (int i = 1; i <= 9; i++)
	{
		string tmp;
		cin >> tmp;
		s = s + tmp;
	}
	set<string>st;//vis
	pii op[5] = { {0,0}, {0,1} ,{0,-1}, {1,0} ,{-1,0} };
	stack<string>stk;

	stk.push(s);
	while (!stk.empty())
	{
		string now = stk.top();
		stk.pop();
		if (now == "12345678x")
		{
			printf("1");
			exit(0);
		}
		st.insert(now);
		for (int i = 0; i < 9; i++)
		{
			if (now[i] == 'x')
			{
				string tmp;
				int x, y;
				for (int j = 1; j <= 4; j++)
				{
					x = i / 3 + op[j].first;
					y = i % 3 + op[j].second;
					if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
					{
						tmp = now;
						swap(tmp[i], tmp[x * 3 + y]);
						if (!st.count(tmp))
							stk.push(tmp);
					}
				}
			}
		}
	}

	printf("0");
}

signed main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	solve();

	return 0;
}
