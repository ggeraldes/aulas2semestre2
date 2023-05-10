package pt.isec.pa.exerc13.Model;

//import pt.isec.pa.exerc13.Model.Book;

import java.util.ArrayList;
import java.util.List;

public class Library implements ILibrary {

    private String name;
    private List<Book> lstBooks;

    public Library(String name){
        this.name = name;
        lstBooks = new ArrayList<>();
    }

    public String getName(){return name;}
    public void setName(String name){this.name=name;}
    public int addBook(Book book){
        lstBooks.add(book);
        return  book.getId();
    }

    public int addBook(String title, List<String> authors){return addBook(new Book(title,authors));}

    public Book findBook(int id){
       if(lstBooks==null || lstBooks.size()==0)
        return null;
        for(Book book : lstBooks)
            if(id== book.getId())
                return book;
        return null;
    }
    public Book findBook2(int id){
        if(lstBooks==null || lstBooks.size()==0)
            return null;
        Book dummyBook = Book.getDummyBook(id);
        int index = lstBooks.indexOf(dummyBook);
        if(index<0)
            return null;
        return  lstBooks.get(index);
    }
    public boolean removeBook(int id){
        if(lstBooks==null)
            return false;
        for(int i=0;i<lstBooks.size();i++)
            if(id==lstBooks.get(i).getId()){
                lstBooks.remove(i);
                return true;
            }
        return false;
    }
    public boolean removeBook2(int id){
        /*if (lstBooks==null)
            return false;
        Book dummyBook = Book.getDummyBook(id);
        return lstBooks.remove(dummyBook);*/
        return lstBooks==null || lstBooks.remove(Book.getDummyBook(id));
    }

    @Override
    public String toString(){
            StringBuilder sb = new StringBuilder(super.toString());
            sb.append("\nBooks:\n");
            if (lstBooks == null || lstBooks.size() == 0)
                sb.append("The library is empty");
            else
                for (Book book : lstBooks)
                    sb.append(String.format("- %s\n",book.toString()));

            return sb.toString();
    }

}



