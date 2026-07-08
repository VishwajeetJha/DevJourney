import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class TaskSchedulerSimulator {
    enum Priority {
        HIGH,
        MEDIUM,
        LOW
    }

    static class Task {
        private static int sequenceCounter = 0;

        final int id;
        final String title;
        final Priority priority;
        final LocalDateTime deadline;
        final int estimatedMinutes;
        final int sequence;

        Task(int id, String title, Priority priority, LocalDateTime deadline, int estimatedMinutes) {
            this.id = id;
            this.title = title;
            this.priority = priority;
            this.deadline = deadline;
            this.estimatedMinutes = estimatedMinutes;
            this.sequence = sequenceCounter++;
        }

        @Override
        public String toString() {
            return String.format(
                    "#%d | %-20s | %-6s | due: %s | est: %d min",
                    id,
                    title,
                    priority,
                    deadline.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm")),
                    estimatedMinutes
            );
        }
    }

    static class Scheduler {
        private final PriorityQueue<Task> queue;
        private int nextId = 1;

        Scheduler() {
            this.queue = new PriorityQueue<>(new Comparator<Task>() {
                @Override
                public int compare(Task first, Task second) {
                    int byPriority = Integer.compare(first.priority.ordinal(), second.priority.ordinal());
                    if (byPriority != 0) {
                        return byPriority;
                    }
                    int byDeadline = first.deadline.compareTo(second.deadline);
                    if (byDeadline != 0) {
                        return byDeadline;
                    }
                    return Integer.compare(first.sequence, second.sequence);
                }
            });
        }

        void addTask(String title, Priority priority, LocalDateTime deadline, int estimatedMinutes) {
            queue.add(new Task(nextId++, title, priority, deadline, estimatedMinutes));
        }

        Task dispatchTask() {
            return queue.poll();
        }

        List<Task> previewQueue() {
            List<Task> snapshot = new ArrayList<>(queue);
            snapshot.sort(queue.comparator());
            return snapshot;
        }

        boolean isEmpty() {
            return queue.isEmpty();
        }
    }

    public static void main(String[] args) {
        Scheduler scheduler = new Scheduler();

        scheduler.addTask("Prepare report", Priority.HIGH, LocalDateTime.now().plusHours(4), 90);
        scheduler.addTask("Reply to email", Priority.MEDIUM, LocalDateTime.now().plusHours(2), 20);
        scheduler.addTask("Code review", Priority.HIGH, LocalDateTime.now().plusHours(6), 45);
        scheduler.addTask("Backup logs", Priority.LOW, LocalDateTime.now().plusDays(1), 30);

        if (args.length > 0 && args[0].equalsIgnoreCase("interactive")) {
            runInteractiveMode(scheduler);
            return;
        }

        System.out.println("=== Task Scheduler Simulator (Demo Mode) ===");
        System.out.println("Queue preview:");
        for (Task task : scheduler.previewQueue()) {
            System.out.println("  " + task);
        }

        System.out.println("\nDispatch order:");
        while (!scheduler.isEmpty()) {
            System.out.println("  -> " + scheduler.dispatchTask());
        }
    }

    private static void runInteractiveMode(Scheduler scheduler) {
        Scanner scanner = new Scanner(System.in);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

        System.out.println("=== Task Scheduler Simulator (Interactive Mode) ===");
        System.out.println("Commands: add, list, next, exit");

        while (true) {
            System.out.print("scheduler> ");
            String command = scanner.nextLine().trim().toLowerCase();

            switch (command) {
                case "add":
                    try {
                        System.out.print("Title: ");
                        String title = scanner.nextLine().trim();

                        System.out.print("Priority (HIGH/MEDIUM/LOW): ");
                        Priority priority = Priority.valueOf(scanner.nextLine().trim().toUpperCase());

                        System.out.print("Deadline (yyyy-MM-dd HH:mm): ");
                        LocalDateTime deadline = LocalDateTime.parse(scanner.nextLine().trim(), formatter);

                        System.out.print("Estimated minutes: ");
                        int estimated = Integer.parseInt(scanner.nextLine().trim());

                        scheduler.addTask(title, priority, deadline, estimated);
                        System.out.println("Task added.");
                    } catch (Exception exception) {
                        System.out.println("Invalid input. Please try again.");
                    }
                    break;
                case "list":
                    List<Task> queue = scheduler.previewQueue();
                    if (queue.isEmpty()) {
                        System.out.println("No tasks pending.");
                    } else {
                        queue.forEach(task -> System.out.println("  " + task));
                    }
                    break;
                case "next":
                    Task dispatched = scheduler.dispatchTask();
                    if (dispatched == null) {
                        System.out.println("No task to dispatch.");
                    } else {
                        System.out.println("Dispatching: " + dispatched);
                    }
                    break;
                case "exit":
                    System.out.println("Exiting scheduler.");
                    return;
                default:
                    System.out.println("Unknown command. Use add, list, next, exit.");
            }
        }
    }
}
