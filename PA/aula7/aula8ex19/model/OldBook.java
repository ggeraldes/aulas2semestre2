package pt.isec.henrique.aula8ex19.model;

import java.util.List;

public class OldBook extends Book {

    private int nCopies;

    public OldBook(String title, List<String> authors, int nCopies) {
        super(title, authors);
        this.nCopies = nCopies;
    }

    public int getNCopies() {
        return nCopies;
    }

    public void setNCopies(int nCopies) {
        this.nCopies = nCopies;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append("\n").append("N Copies: ").append(nCopies);
        return sb.toString();
    }
}
