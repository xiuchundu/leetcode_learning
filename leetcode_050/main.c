double myPow(double x, int n) {
    if (0 == n)
        return 1;

    if (n < 0)
        return 1 / (x * myPow(x, -(n + 1)));

    if (0 == (n & 1)) {
        //判断为偶数
        return myPow(x * x, n >> 1);
    } else {
        //奇数
        return x * myPow(x * x, (n - 1) >> 1);
    }
}
