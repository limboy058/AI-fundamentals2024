#include<bits/stdc++.h>//���������� BFS

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

void check(string s)//����Ƿ��н�
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
    int nxs=0;//������
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
                 {-1, 0}};//��ѡ�Ĳ������������ҽ���
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
