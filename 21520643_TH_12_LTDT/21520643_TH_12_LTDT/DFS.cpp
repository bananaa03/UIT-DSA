#include <iostream>
#include <vector>
#include<fstream>
#include <queue>
using namespace std;
int n, m, s, f;
vector<int> ke[1000];
bool vis[1000];
int b[1000];
ifstream ifile;
ofstream ofile("GRAPH.OUT");
void in()
{
    ifile >> n >> m >> s >> f;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ifile >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        vis[i] = false;
}
void DFS(int s)
{
    ofile << s << ",";
    vis[s] = true;
    for (int x : ke[s])
    {
        if (!vis[x])
        {
            DFS(x);
            b[x] = s;
        }
    }
}
void Timduong(int s, int f)
{
    memset(vis, false, sizeof(vis));
    memset(b, 0, sizeof(b));
    DFS(s);
    ofile << "\n";
    if (!vis[f])
        cout << "\nKhong co duong di";
    else
    {
        vector<int>d;
        while (f != s)
        {
            d.push_back(f);
            f = b[f];
        }
        d.push_back(s);
        reverse(d.begin(), d.end());
        ofile << d[d.size() - 1];
        for (int i = d.size() - 1; i > 0; i--)
            ofile << "<-" << i;
    }

}
int main()
{
    ifile.open("GRAPH.INP");
    in();
    DFS(s);
    ofile << "\n ";
    Timduong(s, f);
    ifile.close();
    ofile.close();
    system("pause");
    return 0;
}