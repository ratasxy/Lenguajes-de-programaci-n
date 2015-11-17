public class p6NoEnum {
    static readonly int Mon = 0, Tue = 1, Wed = 2, Thu = 3, Fri = 4, Sat = 5, Sun = 6;

    public static void Main() {
        int d = Mon;
        while (d <= Sun) {
            System.Console.Write(d + " ");
            if (d >=  Mon && d <= Fri) {
                System.Console.WriteLine("weekday");
            } else {
                System.Console.WriteLine("weekend");
            }
            ++d;
        }
    }
}
