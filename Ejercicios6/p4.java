public class p4 {
    static double[][] multiply(double[][] m1, double[][] m2) {
        double[][] r = new double[m1.length][m2[0].length];
        for (int i = 0; i < m1.length; ++i)
            for (int j = 0; j < m2[0].length; ++j)
                for (int k = 0; k < m1[0].length; ++k)
                    r[i][j] += m1[i][k] * m2[k][j];
        return r;
    }
    public static void main(String[] args) {
        int l = 600;
        double[][] m1 = new double[l][l], m2 = new double[l][l], r;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < l; ++j) {
                m1[i][j] = i + j;
                m2[i][j] = i - j;
            }
        r = multiply(m1, m2);
        double t = 0;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < l; ++j)
                t += r[i][j];
        System.out.println(t);
    }
}

