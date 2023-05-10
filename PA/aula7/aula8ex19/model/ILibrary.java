package pt.isec.henrique.aula8ex19.model;

import java.util.List;

public interface ILibrary {
    int addBook(Book book);

    Book findBook(int bookId);

    boolean removeBook(int bookId);

    String getName();

    String toStringSorted();
}
