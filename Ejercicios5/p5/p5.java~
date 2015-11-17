public class p5 {
    int x;

    void fun() {
        x = 21;  // The global variable is set
        int x;
        x = 42;  // The local variable is set
        System.out.println(x);  // 42
    }

    public static void main(String[] args) {
        (new p5()).run();
    }

    public void run() {
        fun();
        System.out.println(x);  // 21
    }
}
