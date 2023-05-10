package pt.isec.pa.exerc11.model;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Report {

    String title;
    ArrayList<String> authors;
    StringBuilder text;
    public Report(String title){
        this.title=title;
        this.text= new StringBuilder();
        this.authors= new ArrayList<>();
    }
    public String getTitle(){return title;}
    public void setTitle(String title){this.title=title;}

    public String getText(){return text.toString();}
    public boolean addAuthor(String newAuthor){
        if(authors.contains(newAuthor))
            return false;
    //TODO: versão case insensitive
        authors.add(newAuthor);
        return true;
    }
    public boolean removeAuthor(String author){

        authors.add(author);
        return true;



    }
    public void addText(String newText){
        /*if(text == null)
            text = new StringBuilder(newText);
        else */
            text.append(newText);
    }
    public void capitalizeSentences(){
        boolean changeNext=true;
        for(int i=0;i<text.length();i++){
            char c= text.charAt(i);
            if(changeNext && Character.isLetter(c)){
                text.setCharAt(i, Character.toUpperCase(c));
                changeNext = false;
            } else if(".!?".indexOf(c) >=0)
                changeNext=true;
        }
    }

    public int getNumberOfWords(){
        StringTokenizer st = new StringTokenizer(text.toString(), " \t\n,.!?");
        return st.countTokens();
    }
    public int getNumberOfOccurrences(String word){
        int counter=0;
        StringTokenizer st = new StringTokenizer(text.toString(), " \t\n,.!?");
        while(st.hasMoreTokens()){
            if(word.equalsIgnoreCase(st.nextToken()))
                counter++;
        }
        return counter;
    }

   /* @Override
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
    }*/

}
