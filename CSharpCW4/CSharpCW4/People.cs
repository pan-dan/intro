using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpCW4
{
    public class People:Hospital
    {
        public int age { get; set; }
        public double weight { get; set; }
        public double height { get; set; }
        public string disease { get; set; }

        void Medcard()
        {
            Console.WriteLine($"Возраст:{age}, вес: {weight}, рост: {height}, заболевание:{disease} ");
        }



    }



}
