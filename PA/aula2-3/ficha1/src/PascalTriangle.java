import java.util.Arrays;
import java.util.Objects;

public class PascalTriangle {

    private int [][]triangle;
    public PascalTriangle(int depth) {
        triangle = new int[depth][];
        for (int i = 0; i < depth; i++) {
            triangle[i] = new int[i+1];
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    triangle[i][j] = 1;
                } else {
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
                }
            }
        }
    }

    public void showTriangle(){

        for(int l=0; l<triangle.length;l++){
            for(int c=0; c<triangle[l].length; c++)
                System.out.printf("%d",triangle[l][c]);
            System.out.println();
        }
    }
}
