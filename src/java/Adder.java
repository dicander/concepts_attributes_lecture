public class Adder {
    public static <T extends Number> double add(T a, T b) {
        return a.doubleValue() + b.doubleValue();
    }

    public static void main(String[] args) {
        Integer x = 3;
        Integer y = 5;
        System.out.println(add(x, y)); // Output: 8.0
    }
}
