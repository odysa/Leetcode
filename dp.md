### 14 剪绳子

两个选择，前面j个剪掉和一刀不剪

```js
dp[i] = max(dp[i],dp[i-j]*j,j*(i-j))
```


