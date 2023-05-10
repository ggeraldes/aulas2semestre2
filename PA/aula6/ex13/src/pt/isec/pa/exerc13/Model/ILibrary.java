package pt.isec.pa.exerc13.Model;

import java.util.List;

public interface ILibrary {
   String getName();
   void setName(String name);
   int addBook(Book book);
   int addBook(String title, List<String> authors);

   Book findBook(int id);
   boolean removeBook(int id);

}
