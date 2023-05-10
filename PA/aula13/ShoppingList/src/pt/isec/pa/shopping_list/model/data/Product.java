package pt.isec.pa.shopping_list.model.data;

public record Product(String name, double qt) {
    @Override
    public String toString() {
        return String.format(
                "%-20s %8.2f",
                name,qt
        );
    }
}
