import java.io.*;
import java.util.*;

public class evacuation {
	static class Point implements Comparable<Point> {
		final int index;
		final int loc;
		public Point(int index, int loc) {
			this.index = index;
			this.loc = loc;
		}
		public int compareTo(Point that) {
			return loc - that.loc;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("evacuation.in"));
		int n = Integer.parseInt(in.readLine());
		StringTokenizer fl = new StringTokenizer(in.readLine());
		Point[] teams = new Point[n];
		for (int i = 0; i < n; ++i) {
			teams[i] = new Point(i, Integer.parseInt(fl.nextToken()));
		}
		int m = Integer.parseInt(in.readLine());
		StringTokenizer sl = new StringTokenizer(in.readLine());
		Point[] shelters = new Point[m];
		for (int i = 0; i < m; ++i) {
			shelters[i] = new Point(i, Integer.parseInt(sl.nextToken()));
		}
		in.close();
		Arrays.sort(teams);
		Arrays.sort(shelters);

		long INF = 9000000000000000000L;
		long[][] v = new long[n + 1][m + 1];
		boolean[][] b = new boolean[n + 1][m + 1];
		for (long[] vv : v) {
			Arrays.fill(vv, INF);
		}
		v[0][0] = 0;
		for (int t = 0; t < n; ++t) {
			for (int s = 0; s <= m; ++s) {
				if (s > 0) {
					long val = v[t][s] + Math.abs(teams[t].loc - shelters[s - 1].loc);
					if (v[t + 1][s] > val) {
						v[t + 1][s] = val;
						b[t + 1][s] = false;
					}
				}
				if (s < m) {
					long val = v[t][s] + Math.abs(teams[t].loc - shelters[s].loc);
					if (v[t + 1][s + 1] > val) {
						v[t + 1][s + 1] = val;
						b[t + 1][s + 1] = true;
					}
				}
			}
		}

		int[] ans = new int[n];
		for (int i = n - 1, cs = m; i >= 0; --i) {
			ans[teams[i].index] = shelters[cs - 1].index + 1;
			if (b[i + 1][cs]) {
				--cs;
			}
		}

		PrintWriter out = new PrintWriter("evacuation.out");
		out.println(v[n][m]);
		for (int i = 0; i < n; ++i) {
			out.print(ans[i] + " ");
		}
		out.println();
		out.close();
	}
}
