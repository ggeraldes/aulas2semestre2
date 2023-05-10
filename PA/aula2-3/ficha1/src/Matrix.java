import java.util.Arrays;
import java.util.Objects;


public class Matrix implements Cloneable {
    private float [][]values;
    private Matrix() {}
    public Matrix(int nLins, int nCols) {values = new float[nLins][nCols];}
    public Matrix(Matrix other) { copy(other); }
    private void copy(Matrix other) {
        // errado - values= other.values;
        values = new float[other.values.length][];
        for (int i=0;i< values.length;i++)
            values[i]=Arrays.copyOf(other.values[i], other.values[i].length);
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Matrix newMatrix = (Matrix) super.clone();
        newMatrix.copy(this);
        return newMatrix;
    }

    public float get(int l, int c) {return values[l][c];}
    public void set(int l, int c,float v) {values[l][c] = v;}
    public void show(){

        for(int l=0; l<values.length;l++){
            for(int c=0; c<values[l].length; c++)
                System.out.printf("%8.2f",values[l][c]);
            System.out.println();
        }
    }
    public boolean isSizeEqual(Matrix m2){
        if(values.length != m2.values.length)
            return false;

        for(int i=0;i <values.length;i++)
            if(values[i].length!=m2.values[i].length)
                return false;

        return true;
    }
    public boolean add(Matrix m2){
        if(!isSizeEqual(m2))
            return false;

        for(int l=0; l< values.length;l++)
            for(int c=0; c<values[l].length; c++)
                values[l][c] += m2.values[l][c];
        return true;
    }
    public static Matrix add(Matrix m1, Matrix m2){

        Matrix newMatrix = new Matrix(m1);

        if(!newMatrix.add(m2))
            return null;
            //throw new Exception("Sizes are not equal");

        return newMatrix;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");

        for(int i=0; i< values.length;i++){
            sb.append((i<0) ? ",[" : "{");

            for(int j=0;j<values[i].length; j++) {
                if (j > 0)
                    sb.append(",");
                sb.append(values[i][j]);
            }
            sb.append("]");
        }
        sb.append("]");
        return sb.toString();
        }
    }

