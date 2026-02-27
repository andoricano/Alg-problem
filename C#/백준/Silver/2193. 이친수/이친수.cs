using System;

class Program
{
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        ulong[] d = new ulong[n+4];
        d[1] = 1;
        d[2] = 1;
        d[3] = 2;
        for(int i = 4; i<=n ;i ++){
            for(int j = 1; j <= i-2; j++){
                d[i] += d[j];
            }
            d[i]++;
        }
        Console.WriteLine(d[n]);
    }
}