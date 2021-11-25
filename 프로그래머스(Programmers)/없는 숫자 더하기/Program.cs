using System;

namespace ConsoleApp1
{

    class Program
    {
        static int[] check = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        static int solution(int[] numbers)
        {

            int answer = 0;

            for (int i = 0; i < numbers.Length; i++)
            {
                check[numbers[i]]++;
            }

            for (int i = 0; i < check.Length; i++)
            {
                if (check[i] == 0)
                {
                    answer += i;
                }
            }

            return answer;
        }
        static void Main(string[] args)
        {
            int[] numbers = { 1, 2, 3 };
            Console.WriteLine("Hello World!");
            Console.WriteLine(Program.solution(numbers));
        }
    }
}
