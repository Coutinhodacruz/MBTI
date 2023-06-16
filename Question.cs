using System;

public class PersonalityTest
{
    private const int MaxQuestions = 5;
    private const int MaxOptions = 2;

    public char[] Answers { get; set; } = new char[MaxQuestions];
    public int CountA { get; set; }
    public int CountB { get; set; }

    public void GetTrait(string[] questions, string[][] answerOptions)
    {
        for (int i = 0; i < MaxQuestions; i++)
        {
            Console.WriteLine($"Question {questions[i]}");
            Console.WriteLine("Choose either a or b:");
            for (int j = 0; j < MaxOptions; j++)
            {
                Console.WriteLine(answerOptions[i][j]);
            }

            char userAnswer;
            while (!char.TryParse(Console.ReadLine(), out userAnswer) || (userAnswer != 'a' && userAnswer != 'b'))
            {
                Console.WriteLine("Expected a or b as a response");
                Console.WriteLine("I know this is an error, please retry again");
            }

            Answers[i] = userAnswer;
            Console.WriteLine();
        }

        foreach (char answer in Answers)
        {
            if (answer == 'a')
            {
                CountA++;
            }
            else if (answer == 'b')
            {
                CountB++;
            }
        }
    }
}

public class Program
{
    public static void Main()
    {
        string[] questions = { "1", "2", "3", "4", "5" };
        string[][] answerOptions = {
            new string[] { "a. expend energy, enjoy groups", "b. conserve energy, enjoy one-on-one" },
            new string[] { "a. more outgoing, think out loud", "b. more reserved, think to yourself" },
            new string[] { "a. seek many tasks, public activities, interaction with others", "b. seek private solitary activities with quiet to concentrate" },
            new string[] { "a. external, communicative, express yourself", "b. internal, reticent, keep to yourself" },
            new string[] { "a. active, initiate", "b. reflective, deliberate" }
        };

        PersonalityTest test = new PersonalityTest();
        test.GetTrait(questions, answerOptions);

        Console.WriteLine($"Trait A count: {test.CountA}");
        Console.WriteLine($"Trait B count: {test.CountB}");
        Console.WriteLine($"Trait A: {(test.CountA > test.CountB ? 'A' : 'B')}");
        Console.WriteLine($"Trait B: {(test.CountA > test.CountB ? 'B' : 'A')}");
    }
}
