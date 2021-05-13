using System;
using System.Collections.Generic;


class Duplicates
{
    // Find duplicate method to find all duplicate integers in an array
    // Space: O(n), array(n) + list(n/2) + dictionary(n)
    // Time: O(n), time to iter through arr insertions and look ups for dictionary is often O(1)
    public static List<int> duplicates(int[] arr)
    {
        List<int> duplicates = new List<int>();
        Dictionary<int, int> values = new Dictionary<int, int>(arr.Length); // No more then arr.length key pairs are needed.
        foreach (int num in arr)
        {
            try
            {
                if (values[num] == 1)
                {
                    duplicates.Add(num);
                    values[num]++;
                }
            }
            catch (KeyNotFoundException)
            {
                values.Add(num, 1);
            }
        }
        return duplicates;
    }

	static void Main(string[] args)
    {
        int[] num_0 = { 23, 2, 3, 5, 7, 10, 4, 5, 3, 2, 8, 23, 123, 2, 53, 2, 6, 9 };

        foreach (int item in duplicates(num_0))
            Console.WriteLine(item);
    }
}
