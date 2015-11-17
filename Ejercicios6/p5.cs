public class p5 {
    enum Day {
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY
    };

    public static void Main() {
        Day x = Day.MONDAY, y = Day.TUESDAY, z;
        int[] f = new int[2];
        int r;
        x = y;
        x++;
        ++x;
        y = x + 1;
        r = x;
    }
}
