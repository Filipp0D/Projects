using System;
using class_namespace;
using System.IO;


namespace C__dotNET_learn
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Hello World!\n");
            Console.WriteLine("Hello World!");

            int iNum = 3;               // 4 bytes, only integer
            long lNum = 3000L;           // 8 bytes, only integers
            float fNum = 3.14F;          // 4 bytes, 6-7 decimal
            double dNum = 3.14159265D;   // 8 bytes, 15 decimal
            char letter = 'a';          // 1 byte, true or false
            bool boolean = true;        // 2 bytes, single char
            string word = "ciao";       // 2 bytes, sequence of chars

            float f1 = 35e3F;           // float and double also scientific number
            double d1 = 12E4D;
            Console.WriteLine(f1);
            Console.WriteLine(d1);

            const int constINum = 5;
            Console.WriteLine("iNum is: " + iNum);

            int x, y, z;
            x = y = z = 4;

            // Implicit casting: smaller num -> bigger num
            // Explicit casting: bigger num -> smaller num
            int i1 = (int)d1;
            Console.WriteLine(Convert.ToString(dNum));
            Console.WriteLine(Convert.ToDouble(iNum));
            Console.WriteLine(Convert.ToInt32(d1));
            Console.WriteLine(Convert.ToString(boolean));

            Console.WriteLine("Enter a character: ");
            string inputString = Console.ReadLine();
            Console.WriteLine("inputString is: " + inputString);

            // string concatenation
            string firstName = "John ";
            string lastName = "Doe";
            string fullName1 = firstName + lastName;

            // string interpolation
            string fullName2 = $"My full name is: {firstName} {lastName}";

            Console.WriteLine(fullName1[0]);
            int charPos = fullName1.IndexOf("D");
            string subpartofString = fullName1.Substring(charPos);      // return the rest of the string after the specified index
            Console.WriteLine(subpartofString);

            int int1 = 1;
            int int2 = 2;

            if (int1 < int2)
            {
                Console.WriteLine("int1 < int2");
            }
            else if (int1 > int2)
            {
                Console.WriteLine("int1 > int2");
            }else
            {
                Console.WriteLine("int1 = int2");
            }

            bool b = true;
            // Syntax for short-hand condition
            // variable = (condition) ? expressionTrue :  expressionFalse;
            string res = (b == true) ? "True" : "False";
            Console.WriteLine(res);

            switch (int1)
            {
                case 1:
                    Console.WriteLine("int1=1");
                    break;
                case 2:
                    Console.WriteLine("int1=2");
                    break;
                case 3:
                    Console.WriteLine("int1=3");
                    break;
                default:
                    Console.WriteLine("int1 != 1, 2, 3");
                    break;
            }

            int i = 0;
            while (i < 5){
                Console.WriteLine("Count="+i);
                i++;
            }

            i = 0;
            do
            {
                Console.WriteLine("Count="+i);
                i++;
            } while (i < 5);

            for (int j = 0; j < 5; j++) // Outer loop
            {
                Console.WriteLine("Outer count="+j);
                for (int k = 5; k > 0; k--) // Inner loop
                {
                    Console.WriteLine("Inner count=" + k);
                }
            }

            string[] countries = { "Italy", "USA", "Kenya", "Japan" };
            foreach (string country in countries)
            {
                Console.WriteLine("Count of each in foreach loop: " + country);
            }

            for (int j = 0; j < 10; j++)
            {
                if (j == 4)
                {
                    Console.WriteLine("j=4, break");
                    break;
                }
                else
                { 
                    Console.WriteLine("j!=4, continue");
                    continue;
                }
                
            }

            int[] iArray = { 1, 2, 3, 4, 5 };
            string[] strArray = { "aaa", "bbb", "ccc", "ddd", "eee" };
            string[] animal = new string[] { "Eagle", "Lion", "Bear" };
            string[] cars = new string[3] { "BMW", "Ferrari", "Volvo" };
            string[] strArr = new string[3];

            Array.Sort(iArray);
            Array.Sort(animal);
            foreach (string str in animal)
            {
                Console.WriteLine(str);
            }

            // multidimensional array
            int[,] i2DArr = { { 1, 2, 3 }, { 4, 5, 6 } };
            for (int j = 0; j < i2DArr.GetLength(0); j++)
            {
                for (int k = 0; k < i2DArr.GetLength(1); k++)
                {
                    Console.WriteLine(i2DArr[j, k]);
                }
            }

            basicPrintMethod();
            basicPrintMethod();

            Console.WriteLine(method(lastName:"D\'Agostino", age:27));
            Console.WriteLine(sum(1, 2));
            Console.WriteLine(sum(1.1, 2.04));




            // OOP
            // Note: DRY: Don't Reapeat Yourself
            Car1 car = new Car1();
            Console.WriteLine(car.color);

            Car1 ford = new Car1();
            Car1 volvo = new Car1();

            ford.model = "Mustang";
            ford.year = 1998;

            volvo.model = "V70";
            volvo.year = 2006;

            // Overloading of constructors
            Car Ford = new Car(modelCar: "Mustang", yearCar: 1998);
            Car BMW = new Car(modelCar: "Series3", yearCar: 2013);
            BMW.printColor();

            Person personObj = new Person();
            personObj.Name = "Filippo";
            Console.WriteLine(personObj.Name);
            personObj.LastName = "D'Agostino";
            Console.WriteLine(personObj.LastName);
            // ENCAPSULATION's advantages:
            // better contorl over class memebers, less risk of messing up with the code
            // fields can be made read-only, write-only or read-and-write
            // flexibility, change one part of the code without affecting others
            // increased security of data

            Engineer MechEng = new Engineer("Mechatronics");
            MechEng.sayHi();

            Lion lion = new Lion();
            lion.animalSound();
            lion.sleep();

            Tree tree = new Tree();
            tree.grow();
            tree.flourish();

            DemoClass demo = new DemoClass();
            demo.myMethod();
            demo.myOtherMethod();

            Level highLevel = Level.HIGH;
            Console.WriteLine(highLevel);

            int month = (int)Months.March;
            Console.WriteLine(month);


            // FILE
            // write to a file and read it
            string writeText = "Hello World!";
            File.WriteAllText("FileTry.txt", writeText);

            string readText = File.ReadAllText("FileTry.txt");
            Console.WriteLine(readText);


            // EXCEPTIONS - TRY...CATCH
            try
            {
                int[] nums = { 1, 2, 3, 4, 5 };
                Console.WriteLine(nums[10]);
            }
            catch(Exception e)
            {
                Console.WriteLine("Something went wrong");
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.WriteLine("try-catch is finisched");
            }

            checkAge(14);


            // try abstract class/method vs virtual method

            BaseClass[] bcArray = new BaseClass[2];
            bcArray[0] = new DerivedClass(2, 3.14F,"dc1");
            bcArray[1] = new DerivedClass(5, 7.18F, "dc2");

            abstractBaseClass[] abcArray = new abstractBaseClass[2];
            abcArray[0] = new DerivedFromAbstractClass(4, 3.14F);
            abcArray[1] = new DerivedFromAbstractClass(1, 8);
            abcArray[0].typeName();
            abcArray[1].multiply(5,8.6F);



        }



        static void checkAge(int age)
        {
            if (age < 18)
            {
                throw new ArithmeticException("Access denied - You must be at least 18");
            }
            else
            {
                Console.WriteLine("Access granted");
            }
        }

        static void basicPrintMethod()
        {
            Console.WriteLine("I just got executed!");
        }

        static int method(string lastName, int age, string Name = "Filippo")    // default pars are known as "optional pars" and have to be put at the end
        {
            Console.WriteLine("Name+Lastname:"+Name+lastName+", age:"+age);
            return 0;
        }
        
        static int sum(int a, int b)
        {
            return a + b;
        }

        static double sum(double a, double b)
        {
            return a + b;
        }


    }
}
