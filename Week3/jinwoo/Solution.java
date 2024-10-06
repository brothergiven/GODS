import java.util.*;

class Edge implements Comparable<Edge> {
    int v, w;
    Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
    @Override
    public int compareTo(Edge o) {
        return this.w - o.w;
    }
}

class Solution {
    final int max = 200000000;
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = max;
        List<Edge> graph[] = new ArrayList[n+1];
        for(int i = 1; i <= n; i++)
            graph[i] = new ArrayList<>();

        for(int[] fare : fares) {
            int u = fare[0];
            int v = fare[1];
            int w = fare[2];
            graph[u].add(new Edge(v, w));
            graph[v].add(new Edge(u, w));
        }

        int[] distT = dijkstra(n, s, graph);
        int[] distA = dijkstra(n, a, graph);
        int[] distB = dijkstra(n, b, graph);

        for(int i = 1; i <= n; i++)
            answer = Math.min(answer, distT[i] + distA[i] + distB[i]);

        return answer;
    }

    private int[] dijkstra(int n, int s, List<Edge>[] graph) {
        int[] dist = new int[n+1];
        Arrays.fill(dist, max);
        dist[s] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(s, 0));

        while(!pq.isEmpty()) {
            Edge cur = pq.poll();
            int v = cur.v;
            int w = cur.w;

            if(dist[v] < w) continue;

            for(Edge next : graph[v]) {
                int next_v = next.v;
                int next_w = next.w;

                if(dist[next_v] > w + next_w) {
                    dist[next_v] = w + next_w;
                    pq.add(new Edge(next_v, w + next_w));
                }
            }
        }
        return dist;
    }
}
