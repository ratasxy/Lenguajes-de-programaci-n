public class p6Enum {
    enum Day {
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat,
        Sun
    };

    public static void Main() {
        Day d = Day.Mon;
        while (d <= Day.Sun) {
            System.Console.Write(d + " ");
            if (d >=  Day.Mon && d <= Day.Fri) {
                System.Console.WriteLine("weekday");
            } else {
                System.Console.WriteLine("weekend");
            }
            ++d;
        }
    }
}
