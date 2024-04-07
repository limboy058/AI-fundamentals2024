```c
#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


set<int>st[150005];//st[i]琛ㄧずi鍙风偣鐩歌繛鐨勬墍鏈夌偣

void my_bfs()
{
	int n, m;
	cin >> n >> m;

	vector<int>vis(n + 1);//vis[i]琛ㄧずi鏄惁琚闂繃
	for (int i = 1; i <= n; i++)
		st[i].clear();

	int tmp1, tmp2;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2;
		st[tmp1].insert(tmp2);
	}

	pii s = { 1,0 };//鎴戝湪1鍙风偣锛岀Щ鍔ㄨ窛绂讳负0
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
```

```c
#pragma  optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


map<int, int>mp[150005];//mp[i]琛ㄧずi鍙风偣鐩歌繛鐨勬墍鏈夌偣鍙婂叾璺濈

void my_low_dij()
{
	int n, m;
	cin >> n >> m;

	vector<ll>dis(n + 1, 1e18);//璧风偣鍒版瘡涓偣鐨勮窛绂?
	vector<ll>yes(n + 1);//琛ㄧず鏈€鐭矾鏄惁宸茬粡纭畾
	for (int i = 0; i <= n; i++)
		mp[i].clear();

	int tmp1, tmp2, tmp3;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		if (mp[tmp1].count(tmp2))//瀵归噸杈逛繚鐣欐渶灏忚垂鐢?
			mp[tmp1][tmp2] = min(mp[tmp1][tmp2], tmp3);
		else
			mp[tmp1][tmp2] = tmp3;
	}

	dis[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		int now = 0;//褰撳墠鐨勬渶鐭矾鍙揪鐐?
		for (int j = 1; j <= n; j++)
		{
			if (yes[j] == 0 && dis[j] < dis[now])
				now = j;
		}
		if (now == 0)//瀛樺湪鐐逛笉鍙揪
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
```

```C
#pragma  optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
//#define int long long
#define pii pair<int,int>
#define pll pair<ll,ll>


map<int, int>mp[150005];//mp[i]琛ㄧずi鍙风偣鐩歌繛鐨勬墍鏈夌偣鍙婂叾璺濈


void my_dij()
{
	int n, m;
	cin >> n >> m;

	vector<ll>dis(n + 1, 1e18);//璧风偣鍒版瘡涓偣鐨勮窛绂?
	vector<ll>yes(n + 1);//琛ㄧず鏈€鐭矾鏄惁宸茬粡纭畾
	priority_queue<pll, vector<pll>, greater<pll>>q;
	for (int i = 0; i <= n; i++)
		mp[i].clear();

	int tmp1, tmp2, tmp3;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		if (mp[tmp1].count(tmp2))//瀵归噸杈逛繚鐣欐渶灏忚垂鐢?
			mp[tmp1][tmp2] = min(mp[tmp1][tmp2], tmp3);
		else
			mp[tmp1][tmp2] = tmp3;
	}

	dis[1] = 0;
	q.push({ 0,1 });//鑺辫垂0锛屽湪1鍙风偣
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
```



---

---



```c
#include<bits/stdc++.h>//DFS 八数码问题 
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
```

```c
#pragma GCC optimize(2)
#include<bits/stdc++.h>//八数码问题 BFS

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

void check(string s)//检查是否有解
{
    if(s.length()!=9)
    {
        printf("-1\n");
        exit(0);
    }
    bool yes[9]={0};
    for(auto x:s)
    {
        if(x<'9'&&x>='0')yes[x-'0']=1;
        if(x=='x')yes[0]=1;
    }
    for(int i=0;i<=8;i++)
    {
        if(!yes[i])
        {
            printf("-1\n");
            exit(0);
        }
    }
    int nxs=0;//逆序数
    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
        {
            char a=s[i],b=s[j];
            if (a=='x'||b=='x')continue;
            if(a>b)nxs++;
        }
    if(nxs%2==1)
    {
        printf("-1\n");
        exit(0);
    }
}


void solve()
{
    string s = "";

    for (int i = 1; i <= 9; i++)
    {
        string tmp;
        cin >> tmp;
        s = s + tmp;
    }

    check(s);

    set<string> st;//vis
    pii op[5] = {{0,  0},
                 {0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};//可选的操作，上下左右交换
    queue<pair<int, string>> q;

    q.emplace(0, s);
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        if (now.second == "12345678x")
        {
            printf("%d\n", now.first);
            exit(0);
        }
        st.insert(now.second);
        for (int i = 0; i < 9; i++)
        {
            if (now.second[i] == 'x')
            {
                string tmp;
                int x, y;
                for (int j = 1; j <= 4; j++)
                {
                    x = i / 3 + op[j].first;
                    y = i % 3 + op[j].second;
                    if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
                    {
                        tmp = now.second;
                        swap(tmp[i], tmp[x * 3 + y]);
                        if (!st.count(tmp))
                        {
                            q.emplace(1 + now.first, tmp);
                        }
                    }

                }
            }
        }
    }

    printf("-1");
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    solve();

    return 0;
}
```

