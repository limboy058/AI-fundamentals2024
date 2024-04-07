#include<bits/stdc++.h>//���������� A*

using namespace std;
#define db double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>

map<string, string> mp;//�洢��ʷ����
map<string, pii> dis;//�洢����ĳ����ģ���̾���+���յ�Ĺ��Ƽ�ֵ��,firstΪ�ܾ��룬secondΪʵ���߹��ľ���

void check(string s)//����Ƿ��н�
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
    int nxs = 0;//������
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

int cal(string s)//��������,�����پ���
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
                 {-1, 0}};//��ѡ�Ĳ������������ҽ���

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
        //˵��������û�и��¼�ֵ�ˣ��Ѿ��и��̹���

        dis[now.second]=now.first;//���¾���Ԫ��

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
