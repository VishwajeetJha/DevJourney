import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class DijkstraRoutePlanner {
    static class Edge {
        final String to;
        final int weight;

        Edge(String to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static class NodeDistance {
        final String node;
        final int distance;

        NodeDistance(String node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }

    static class Graph {
        private final Map<String, List<Edge>> adjacency = new HashMap<>();

        void addEdge(String from, String to, int weight) {
            adjacency.computeIfAbsent(from, key -> new ArrayList<>()).add(new Edge(to, weight));
            adjacency.computeIfAbsent(to, key -> new ArrayList<>()).add(new Edge(from, weight));
        }

        PathResult shortestPath(String source, String destination) {
            Map<String, Integer> distance = new HashMap<>();
            Map<String, String> parent = new HashMap<>();

            for (String node : adjacency.keySet()) {
                distance.put(node, Integer.MAX_VALUE);
            }
            distance.put(source, 0);

            PriorityQueue<NodeDistance> pq = new PriorityQueue<>((first, second) -> Integer.compare(first.distance, second.distance));
            pq.add(new NodeDistance(source, 0));

            while (!pq.isEmpty()) {
                NodeDistance current = pq.poll();

                if (current.distance != distance.get(current.node)) {
                    continue;
                }

                for (Edge edge : adjacency.getOrDefault(current.node, Collections.emptyList())) {
                    int candidate = current.distance + edge.weight;
                    if (candidate < distance.get(edge.to)) {
                        distance.put(edge.to, candidate);
                        parent.put(edge.to, current.node);
                        pq.add(new NodeDistance(edge.to, candidate));
                    }
                }
            }

            if (!distance.containsKey(destination) || distance.get(destination) == Integer.MAX_VALUE) {
                return new PathResult(Collections.emptyList(), Integer.MAX_VALUE);
            }

            List<String> path = new ArrayList<>();
            String cursor = destination;
            while (cursor != null) {
                path.add(cursor);
                cursor = parent.get(cursor);
            }
            Collections.reverse(path);

            return new PathResult(path, distance.get(destination));
        }
    }

    static class PathResult {
        final List<String> path;
        final int totalCost;

        PathResult(List<String> path, int totalCost) {
            this.path = path;
            this.totalCost = totalCost;
        }
    }

    public static void main(String[] args) {
        Graph cityMap = new Graph();
        cityMap.addEdge("A", "B", 4);
        cityMap.addEdge("A", "C", 2);
        cityMap.addEdge("B", "C", 1);
        cityMap.addEdge("B", "D", 5);
        cityMap.addEdge("C", "D", 8);
        cityMap.addEdge("C", "E", 10);
        cityMap.addEdge("D", "E", 2);
        cityMap.addEdge("D", "F", 6);
        cityMap.addEdge("E", "F", 3);

        String source = args.length > 0 ? args[0] : "A";
        String destination = args.length > 1 ? args[1] : "F";

        PathResult result = cityMap.shortestPath(source, destination);

        System.out.println("=== Dijkstra Route Planner ===");
        System.out.println("Nodes: " + Arrays.asList("A", "B", "C", "D", "E", "F"));
        if (result.totalCost == Integer.MAX_VALUE) {
            System.out.println("No route found from " + source + " to " + destination);
        } else {
            System.out.println("Best route from " + source + " to " + destination + ": " + result.path);
            System.out.println("Total cost: " + result.totalCost);
        }
    }
}
