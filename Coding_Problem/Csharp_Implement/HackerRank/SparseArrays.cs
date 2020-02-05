// HackerRank problem 
// Sparse Arrays

using System;
using System.Collections.Generic;
using System.IO;

class Solution
{

    // Complete the matchingStrings function below.
    static int[] matchingStrings(string[] strings, string[] queries)
    {
        List<string> lStr = new List<string>(strings);
        List<int> result = new List<int>(queries.Length);
        foreach (var it in queries)
        {
            result.Add(lStr.FindAll(x => x == it).Count);
        }
        return result.ToArray();
    }

    static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int stringsCount = Convert.ToInt32(Console.ReadLine());

        string[] strings = new string[stringsCount];

        for (int i = 0; i < stringsCount; i++)
        {
            string stringsItem = Console.ReadLine();
            strings[i] = stringsItem;
        }

        int queriesCount = Convert.ToInt32(Console.ReadLine());

        string[] queries = new string[queriesCount];

        for (int i = 0; i < queriesCount; i++)
        {
            string queriesItem = Console.ReadLine();
            queries[i] = queriesItem;
        }

        int[] res = matchingStrings(strings, queries);

        textWriter.WriteLine(string.Join("\n", res));

        textWriter.Flush();
        textWriter.Close();
    }
}
