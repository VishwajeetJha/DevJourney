#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

class SearchEngine {
private:
    unordered_map<string, unordered_set<int>> index;
    unordered_map<int, string> documents;

    vector<string> normalize(const string& text) const {
        string cleaned = text;
        transform(cleaned.begin(), cleaned.end(), cleaned.begin(), ::tolower);
        
        for (char& c : cleaned) {
            if (!isalnum(c)) {
                c = ' ';
            }
        }

        cleaned.erase(0, cleaned.find_first_not_of(" \t\n\r\f\v"));
        cleaned.erase(cleaned.find_last_not_of(" \t\n\r\f\v") + 1);

        vector<string> tokens;
        if (cleaned.empty()) {
            return tokens;
        }

        stringstream ss(cleaned);
        string token;
        while (ss >> token) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
        return tokens;
    }

public:
    void addDocument(int docId, const string& text) {
        documents[docId] = text;
        for (const auto& token : normalize(text)) {
            index[token].insert(docId);
        }
    }

    vector<int> searchAnd(const string& query) const {
        vector<string> terms = normalize(query);
        if (terms.empty()) {
            return vector<int>();
        }

        unordered_set<int> result = index.at(terms[0]);
        for (size_t i = 1; i < terms.size(); i++) {
            if (index.find(terms[i]) == index.end()) {
                result.clear();
                break;
            }
            unordered_set<int> temp;
            for (int docId : result) {
                if (index.at(terms[i]).count(docId)) {
                    temp.insert(docId);
                }
            }
            result = temp;
        }

        vector<int> sorted_result(result.begin(), result.end());
        sort(sorted_result.begin(), sorted_result.end());
        return sorted_result;
    }

    vector<int> searchOr(const string& query) const {
        vector<string> terms = normalize(query);
        unordered_set<int> result;
        for (const auto& term : terms) {
            if (index.find(term) != index.end()) {
                for (int docId : index.at(term)) {
                    result.insert(docId);
                }
            }
        }

        vector<int> sorted_result(result.begin(), result.end());
        sort(sorted_result.begin(), sorted_result.end());
        return sorted_result;
    }

    void printDocument(int docId) const {
        if (documents.find(docId) != documents.end()) {
            cout << "Doc " << docId << ": " << documents.at(docId) << endl;
        } else {
            cout << "Doc " << docId << ": <missing>" << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    SearchEngine engine;

    engine.addDocument(1, "Java concurrency in practice with synchronized blocks");
    engine.addDocument(2, "Graph algorithms and shortest path in Java");
    engine.addDocument(3, "Building a search engine using inverted index and ranking");
    engine.addDocument(4, "Concurrency and graph processing for large scale systems");

    string andQuery = argc > 1 ? argv[1] : "java concurrency";
    string orQuery = argc > 2 ? argv[2] : "graph search";

    cout << "=== Inverted Index Search Engine ===" << endl;

    vector<int> andResult = engine.searchAnd(andQuery);
    cout << "AND query: '" << andQuery << "' -> [";
    for (size_t i = 0; i < andResult.size(); i++) {
        if (i > 0) cout << ", ";
        cout << andResult[i];
    }
    cout << "]" << endl;
    for (int docId : andResult) {
        engine.printDocument(docId);
    }

    cout << endl;

    vector<int> orResult = engine.searchOr(orQuery);
    cout << "OR query: '" << orQuery << "' -> [";
    for (size_t i = 0; i < orResult.size(); i++) {
        if (i > 0) cout << ", ";
        cout << orResult[i];
    }
    cout << "]" << endl;
    for (int docId : orResult) {
        engine.printDocument(docId);
    }

    return 0;
}
