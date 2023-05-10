package pt.isec.henrique.aula8ex19.model;

import java.util.*;

public class LibraryMap implements ILibrary {

    private String name;
    private Map<Integer, Book> books;

    public LibraryMap(String name) {
        this.name = name;
        this.books = new HashMap<>();
    }

    @Override
    public int addBook(Book book) {
        this.books.put(book.getId(), book);
        return book.getId();
    }

    @Override
    public Book findBook(int bookId) {
        return this.books.get(bookId);
    }

    @Override
    public boolean removeBook(int bookId) {
        return this.books.remove(bookId) != null;
    }

    @Override
    public String getName() {
        return this.name;
    }

    @Override
    public String toStringSorted() {
        StringBuilder sb = new StringBuilder(super.toString());
        sb.append("\nBooks:\n");
        if (books == null || books.size() == 0) {
            sb.append("The library is empty");
        }
        else {
            List<Book> sortedBooks = new ArrayList<>(books.values());
            Collections.sort(sortedBooks, new BookComparatorIgnoreCase());
            for (Book book : sortedBooks) {
                sb.append(String.format("- %s\n", book.toString()));
            }
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(super.toString());
        sb.append("\nBooks:\n");
        if (books == null || books.size() == 0) {
            sb.append("The library is empty");
        }
        else {
            for (Book book : books.values()) {
                sb.append(String.format("- %s\n", book.toString()));
            }
        }
        return sb.toString();
    }
}

class BookComparatorIgnoreCase implements Comparator<Book> {

    @Override
    public int compare(Book o1, Book o2) {
        return o1.getTitle().compareToIgnoreCase(o2.getTitle());
    }
}
