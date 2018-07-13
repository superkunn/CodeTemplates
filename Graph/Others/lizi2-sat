struct TWO_SAT //2*i-1 && 2*i
{
    int pre[2*maxn],sccno[2*maxn],low[2*maxn];
    int sta[2*maxn],stac;
    int dfs_clock,scc_cnt,n;
    stack<int> s;
    vector<int> g[2*maxn],gg[2*maxn];//gg for topsort
    bool mark[2*maxn];//solve for all
    int col[2*maxn],du[2*maxn];//solve for topsort
    queue<int> q;//solve for topsort
 
    void init(int x)
    {
        n=x;stac=0;
        for(int i=0;i<=2*n;i++)g[i].clear(),mark[i]=false,sta[i]=0;
    }
    
    void add1(int x,int xx,int y,int yy)//x,y && 0 for i , 1 for opposite
    {
        xx--;yy--;
        g[2*x+xx].pb(2*y+yy);
    }
    
    void add2(int x,int y)
    {
        g[x].pb(y);
    }
 
    void SCC(int u)
    {
        pre[u]=low[u]=++dfs_clock;
        s.push(u);
        for(auto v : g[u])
        {
            if(!pre[v])
            {
                SCC(v);
                low[u]=min(low[u],low[v]);
            }else if(!sccno[v])low[u]=min(low[u],pre[v]);
        }
        if(low[u]==pre[u])
        {
            scc_cnt++;
            for(;;)
            {
                int x=s.top();s.pop();
                sccno[x]=scc_cnt;
                if(x==u)break;
            }
        }
    }
 
    void tarjan()
    {
        dfs_clock=scc_cnt=0;
        for(int i=1;i<=2*n;i++)sccno[i]=pre[i]=low[i]=0;
        while(!s.empty())s.pop();
        for(int i=1;i<=2*n;i++)if(!pre[i])SCC(i);
    }
 
    bool judge()
    {
        tarjan();
        for(int i=1;i<=n;i++)
            if(sccno[i<<1]==sccno[(i<<1)-1])return false;
        return true;
    }
 
    bool dfs(int x)
    {
        int k=(x%2==0)?x-1:x+1;
        if(mark[k])return false;
        if(mark[x])return true;
        mark[x]=true;
        sta[stac++]=x;
        for(auto p : g[x])if(!dfs(p))return false;
        return true;
    }
 
    bool solve1()//DFS,can replace judge,can solve dictionary-min
    {
        for(int i=1;i<=n;i++)
        {
            int k=2*i-1;
            stac=0;
            if(!dfs(k))
            {
                while(stac>0)mark[sta[--stac]]=false;
                if(!dfs(k+1))return false;
            }
        }
        return true;
    }
 
    void solve2()//topsort , must after judge!!! 
    {
        int conf[scc_cnt+5];
        for(int i=1;i<=scc_cnt;i++)col[i]=du[i]=0,conf[i]=0;
        for(int i=1;i<=scc_cnt;i++)gg[i].clear();
        for(int i=1;i<=2*n;i++)
        {
            int k=sccno[i];
            int j=sccno[(i%2==0)?i-1:i+1];
            conf[j]=k;
            for(auto p : g[i])
            {
                int t=sccno[p];
                if(t==k)continue;
                gg[t].pb(k);
                du[k]++;
            }
        }
        while(!q.empty())q.pop();
        for(int i=1;i<=scc_cnt;i++)
            if(du[i]==0)q.push(i);
        int tot=0;
        while(tot<scc_cnt)
        {
            int x=q.front();q.pop();tot++;
            if(!col[x])
            {
                col[x]=1;
                col[conf[x]]=2;
            }
            for(auto p : gg[x])
            {
                du[p]--;
                if(du[p]==0)q.push(p);
            }
        }
        for(int i=1;i<=n;i++)
            if(col[sccno[2*i-1]]==1)mark[2*i-1]=true;else mark[2*i]=true;
    }
}ts;