```c
#pragma  optimize(2)
#include<bits/stdc++.h>//八数码问题 Dij

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

map<string, int> dis;//存储到达某个点的最短距离

void check(string s)//检查是否有解
{
    if (s.length() != 9)
    {
        printf("-1\n");
        exit(0);
    }
    bool yes[9] = {0};
    for (auto x: s)
    {
        if (x < '9' && x >= '0')yes[x - '0'] = 1;
        if (x == 'x')yes[0] = 1;
    }
    for (int i = 0; i <= 8; i++)
    {
        if (!yes[i])
        {
            printf("-1\n");
            exit(0);
        }
    }
    int nxs = 0;//逆序数
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
        {
            char a = s[i], b = s[j];
            if (a == 'x' || b == 'x')continue;
            if (a > b)nxs++;
        }
    if (nxs % 2 == 1)
    {
        printf("-1\n");
        exit(0);
    }
}

void solve()
{
    string s = "";

    for (int i = 1; i <= 9; i++)
    {
        string tmp;
        cin >> tmp;
        s = s + tmp;
    }

    check(s);

    pii op[5] = {{0,  0},
                 {0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};//可选的操作，上下左右交换

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;

    q.emplace(0, s);
    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        if (now.second == "12345678x")
        {
            printf("%d\n", now.first);
            exit(0);
        }

        if(dis.count(now.second))
            if(dis[now.second]<now.first)continue;
            //说明这条边没有更新价值了，已经有更短路

        dis[now.second]=now.first;//更新最小距离

        for (int i = 0; i < 9; i++)
        {
            if (now.second[i] == 'x')
            {
                string tmp;
                int x, y;
                for (int j = 1; j <= 4; j++)
                {
                    x = i / 3 + op[j].first;
                    y = i % 3 + op[j].second;
                    if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
                    {
                        tmp = now.second;
                        swap(tmp[i], tmp[x * 3 + y]);
                        if (!dis.count(tmp)||dis[tmp]>now.first+1)
                        {
                            q.emplace(1 + now.first, tmp);
                        }
                    }
                }
            }
        }
    }

    printf("-1");
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    solve();

    return 0;
}
```

```c
#pragma  optimize(2)
#include<bits/stdc++.h>//八数码问题 A*

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

map<string, string> mp;//存储历史操作
map<string, pii> dis;//存储到达某个点的（最短距离+距终点的估计价值）,first为总距离，second为实际走过的距离

void check(string s)//检查是否有解
{
    if (s.length() != 9)
    {
        printf("unsolvable\n");
        exit(0);
    }
    bool yes[9] = {0};
    for (auto x: s)
    {
        if (x < '9' && x >= '0')yes[x - '0'] = 1;
        if (x == 'x')yes[0] = 1;
    }
    for (int i = 0; i <= 8; i++)
    {
        if (!yes[i])
        {
            printf("unsolvable\n");
            exit(0);
        }
    }
    int nxs = 0;//逆序数
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
        {
            char a = s[i], b = s[j];
            if (a == 'x' || b == 'x')continue;
            if (a > b)nxs++;
        }
    if (nxs % 2 == 1)
    {
        printf("unsolvable\n");
        exit(0);
    }
}

int cal(string s)//启发函数,曼哈顿距离
{
    int ret=0;
    for(int i=0;i<9;i++)
    {
        if(s[i]!='x')
        {
            ret+=abs(i/3-(s[i]-'1')/3);
            ret+=abs(i%3-(s[i]-'1')%3);
        }
    }
    return ret;
}

void solve()
{
    string s = "";

    for (int i = 1; i <= 9; i++)
    {
        string tmp;
        cin >> tmp;
        s = s + tmp;
    }

    check(s);

    pii op[5] = {{0,  0},
                 {0,  1},
                 {1,  0},
                 {0,  -1},
                 {-1, 0}};//可选的操作，上下左右交换

    priority_queue<pair<pii, string>, vector<pair<pii, string>>, greater<pair<pii, string>>> q;


    q.push({{0+cal(s),0}, s});
    mp[s]="";

    while (!q.empty())
    {
        auto now = q.top();
        q.pop();
        if (now.second == "12345678x")
        {
            //printf("%d\n", now.first.first);
            printf("%s\n", mp[now.second].c_str());
            exit(0);
        }

        if(dis.count(now.second))
            if(dis[now.second].first<now.first.first)continue;
        //说明这条边没有更新价值了，已经有更短估计

        dis[now.second]=now.first;//更新距离元组

        for (int i = 0; i < 9; i++)
        {
            if (now.second[i] == 'x')
            {
                string tmp;
                int x, y;
                for (int j = 1; j <= 4; j++)
                {
                    x = i / 3 + op[j].first;
                    y = i % 3 + op[j].second;
                    if (x <= 2 && x >= 0 && y <= 2 && y >= 0)
                    {
                        tmp = now.second;
                        swap(tmp[i], tmp[x * 3 + y]);
                        if (!dis.count(tmp)||dis[tmp].first>now.first.second+1+cal(tmp))
                        {
                            q.push({{1+now.first.second+cal(tmp),1+now.first.second}, tmp});
                            if(j==1)mp[tmp]=mp[now.second]+'r';
                            if(j==2)mp[tmp]=mp[now.second]+'d';
                            if(j==3)mp[tmp]=mp[now.second]+'l';
                            if(j==4)mp[tmp]=mp[now.second]+'u';
                        }
                    }
                }
            }
        }
    }

    printf("unsolvable");
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    solve();

    return 0;
}
```

