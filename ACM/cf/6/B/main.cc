# include <stdio.h>
# include <string.h>
int n, m, vis[26], next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char c, space, map[101][101];
int dfs(int x, int y)
{
    int mx, my;
    for(int i=0; i<4; ++i)
    {
        mx = x + next[i][0];
        my = y + next[i][1];
        if(mx<0 || my<0 || mx>=n || my>=m)
            continue;
        if(map[mx][my] != '.')
        {
            if(map[mx][my] != c)
            {
                vis[map[mx][my]-'A'] = 1;
                map[mx][my] = '.';
            }
            else
            {
                map[mx][my] = '.';
                dfs(mx, my);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d%c%c",&n,&m,&space,&c))
    {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i)
            scanf("%s",map[i]);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
            {
                if(map[i][j] == c)
                {
                    dfs(i, j);
                    break;
                }
            }
        for(int i=0; i<26; ++i)
            if(vis[i])
                ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
