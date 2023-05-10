package pt.isec.henrique.aula8ex19.model;

import java.util.List;

public class RecentBook extends Book {

    private String isbn;

    private double price;

    public RecentBook(String title, List<String> authors, String isbn, double price) {
        super(title, authors);
        this.isbn = isbn;
        this.price = price;
    }

    public String getIsbn() {
        return isbn;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append("\n").append("ISBN: ").append(isbn);
        sb.append("\n").append("Price: ").append(price);
        return sb.toString();
    }
}
