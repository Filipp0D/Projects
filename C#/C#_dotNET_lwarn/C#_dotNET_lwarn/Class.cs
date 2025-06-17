using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Linq;
using System.Management.Instrumentation;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace class_namespace
{
    class Car1
    {
        public string color = "blue";
        public string model;
        public int year;
    }
    class Car
    {
        private string color = "blue";
        public string model;
        public int year;

        // Constructor
        public Car(string modelCar, int yearCar)
        {
            model = modelCar;
            year = yearCar;
        }

        public void printColor()
        {
            Console.WriteLine(color);
        }

    }

    class Person
    {
        // Encapsulation
        private string name;    // field
        public string Name      // property
        {
            get { return name; }
            set { name = value; }
        }

        // short-hand for getter and setter
        private string lastName;
        public string LastName
        { get; set; }

        public void sayHi()
        {
            Console.WriteLine("Hi");
        }

        public virtual void professionSay()     // if not virtual, the base class keeps the method
        {
            Console.WriteLine("I am a person");
        }

    }

    // INHERITANCE
    // adv: reusability->reuse fields and methods of an existing class to make a new one
    class Engineer : Person
    {
        private string field;

        public Engineer(string specField)
        {
            field = specField;
        }

        // POLYMORPHYSM-> adv: reusability
        public override void professionSay()        // if base class has virtual
        {
            Console.WriteLine("I am a Mechtronic Engineer");
        }

    }

    sealed class Door       // sealed->class cannot be inheritied
    {
        public string color = "brown";
    }

    // ABSTRACTION -> used for classes and methods, abstraction can be achieved with either abstract classes or interfaces
    // abstract class: restricted class that cannot be used to create objects
    // abstract method: can only be used in an abstract class, and it does not have a body. The body is provided by the derived class (inherited from)
    // adv: achieve security, hide certain details and only show the important details of an object
    abstract class Animal
    {
        public abstract void animalSound();
        public void sleep()
        {
            Console.WriteLine("Zzz");
        }
    }

    class Lion : Animal
    {
        public override void animalSound()
        {
            Console.WriteLine("Roaaar");
        }
    }

    // INTERFACE
    // By default, members of an interface are abstract and public
    // Interfaces can contain properties and methods, but not fields
    // good practice to add 'I' before the name
    interface IPlant
    {
        void grow();
        void flourish();
    }

    class Tree : IPlant
    {
        public void grow()
        {
            Console.WriteLine("Grow");
        }

        public void flourish()
        {
            Console.WriteLine("Bloom");
        }
    }

    // MULTIPLE INTERFACE
    interface IFirstInterface
    {
        void myMethod();
    }

    interface ISecondInterface
    {
        void myOtherMethod();
    }

    class DemoClass : IFirstInterface, ISecondInterface
    {
        public void myMethod()
        {
            Console.WriteLine("Some text..");
        }
        public void myOtherMethod()
        {
            Console.WriteLine("Some other text...");
        }
    }

    enum Level
    {
        LOW,
        MEDIUM,
        HIGH
    }

    enum Months
    {
        January,    // 0
        February,   // 1
        March,      // 2
        April,      // 3
        May,        // 4
        June,       // 5
        July        // 6
    }

    class BaseClass
    {
        private int ifield = 0;
        protected float ffield = 3.14F;
        private string sfield = "";
        public int instanceCount = 0;

        public BaseClass(int init_ifield, float init_ffield, string init_sfield)
        {
            this.ifield = init_ifield;
            this.ffield = init_ffield;
            this.sfield = init_sfield;
            instanceCount++;
        }
        public virtual float Multiply(int inum, float fnum)
        {
            return (inum * fnum);
        }

        virtual public void typeName()
        {
            Console.WriteLine("BaseClass");
        }
    }

    class DerivedClass : BaseClass
    {
        public DerivedClass(int init_ifield, float init_ffield, string init_sfield) : base(init_ifield, init_ffield, init_sfield)
        {
        }

        public override float Multiply(int inum, float fnum) => (inum*fnum);    // expression body

        public override void typeName() => Console.WriteLine("DerivedClass");
    }

    abstract class abstractBaseClass
    {
        private int ifield = 0;
        protected float ffield = 3.14F;
        public abstractBaseClass(int ifield, float ffield)
        {
            this.ifield = ifield;
            this.ffield = ffield;
        }

        abstract public float multiply(int inum, float fnum);

        abstract public void typeName();
    }

    class DerivedFromAbstractClass : abstractBaseClass
    {
        public DerivedFromAbstractClass(int ifield, float ffield) : base(ifield, ffield)
        {
        }

        public override float multiply(int inum, float fnum) => (inum * fnum);

        public override void typeName() => Console.WriteLine("DerviedFromAbstractClass");
    }
}
