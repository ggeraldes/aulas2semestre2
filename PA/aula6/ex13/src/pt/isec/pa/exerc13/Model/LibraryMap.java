package pt.isec.pa.exerc13.Model;

import java.util.*;

public class LibraryMap implements ILibrary{
    private String name;
    private Map<Integer, Book> books;

    public LibraryMap(String name) {
        this.name = name;
        books = new HashMap<>();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int addBook(Book book) {
        if (book == null)
            return -1;
        int id = book.getId();
        if (books.containsKey(id))
            return -1;
        books.put(id, book);
        return id;
    }

    public int addBook(String title, List<String> authors) {
        return addBook(new Book(title, authors));
    }

    public Book findBook(int id) {
        if (books == null)
            return null;
        return books.get(id);
    }

    public boolean removeBook(int id) {
        if (books == null)
            return false;
        return books.remove(id) != null;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(super.toString());
        sb.append("\nBooks:\n");
        if (books == null || books.size() == 0)
            sb.append("The library is empty");
        else
            for (Book book : books.values())
                sb.append(String.format("- %s\n",book.toString()));

        return sb.toString();
    }
}
