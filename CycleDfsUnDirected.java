import java.util.*;



public class Sol
{
    public boolean CheckForCycle(int node,int parent,ArrayList<ArrayList<Integer>> adj,boolean[] vis)
    {
        vis[node]=true;
        for(Integer it:adj.get(node))
        {
            if(vis[it]==false)
            {
                if(CheckForCycle(it,node,adj,vis)) return true;
            }
            else if(parent!=it)
            return true;
        }
        return false;
    }
    
    
    public boolean isCycle(int v,ArrayList<ArrayList<Integer>> adj)
    {
        boolean vis[]=new boolean[v+1];
        
        for(int i=1;i<=v;i++)
        {
            if(vis[i]==false)
            {
            if(CheckForCycle(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }

    public static void main(String[] args)
    {   Sol d=new Sol();
        Scanner S=new Scanner(System.in);
        int n,m;
        System.out.println("Enter number of vertices : ");
        n=S.nextInt();
        System.out.println("Enter number of Edges : ");
        m=S.nextInt();
        ArrayList<ArrayList<Integer>> adj=new ArrayList<ArrayList<Integer>> ();
        for(int i=0;i<=n;i++)
        {
            adj.add(new ArrayList<Integer>());
        }
        
        for(int i=1;i<=m;i++)
        {
            int u,v;
            u=S.nextInt();
            v=S.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        if(d.isCycle(n,adj))
        System.out.println("YES CYCLE EXIST's....");
        else
        System.out.println("NO CYCLE DO NOT EXIST's....");
    }
    
}

    
        
        
    
