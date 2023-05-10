package pt.isec.pa.exerc13.Model;

import java.util.List;



public class Book {

    private static int countID=0;
    private static int getNewId() {return ++countID;}
    private int id;
    private String title;
    private List<String> authors;

    private Book(int id){
        this.id=id;
        this.title = null;
        this.authors=null;
    }

    public static Book getDummyBook(int id){
        return new Book(id);
    }

    public Book(String title, List<String> authors){
       id=getNewId();
       this.title=title;
       this.authors=authors;
    }
    public Book(String title, String... authors){
        id=getNewId();
        this.title=title;
        this.authors=List.of(authors);
    }
    public int getId(){return id;}
    public String getTitle(){return title;}
    public void setTitle(String title){this.title=title;};

    public List<String> getAuthors(){ return authors;}
    public void setAuthors(List<String> authors){ this.authors=authors;}

    @Override
    public String toString() {
        if (title==null)
            return "DummyBook ["+ id + ']';

        if(authors==null || authors.size()==0)
            return id + ",'" + title + "'";

        String strAuthors = authors.toString();

        return id + ",'" + title + "', " + strAuthors.substring(1,strAuthors.length()-1);

    }

    @Override
    public boolean equals(Object o){
        if(this==o)
            return true;
        if(o == null || getClass() != o.getClass())
            return false;

        Book book = (Book) o;
        return id==book.id;
    }

    @Override
    public int hashCode(){return id;}


}
