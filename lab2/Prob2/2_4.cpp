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
