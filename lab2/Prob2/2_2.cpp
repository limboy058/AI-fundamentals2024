#pragma GCC optimize(2)

#include<bits/stdc++.h>//八数码问题 BFS 优化版(康托展开)

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

bool vis[400000];
int jc[10];

void check(string s)//检查是否有解
{
    if (s.length() != 9)
    {
        printf("-1\n");
        exit(0);
    }
    bool yes[9] = {0};
    for (auto x: s)
        if (x < '9' && x >= '0')yes[x - '0'] = 1;
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
            if (a == '0' || b == '0')continue;
            if (a > b)nxs++;
        }
    if (nxs % 2 == 1)
    {
        printf("-1\n");
        exit(0);
    }
}

inline int kt(string str)
{
    int ans = 0;
    int len = str.length();
    for(int i = 0; i < len; i++){
        int tmp = 0;
        for(int j = i + 1; j < len; j++)
            if(str[i] > str[j]) tmp++;
        ans += tmp * jc[len - i - 1];
    }
    return ans;
}


void solve()
{
    string s = "";
    jc[0]=1;
    for(int i=1;i<9;i++)
        jc[i]=i*jc[i-1];

    for (int i = 1; i <= 9; i++)
    {
        string tmp;
        cin >> tmp;
        if (tmp == "x")s = s + '0';
        else s = s + tmp;
    }

    check(s);

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
        if (now.second == "123456780")
        {
            printf("%d\n", now.first);
            exit(0);
        }
        vis[kt(now.second)] = 1;
        for (int i = 0; i < 9; i++)
        {
            if (now.second[i] == '0')
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
                        if (tmp == "123456780")
                        {
                            printf("%d\n", now.first+1);
                            exit(0);
                        }
                        else if (!vis[kt(tmp)])
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

    solve();

    return 0;
}
