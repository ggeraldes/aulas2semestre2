package pt.isec.henrique.aula8ex19.model;

import java.util.ArrayList;
import java.util.List;

public abstract class Book implements Comparable<Book> {

    private static int countID = 0;
    private int id;
    private String title;
    private List<String> authors;

    private Book(int id) {
        this.id = id;
    }

    protected Book(String title, List<String> authors) {
        this.id = ++countID;
        this.title = title;
        this.authors = new ArrayList<>(authors);
    }

    protected Book(String title, String... authors) {
        this.id = ++countID;
        this.title = title;
        this.authors = List.of(authors);
    }

    public int getId() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof Book book)) {
            return false;
        }
        return this.id == book.id;
    }

    @Override
    public int hashCode() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public List<String> getAuthors() {
        return authors;
    }

    public void setAuthors(List<String> authors) {
        this.authors = authors;
    }

    @Override
    public int compareTo(Book o) {
        return title.compareTo(o.getTitle());
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Book\n");
        sb.append("Title: ").append(this.title).append("\n");
        sb.append("Authors: ");
        for (int i = 0; i < authors.size(); i++) {
            sb.append(this.authors.get(i));
            if (i != authors.size() - 1) {
                sb.append(", ");
            }
        }
        return sb.toString();
    }
}
