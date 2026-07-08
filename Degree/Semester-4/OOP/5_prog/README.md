# 5 Java Programs (Intermediate to High Level)

This folder contains **5 Java programs** designed for OOP practice at intermediate-to-advanced level.
Each program focuses on a different concept: scheduling, catalog management, concurrency, graph algorithms, and text indexing.

## How to Compile All

```bash
cd /home/vish/Documents/Coding/DevJourney/Degree/Semester-4/OOP/Project/5_prog
javac *.java
```

## 1) TaskSchedulerSimulator

- **File:** `TaskSchedulerSimulator.java`
- **Definition:** Simulates a task scheduling engine that prioritizes tasks using a priority queue based on priority and deadline.

### Core Concepts
- `PriorityQueue` with custom comparator
- Multi-criteria scheduling (priority -> deadline -> insertion sequence)
- Interactive command-driven mode

### How It Works
1. A `Task` object stores id, title, priority, deadline, estimated duration, and insertion order.
2. `Scheduler` keeps tasks in a `PriorityQueue`.
3. Comparator logic decides dispatch order:
   - `HIGH` before `MEDIUM` before `LOW`
   - Earlier deadline first when priority ties
   - Earlier insertion first when everything ties
4. `dispatchTask()` pops the next best task.
5. In interactive mode (`interactive` argument), you can add/list/dispatch tasks dynamically.

### Run
```bash
java TaskSchedulerSimulator
java TaskSchedulerSimulator interactive
```

---

## 2) LibraryCatalogManager

- **File:** `LibraryCatalogManager.java`
- **Definition:** A mini library management system using OOP entities and service-layer logic for issue/return/search operations.

### Core Concepts
- OOP modeling (`Book`, `Member`, `LibraryService`)
- Relationship management (member <-> borrowed books)
- Map-based indexing and keyword search

### How It Works
1. `Book` has metadata + `available` state.
2. `Member` has identity and borrowed ISBN list.
3. `LibraryService` maintains:
   - `booksByIsbn`
   - `membersById`
4. `issueBook(memberId, isbn)` validates member/book availability and updates both states.
5. `returnBook(memberId, isbn)` restores availability and updates member record.
6. `searchByKeyword` scans title/author case-insensitively.

### Run
```bash
java LibraryCatalogManager
```

---

## 3) ConcurrentBankingSystem

- **File:** `ConcurrentBankingSystem.java`
- **Definition:** Simulates concurrent money transfers between accounts while preserving consistency and avoiding deadlocks.

### Core Concepts
- Multithreading with `Thread` and `Runnable`
- Synchronization (`synchronized` methods + nested locks)
- Deadlock prevention through lock ordering

### How It Works
1. `BankAccount` provides synchronized `deposit`, `withdraw`, `getBalance`.
2. `TransactionTask` repeatedly transfers amount from one account to another.
3. Transfer function acquires locks in fixed order (by account id) to prevent cyclic lock waiting.
4. Multiple threads run transfer loops simultaneously.
5. Before and after totals are compared to verify invariant:
   - **Total balance remains constant**

### Run
```bash
java ConcurrentBankingSystem
```

---

## 4) DijkstraRoutePlanner

- **File:** `DijkstraRoutePlanner.java`
- **Definition:** Finds the minimum-cost route between two nodes in a weighted graph using Dijkstra’s algorithm.

### Core Concepts
- Weighted undirected graph (adjacency list)
- Greedy shortest path with min-priority queue
- Path reconstruction using parent pointers

### How It Works
1. Graph is built with `addEdge(from, to, weight)`.
2. `shortestPath(source, destination)` initializes:
   - distance map (`∞` except source = 0)
   - parent map for backtracking
   - min-heap of `(node, distance)`
3. Repeatedly process nearest unprocessed node.
4. Relax edges: if a shorter path found, update distance + parent.
5. Reconstruct path by walking parent pointers from destination to source.

### Run
```bash
java DijkstraRoutePlanner
java DijkstraRoutePlanner A F
java DijkstraRoutePlanner B E
```

---

## 5) InvertedIndexSearchEngine

- **File:** `InvertedIndexSearchEngine.java`
- **Definition:** A mini search engine that builds an inverted index and supports AND/OR keyword queries.

### Core Concepts
- Text normalization and tokenization
- Inverted index (`term -> set of document IDs`)
- Boolean retrieval (intersection for AND, union for OR)

### How It Works
1. `addDocument(docId, text)` stores document text and indexes every normalized token.
2. Normalization:
   - lowercase conversion
   - punctuation cleanup
   - whitespace token split
3. `searchAnd(query)` intersects posting lists of all terms.
4. `searchOr(query)` unions posting lists.
5. Result document IDs are sorted and printed with full document text.

### Run
```bash
java InvertedIndexSearchEngine
java InvertedIndexSearchEngine "java concurrency" "graph index"
```

---

## Suggested Learning Path

1. Start with `LibraryCatalogManager` for clean OOP fundamentals.
2. Move to `TaskSchedulerSimulator` for comparator and priority structures.
3. Study `DijkstraRoutePlanner` for graph algorithm implementation.
4. Explore `InvertedIndexSearchEngine` for practical data indexing.
5. Finish with `ConcurrentBankingSystem` for advanced synchronization and safety.
