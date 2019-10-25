import java.io.*;
import java.util.*;

public class matching {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        long n = Long.parseLong(in.readLine());
        String s = in.readLine();
        String t = in.readLine();
        if(n == 1) {
            System.out.println(numCopies(s, t));
        } else {
            if(s.length() > t.length() * n) {
                System.out.println(0);
            } else {
                StringBuilder sb = new StringBuilder("");
                int count = 0;
                for(int i = 0; i < s.length(); i += t.length()) {
                    sb.append(t);
                    count++;
                }
                if(s.length() > t.length() * (n - 1)) {
                    System.out.println(numCopies(s, sb.toString()));
                } else {
                    String str = sb.toString();
                    int a = numCopies(s, str);
                    str += t.substring(0, s.length() + t.length() - 1 - str.length());
                    int b = numCopies(s, str) - a;
                    //System.out.println(a + " " + b);
                    System.out.println(a * (n - count + 1) + b * (n - count));
                }
            }
        }
    }

    public static int numCopies(String s, String t) {
        //System.out.println(s + " " + t);
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        for(int i = 1; i < dp.length; i++) {
            //System.out.println(i + " " + dp[i]);
            if(dp[i] == -1) dp[i] = dp[i - 1] + 1;
            if(s.charAt(i) != s.charAt(dp[i])) {
                if(dp[i] == 0 || dp[i - 1] == -1) {
                    dp[i] = -1;
                }
                if(dp[i - 1] != -1 && dp[i] != -1) {
                    dp[i] = dp[dp[--i]] + 1;
                }
            }
        }
        //System.out.println(Arrays.toString(dp));
        //System.out.println("test");
        int ind = 0;
        int count = 0;
        for(int i = 0; i < t.length(); i++) {
            if(s.charAt(ind) == t.charAt(i)) {
                ind++;
            } else {
                if(ind > 0) {
                    ind = dp[ind - 1] + 1;
                    i--;
                } else {
                    ind = 0;
                }
            }
            if(ind == s.length()) {
                count++;
                //System.out.println(i);
                ind = dp[ind - 1] + 1;
            }
            //System.out.println(i + " " + ind);
        }
        return count;
    }
}
