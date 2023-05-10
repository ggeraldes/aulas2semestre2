package pt.isec.henrique.aula8ex19.model;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LibraryList implements ILibrary {

    private String name;
    private List<Book> books;

    public LibraryList(String name) {
        this.name = name;
        this.books = new ArrayList<>();
    }

    @Override
    public int addBook(Book book) {
        this.books.add(book);
        return book.getId();
    }

    @Override
    public Book findBook(int bookId) {
        for (Book book : this.books) {
            if (book.getId() == bookId){
                return book;
            }
        }
        return null;
    }

    @Override
    public boolean removeBook(int bookId) {
        for (Book book : this.books) {
            if (book.getId() == bookId){
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
            List<Book> sortedBooks = new ArrayList<>(this.books);
            Collections.sort(sortedBooks);
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
        } else {
            for (Book book : books) {
                sb.append(String.format("- %s\n", book.toString()));
            }
        }
        return sb.toString();
    }
}
