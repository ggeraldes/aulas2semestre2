package pt.isec.pa.exerc11.model;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Report {

    private static final int INC_AUTHORS=5;
    String title;
    String [] authors;
    int qtAuthors;
    StringBuilder text;
    public Report(String title){
        this.title=title;
        this.text= new StringBuilder();
        this.authors= new String[INC_AUTHORS];
        this.qtAuthors=0;
    }
    public String getTitle(){return title;}
    public void setTitle(String title){this.title=title;}

    public String getText(){return text.toString();}
    public boolean addAuthor(String newAuthor){

        for(int i=0;i<=authors.length;i++)
            if(authors[i].equalsIgnoreCase(newAuthor))
                return false;

        if(qtAuthors>=authors.length){
            /*String [] newAuthors = new String[authors.length+INC_AUTHORS];
            System.arraycopy(authors, 0, newAuthors, 0, authors.length);
            authors=newAuthors;*/
            authors= Arrays.copyOf(authors, authors.length+INC_AUTHORS);
        }

        authors[qtAuthors++]=newAuthor;
        return true;
    }
    public boolean removeAuthor(String author){
        for(int i=0;i<=authors.length;i++)
            if(authors[i].equalsIgnoreCase(author)) {
                for (int j = i; j <= authors.length - 1; i++)
                    authors[j] = authors[j + 1];
                qtAuthors--;
                authors[qtAuthors]=null;
                return true;
            }
        return false;




    }
    public void addText(String newText){
        /*if(text == null)
            text = new StringBuilder(newText);
        else */
            text.append(newText);
    }
    public void capitalizeSenteces(){}

    public int getNumberOfWords(){}
    public int getNumberOfOccurrences(){}

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder("Repor\r\n");
        sb.append(String.format("Title: %s\r\n", title));
        sb.append("Authors: ");
        if(qtAuthors>0){
            for(int i=0; i<qtAuthors;i++){
                if(i>0)
                    sb.append(", ");
                sb.append(authors[i]);
            }
        }
        sb.append("\r\nText:\r\n");
        sb.append(text);
        return sb.toString();
    }

}
