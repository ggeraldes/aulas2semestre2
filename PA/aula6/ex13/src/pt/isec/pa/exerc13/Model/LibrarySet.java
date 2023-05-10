package pt.isec.pa.exerc13.Model;

import java.util.*;

public class LibrarySet implements ILibrary{
    private String name;
    private Set<Book> books;

    public LibrarySet(String name){
        this.name = name;
        books = new HashSet<>();
    }

    public String getName(){return name;}
    public void setName(String name){this.name=name;}
    public int addBook(Book book){
        books.add(book);
        return  book.getId();
    }

    public int addBook(String title, List<String> authors){return addBook(new Book(title,authors));}

    public Book findBook(int id){
        if(books==null || books.size()==0)
            return null;
        for(Book book : books)
            if(id== book.getId())
                return book;
        return null;
    }
    public Book findBook2(int id){
        if(books==null || books.size()==0)
            return null;
        Iterator<Book> it = books.iterator();
        while(it.hasNext()){
            Book book = it.next();
            if(id== book.getId())
                return book;
        }
        return null;
    }
    public boolean removeBook(int id){
       if(books==null)
           return false;
       return books.remove(Book.getDummyBook(id));
    }
    public boolean removeBook2(int id){
        /*if (lstBooks==null)
            return false;
        Book dummyBook = Book.getDummyBook(id);
        return lstBooks.remove(dummyBook);*/
        return books==null || books.remove(Book.getDummyBook(id));
    }

    @Override
    public String toString(){return "library: "+name;}
}
