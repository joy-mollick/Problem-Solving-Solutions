

    #include <bits/stdc++.h>
    using namespace std;
    #define mod 1000000007
    #define ll long long int
    #define pb push_back
    #define mk make_pair
    #define pp pair<pair<ll,ll>,pair<ll,ll> >
    vector<pair<ll,ll> >adj[100002];
    pair<ll,ll>dis[100002];
    priority_queue<pp,vector<pp>,greater<pp> >q;
    int main()
    {
    	ios_base::sync_with_stdio(0); cin.tie(0);
    	ll n,m,u,v,x,w;
    	cin>>n>>m;
    	while(m--) {
    		cin>>u>>v>>w;
    		adj[u].pb({v,w});
    		adj[v].pb({u,w});
    	}
    	for(ll i = 1; i <= n; i++) {
    		dis[i].first = dis[i].second = 1000000000000LL;
    	}
    	pp p;
    	p.first = {0,0};
    	p.second = {1,-1};
    	q.push(p);
    	dis[1].first = dis[1].second = 0;
    	while(q.size()) {
    		p = q.top();
    		q.pop();
    		u = p.second.first;
    		for(ll i = 0; i < adj[u].size(); i++) {
    			v = adj[u][i].first;
    			w = adj[u][i].second;
    			x = p.first.second + ((p.second.second == -1 || p.second.second == w%2)?0:1);
    			w += p.first.first;
    			pair<ll,ll>p1 = dis[v];
    			if(p1.first < w) continue;
    			if(p1.first == w && p1.second < x) continue;
    			dis[v] = {w,x};
    			q.push({{w,x},{v,(adj[u][i].second)%2}});
    		}
    	}
    	cout<<dis[n].first<<" "<<dis[n].second<<endl;
    	return 0;
    }
