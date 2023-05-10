package pt.isec.henrique.aula8ex19.model;

import java.util.*;
import java.util.stream.Stream;

public class LibrarySet implements ILibrary {

    private String name;
    private Set<Book> books;

    public LibrarySet(String name) {
        this.name = name;
        this.books = new HashSet<>();
    }

    @Override
    public int addBook(Book book) {
        this.books.add(book);
        return book.getId();
    }

    @Override
    public Book findBook(int bookId) {
        for (Book book : books) {
            if (bookId == book.getId()) {
                return book;
            }
        }
        return null;
    }

    public Book findBook2(int bookId) {
        Iterator<Book> it = books.iterator();
        while (it.hasNext()) {
            Book book = it.next();
            if (bookId == book.getId())
                return book;
        }
        return null;
    }

    @Override
    public boolean removeBook(int bookId) {
        for (Book book : this.books) {
            if (book.getId() == bookId) {
                return this.books.remove(book);
            }
        }
        return false;
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
        } else {
            List<Book> orderSet = new ArrayList<>(books);
            Collections.sort(orderSet,new BookComparator());
            for (Book book : orderSet) {
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
        } else {
            for (Book book : books) {
                sb.append(String.format("- %s\n", book.toString()));
            }
        }
        return sb.toString();
    }
}

class BookComparator implements Comparator<Book> {

    @Override
    public int compare(Book o1, Book o2) {
        return o1.getTitle().compareTo(o2.getTitle());
    }
}
