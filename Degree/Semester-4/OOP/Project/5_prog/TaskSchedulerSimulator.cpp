#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;
using Clock = chrono::system_clock;

enum Priority { HIGH = 0, MEDIUM = 1, LOW = 2 };

struct Task {
    static int sequenceCounter;
    int id;
    string title;
    Priority priority;
    Clock::time_point deadline;
    int estimatedMinutes;
    int sequence;

    Task(int id, const string& title, Priority priority, 
         Clock::time_point deadline, int estimatedMinutes)
        : id(id), title(title), priority(priority), deadline(deadline),
          estimatedMinutes(estimatedMinutes), sequence(sequenceCounter++) {}

    string toString() const {
        auto ms = Clock::to_time_t(deadline);
        auto tm = *localtime(&ms);
        ostringstream ss;
        ss << "#" << id << " | " << setw(20) << left << title << " | "
           << setw(6) << left << (priority == HIGH ? "HIGH" : priority == MEDIUM ? "MEDIUM" : "LOW")
           << " | due: " << put_time(&tm, "%Y-%m-%d %H:%M") << " | est: " << estimatedMinutes << " min";
        return ss.str();
    }
};

int Task::sequenceCounter = 0;

struct TaskComparator {
    bool operator()(const Task& first, const Task& second) const {
        if (first.priority != second.priority) {
            return first.priority > second.priority;
        }
        if (first.deadline != second.deadline) {
            return first.deadline > second.deadline;
        }
        return first.sequence > second.sequence;
    }
};

class Scheduler {
private:
    priority_queue<Task, vector<Task>, TaskComparator> queue;
    int nextId = 1;

public:
    void addTask(const string& title, Priority priority, 
                 Clock::time_point deadline, int estimatedMinutes) {
        queue.push(Task(nextId++, title, priority, deadline, estimatedMinutes));
    }

    Task dispatchTask() {
        Task top = queue.top();
        queue.pop();
        return top;
    }

    vector<Task> previewQueue() const {
        vector<Task> snapshot;
        priority_queue<Task, vector<Task>, TaskComparator> temp = queue;
        while (!temp.empty()) {
            snapshot.push_back(temp.top());
            temp.pop();
        }
        return snapshot;
    }

    bool isEmpty() const {
        return queue.empty();
    }
};

int main(int argc, char* argv[]) {
    Scheduler scheduler;

    auto now = Clock::now();
    scheduler.addTask("Prepare report", HIGH, now + chrono::hours(4), 90);
    scheduler.addTask("Reply to email", MEDIUM, now + chrono::hours(2), 20);
    scheduler.addTask("Code review", HIGH, now + chrono::hours(6), 45);
    scheduler.addTask("Backup logs", LOW, now + chrono::hours(24), 30);

    cout << "=== Task Scheduler Simulator (Demo Mode) ===" << endl;
    cout << "Queue preview:" << endl;
    for (const auto& task : scheduler.previewQueue()) {
        cout << "  " << task.toString() << endl;
    }

    cout << "\nDispatch order:" << endl;
    while (!scheduler.isEmpty()) {
        cout << "  -> " << scheduler.dispatchTask().toString() << endl;
    }

    return 0;
}
