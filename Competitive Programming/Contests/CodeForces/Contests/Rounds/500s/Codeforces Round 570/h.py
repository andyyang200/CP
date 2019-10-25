line = input().split()
n = int(line[0])
k = int(line[1])
dp = [[0 for x in range(n + 1)] for y in range(n + 1)]
last = [-1 for i in range(1000)]
s = input()
s = "$" + s
dp[0][0] = 1
for i in range(1, n + 1):
	dp[i][0] = 1
	for j in range(1, n + 1):
		dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
		if last[ord(s[i])] != -1:
			dp[i][j] -= dp[last[ord(s[i])]][j]
	last[ord(s[i])] = i


ans = 0
for i in range(n, -1):
	take = min(k, dp[n][i])
	k -= take
	ans += take * (n - i)
	if (k == 0):
		break

if k == 0:
	print(ans)
else:
	print(-1)

