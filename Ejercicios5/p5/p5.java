public class p5 {
    int bibble;

    void JavaApesta() {
        bibble = "Es un perro";  // global variable
        int bibble;
        bibble = "Es un cachorro";  // local variable
        System.out.println(x);  // local
    }

    public static void main(String[] args) {
        (new p5()).run();
    }

    public void run() {
        JavaApesta();
        System.out.println(x);  // global
    }
}
