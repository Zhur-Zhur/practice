using System;
using System.Collections.Generic;


class Program
{
    // All Sum program to find all the ways and orders to use a set of numbers to calculate a given integer sum greater then 0
    // Worst Case time: O(goal*n*n), O(n^3)
    //     If arr contains all numbers from 1 to goal, buckets will take 1 + 2 + 3 + ... + goal-1 + goal = n(n+1)/2 steps
    //     There are goal outer loops and goal == n
    // Space: O(n^2)
    //     n for array
    //     n lists of size 1 to n, (n(n+1)/2), n^2
    public static List<string> all_sum(int[] arr, int goal)
    {
        if (goal <= 0) return null;

        List<string>[] buckets = new List<string>[goal + 1];
        for (int i = 0; i < buckets.Length; i++)
            buckets[i] = new List<string>();

        foreach (int num in arr)
            if (num <= goal)
                buckets[num].Add(num.ToString());

        for (int i = 1; i < goal; i++)
            foreach (String numbers in buckets[i])
                foreach (int num in arr)
                    if (i + num <= goal)
                        buckets[i + num].Add(numbers + "," + num.ToString());

        return buckets[goal];
    }

    static void Main(string[] args)
    {
        int[] num_0 = { 2, 3, 5, 7, 10 };
        int goal_0 = 15;
        
        List<String> results_0 = all_sum(num_0, goal_0);
        
        Console.WriteLine(goal_0);
        Console.WriteLine();
        foreach (String item in results_0)
            Console.WriteLine(item);
    }
}