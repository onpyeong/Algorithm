/*
2번의 다익스트라 풀이
정방향 (X -> i 까지의 최단 거리)
역방향 (X -> i 까지의 최단 거리) - 사실상 i -> X로 들어가는 최단임
import java.io.*;
import java.util.*;

public class Main {

    static int N, M, X;
    static List<Edge>[] graph;
    static List<Edge>[] reverseGraph;
    static int[] distFromX;
    static int[] distToX;

    static class Edge {
        int city, time;
        public Edge(int city, int time) {
            this.city = city;
            this.time = time;
        }
    }

    private static void dijkstra(List<Edge>[] g, int[] dist, int start) {
        Arrays.fill(dist, Integer.MAX_VALUE);
        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.time - b.time);

        dist[start] = 0;
        pq.offer(new Edge(start, 0));

        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            int x = cur.city;
            int t = cur.time;

            if (t > dist[x]) continue;

            for (Edge edge : g[x]) {
                int newDist = dist[x] + edge.time;
                if (newDist < dist[edge.city]) {
                    dist[edge.city] = newDist;
                    pq.offer(new Edge(edge.city, newDist));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        reverseGraph = new ArrayList[N + 1];

        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
            reverseGraph[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            graph[s].add(new Edge(e, t));         // 정방향
            reverseGraph[e].add(new Edge(s, t));  // 역방향
        }

        distFromX = new int[N + 1]; // X → i
        distToX = new int[N + 1];   // i → X

        // X → 모든 노드
        dijkstra(graph, distFromX, X);
        // 모든 노드 → X (역방향에서 X 출발)
        dijkstra(reverseGraph, distToX, X);

        int maxTime = 0;
        for (int i = 1; i <= N; i++) {
            int roundTrip = distToX[i] + distFromX[i];
            if (roundTrip > maxTime) {
                maxTime = roundTrip;
            }
        }

        System.out.println(maxTime);
    }
}

*/

import java.util.*;
import java.io.*;

public class Main {
  
  static int N, M, X;
  static int s, e, t;
  static List<Edge> graph[];
  static int minDist[];
  
  static class Edge{
    int city;
    int time;
    
    public Edge(int city, int time) {
      this.city = city;
      this.time = time;
    }
  }
  
  private static int calcMinDist(int start, int end) {
    PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> a.time - b.time);
    int x;
    
    pq.offer(new Edge(start, 0));
    minDist[start] = 0;
    while(!pq.isEmpty()) {
      x = pq.peek().city;
      t = pq.peek().time;
      pq.poll();
      
      if(t > minDist[x]) // 현재 위치에서 x까지 가는 시간 > 시작점 minDist[x]
        continue;
        
      for(Edge edge : graph[x]) {
        // s-x + 뻗어나가는 시간 < s-뻗어나간곳까지의 시간
        if(minDist[x] + edge.time  < minDist[edge.city]) {
          minDist[edge.city] = minDist[x] + edge.time;
          pq.offer(new Edge(edge.city, minDist[x] + edge.time);
        }
      }
    }
    
    return minDist[end];
  }
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    
    st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    X = Integer.parseInt(st.nextToken());
    
    graph = new ArrayList[N + 1];
    minDist = new int[N + 1];
    
    for(int i = 1; i <= N; i++) {
      graph[i] = new ArrayList<>();
    }
  
    for(int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      s = Integer.parseInt(st.nextToken());
      e = Integer.parseInt(st.nextToken());
      t = Integer.parseInt(st.nextToken());
      graph[s].add(new Edge(e, t));
    }
    
    int longTime = 0;
    for(int i = 1; i <= N; i++) {
       Arrays.fill(minDist, Integer.MAX_VALUE);
       int totalTime = calcMinDist(i, X);
       Arrays.fill(minDist, Integer.MAX_VALUE);
       totalTime += calcMinDist(X, i);
       if(longTime < totalTime) {
         longTime = totalTime;
       }
    }
    
    System.out.println(longTime);
    
  }
}
