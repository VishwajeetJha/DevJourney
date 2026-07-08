import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LibraryCatalogManager {
    static class Book {
        final String isbn;
        final String title;
        final String author;
        boolean available;

        Book(String isbn, String title, String author) {
            this.isbn = isbn;
            this.title = title;
            this.author = author;
            this.available = true;
        }

        @Override
        public String toString() {
            return String.format("%s | %s by %s | %s", isbn, title, author, available ? "Available" : "Issued");
        }
    }

    static class Member {
        final int memberId;
        final String name;
        final List<String> borrowedIsbns = new ArrayList<>();

        Member(int memberId, String name) {
            this.memberId = memberId;
            this.name = name;
        }

        @Override
        public String toString() {
            return String.format("#%d %s | borrowed: %s", memberId, name, borrowedIsbns);
        }
    }

    static class LibraryService {
        private final Map<String, Book> booksByIsbn = new HashMap<>();
        private final Map<Integer, Member> membersById = new HashMap<>();

        void registerBook(Book book) {
            booksByIsbn.put(book.isbn, book);
        }

        void registerMember(Member member) {
            membersById.put(member.memberId, member);
        }

        boolean issueBook(int memberId, String isbn) {
            Member member = membersById.get(memberId);
            Book book = booksByIsbn.get(isbn);

            if (member == null || book == null || !book.available) {
                return false;
            }

            book.available = false;
            member.borrowedIsbns.add(isbn);
            return true;
        }

        boolean returnBook(int memberId, String isbn) {
            Member member = membersById.get(memberId);
            Book book = booksByIsbn.get(isbn);

            if (member == null || book == null || !member.borrowedIsbns.contains(isbn)) {
                return false;
            }

            member.borrowedIsbns.remove(isbn);
            book.available = true;
            return true;
        }

        List<Book> searchByKeyword(String keyword) {
            String key = keyword.toLowerCase();
            List<Book> result = new ArrayList<>();

            for (Book book : booksByIsbn.values()) {
                if (book.title.toLowerCase().contains(key) || book.author.toLowerCase().contains(key)) {
                    result.add(book);
                }
            }
            return result;
        }

        void printState() {
            System.out.println("Books:");
            booksByIsbn.values().forEach(book -> System.out.println("  " + book));

            System.out.println("Members:");
            membersById.values().forEach(member -> System.out.println("  " + member));
        }
    }

    public static void main(String[] args) {
        LibraryService library = new LibraryService();

        library.registerBook(new Book("978-0134685991", "Effective Java", "Joshua Bloch"));
        library.registerBook(new Book("978-1617294945", "Spring in Action", "Craig Walls"));
        library.registerBook(new Book("978-1492056270", "Designing Data-Intensive Applications", "Martin Kleppmann"));

        library.registerMember(new Member(1, "Aarav"));
        library.registerMember(new Member(2, "Meera"));

        System.out.println("=== Library Catalog Manager ===");
        System.out.println("Issue Effective Java to member #1: " + library.issueBook(1, "978-0134685991"));
        System.out.println("Issue Effective Java to member #2 (should fail): " + library.issueBook(2, "978-0134685991"));
        System.out.println("Return Effective Java from member #1: " + library.returnBook(1, "978-0134685991"));
        System.out.println("Issue Effective Java to member #2 (should pass): " + library.issueBook(2, "978-0134685991"));

        System.out.println("\nSearch keyword 'data':");
        List<Book> matches = library.searchByKeyword("data");
        if (matches.isEmpty()) {
            System.out.println("  No books found.");
        } else {
            matches.forEach(book -> System.out.println("  " + book));
        }

        System.out.println();
        library.printState();
    }
}
