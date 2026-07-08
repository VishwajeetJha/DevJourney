import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class InvertedIndexSearchEngine {
    static class SearchEngine {
        private final Map<String, Set<Integer>> index = new HashMap<>();
        private final Map<Integer, String> documents = new HashMap<>();

        void addDocument(int docId, String text) {
            documents.put(docId, text);
            for (String token : normalize(text)) {
                index.computeIfAbsent(token, key -> new HashSet<>()).add(docId);
            }
        }

        List<Integer> searchAnd(String query) {
            List<String> terms = normalize(query);
            if (terms.isEmpty()) {
                return Collections.emptyList();
            }

            Set<Integer> result = new HashSet<>(index.getOrDefault(terms.get(0), Collections.emptySet()));
            for (int indexPosition = 1; indexPosition < terms.size(); indexPosition++) {
                result.retainAll(index.getOrDefault(terms.get(indexPosition), Collections.emptySet()));
            }

            List<Integer> sorted = new ArrayList<>(result);
            Collections.sort(sorted);
            return sorted;
        }

        List<Integer> searchOr(String query) {
            List<String> terms = normalize(query);
            Set<Integer> result = new HashSet<>();
            for (String term : terms) {
                result.addAll(index.getOrDefault(term, Collections.emptySet()));
            }

            List<Integer> sorted = new ArrayList<>(result);
            Collections.sort(sorted);
            return sorted;
        }

        void printDocument(int docId) {
            System.out.println("Doc " + docId + ": " + documents.getOrDefault(docId, "<missing>"));
        }

        private List<String> normalize(String text) {
            String cleaned = text.toLowerCase().replaceAll("[^a-z0-9\\s]", " ").trim();
            if (cleaned.isEmpty()) {
                return Collections.emptyList();
            }
            return Arrays.asList(cleaned.split("\\s+"));
        }
    }

    public static void main(String[] args) {
        SearchEngine engine = new SearchEngine();

        engine.addDocument(1, "Java concurrency in practice with synchronized blocks");
        engine.addDocument(2, "Graph algorithms and shortest path in Java");
        engine.addDocument(3, "Building a search engine using inverted index and ranking");
        engine.addDocument(4, "Concurrency and graph processing for large scale systems");

        String andQuery = args.length > 0 ? args[0] : "java concurrency";
        String orQuery = args.length > 1 ? args[1] : "graph search";

        System.out.println("=== Inverted Index Search Engine ===");

        List<Integer> andResult = engine.searchAnd(andQuery);
        System.out.println("AND query: '" + andQuery + "' -> " + andResult);
        for (int docId : andResult) {
            engine.printDocument(docId);
        }

        List<Integer> orResult = engine.searchOr(orQuery);
        System.out.println("\nOR query: '" + orQuery + "' -> " + orResult);
        for (int docId : orResult) {
            engine.printDocument(docId);
        }
    }
}
